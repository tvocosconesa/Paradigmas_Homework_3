#include <iostream>
#include <vector>
#include <string>
// #include <type_traits>



using namespace std;

template<typename T>
class Conenedor { 
    protected:
        vector<T> datos;
        string tag;
    

    public:
        Conenedor(){
            datos =  vector<T>;

            if constexpr(is_integral_v<T>){ // noc q tan bien chequea esto pq le meto un vector de ints no un int asi q nada ahora me fijo
                tag = "Listas"
            }

            if constexpr(is_same_v(T,double)){
                tag = "vec_doubles"
            }
        }

        template<typename T>
        void agregar(T dato){ datos.push_back(dato);}

        template<>
        void agregar<double>(T)

};


