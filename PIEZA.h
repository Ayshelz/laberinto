// Cabecera con la definición de la estructura de la pieza y funciones asociadas a ella

// Instrucciones para el preprocesador
#ifndef PIEZA_H
#define PIEZA_H

// Bibliotecas del proyecto
#include "LABERINTO.h"

// Definición de la estructura pieza
class Pieza{

  // Atributos accesibles desde fuera de la clase:
  public:
    Pieza();       
    bool rotar( Laberynth& const);                   
    bool mover_arriba( Laberynth& const);
    bool mover_abajo( Laberynth& const);
    bool mover_derecha( Laberynth& const);
    bool mover_izquierda( Laberynth& const);
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
