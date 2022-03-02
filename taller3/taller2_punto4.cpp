#include <iostream>
using namespace std;

// juan pablo sanchez gaitan

// Punto 4
int extraccion_ruedas(int coches, int motos, int vehiculos, int ruedas);

int main()
{
    int coches = 0, motos = 0;
    int vehiculos = 0;
    // vehiculos = coches + motos;
    int ruedas = 0;
    // ruedas = coches * 4 + motos * 2;
    coches = motos = extraccion_reudas(coches, motos, vehiculos, ruedas);
}

int extraccion_reudas(int coches, int motos, int vehiculos, int ruedas)
{
    for (int i = 0; i < vehiculos; i++)
    {
        if (coches * 4 + motos * 2 == ruedas)
        {
            return coches, motos;
        }
    }
    return 0;
}

// algoritmo de O(n)
/*
Este algoritmo es de orden O(n) ya que se va a realizar una sola vez la extraccion de ruedas
recogiendo los datos de los vehiculos.


*/

