#include <iostream>

using namespace std;

int MCD(int max, int min);

int main(void){
    int a;
    int b;
    int max;
    int min;

    cout <<"Ejercicio 1: De forma RECURSIVA.";

    cout <<endl;
    cout <<endl;

    cout <<"Digite su primer numero: ";
    cin >> a; cout <<endl;

    cout <<"Digite su segundo numero: ";
    cin >> b; cout <<endl;

    if (a > b)
    {
        max = a;
        min = b;
    }

    else
    {
        max = b;
        min = a;
    }
    
    cout <<"El MCD de sus numeros es igual a: " <<MCD(max,min);

    cout <<endl;
    cout <<endl;

    return 0;
}

int MCD(int max,int min){

    int residuo = max%min;

    if (residuo == 0) // Caso base
    {
        return min;   
    }

    else // Caso recursivo
    {
        max = min;
        min = residuo;

        return MCD(max,min);
    }
}