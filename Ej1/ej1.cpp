#include <iostream>
#include <memory>
#include <fstream>
using namespace std;

class IMediciones{

    public:
       virtual void serializar(ofstream& out) const = 0;
       virtual void deserializar(ifstream& in ) = 0;
};


class MedicionBase : public IMediciones {

    protected:
        unique_ptr<float> tiempoMedicion;

    public:
        MedicionBase(){
            tiempoMedicion = make_unique<float>(0.0);
        }    

        MedicionBase(float tiempo){
            tiempoMedicion = make_unique<float>(tiempo);
        }

        MedicionBase(const MedicionBase& other) { // constructor para una copia
            tiempoMedicion = make_unique<float>(*other.tiempoMedicion);
        }

        MedicionBase& operator=(const MedicionBase& other) {
            if (this != &other) {
                tiempoMedicion = make_unique<float>(*other.tiempoMedicion);
            }
            return *this;
        }

        virtual void imprimir() const = 0;
        void serializar(ofstream& out) const override;
        void deserializar(ifstream& in ) override;

        
    
        
};

void MedicionBase::serializar(ofstream& out) const{
    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(float));
}

void MedicionBase::deserializar(ifstream& in){
    if (!tiempoMedicion){tiempoMedicion = make_unique<float>();} // si por alguna razon el tiempo de medicion es un nullptr esto me hace que no acceda a la memoria 0
    in.read(reinterpret_cast<char*>(tiempoMedicion.get()),sizeof(float));
}







class Presion : public MedicionBase{

    public:
        float presionEstatica; //p
        float presionDinamica; //q

        Presion(float p , float q, float t) : MedicionBase(t), presionEstatica(p), presionDinamica(q){}

        Presion(const Presion& other) // constructor de la copia
        : MedicionBase(other),
          presionEstatica(other.presionEstatica),
          presionDinamica(other.presionDinamica) {}

        void serializar(ofstream& out) const override;
        void deserializar(ifstream& in ) override;
        void imprimir() const override;

    
        Presion& operator=(const Presion& other) {  // Operador de asignación por copia
            if (this != &other) {
                MedicionBase::operator=(other);
                presionEstatica = other.presionEstatica;
                presionDinamica = other.presionDinamica;
            }
            return *this;
        }
};

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









class Posicion : public MedicionBase {

    public:
        float latitud;
        float longitud;
        float altitud;

        Posicion(float lat, float lon, float alt, float t):MedicionBase(t), latitud(lat), longitud(lon), altitud(alt){}

        Posicion(const Posicion& other):
            MedicionBase(other), latitud(other.latitud), longitud(other.longitud), altitud(other.altitud){}
            
            
        void serializar(ofstream& out) const override;
        void deserializar(ifstream& in ) override;
        void imprimir() const override;

        Posicion& operator=(const Posicion& other){
            if (this != &other){
                MedicionBase::operator=(other);
                latitud = other.latitud;
                longitud = other.longitud;
                altitud = other.altitud;
            }
            return *this;
        }

};


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








class SaveFlightData {
    public:
        Posicion posicion;
        Presion presion;

        SaveFlightData(const Posicion& p, const Presion& q);
        void serializar(ofstream& out) const;
        void deserializar(ifstream& in);
        void imprimir() const;
};

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