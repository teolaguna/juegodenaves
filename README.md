# juegodenaves

**Actividad 8 — Programación Orientada a Objetos (POO) en C++**
Juego de naves en consola (`class Nave`) — Laboratorio de Programación (LPR) 5° Año, 3° Grupos A-B.

---

## Descripción

Simulador de combate espacial en consola desarrollado con Programación Orientada a Objetos en C++.
Se definen las clases `Nave`, `Asteroide` y `Bala`, aplicando atributos privados (`private:`),
métodos públicos (`public:`), constructores y encapsulamiento.

## Objetivos

1. **Diseño de Clases (class):** definir atributos privados (`private:`) y métodos públicos (`public:`).
2. **Encapsulamiento:** proteger la salud y energía de la nave para que no acepten valores negativos.
3. **Documentación técnica:** redactar el Informe APA v7, el Manual del Programador y el Manual del Usuario.

## Controles

| Tecla      | Acción                     |
| ---------- | -------------------------- |
| `W`        | Mover la nave hacia arriba |
| `S`        | Mover la nave hacia abajo  |
| `A`        | Mover la nave a la izquierda |
| `D`        | Mover la nave a la derecha |
| `ESPACIO`  | Disparar                   |

## Estructura del proyecto

```
juegodenaves/
├── .gitignore
├── LICENSE
├── README.md
├── docs/
│   ├── InformeEEST1_LPR2026_ACT08_TeoLaguna_v1.0.0.docx
│   ├── CHANGELOG.md
│   └── manuales/
│       ├── manual_programador_v1.0.0.docx
│       └── manual_usuario_v1.0.0.docx
├── src/
│   └── main.cpp
└── capturas/
    └── combate_consola.png
```

## Compilación y ejecución

Desde la raíz del proyecto, en PowerShell:

```powershell
g++ -std=c++11 src/main.cpp -o src/juegodenaves.exe
.\src\juegodenaves.exe
```

El ejecutable generado (`*.exe`) está excluido por `.gitignore`.

## Funcionalidad implementada

**Funcionalidad 1 (Score):** cada asteroide destruido con un disparo suma **+10 puntos**. El score
se muestra en el HUD durante la partida y como "SCORE FINAL" en la pantalla de Game Over. Al llegar
a **300 puntos**, el disparo con `ESPACIO` pasa a ser **doble** (dos balas desde las alas).

## Ficha

- **Estudiante:** Teo Laguna
- **Curso / Grupo:** 5° Año 3° — Grupos A / B
- **Materia:** Laboratorio de Programación (LPR)
- **Institución:** E.E.S.T. N° 1 "Eduardo Ader" — Vicente López
- **Docentes:** Mansilla Muñoz York Elías y Yamil Ganduglia
- **Licencia:** MIT escolar (ver `LICENSE`)
