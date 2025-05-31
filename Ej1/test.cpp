#include "ej1.hpp"
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    Posicion pos(40.7128f, -74.0060f, 10.0f, 123.45f); 
    Presion pres(1013.25f, 5.8f, 123.45f);  

    // Muestro los datos originales
    cout << "Datos originales:" << endl;
    SaveFlightData vuelo(pos, pres);
    vuelo.imprimir();

    // Guardo en archivo binario
    ofstream outFile("vuelo.dat", ios::binary); // creo el archivo
    if (!outFile) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return 1;
    }
    vuelo.serializar(outFile); //serializo
    outFile.close();

    // Leo desde archivo binario
    SaveFlightData vueloCopia(pos, pres);
    ifstream inFile("vuelo.dat", ios::binary);
    if (!inFile) {
        cerr << "Error al abrir el archivo para lectura." << endl;
        return 1;
    }
    vueloCopia.deserializar(inFile); // deserializo los datos del archivo en mi copia
    inFile.close();

    // Mostrar los datos después de la deserialización
    cout << "\nDatos deserializados:" << endl;
    vueloCopia.imprimir();

    return 0;
}
