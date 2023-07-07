#include <iostream>
#include <vector>
#include <string>
#include "LABERINTO.h"
#include "PIEZA.h"

using namespace std;

// Creamos una estructura que guardará estados que ya han sido visitados
struct PiezaVisitada {
    int coordenadax;
    int coordenaday;
    int pos_pieza;
};

// Declaramos las funciones auxiliares que usaremos para resolver el problema
int resolver (const Laberynth&, const Pieza&, int, std::vector<PiezaVisitada>&);
bool visitada(const Pieza&, const std::vector<PiezaVisitada>&);

// Comenzamos la ejecución para la resolución:
int main() {
    // Pedimos el laberinto al usuario
    std::vector<std::string> entradas;
    std::string cadena;
    std::cout << "Ingrese el laberinto separando cada fila con un salto de linea, inserte 'f' para finalizar:" << std::endl;
    while (std::getline(std::cin, cadena) && cadena != "f") {
        entradas.push_back(cadena);
    }

    // Creamos el laberinto a partir de la entrada del usuario
    Laberynth lab(entradas);

    // Creamos la pieza inicial
    Pieza p;
    
    // Creamos el resto de variables para llamar a la función resolver
    int m = 0;
    std::vector<PiezaVisitada> visitados;
    
    // LLamamos a la función resolver
    int resultado = resolver (lab, p, m, visitados);

    // Mostramos el resultado
    if (resultado != -1)
        std::cout << "El laberinto se resolvio en " << resultado << " movimientos." << std::endl;
    else
        std::cout << "El laberinto no se puede resolver." << std::endl;
        
    // Pausamos la ejecución si es necesario para observar el resultado.
    system("pause");
    return 0;
}

// Implementación de la función recursiva que resuelve el laberinto
// Recibe el laberinto, la pieza, el número de movimientos y el vector de piezas visitadas
// Devuelve -1 si no se encuentra la solución y el número de movimientos en caso contrario
int resolver(const Laberynth& lab, const Pieza& p, int mov, std::vector<PiezaVisitada>& visitados){
    
    // Si estamos en la casilla final, devolvemos 0 para indicar que no son necesarios más movimientos
    if (lab.objetivo(p))
        return 0;

    // Si no hemos llegado al final añadiremos la pieza al vector de visitadas con sus datos
    PiezaVisitada pv;
    pv.coordenadax = p.centroi();
    pv.coordenaday = p.centroj();
    pv.pos_pieza = p.orientacion();
    visitados.push_back(pv);

    // Inicializamos la variable donde almacenaremos si se encontró algún movimiento disponible para realizar
    int movimientosValidos = -1;

    // Si es posible moverse hacia la derecha, crearemos una pieza resultado de dicho movimiento  
    // Si dicha  pieza no ha sido visitada anteriormente, aumentaremos los movimientos realizados
    // Llamaremos de forma recursiva a la función con la nueva pieza creada y actualizaremos las variables de movimientos
    if (p.correcto_derecha(lab)) {
        Pieza q(p.centroi(), p.centroj() + 1, p.orientacion());
        if (!visitada(q, visitados)) {
            mov++;
            int resultado = resolver(lab, q, mov, visitados);
            if (resultado != -1)
                movimientosValidos = 1 + resultado;  // Sumamos 1 al resultado para contar el movimiento actual
            mov--;
        }
    }

    // Repetimos el proceso para el movimiento hacia abajo
    if (movimientosValidos == -1 && p.correcto_abajo(lab)) {
             std::cout << "Entra a abajo" << std::endl;
        Pieza q(p.centroi() + 1, p.centroj(), p.orientacion());
        if (!visitada(q, visitados)) {
            mov++;
            int resultado = resolver(lab, q, mov, visitados);
            if (resultado != -1)
                movimientosValidos = 1 + resultado;
            mov--;
        }
    }

    // Repetimos el proceso para el movimiento de rotación
    if (movimientosValidos == -1 && p.correcto_rotar(lab)) {
             std::cout << "Entra a rotar" << std::endl;
        Pieza q(p.centroi(), p.centroj(), 1 - p.orientacion());
        if (!visitada(q, visitados)) {
            mov++;
            int resultado = resolver(lab, q, mov, visitados);
            if (resultado != -1)
                movimientosValidos = 1 + resultado;
            mov--;
        }
    }

    // Repetimos el proceso para el movimiento hacia la izquierda
    if (movimientosValidos == -1 && p.correcto_izquierda(lab)) {
             std::cout << "Entra a izquierda" << std::endl;
        Pieza q(p.centroi(), p.centroj() - 1, p.orientacion());
        if (!visitada(q, visitados)) {
            mov++;
            int resultado = resolver(lab, q, mov, visitados);
            if (resultado != -1)
                movimientosValidos = 1 + resultado;
            mov--;
        }
    }

    // Repetimos el proceso para el movimiento hacia arriba
    if (movimientosValidos == -1 && p.correcto_arriba(lab)) {
             std::cout << "Entra a arriba" << std::endl;
        Pieza q(p.centroi() - 1, p.centroj(), p.orientacion());
        if (!visitada(q, visitados)) {
            mov++;
            int resultado = resolver(lab, q, mov, visitados);
            if (resultado != -1)
                movimientosValidos = 1 + resultado;
            mov--;
        }
    }

    // Se elimina la pieza visitada si finalmente no se utiliza en el camino actual
    visitados.pop_back();

    // Devolvemos el número de movimientos válidos encontrados 
    // Se incializó -1 por lo que éste será su valor si no encuentra un movimiento válido
    return movimientosValidos;
}

// Implementación del método que comprueba si una pieza ya ha aparecido anteriormente en su estado
// Devuelve verdadero si ya había aparecido y falso en caso contrario
// Recibe la pieza y un vector con las piezas ya visitadas
bool visitada(const Pieza& p, const std::vector<PiezaVisitada>& visitados) {
    // Para cada pieza en el vector, comprobamos si coinciden sus características
    for (const auto& piezaVisitada : visitados) {
        if (piezaVisitada.coordenadax == p.centroi() && piezaVisitada.coordenaday == p.centroj() && piezaVisitada.pos_pieza == p.orientacion())
            return true; // Coinciden las 3
    }
    return false; // Alguna no coincide
}
