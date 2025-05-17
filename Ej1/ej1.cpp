#include "ej1.hpp"


void MedicionBase::serializar(ofstream& out) const{
    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(float));
}

void MedicionBase::deserializar(ifstream& in){
    if (!tiempoMedicion){tiempoMedicion = make_unique<float>();} // si por alguna razon el tiempo de medicion es un nullptr esto me hace que no acceda a la memoria 0
    in.read(reinterpret_cast<char*>(tiempoMedicion.get()),sizeof(float));
}



void Presion::serializar(ofstream& out) const{
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(float));
    out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(float));
}


void Presion::deserializar(ifstream& in ) { 
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(float));
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(float));
}

void Presion::imprimir()const{
    cout << "----- Presion ----- " << endl;
    cout << "Tiempo: " << *tiempoMedicion << endl;
    cout << "Presion Estatica: " << presionEstatica << endl;
    cout << "Presion Dinamica: " << presionDinamica << endl;
}


void Posicion::serializar(ofstream& out) const{
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(float));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(float));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(float));
}

void Posicion::deserializar(ifstream& in) {
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&latitud), sizeof(float));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(float));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(float));
}

void Posicion::imprimir() const{
    cout << "----- Posicion ----- " << endl;
    cout << "Tiempo: " << *tiempoMedicion << endl;
    cout << "Latitud: " <<latitud << endl;
    cout << "Longitud: " << longitud << endl;
    cout << "Altitud: " << altitud << endl;
}



SaveFlightData::SaveFlightData(const Posicion& p, const Presion& q): posicion(p), presion(q){}

void SaveFlightData:: serializar(ofstream& out) const{
    posicion.serializar(out);
    presion.serializar(out);
}

void SaveFlightData:: deserializar(ifstream& in){
    posicion.deserializar(in);
    presion.deserializar(in);
}

void SaveFlightData::imprimir() const{
    cout << "------ Informacion del vuelo ------" << endl;
    posicion.imprimir();
    presion.imprimir();
}
