#include "PIEZA.h"

// Implementación del constructor de la clase:
Pieza::Pieza(){
    centro_fila = 0;
    centro_columna = 1;
    posicion = 0;
}

// Implementación de la función mostrar:
void Pieza::mostrar() const{
    std::cout << "Centro fila: " << centro_fila << ", Centro columna: " << centro_columna << "Posición: ";
    if(posicion ==0)
        std::cout << "Horizontal";
    else
        std::cout << "Vertical";
    std::cout << std::endl;
}

// Implementación de las funciones de movimiento, comprobando que el movimiento sea posible:
bool Pieza::rotar (const Laberynth& lab){
    // Definimos la esquina superior izquierda del área de 3x3 a comprobar
    int esquinax = centro_fila - 1;
    int esquinay = centro_columna - 1;

    // Verificar la validez de las celdas en el área de 3x3
    for (int i = esquinax; i <= esquinax + 2; i++) {
        for (int j = esquinay; j <= esquinay + 2; j++) {
            if (!lab.celda_valida(i, j))
                return false; // Al menos una celda es inválida
        }
    }
    // Si todas las celdas son válidas realizamos el movimiento
    if (posicion == 0)
        posicion = 1;
    else
        posicion = 0;
    return true;
}

bool Pieza::mover_arriba (const Laberynth& lab){
    // Si la pieza está en posición horizontal, comprobamos las 3 celdas superiores a ella
    if (posicion == 0){
        if (!lab.celda_valida(centro_fila-1, centro_columna) ||
            !lab.celda_valida(centro_fila-1, centro_columna - 1) ||
            !lab.celda_valida(centro_fila-1, centro_columna + 1)) {
            return false;    // Al menos una de las tres celdas superiores es inválida
        }
        // Si todo es correcto realizamos el movimiento
        else{
            centro_fila--;
            return true;
        }
    }

    // Si la pieza está en posición vertical, comprobamos la celda superior a ella
    if (posicion == 1){
        if (!lab.celda_valida(centro_fila-2, centro_columna)) {
            return false;    // La celda superior es inválida
        }
        // Si todo es correcto, realizamos el movimiento
        else{
            centro_fila--;
            return true;
        }
    }
}

bool Pieza::mover_abajo (const Laberynth& lab){
    // Si la pieza está en posición horizontal, comprobamos las 3 celdas inferiores a ella
    if (posicion == 0){
        if (!lab.celda_valida(centro_fila+1, centro_columna) ||
            !lab.celda_valida(centro_fila+1, centro_columna - 1) ||
            !lab.celda_valida(centro_fila+1, centro_columna + 1)) {
            return false;    // Al menos una de las tres celdas infereiores es inválida
        }
        // Si todo es correcto realizamos el movimiento
        else{
            centro_fila++;
            return true;
        }
    }

    // Si la pieza está en posición vertical, comprobamos la celda inferior a ella
    if (posicion == 1){
        if (!lab.celda_valida(centro_fila-2, centro_columna)) {
            return false;    // La celda superior es inválida
        }
        // Si todo es correcto, realizamos el movimiento
        else{
            centro_fila++;
            return true;
        }
    }
}

bool Pieza::mover_derecha (const Laberynth& lab){
    // Si la pieza está en posición vertical, comprobamos las 3 celdas a su derecha
    if (posicion == 1){
        if (!lab.celda_valida(centro_fila, centro_columna+1) ||
            !lab.celda_valida(centro_fila-1, centro_columna+1) ||
            !lab.celda_valida(centro_fila+1, centro_columna+1)) {
            return false;    // Al menos una de las tres celdas derechas es inválida
        }
        // Si todo es correcto realizamos el movimiento
        else{
            centro_columna++;
            return true;
        }
    }

    // Si la pieza está en posición horizontal, comprobamos la celda a su derecha
    if (posicion == 0){
        if (!lab.celda_valida(centro_fila, centro_columna+2)) {
            return false;    // La celda derecha es inválida
        }
        // Si todo es correcto, realizamos el movimiento
        else{
            centro_columna++;
            return true;
        }
    }
}

bool Pieza::mover_izquierda (const Laberynth& lab){
    // Si la pieza está en posición vertical, comprobamos las 3 celdas a su izquierda
    if (posicion == 1){
        if (!lab.celda_valida(centro_fila, centro_columna-1) ||
            !lab.celda_valida(centro_fila-1, centro_columna-1) ||
            !lab.celda_valida(centro_fila+1, centro_columna-1)) {
            return false;    // Al menos una de las tres celdas izquierdas es inválida
        }
        // Si todo es correcto realizamos el movimiento
        else{
            centro_columna--;
            return true;
        }
    }

    // Si la pieza está en posición horizontal, comprobamos la celda a su izquierda
    if (posicion == 0){
        if (!lab.celda_valida(centro_fila, centro_columna-2)) {
            return false;    // La celda izquierda es inválida
        }
        // Si todo es correcto, realizamos el movimiento
        else{
            centro_columna--;
            return true;
        }
    }
}

// Implementación de las funciones de consulta:
int Pieza::centroi() const{ return centro_fila;}

int Pieza::centroj() const{ return centro_columna;}

int Pieza::orientacion() const{ return posicion;}
