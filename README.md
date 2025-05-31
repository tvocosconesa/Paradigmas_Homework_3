# Paradigmas_Homework_3

# Compilacion
Todos los ejercicios tienen en su respectiva carpeta un archivo `Makefile`. En el mismo se encuentran numerosas flags para aseguerarse
de que el codigo no tenga warnings ni errores a la hora de compilar. 
### Para compilar:
    1. Seleccionar la carpeta del ejercicio: cd Ejn (siendo n el num del ej)
    2. Utilizar el comando por terminal make run para compilar y correr el ejercicio 
    3. una ver ejecutado el ejecutable puede ser borrado con el comando make clean 


# Ejercicio 1:

## Clases Mediciones:
Este ejercicio constó en la creacion de clases de distintos tipos de mediciones para aviacion, `Presion` (que almacenaba una medicion de precion dinamica y una estatica) y `Posicion` (que almacenaba la latitud, longitud, y altitud del avion). 
Las mismas se basaban en una clase abstracta `MedicionBase`, la cual tenia como atributo del tiempo de la medicion. 
Asimismo esta provenia de una Interfac `IMediciones`.

## SaveFlightData:
Esta clase almacena los datos de medicio. Tiene como atributos una clase `Presion` y una `Posicion`. Desde la misma se puede `serializar()` y `deserializar()` su contenido e imprimir sus datos.

### Uso de unique_ptr en Medicion Base:
los `unique_ptr` tienen la particularidad de que, debido a su caracteristica de tener un solo owner, el compilador no dejara que las clases que los poseen
sean copiadas cuando se pasan a la clase `SaveFlightData`. El Ejercicio pide resolver esto sin utilizar `std::move`. 
Para solucionar esto sobreescribí el operador `=` de las clases las cuales poseyeran un `unique_ptr`.  De esta manera hice que cuando se iguale una clase a otra se haga un deep copy de la misma, incluyendo al `unique_ptr`, para el cual creo una copia y le aplico el valor del original.

# Ejercicio 2:

El ejercicio constó de la creacion de distintas clases que representaban figuras geomentricas (`Circulo`, `Rectangulo` y `Elipse`).
Estas contenian dentro de sus atributos una clase `Punto` la cual podia ser el centro de la figura, o en el caso del rectangulo su borde inferior izquierdo.
Mediante el uso de `templates` hice las clases `ProcesadorFigura`. Estas te dan la posbilidad de calcular el area de las formas. Al usar `templates` pude reescribir la clase
para cada figura de manera distinta, ya que con cada figura el area se calcula de una manera diferente. Las funciones de calcular area son `static`, por lo tanto funcionan como una libreria y pueden llamarse sin la necesidad de instanciarla.

# Ejercicio 3:
El ejercicio 3 cuenta con 2 clases, una para almacenar y procesar los datos y otra para introducir los mismos en un archivo `JSON` con sus respectivas etiquetas

## Clase 1 - Container : 
Mi clase `Container` fue implementada con con un `template` para que pueda recibir cualquier tipo de variable. Su funcion `procesar_datos()`
devuelve un `string` con los datos del contenedor con el formato necesario para ser introducidos e el `JSON`. Utilice condicionales
de `constexp` para procesar de manera distinta los distintos tipos de datos pedidos en el ejercicio.

## Clase 2 - JsonCreatos
La clase `JsonCreatos` tiene como atributos a los `containers` de los `types` solicitados en el ejercicio. Los mismos son introducidos en la clase mediante el metodo `add_info()`.
La funcion `crear_Json()`, crea un archivo `JSON` e introduce los datos de los `containers`, cada uno con su respectiva etiqueta.
Por otro lado la funcion `leer_Json()` lee el archivo creado e imprime por terminal el contenido del mismo con su respectivo formato.    
