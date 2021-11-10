#include <iostream>

using namespace std;

int funcion(int actual,int valor, int incremento);

int main(void){

    int valor;

    cout <<"Ejercicio 2: De forma RECURSIVA.";

    cout <<endl;
    cout <<endl;

    cout <<"Digite su numero entero: ";
    cin >> valor; cout <<endl;

    cout <<endl;

    if (valor<=0)
    {
        cout <<"El valor que digito no es un entero. "; cout <<endl;
        cout <<endl;
    }
    
    else
    {
        funcion(1,valor,1); 
        cout <<endl;
    }
    return 0;
}

int funcion(int actual,int valor, int incremento){

    if (actual == 0) // CASO BASE
    {
        return 0;
    }
    
    else // CASO RECURSIVO
    {
        cout <<actual; cout <<endl;

        if (valor == actual)
        {
            incremento = 0;
        }
        
        if (incremento == 1)
        {
            actual = actual + 1;
        }
        else
        {
            actual = actual - 1;
        }
        return funcion(actual,valor,incremento);
    }
}