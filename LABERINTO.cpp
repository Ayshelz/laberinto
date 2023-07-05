#include "LABERINTO.h"

// Implementación del constructor:
Laberynth::Laberynth(const std::vector<std::string>& lab){
  for (const std::string& fila_entrada : lab){   // Por cada vector en el vector de entrada
    std::vector<char> fila_laberinto;            // Creamos una nueva fila para el laberinto
    for (char dato : fila_entrada){              // Introducimos cada caracter en dicha fila
      fila_laberinto.pushback(dato);             
    }
    matriz.push_back(fila_laberinto);             // Introducimos la fila una vez completada en la estructura del laberinto
  }
}

// Implementación de la función mostrar:
void Laberynth::mostrar() const {}

// Implementación de la función movimiento:
bool Laberynth::movimiento(int x, int y, int pos) const{}

// Implementación de la función objetivo:
bool Laberynth:::objetivo (int x, int y){}
