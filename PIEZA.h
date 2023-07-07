// Cabecera con la definición de la estructura de la pieza y funciones asociadas a ella

// Instrucciones para el preprocesador
#ifndef PIEZA_H
#define PIEZA_H

// Bibliotecas estándar de C++
#include <iostream>

// Bibliotecas del proyecto
#include "LABERINTO.h"

// Se declara la clase Laberynth para no obtener errores de compilación
class Laberynth;

// Definición de la estructura pieza
class Pieza{

  // Métodos accesibles desde fuera de la clase:
  public:
    // Constructor de la clase. Crea una pieza horizontal cuyo centro está en las coordenadas (0,1)
    Pieza();
    // Constructor de la clase a partir de dos coordenadas y una orientación
    Pieza(int, int, int);

    // Métodos para comprobar si puede realizarse un movimiento.
    // Reciben un laberinto por referencia y devuelvuen TRUE si se puede realizar el movimiento
    bool correcto_rotar (const Laberynth& lab) const;
    bool correcto_arriba (const Laberynth& lab) const;
    bool correcto_abajo (const Laberynth& lab) const;
    bool correcto_derecha (const Laberynth& lab) const;
    bool correcto_izquierda (const Laberynth& lab) const;

    // Métodos consultores de los atributos privados de Pieza
    int centroi() const;        // Devuelve la fila donde se encuentra el centro de la pieza siendo 0 la primera
    int centroj() const;        // Devuelve la columna donde se encuentra el centro de la pieza siendo 0 la primera
    int orientacion() const;    // Devuelve 0 si la pieza está horizontsl y 1 si está vertical

    // Método para mostrar toda la información de la pieza en pantalla
    void mostrar() const;

// Atributos accesibles sólo desde la clase:
  private:
    int centro_fila;
    int centro_columna;
    int posicion;
};

#endif
