// Cabecera con la definición de la estructura del laberinto y funciones asociadas a él

// Instrucciones para el preprocesador
#ifndef LABERINTO_
#define LABERINTO_

// Bibliotecas estándar de C++ que usaremos
#include <vector>
#include <string>
#include "PIEZA.h"

// Definición de la estructura laberinto
class Laberynth{

  // Atributos accesibles desde fuera de la clase:
  public:
    Laberynth(const std::vector<std::string>&);   // Constructor de la clase a partir de un vector de cadenas de caracteres
    void mostrar() const;                             // Muestra el laberinto
    bool movimiento (const Pieza&) const;    // Devuelve true si el movimiento es posible y false en caso contrario
    bool objetivo (const Pieza&) const;               // Comprueba si el laberinto está resuelto
   

// Atributos accesibles sólo desde la clase: (matriz de caracteres)
  private:
    std::vector<std::vector<char>> matriz;
};

#endif
