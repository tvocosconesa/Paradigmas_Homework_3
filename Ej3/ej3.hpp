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

            void agregar_datos(const T& dato){
                datos.push_back(dato);
            }
            
            string procesar_datos(){
                ostringstream datos_procesados;
                datos_procesados << " [";
                if constexpr (is_same_v<T, string>) {
                    
                    for (size_t i = 0; i < datos.size(); ++i) {
                        datos_procesados << "\"" << datos[i] << "\"";   // uso "\"" para agregar comillas dobles
                    
                        if (i != datos.size() - 1) datos_procesados << ",";
                    }
                    datos_procesados << "]";
                }

                else if constexpr( is_same_v<T, double>){

                    for (size_t i = 0; i < datos.size(); i++){
                            
                        datos_procesados << fixed <<setprecision(1) << datos[i]; // fixed hace que la precision solicitada en el set precision sea aplicada a los decimales 
                        if (i != datos.size() - 1) datos_procesados << ",";
                    }
                    datos_procesados << "]";
                }

                else if constexpr(is_same_v<T, vector<int>>){

                    for (size_t i = 0 ; i < datos.size(); i++){
                        datos_procesados << "\n        [";

                        for (size_t j = 0 ; j < datos[i].size(); j++){
                            datos_procesados << datos[i][j] ;

                            if(j != datos[i].size() -1 ) datos_procesados << ",";
                        }

                        datos_procesados << "]";
                        if (i != datos.size()-1) datos_procesados << ",";
                    }
                    datos_procesados << "\n";
                    datos_procesados << "        ]";
                }

                else { datos_procesados << "\"Tipo no soportado\""; }
                
                
                
                return datos_procesados.str();
            }
};



class JsonCreator{

    private:
  
        Container<double> doubles;
        Container<string> palabras;
        Container<vector<int>> listas;

    public:
        
        JsonCreator() = default;



        void add_info(Container<double>& c) { doubles = c; }
        void add_info(Container<string>& c) { palabras = c; }
        void add_info(Container<vector<int>>& c) { listas = c; }

        void crear_Json(){
            
            ofstream archivo("datos.json");
            if (!archivo.is_open()){
                cerr << "ERROR:Ocurió un problema a la hora de crear el archivo Json";
                return;
            }
            archivo << "{ ";


            archivo << "\"vec_doubles\":";
            archivo << doubles.procesar_datos() << "," << endl;
            archivo << "\"palabras\":" << palabras.procesar_datos() << "," << endl;
            archivo << "\"listas\":" << listas.procesar_datos() << endl;

            archivo << "\n }";

        }

        void leer_Json(){
            ifstream archivo("datos.json");
            
            if (!archivo.is_open()) {
                std::cerr << "No se pudo abrir el archivo.\n";
                return;
            }
            
            string linea;
            cout << "\n";
            while (getline(archivo, linea)) {
                cout << linea <<endl;
            }
            archivo.close();
            return ;
        }


};