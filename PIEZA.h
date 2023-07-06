// Cabecera con la definición de la estructura de la pieza y funciones asociadas a ella

// Instrucciones para el preprocesador
#ifndef PIEZA_
#define PIEZA_

// Definición de la estructura pieza
class Pieza{

  // Atributos accesibles desde fuera de la clase:
  public:
    Pieza();       
    bool rotar();                   
    bool mover_arriba();
    bool mover_abajo();
    bool mover_derecha();
    bool mover_izquierda();
    void mostrar () const;               
   

// Atributos accesibles sólo desde la clase: 
  private:
    int centro_fila;
    int centro_columna;
    int posicion;
};

#endif
