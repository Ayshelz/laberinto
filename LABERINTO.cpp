#include "LABERINTO.h"

// Implementación del constructor:
Laberynth::Laberynth(const std::vector<std::string>& lab){
  for (const std::string& fila_entrada : lab){     // Por cada vector en el vector de entrada
    std::vector<char> fila_laberinto;              // Creamos una nueva fila para el laberinto
    for (char dato : fila_entrada){                
      fila_laberinto.pushback(dato);               // Introducimos cada caracter en dicha fila
    }
    matriz.push_back(fila_laberinto);              // Introducimos la fila una vez completada en la estructura del laberinto
  }
}

// Implementación de la función mostrar:
void Laberynth::mostrar() const {
  for (const std::vector<char>& fila : mazeGrid) {  // Para cada vector de caracteres
        for (char dato : fila) {              
            std::cout << dato;                      // Mostramos cada uno de sus caracteres
        }
        std::cout << '\n';                          // Separando las filas con un salto de línea
    }
}

// Implementación de la función objetivo:
bool Laberynth:::objetivo (const Pieza& bloque) const{
  int total_filas = matriz.size();          // Comprobamos las dimensiones del laberinto
  int total_columnas = matriz[0].size();
  int i = bloque.centroi();                 // Obtenemos la posición y orientación de la pieza
  int j = bloque.centroj();
  int pos = bloque.orientacion();

  if (pos == 0){                            // Si la pieza está horizontal y toca la esquina del tablero devolvemos true
    if ((i ==  total_filas-1) && (j+1 == total_columnas-1))               
      return true;                      
    else
      return false;                          // y si no lo toca devolvemos false
  }
  else{                                      // Si la pieza está vertical y toca la esquina del tablero devolvemos true
    if ((i+1 == total_filas-1) && (j == total_columnas-1))
      return true;
    else
      return false;                          // y si no lo toca devolvemos false
  }
}
