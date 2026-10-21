# CHANGELOG — juegodenaves

## [v1.0.0] — 2026-10-20

### Añadido
- Motor del juego de naves en consola con POO: clases `Nave`, `Asteroide` y `Bala`.
- Sistema de entrada por teclado (`W`, `A`, `S`, `D` y `ESPACIO`) con ocultación del cursor.
- HUD con nombre del piloto y cantidad de vidas.
- Detección de colisiones asteroide-jugador y bala-asteroide.
- Sistema de solicitud del nombre del piloto (sistema anti-copia) mostrado en el HUD.
- **Funcionalidad 1 (Score):** contador de puntos (+10 por asteroide destruido) mostrado en el HUD y como SCORE FINAL; a partir de 300 puntos el disparo con ESPACIO se convierte en doble (dos balas desde las alas).

### Corregido
- Evitado el salto de elementos al eliminar una bala de `vector<Bala*>` (decremento del índice).
- Liberación de memoria (`delete`) de asteroides reemplazados para evitar fugas.

### Documentación
- Informe técnico en formato APA 7.ª edición (`docs/`).
- Manual del Programador y Manual de Usuario (`docs/manuales/`).
- `README.md` con portada del proyecto y guía de compilación.
