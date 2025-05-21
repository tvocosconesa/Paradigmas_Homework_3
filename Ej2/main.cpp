#include "ej2.hpp"

int main() {

    Circulo circ(5.0f, 0.0f, 0.0f);
    cout << "Area del circulo: " << ProcesadorFigura<Circulo>::calcular_area(circ) << endl;


    Rectangulo rect(25.0f, 10.0f, 0.0f, 0.0f);
    cout << "Area del rectangulo: " << ProcesadorFigura<Rectangulo>::calcular_area(rect) << endl;

    Elipse elipse(12.5f, 12.5f, 0.0f, 0.0f);
    cout << "Area del elipse: " << ProcesadorFigura<Elipse>::calcular_area(elipse) << endl;
}