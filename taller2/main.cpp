#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string.h>
using namespace std;

struct censo
{
    string numero;
    string nombre;
    int edad;
    bool impuestos;
};

void llenarCenso(censo persona[], int n);
bool verificarRepetidos(censo persona[], int tam, string numero);
string llenarNumeroPersona(censo persona[], int pos);

// busqueda lineal
void busquedaPorNombre(censo persona[], int tam, string nombre);

// busqueda binaria
void busquedaPorNumero(censo persona[], int tam, string numero);

int main()
{
    censo persona[5000];
    llenarCenso(persona, 5000);
    do
    {
        cout << "1. Busqueda por nombre" << endl;
        cout << "2. Busqueda por numero" << endl;
        cout << "3. Salir" << endl;
        int opcion;
        cin >> opcion;
        string nombre;
        string numero;

        switch (opcion)
        {
        case 1:
            cout << "Ingrese nombre: ";
            cin >> nombre;
            busquedaPorNombre(persona, 5000, nombre);
            break;
        case 2:
            cout << "Ingrese numero: ";
            cin >> numero;
            busquedaPorNumero(persona, 5000, numero);
            break;
        case 3:
            break;
        }
    }

    void llenarCenso(censo persona[], int n)
    {
        char strrnd[10];
        srand(time(NULL));

        for (int i = 0; i < n; i++)
        {
            for (int i = 0; i <= 5; i++)
            {
                strrnd[i] = 33 + rand() % (126 - 33);
            }
            string tmp_string(strrnd);
            persona[i].nombre = tmp_string;
            persona[i].edad = rand() % (99 - 18 + 1) + 18;
            persona[i].numero = llenarNumeroPersona(persona, i);

            if (persona[i].edad < 65)
            {
                persona[i].impuestos = true;
            }
            else
            {
                persona[i].impuestos = false;
            }
            persona[i].impuestos = true;
        }
    }
    string llenarNumeroPersona(censo persona[], int pos)
    {
        int num[10];
        srand(time(NULL));
        for (int i = 0; i <= 9; i++)
        {
            num[i] = 0 + rand() % (9);
        }
        string str;
        for (int i : num)
        {
            str.push_back(i + '0');
        }
        cout << str << endl;
        if (pos == 0)
        {
            return str;
        }
        else
        {
            if (verificarRepetidos(persona, 5000, str))
            {
                return llenarNumeroPersona(persona, pos);
            }
            else
            {
                return str;
            }
        }
    }

    bool verificarRepetidos(censo persona[], int tam, string numero)
    {
        for (int i = 0; i < tam; i++)
        {
            if (persona[i].numero == numero)
            {
                return true;
            }
        }
        return false;
    }

    void busquedaPorNombre(censo persona[], int tam, string nombre)
    {
    }

    void busquedaPorNumero(censo persona[], int tam, string numero)
    {
    }