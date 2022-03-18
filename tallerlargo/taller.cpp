#include <iostream>
using namespace std;

struct asignaturas
{
    string nombre;
    float nota;
};

struct cursos
{
    string mombre;
    int codigo;
    asignaturas asignatura[5];
};

void mediaporestudiante(cursos curso[], int tamano, asignaturas promedioestiduantes[])
{
    for (int i = 0; i < tamano; i++)
    {
        float suma = 0;
        for (int j = 0; j < 5; j++)
        {
            suma += curso[i].asignatura[j].nota;
        }
        float prom = suma / 5;
        promedioestiduantes[i].nota = prom;
        promedioestiduantes[i].nombre = curso[i].mombre;
        cout << "el promedio del estudiante " << curso[i].mombre << " es " << prom << endl;
    }
}

void mediaporasignatura(cursos cursos[], int tamano)
{
    for (int i = 0; i < 5; i++)
    {
        float suma = 0;
        string materia;
        for (int j = 0; j < 10; j++)
        {
            suma += cursos[j].asignatura[i].nota;
            materia = cursos[j].asignatura[i].nombre;
        }
        float prom = suma / 10;
        cout << "el promedio de la asignatura " << materia << " es " << prom << endl;
    }
}

// promedio total del curso
void promediototal(cursos cursos[], int tamano)
{
    float suma = 0;
    for (int i = 0; i < tamano; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            suma += cursos[i].asignatura[j].nota;
        }
    }
    cout << "el promedio total del curso es " << suma / (tamano * 5) << endl;
}

void mediatotal(cursos cursos[], int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        float suma = 0;
        for (int j = 0; j < 5; j++)
        {
            suma += cursos[i].asignatura[j].nota;
        }
        cout << "el promedio total del curso " << cursos[i].mombre << " es " << suma / 10 << endl;
    }
}

void ordenarporpromedioestudiante(asignaturas promedioestiduantes[], int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        for (int j = 0; j < tamano; j++)
        {
            if (promedioestiduantes[i].nota > promedioestiduantes[j].nota)
            {
                asignaturas aux;
                aux = promedioestiduantes[i];
                promedioestiduantes[i] = promedioestiduantes[j];
                promedioestiduantes[j] = aux;
            }
        }
    }
}

void imprimir(asignaturas promedioestiduantes[], int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        cout << "el promedio del estudiante " << promedioestiduantes[i].nombre << " es " << promedioestiduantes[i].nota << endl;
    }
}

int main()
{
    struct cursos estudiantes[10] =
        {
            {"Juan Pablo Sanchez Gaitan", 1, {{"Matematicas", 10}, {"Lengua", 8}, {"Historia", 7}, {"Ciencias", 4}, {"Ingles", 6}}},
            {"Carlos David Gaitan", 2, {{"Matematicas", 8}, {"Lengua", 5}, {"Historia", 4}, {"Ciencias", 2}, {"Ingles", 7}}},
            {"Diana  Sanchez Gaitan", 3, {{"Matematicas", 1}, {"Lengua", 9}, {"Historia", 3}, {"Ciencias", 1}, {"Ingles", 10}}},
            {"Juan Pablo Vera", 4, {{"Matematicas", 10}, {"Lengua", 8}, {"Historia", 10}, {"Ciencias", 4}, {"Ingles", 9}}},
            {"Diana Sofia", 5, {{"Matematicas", 10}, {"Lengua", 7}, {"Historia", 9}, {"Ciencias", 8}, {"Ingles", 8}}},
            {"Juliana Naranjo", 6, {{"Matematicas", 5}, {"Lengua", 8}, {"Historia", 9}, {"Ciencias", 8}, {"Ingles", 7}}},
            {"Pia Iyurbiales", 7, {{"Matematicas", 7}, {"Lengua", 1}, {"Historia", 0}, {"Ciencias", 1}, {"Ingles", 1}}},
            {"Andres Pena", 8, {{"Matematicas", 9}, {"Lengua", 1}, {"Historia", 6}, {"Ciencias", 4}, {"Ingles", 6}}},
            {"Karol geraldine", 9, {{"Matematicas", 3}, {"Lengua", 1}, {"Historia", 8}, {"Ciencias", 2}, {"Ingles", 5}}},
            {"Ana Maria", 10, {{"Matematicas", 1}, {"Lengua", 1}, {"Historia", 1}, {"Ciencias", 2}, {"Ingles", 10}}}};

    struct asignaturas promedioestiduantes[10];
    mediaporestudiante(estudiantes, 10, promedioestiduantes);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    mediaporasignatura(estudiantes, 10);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    promediototal(estudiantes, 10);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    ordenarporpromedioestudiante(promedioestiduantes, 10);
    imprimir(promedioestiduantes, 10);
}
