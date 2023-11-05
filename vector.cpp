/*
MARCO PRACTICO
    1. Ejercicio STL vector de C++
        a. Escribe un programa que defina un vector de enteros.
        b. Inserte dos elementos en un vector.
        c. Imprima el contenido vectorial utilizando el bucle basado en rangos.
        d. Borre el segundo elemento del vector.
        e. Imprima el contenido vectorial utilizando el bucle basado en rangos.
        f. Borre el rango de 3 elementos a partir del principio del vector.
        g. Imprima el contenido vectorial utilizando el bucle basado en rangos.
        h. Escriba un programa que busque un elemento vectorial utilizando la función de algoritmo std::find().
        i. Si se ha encontrado el elemento, elimínelo.
        j. Imprima el contenido vectorial.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc,char **argv)
{
    //Resolución punto a
    vector<int> vector1;
    //Resolución punto b
    vector1.push_back(80);
    vector1.push_back(456);
    //auto es una palabra clave que le dice al compilador que deduzca automáticamente el
    //tipo de la variable, en este caso la referencia a datosVector
    //La variable datosVector se inicializa automáticamente y va a ser del mismo tipo que vector1
    cout << "Elementos del vector agregados" << endl;
    for (const auto & datosVector : vector1)
    {//Resolución punto c
        cout << datosVector << endl;
    }
    //Resolución punto d
    vector1.pop_back();//Borrado de segundo elemento del vector
    //Muestro por pantalla el resultado de la operación 
    //Resolución punto e
    cout << "Operación de borrado de segundo elemento del vector concretada" << endl;
    cout << "Impresion del array por pantalla" << endl;
    for (const auto& datosVector : vector1)
    {
        cout << datosVector << endl;
    }
    //Resolución de inciso f
    //Primero agrego 7 elementos, asi tengo rango para borrar 3 elementos del principio
    vector1.push_back(77);
    vector1.push_back(99);
    vector1.push_back(435);
    vector1.push_back(978);
    vector1.push_back(11);
    vector1.push_back(1978);
    vector1.push_back(2023);
    cout << "Muestro el vector antes de la operacion de borrado" << endl;
    for(const auto& datosVector: vector1) 
    {
    cout << datosVector << endl;
    } 
    //Procedo a la operación de borrado
    vector1.erase(vector1.begin(),vector1.begin()+3);
    //Muestro el resultado por pantalla
    cout << "Resultado de la operación de borrado por rango del vector" << endl;
    for(const auto& datosVector: vector1) 
    {//Resolución inciso g
    cout << datosVector << endl;
    }
    //Resolución inciso h
    int numeroBuscado = 1978;
    //Creo una variable que el compilador va a deducir el tipo, y le digo busca desde principio
    //al fin del vector, en el tercer parámetro, le digo que numero quiero que encuentre
    auto busqueda = find(vector1.begin(),vector1.end(),numeroBuscado);
    
    //Si busqueda diferente del final, entonces encontró el númeroBuscado
    if(busqueda!= vector1.end())
    {//distance calcula la distancia entre que empieza el vector y el lugar del vector que ocupa el número encontrado
        cout << "Numero encontrado en la posición: " << distance(vector1.begin(),busqueda);
    }
    else
    {
        cout << "\nNo se encontro el numero buscado" << endl;
    }
    //Resolución último inciso
    vector1.pop_back();

    cout << "\nMuestro el vector despues de la operacion de borrado" << endl;
    for(const auto& datosVector: vector1) 
    {
    cout << datosVector << endl;
    } 

    return 0;
}