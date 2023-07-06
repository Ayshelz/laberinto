#include "PIEZA.h"

// Implementación del constructor de la clase:
Pieza(){
    centro_fila = 0;
    centro_columna = 1;
    posicion = 0;
}      

bool rotar( Laberynth& const);                   
bool mover_arriba( Laberynth& const);
bool mover_abajo( Laberynth& const);
bool mover_derecha( Laberynth& const);
bool mover_izquierda( Laberynth& const);
void mostrar() const; 
int centroi() const;
int centroj() const;
int orientacion() const;
