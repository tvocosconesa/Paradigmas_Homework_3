#ifndef EJ3_HPP
#define EJ3_HPP

#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

using namespace std;

template<typename T>
struct always_false : std::false_type {};

template<typename T>
class Contenedor {
protected:
    vector<double> vector_double;
    vector<string> vector_string;
    vector<vector<int>> matriz_int;

public:
    Contenedor() {}

    void agregar(T dato) {
        if constexpr (std::is_same_v<T, double>) {
            vector_double.push_back(dato);
        } else if constexpr (std::is_same_v<T, string>) {
            vector_string.push_back(dato);
        } else if constexpr (std::is_same_v<T, vector<int>>) {
            matriz_int.push_back(dato);
        } else {
            static_assert(always_false<T>::value, "Tipo no soportado");
        }
    }

    // Getters para acceder a los datos desde fuera
    const vector<double>& getDoubles() const { return vector_double; }
    const vector<string>& getStrings() const { return vector_string; }
    const vector<vector<int>>& getListas() const { return matriz_int; }
};

#endif
