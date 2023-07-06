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

    // Creamos el laberinto a partir de la entrada del usuario
    Laberynth lab(entradas);

    // Creamos la pieza
    Pieza p;

    // Creamos el contador de movimientos
    int mov = 0;

    while (!lab.objeivo(p)) {
        // Realizar un movimiento válido
        if (p.mover_derecha() || p.mover_abajo() || p.rotar() || p.mover_izquierda() || p.mover_arriba()) {
            mov++;
        } else {
           mov = -1; // Imposible de resolver
            break;
        }
    }

    // Mostrar el resultado
    if (mov != -1) {
        std::cout << "El laberinto se resolvió en " << numMovimientos << " movimientos." << std::endl;
    } else {
        std::cout << "El laberinto no se puede resolver." << std::endl;
    }
    return 0;
}
