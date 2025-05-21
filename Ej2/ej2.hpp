#include <iostream>
#include <memory>
#include <fstream>
#include <cmath>
#pragma once
using namespace std;

class Punto {
    protected:
        float posicionX, posicionY;

    public:
        Punto(float x = 0, float y = 0) : posicionX(x), posicionY(y) {}

        float getX() const { return posicionX; }
        float getY() const { return posicionY; }

        void setX(float value) { posicionX = value; }
        void setY(float value) { posicionY = value; }
};

class Circulo {
    protected:
        float radio;
        Punto posicion;

    public:
        Circulo(float rad = 1.0, float x = 0, float y = 0)
            : radio(rad), posicion(x, y) {}

        float getRadio() const { return radio; }
        void setRadio(float value) { radio = value; }

        float getPosX() const { return posicion.getX(); }
        float getPosY() const { return posicion.getY(); }

        void setPosX(float value) { posicion.setX(value); }
        void setPosY(float value) { posicion.setY(value); }
};


class Elipse {

    protected:
        Punto centro;
        float a; //semieje mayor
        float b; // smieje menor

    public:
        Elipse(float sMayor = 1.0 , float sMenor = 1.0 , float x = 0 , float y = 0):  centro(x,y), a(sMayor), b(sMenor){}

        float get_semieje_mayor() const {return a;}
        float get_semieje_menor() const {return b;}
        
        float getPosX() const { return centro.getX(); }
        float getPosY() const { return centro.getY(); }
        
        void set_sMayor(float value) { a = value; }
        void set_sMenor(float value) { b = value; }

        void setPosX(float value) { centro.setX(value); }
        void setPosY(float value) { centro.setY(value); }

};

class Rectangulo {

    protected:
        Punto vertice_izq;
        float largo, ancho;

    public:
        Rectangulo(float larg = 1.0, float anch = 1.0, float x = 0, float y = 0): vertice_izq(x,y), largo(larg), ancho(anch){} // el diablaso

        float get_largo() const { return largo; }
        float get_ancho() const { return ancho; }

        float getPosX() const { return vertice_izq.getX(); }
        float getPosY() const { return vertice_izq.getY(); }

        void set_largo(float value) { largo = value;}
        void set_ancho(float value) { ancho = value;}

        void setPosX(float value) { vertice_izq.setX(value); }
        void setPosY(float value) { vertice_izq.setY(value); }
};

template <typename T>
class ProcesadorFigura { 

    public:
        static float calcular_area(const T& fig){ 
            return 0;}    
};
template <>
class ProcesadorFigura<Circulo> {
public:
    static float calcular_area(const Circulo& fig) {
        return M_PIf * fig.getRadio() * fig.getRadio();
    }
};

template <>
class ProcesadorFigura<Rectangulo> {
public:
    static float calcular_area(const Rectangulo& fig) {
        return fig.get_largo() * fig.get_ancho();
    }
};

template <>
class ProcesadorFigura<Elipse> {
public:
    static float calcular_area(const Elipse& fig) {
        return M_PIf * fig.get_semieje_mayor() * fig.get_semieje_menor();
    }
};
