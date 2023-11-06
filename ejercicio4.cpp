/*
Implementar un unordermap que cuente la cantidad de repetición de  palabras de la frase:
“Existen dos tipos de lenguajes de programación: 
por un lado, aquellos de los que la gente se queja todo el rato; por otro, los que nadie utiliza.” —  Bjarne Stroustrup
*/
#include <iostream>
#include<unordered_map>
#include<vector>
#include<sstream>
using namespace std;

int main(int argc,char **argv)
{
    //Declaro un string que almacene todos los datos de la frase de Stroustrup
    string fraseStroustrup = "“Existen dos tipos de lenguajes de programación: "
    "por un lado, aquellos de los que la gente se queja todo el rato;"
    " por otro, los que nadie utiliza.” — Bjarne Stroustrup";
    /*Declaro variable iss del tipo istringstream, istringstream me permite operar con
    strings como si fueran flujos de entrada, es decir me permite separar el flujo de palabras
    en unidades invidiuales(análisis) y poder tratar cada palabra como una unidad,
    es decir romper el TODO y poder  manipular cada ELEMENTO DEL TODO(en este caso, un elemento 
    es una palabra)*/
    istringstream flujo(fraseStroustrup);
    string palabra;

    //Creo un unordered_map, que me permite usar esta estructura tipo llave valor
    unordered_map<string,int> contadorPalabras;//contadorPalabras es un objeto del tipo unordered_map
    
    //Mientras sea verdadero que lo que esta en flujo pase a la variable palabra, segui iterando
    while (flujo >> palabra)
    {//Contador
        if (contadorPalabras.find(palabra) != contadorPalabras.end())
        {
            ++contadorPalabras[palabra];
        }
        else
        {
            contadorPalabras[palabra] = 1;
        }
    }
        
    // Imprimo el contador de palabras
    for (const auto &par : contadorPalabras)
    {
        cout << par.first << ": " << par.second << endl;
    }


    
    return 0;
}