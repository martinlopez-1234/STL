/*
Los mapas son contenedores asociativos que almacenan elementos de manera mapeada.
Cada elemento tiene un valor clave y un valor asignado. 
No hay dos valores asignados que puedan tener los mismos valores clave.
    3. Implementar un Map en C++ 
        a. contenedor de mapa vacío
        b. insertar elementos en orden aleatorio
        c. imprimiendo mapa Map1
        d. asignando los elementos de Map1 a Map2
        e. imprimir todos los elementos del mapa Map2
        f. eliminar todos los elementos hasta
        g. elemento con clave=3 en Map2
        h. eliminar todos los elementos con clave = 4
        i. límite inferior y límite superior para el mapa Map1 clave = 5
*/

#include <iostream>
#include <map>
using namespace std;

int main(int argc,char **argv)
{
    //Resolución punto a
    map<int,string>Map1;
    //Resolución punto b
    Map1[1] = "perro";//Boby es la clave y perro es el valor
    Map1[2] = "gato";
    Map1[3] = "hamster";
    Map1[4] = "canario";
    //Resolución punto c
    for (const auto& elementoMapa: Map1)
    {
        cout << "Clave de la mascota: " << elementoMapa.first << ", tipo de mascota: " << elementoMapa.second << endl;
    }
    //Resolución punto d
    map<int,string> Map2 = Map1;
    //Resolución punto e
    cout << "\nMuestro el mapa 2 recien copiado del mapa 1" << endl;

    for (const auto& claveValor: Map2)
    {
        cout << "Clave de la mascota: " << claveValor.first << ", tipo de mascota: " << claveValor.second << endl;
    }
    //Resolución problemas puntos f y g 
    //Agrego mas pares de clave valor para poder cumplir con la consigna
    pair<int,string>nuevodato(5,"cotorra");
    pair<int,string>nuevodato1(6,"tortuga");

    Map2.insert(nuevodato);
    Map2.insert(nuevodato1);

        
    cout <<"\nMuestro por pantalla los nuevo datos insertados en el mapa Map2" << endl << endl;
    for (const auto& elementoMapa: Map2)
    {
        cout << "Clave de la mascota: " << elementoMapa.first << ", tipo de mascota: " << elementoMapa.second << endl;
    }
    //Creo iteradores, lo que digo es, el iterador inicio, adopta el valor 0 del mapa 
    map<int,string>::iterator inicio = Map2.find(1);
    //Ahora creo el iterador que representa el lugar hasta donde quiero borrar
    map<int,string>::iterator destino = Map2.find(4);//Como find no incluye al 3, le tengo que pasar un número mas

    //Borro los elementos del 1 al 3
    Map2.erase(inicio,destino);
    //Muestro por pantalla como quedo el array despues de borrar los elementos del mapa
    cout <<"\nMuestro por pantalla lo que quedo del mapa Map2" << endl << endl;
    for (const auto& elementoMapa: Map2)
    {
        cout << "Clave de la mascota: " << elementoMapa.first << ", tipo de mascota: " << elementoMapa.second << endl;
    }
    
    //Resolución punto h
    Map1.erase(4);
    //Muestro por pantalla como quedo el array despues de borrar los elementos del mapa
    cout <<"\nMuestro por pantalla los resultados de borrar el elemento con clave 1" << endl << endl;
    for (const auto& elementoMapa: Map1)
    {
        cout << "Clave de la mascota: " << elementoMapa.first << ", tipo de mascota: " << elementoMapa.second << endl;
    }
    //Resolución punto 1
    //Para que tenga gracia resolverlo, agrego más datos a Map1
    cout <<"\nMuestro por pantalla los resultados de borrar el elemento con clave 1" << endl << endl;
    for (const auto& elementoMapa: Map1)
    {
        cout << "Clave de la mascota: " << elementoMapa.first << ", tipo de mascota: " << elementoMapa.second << endl;
    }
    
    /*Si no hay un elemento con la clave 5, pero hay elementos con claves mayores que 5,
    lower_bound me va a dar el primer elemento que tiene una clave mayor que 5.
    O sea me indica cual es el primer elemento que tiene un valor igual o superior a
    al valor que establecí como límite inferior.
    Lo mismo pasa con upper_bond, la sentencia me va a devolver el primer lugar cuyo elemento
    clave valor, tiene una clave mayor al limite superior que establecí usando la sentencia upper_bond 
    */
    
    pair<int,string>nuevodato3(5,"cotorra");
    pair<int,string>nuevodato4(6,"tortuga");
    pair<int,string>nuevodato5(7,"cobayo");

    Map1.insert(nuevodato3);
    Map1.insert(nuevodato4);
    Map1.insert(nuevodato5);
    
    //Uso los métodos lower_bound y upper_bound.
    auto cotaInferior = Map1.lower_bound(5);
    auto cotaSuperior = Map1.upper_bound(5);

    cout <<"\nMuestro por pantalla los resultados de agregar elementos al Map1" << endl << endl;
    for (const auto& elementoMapa: Map1)
    {
        cout << "Clave de la mascota: " << elementoMapa.first << ", tipo de mascota: " << elementoMapa.second << endl;
    }


    
    if (cotaInferior != Map1.end())
    {
       cout << "El límite inferior para la clave 5 es: " << cotaInferior->second << endl;
    }
    else
        cout << "No hay un límite inferior para la clave 5." << endl;

    if (cotaSuperior != Map1.end())
    {
        cout << "El límite superior para la clave 5 es: " << cotaSuperior->second << endl;
    }
        
    else
        cout << "No hay un límite superior para la clave 5." << endl;
    
    
    return 0;
}