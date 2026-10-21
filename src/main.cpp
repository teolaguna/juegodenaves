/*
================================================================================
=========
   Materia: Laboratorio de Programación (LPR) — 5° Año
   Institución: E.E.S.T. N° 1 "Eduardo Ader" — Vicente López
   Archivo: src/main.cpp
   Actividad 8: Introducción a POO - Motor de Juego de Naves (Clases, Objetos y Constructores)
   Docente: Mansilla Muñoz York
   Estudiante: Teo Laguna
================================================================================
=========
*/

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <ctime>
#include <cctype> // Para tolower()

using namespace std;

void gotoxy(int x, int y) {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x; dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void ocultarCursor() {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2; cci.bVisible = FALSE;
    SetConsoleCursorInfo(hCon, &cci);
}

// ========================================================================
// CLASE NAVE (El Jugador)
// ========================================================================
class Nave {
private:
    int x, y;
    int vidas;

public:
    Nave(int _x, int _y, int _vidas) {
        x = _x; y = _y; vidas = _vidas;
    }

    int getX() { return x; }
    int getY() { return y; }
    int getVidas() { return vidas; }
    void reducirVida() { vidas--; }

    void pintar() {
        gotoxy(x, y);     cout << "  ^  ";
        gotoxy(x, y + 1); cout << " (O) ";
        gotoxy(x, y + 2); cout << "^^^^ ";
    }

    void borrar() {
        gotoxy(x, y);     cout << "     ";
        gotoxy(x, y + 1); cout << "     ";
        gotoxy(x, y + 2); cout << "     ";
    }

    void mover(char tecla) {
        borrar();
        if (tecla == 'a' && x > 2) x--;
        if (tecla == 'd' && x < 70) x++;
        if (tecla == 'w' && y > 3) y--;
        if (tecla == 's' && y < 20) y++;
        pintar();
    }
};

// ========================================================================
// CLASE ASTEROIDE Y BALA (Simplificadas)
// ========================================================================
class Asteroide {
private:
    int x, y;
public:
    Asteroide(int _x, int _y) { x = _x; y = _y; }
    int getX() { return x; }
    int getY() { return y; }
    void pintar() { gotoxy(x, y); cout << "O"; }
    void borrar() { gotoxy(x, y); cout << " "; }
    void mover() {
        borrar();
        y++;
        if (y > 23) { y = 4; x = (rand() % 70) + 2; }
        pintar();
    }
};

class Bala {
private:
    int x, y;
public:
    Bala(int _x, int _y) { x = _x; y = _y; }
    int getX() { return x; }
    int getY() { return y; }
    void mover() {
        gotoxy(x, y); cout << " ";
        y--;
        gotoxy(x, y); cout << "|";
    }
    bool fueraDeRango() { return y < 4; }
};

// ====================================================================
// PROGRAMA PRINCIPAL
// ====================================================================
int main() {
    srand(time(NULL));

    // SISTEMA ANTI-COPIA: Petición de datos
    string nombrePiloto;
    cout << "Ingresa tu Nombre y Apellido (Se mostrara en la captura de pantalla): ";
    getline(cin, nombrePiloto);

    system("cls");
    ocultarCursor();
    bool gameOver = false;

    // [!] PISTA: Requiere la funcionalidad 1 (Score).
    int score = 0;

    Nave jugador(35, 20, 3);
    vector<Asteroide*> asteroides;
    vector<Bala*> balas;

    for (int i = 0; i < 5; i++) {
        asteroides.push_back(new Asteroide((rand() % 70) + 2, (rand() % 5) + 4));
    }

    jugador.pintar();

    while (!gameOver) {
        // HUD CON NOMBRE DEL ESTUDIANTE
        gotoxy(2, 1); cout << "PILOTO: " << nombrePiloto << "  ";
        gotoxy(2, 2); cout << "VIDAS: " << jugador.getVidas() << "  ";
        gotoxy(2, 3); cout << "SCORE: " << score << "  ";

        if (_kbhit()) {
            char tecla = tolower(_getch()); // tolower evita el problema del Bloq Mayus
            // [!] PISTA: Requiere la funcionalidad 1 (Score).
            // Modificar el if(tecla == ' ') en el main() para instanciar dos objetos Bala.
            if (tecla == ' ') {
                if (score < 300) {
                    // Disparo simple central
                    balas.push_back(new Bala(jugador.getX() + 2, jugador.getY() - 1));
                } else {
                    // Disparo doble desde las alas
                    balas.push_back(new Bala(jugador.getX(), jugador.getY()));
                    balas.push_back(new Bala(jugador.getX() + 4, jugador.getY()));
                }
            } else {
                jugador.mover(tecla);
            }
        }

        for (int i = 0; i < balas.size(); i++) {
            balas[i]->mover();
            if (balas[i]->fueraDeRango()) {
                gotoxy(balas[i]->getX(), balas[i]->getY()); cout << " ";
                delete balas[i];
                balas.erase(balas.begin() + i);
                i--;
            }
        }

        for (int i = 0; i < asteroides.size(); i++) {
            asteroides[i]->mover();

            // Colision Asteroide -> Jugador
            if ((asteroides[i]->getX() >= jugador.getX() && asteroides[i]->getX() <= jugador.getX() + 4) &&
                (asteroides[i]->getY() >= jugador.getY() && asteroides[i]->getY() <= jugador.getY() + 2)) {
                jugador.borrar();
                jugador.reducirVida();
                asteroides[i]->borrar();
                delete asteroides[i];
                asteroides[i] = new Asteroide((rand() % 70) + 2, 4);
                jugador.pintar();

                if (jugador.getVidas() == 0) gameOver = true;
            }

            // Colision Bala -> Asteroide
            for (int j = 0; j < balas.size(); j++) {
                if (asteroides[i]->getX() == balas[j]->getX() && (asteroides[i]->getY() == balas[j]->getY() ||
                    asteroides[i]->getY() + 1 == balas[j]->getY())) {
                    gotoxy(balas[j]->getX(), balas[j]->getY()); cout << " ";
                    delete balas[j];
                    balas.erase(balas.begin() + j);

                    asteroides[i]->borrar();
                    delete asteroides[i];
                    asteroides[i] = new Asteroide((rand() % 70) + 2, 4);
                    score += 10; // FUNCIONALIDAD 1 (Score): suma puntos al destruir un asteroide
                    break;
                }
            }
        }
        Sleep(30);
    }

    system("cls");
    gotoxy(30, 10);
    cout << "G A M E   O V E R... O sea... Perdiste!!";
    gotoxy(30, 12);
    cout << "SCORE FINAL: " << score << " puntos";
    gotoxy(30, 14);
    system("pause");
    return 0;
}
