#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <vector>
using namespace std;
struct censo
{
    int numero;
    string nombre;
    int edad;
    bool impuestos;
};

void llenarCenso(vector<censo> &persona, int n);

string llenarNumeroPersona(vector<censo> persona, int pos);
void imprimirNumeros(vector<censo> persona);

void imprimirNombres(vector<censo> persona);

// busqueda binaria

int busquedaPorNumero(vector<censo> &vec, int &item, int s1, int s2);

int BusquedaBinaria(vector<censo> &vec, int &item);

// busqueda lineal
void busquedaPorNombre(vector<censo> persona, string nombre);

int main()
{
    vector<censo> persona;
    llenarCenso(persona, 500000); // llena el vector de censo
    bool salir = false;

    do
    {
        cout << "Censo de Poblacion" << endl;
        cout << "1. Busqueda por nombre" << endl;

        cout << "2. Busqueda por numero" << endl;
        cout << "3. Salir" << endl;
        cout << "4. imprimir numeros" << endl;
        cout << "5. imprimir nombres" << endl;
        int opcion;
        cin >> opcion;
        string nombre;
        int numero;
        int pos;
        switch (opcion)
        {
        case 1:
            cout << "Ingrese nombre: ";
            cin >> nombre;
            busquedaPorNombre(persona, nombre);
            break;

        case 2:
            cout << "Ingrese numero: ";
            cin >> numero;
            pos = BusquedaBinaria(persona, numero);
            if (pos == numero)
            {
                cout << "Numero encontrado" << endl;
            }
            else
            {
                cout << "Numero no encontrado" << endl;
            }
            break;

        case 3:
            salir = true;
            break;

        case 4:
            imprimirNumeros(persona);
            break;

        case 5:
            imprimirNombres(persona);
            break;

        default:
            cout << "Opcion no valida" << endl;
        }
    } while (!salir);
}

void llenarCenso(vector<censo> &persona, int n)
{
    char strrnd[10];
    srand(time(NULL));
    censo p;
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i <= 5; i++)
        {
            strrnd[i] = 65 + rand() % (90 - 65);
        }

        string tmp_string(strrnd);

        p.nombre = tmp_string;
        p.edad = rand() % (99 - 18 + 1) + 18;
        p.numero = rand() % (500000 + 1) + 0;
        if (p.edad < 65)
        {
            p.impuestos = true;
        }
        else
        {
            p.impuestos = false;
        }
        p.impuestos = true;
        persona.push_back(p);
    }
}

void imprimirNumeros(vector<censo> persona)
{
    vector<censo> parr3(persona.begin(), persona.end());
    for (vector<censo>::iterator it = persona.begin(); it != persona.end(); ++it)
    {
        cout << it->numero << endl;
    }
}

void imprimirNombres(vector<censo> persona)
{
    vector<censo> parr3(persona.begin(), persona.end());
    for (vector<censo>::iterator it = persona.begin(); it != persona.end(); ++it)
    {
        cout << it->nombre << endl;
    }
}

void busquedaPorNombre(vector<censo> persona, string nombre)
{
    for (vector<censo>::iterator it = persona.begin(); it != persona.end(); ++it)
    {
        if (it->nombre == nombre)
        {
            cout << "se encontro el numero que andas buscando" << endl;
            cout << "Nombre: " << it->nombre << endl;
        }
    }
}

int busquedaPorNumero(vector<censo> &vec, int &item, int s1, int s2)
{
    if (s1 > s2)
        return -1;

    auto middle = (s1 + s2) / 2;

    if (item == middle)
    {
        return middle;
    }
    if (item > middle)
    {
        return busquedaPorNumero(vec, item, middle + 1, s2);
    }
    else
    {
        return busquedaPorNumero(vec, item, s1, middle - 1);
    }
}

int BusquedaBinaria(vector<censo> &vec, int &item)
{
    return busquedaPorNumero(vec, item, 0, vec.size() - 1);
}