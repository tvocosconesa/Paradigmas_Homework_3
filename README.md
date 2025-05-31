# Paradigmas_Homework_3


# Compilacion
Todos los ejercicios tienen en su respectiva carpeta un archivo Makefile. En el mismo se encuentran numerosas flags para aseguerarse
de que el codigo no tenga warnings ni errores a la hora de compilar. 
### Para compilar:
    1. Seleccionar la carpeta del ejercicio: cd Ejn 
    2. Utilizar el comando por terminal make run para compilar y correr el ejercicio 
    3. una ver ejecutado el ejecutable puede ser borrado con el comando make clean 


# Ejercicio 1:

## Clases Mediciones:
Este ejercicio constó en la creacion de clases de distintos tipos de mediciones para aviacion, Presion (que almacenaba una medicion de precion dinamica y una estatica) y Posicion (que almacenaba la latitud, longitud, y altitud del avion). 
Las mismas se basaban en una clase abstracta "Medicion Base", la cual tenia como atributo del tiempo de la medicion. 
Asimismo esta provenia de una Interfac "IMediciones".

## SaveFlightData:
Esta clase almacena los datos de medicio. Tiene como atributos una clase Presion y una Posicion. Desde la misma se puede serializar y deserializar su contenido e imprimir sus datos.

### Uso de unique_ptr en Medicion Base:
los unique_pointers tienen la particularidad de que, debido a su caracteristica de tener un solo owner, el compilador no dejara que las clases que los poseen
sean copiadas cuando se pasan a la clase SaveFlightData. El Ejercicio pide resolver esto sin utilizar std:::move. 
Para solucionar esto sobreescribí el operador "=" de las clases las cuales poseyeran un unique_ptr.  De esta manera hice que cuando se iguale una clase a otra se haga un deep copy de la misma, incluyendo al unique_ptr, para el cual creo una copia y le aplico el valor del original.

