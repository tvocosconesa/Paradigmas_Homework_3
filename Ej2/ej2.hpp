#include <iostream>
#include <memory>
#include <fstream>
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
        Elipse(float a = 1.0 , float b = 1.0 , float x = 0 , float y = 0): a(a), b(b), centro(x,y){}

        float get_semieje_mayor() const {return a;}
        float get_semieje_menor(){return b;}
        
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

        float get_largo() const { return largo; }
        float get_ancho() const { return ancho; }

        float getPosX() const { return vertice_izq.getX(); }
        float getPosY() const { return vertice_izq.getY(); }

        void set_largo(float value) { largo = value;}
        void set_ancho(float value) { largo = value;}

        void setPosX(float value) { vertice_izq.setX(value); }
        void setPosY(float value) { vertice_izq.setY(value); }
};

template <typename T>
class ProcesadorFigura { 

    protected:
        T figura;
    public:
        ProcesadorFigura();

        
};
