#include <iostream>
#include <memory>
#include <fstream>
using namespace std;



class IMediciones{

    public:
       virtual ~IMediciones() = default;
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

        virtual ~MedicionBase() = default;

        virtual void imprimir() const = 0;
        void serializar(ofstream& out) const override;
        void deserializar(ifstream& in ) override;
     
};


class Presion : public MedicionBase{

    public:
        float presionEstatica; //p
        float presionDinamica; //q

        Presion(float p , float q, float t) : MedicionBase(t), presionEstatica(p), presionDinamica(q){}

        Presion(const Presion& other) // constructor de la copia
        : MedicionBase(other),
          presionEstatica(other.presionEstatica),
          presionDinamica(other.presionDinamica) {}
        virtual ~Presion() = default;
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




class Posicion : public MedicionBase {

    public:
        float latitud;
        float longitud;
        float altitud;

        Posicion(float lat, float lon, float alt, float t):MedicionBase(t), latitud(lat), longitud(lon), altitud(alt){}

        Posicion(const Posicion& other):
            MedicionBase(other), latitud(other.latitud), longitud(other.longitud), altitud(other.altitud){}
            
        virtual ~Posicion() = default;    
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


class SaveFlightData {
    public:
        Posicion posicion;
        Presion presion;

        SaveFlightData(const Posicion& p, const Presion& q);
        virtual ~SaveFlightData() = default;    

        void serializar(ofstream& out) const;
        void deserializar(ifstream& in);
        void imprimir() const;
};