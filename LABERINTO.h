// Cabecera con la definición de la estructura del laberinto y funciones asociadas a él

// Instrucciones para el preprocesador
#ifndef LABERINTO_H
#define LABERINTO_H

// Bibliotecas estándar de C++ 
#include <vector>
#include <string>

// Bibliotecas del proyecto 
#include "PIEZA.h"

// Definición de la estructura laberinto
class Laberynth{

  // Atributos accesibles desde fuera de la clase:
  public:
    Laberynth(const std::vector<std::string>&);       // Constructor de la clase a partir de un vector de cadenas de caracteres
    void mostrar() const;                             // Muestra el laberinto
    bool objetivo (const Pieza&) const;               // Devuelve TRUE si el laberinto está resuelto y FALSE en caso contrario. Recibe la pieza.
    bool celda_valida(int, int) const;                // Devuelve TRUE si la casilla está vacía y FALSE si la casilla es un obstáculo o está fuera del laberinto

// Atributos accesibles sólo desde la clase: 
  private:
    std::vector<std::vector<char>> matriz;            // Estructura que almacenará el laberinto
};

#endif
