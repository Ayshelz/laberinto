#include <iostream>
#include <vector>
#include <string>
#include "LABERINTO.h"
#include "PIEZA.h"

int main() {
    // Pedimos el laberinto al usuario
    std::vector<std::string> entradas;
    std::string cadena;
    std::cout << "Ingrese el laberinto separando cada fila con un salto de línea, inserta 'f' para finalizar):" << std::endl;

    while (std::getline(std::cin, cadena) && cadena != "f") {
        entradas.push_back(cadena);
    }
    std::cout << "Salimos del bucle" << std::endl;

    // Creamos el laberinto a partir de la entrada del usuario
    Laberynth lab(entradas);

     std::cout << "El laberinto se ha creado" << std::endl;

    // Creamos la pieza
    Pieza p;
     std::cout << "La pieza se ha creado" << std::endl;

    // Creamos el contador de movimientos
    int mov = 0;

    while (!lab.objetivo(p)) {
        // Realizar un movimiento válido
        if (p.rotar(lab) || p.mover_derecha(lab) || p.mover_abajo(lab) || p.mover_izquierda(lab) || p.mover_arriba(lab)) {
                std::cout << "Movimiento numero: " << mov <<std::endl;
            mov++;
        } 
        else {
           mov = -1; // Imposible de resolver
            break;
        }
    }
    std::cout << "Salimos de la resolucion" << std::endl;

    // Mostrar el resultado
    if (mov != -1) {
        std::cout << "El laberinto se resolvio en " << mov << " movimientos." << std::endl;
    } else {
        std::cout << "El laberinto no se puede resolver." << std::endl;
    }
    return 0;
}
