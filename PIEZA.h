// Cabecera con la definición de la estructura de la pieza y funciones asociadas a ella

// Instrucciones para el preprocesador
#ifndef PIEZA_H
#define PIEZA_H

// Bibliotecas estándar de C++
#include <iostream>

// Bibliotecas del proyecto
#include "LABERINTO.h"

class Laberynth;

// Definición de la estructura pieza
class Pieza{

  // Atributos accesibles desde fuera de la clase:
  public:
    Pieza();
    bool rotar (Laberynth& lab);
    bool mover_arriba (const Laberynth& lab);
    bool mover_abajo (const Laberynth& lab);
    bool mover_derecha (const Laberynth& lab);
    bool mover_izquierda (const Laberynth& lab);
    void mostrar() const;
    int centroi() const;
    int centroj() const;
    int orientacion() const;


// Atributos accesibles sólo desde la clase:
  private:
    int centro_fila;
    int centro_columna;
    int posicion;
};

#endif
