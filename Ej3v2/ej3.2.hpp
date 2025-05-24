#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <type_traits>
using namespace std;

template<typename T>
class Container{

    protected:
        vector<T> datos;
        using tipo_dato = T;  // Alias del tipo ( desp veo si lo uso  )

        public:

            Container() = default;

            void agregar_datos(T& dato){
                datos.push_back(dato);
            }
            
            string procesar_datos(){
                ostringstream datos_procesados;
                datos_procesados << "[";
                if constexpr (is_same_v<T, string>) {
                    
                    for (size_t i = 0; i < datos.size(); ++i) {
                        datos_procesados << "\"" << datos[i] << "\"";   // uso "\"" para agregar comillas dobles
                    if (i != datos.size() - 1) datos_procesados << ",";
                }
                }

                else if constexpr( is_same_v<T, double>){

                    for (size_t i = 0; i < datos.size(); i++){
                            // datos_procesados.precision(2);
                            // datos_procesados << fixed;
                        datos_procesados << fixed <<setprecision(2) << datos[i]; // fixed hace que la precision solicitada en el set precision sea aplicada a los decimales 
                        if (i != datos.size() - 1) datos_procesados << ",";
                    }

                }

                else if constexpr(is_same_v<T, vector<int>>){

                    for (size_t i = 0 ; i < datos.size(); i++){
                        datos_procesados << "[";

                        for (size_t j = 0 ; j < datos[i].size(); j++){
                            datos_procesados << datos[i][j];

                            if(j != datos[i].size() -1 ) datos_procesados << ",";
                        }

                        datos_procesados << "]";
                        if (i != datos.size()-1) datos_procesados << ",";
                    }
                }

                else { datos_procesados << "\"Tipo no soportado\""; }
                
                
                datos_procesados << "]";
                return datos_procesados.str();
            }
};


template <typename T>
class JsonCreator{

    protected:
        vector<Container<T>> info;

    public: 
        JsonCreator() = default;

        void add_info(Container<T>& cont){
            info.push_back(cont);
        }

        void create_json(){
            ofstream archivo("datos.json");
            if (!archivo.is_open()){
                cerr << "ERROR:Ocurió un problema a la hora de crear el archivo Json";
                return;
            }
            archivo << "{ ";
            for(size_t i = 0 ; i < info.size() ; i++){

                if constexpr (is_same_v<T, string>) {
                    archivo << "\"palabras\":";
                
                } else if constexpr (is_same_v<T, double>) {
                    archivo << "\"vec_doubles\":";
                
                } else if constexpr (is_same_v<T, vector<int>>) {
                    archivo << "\"listas\":";
                
                } else {
                    archivo << "\"desconocido\":"; // por las dudas 
                }
                
                archivo << info[i].procesar_datos();
                
                if(i < info.size() - 1) archivo << ",";

            }

            archivo << "\n }";
            archivo.close();
        }
};