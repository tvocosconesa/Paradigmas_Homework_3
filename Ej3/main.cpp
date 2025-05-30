#include "ej3.hpp"


int main() {
    // Container de doubles
    Container<double> cont_doubles;
    double d1 = 1.3, d2 = 2.1, d3 = 3.2;
    cont_doubles.agregar_datos(d1);
    cont_doubles.agregar_datos(d2);
    cont_doubles.agregar_datos(d3);

    

    // Container de palabras (strings)
    Container<string> cont_strings;
    string s1 = "Hola", s2 = "Mundo";
    cont_strings.agregar_datos(s1);
    cont_strings.agregar_datos(s2);

    // Container de listas de enteros (vector<int>)
    Container<vector<int>> cont_listas;
    vector<int> l1 = {1, 2};
    vector<int> l2 = {3, 4};
    cont_listas.agregar_datos(l1);
    cont_listas.agregar_datos(l2);

    
    JsonCreator Jason_Voorhees;


    // Jason_Voorhees.add_info(cont_doubles);
    Jason_Voorhees.add_info(cont_doubles);
    Jason_Voorhees.add_info(cont_strings);
    Jason_Voorhees.add_info(cont_listas);

    Jason_Voorhees.crear_Json();
    
    Jason_Voorhees.leer_Json();
}