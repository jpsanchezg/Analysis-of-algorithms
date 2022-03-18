#include <iostream>
#include <chrono>
using namespace std;

void ordenarburbuja(int arreglo[], int tamano);
void imprimirarreglo(int arreglo[], int tamano);

void selectionSort(int arreglo[], int tamano);

void mergeSort(int arr[], int l, int r);
void merge(int arr[], int p, int q, int r);

void quickSort(int arreglo[], int tamano);
void ramdomquickSort(int arreglo[], int tamano);

int tiempodeejecucion(int arreglo[], int tamano);
int main()
{
    int tamano = 20;
    cout << "burbuja" << endl;
    int burbuja[20] = {5, 11, 6, 2, 3, 16, 17, 4, 10, 20, 7, 8, 9, 12, 13, 14, 15, 18, 19, 1};
    imprimirarreglo(burbuja, tamano); // arreglo sin ordenar
    ordenarburbuja(burbuja, tamano);
    imprimirarreglo(burbuja, tamano); // arreglo ordenado
    cout << endl;
    cout << endl;
    cout << "selection" << endl;
    int selectionsortarray[20] = {5, 11, 6, 2, 3, 16, 17, 4, 10, 20, 7, 8, 9, 12, 13, 14, 15, 18, 19, 1};
    imprimirarreglo(selectionsortarray, tamano); // arreglo sin ordenar
    selectionSort(selectionsortarray, tamano);
    imprimirarreglo(selectionsortarray, tamano); // arreglo ordenado
    cout << endl;
    cout << endl;
    cout << "merge" << endl;
    int mergesortarray[20] = {5, 11, 6, 2, 3, 16, 17, 4, 10, 20, 7, 8, 9, 12, 13, 14, 15, 18, 19, 1};
    imprimirarreglo(mergesortarray, tamano); // arreglo sin ordenar
    mergeSort(mergesortarray, 0, tamano - 1);
    imprimirarreglo(mergesortarray, tamano); // arreglo ordenado
    cout << endl;
    cout << endl;
    cout << "quick" << endl;
    int quicksortarray[20] = {5, 11, 6, 2, 3, 16, 17, 4, 10, 20, 7, 8, 9, 12, 13, 14, 15, 18, 19, 1};
    imprimirarreglo(quicksortarray, tamano); // arreglo sin ordenar
    quickSort(quicksortarray, tamano);
    imprimirarreglo(quicksortarray, tamano); // arreglo ordenado
    cout << endl;
    cout << endl;
    cout << "random quick" << endl;
    int ramdomquicksortarray[20] = {5, 11, 6, 2, 3, 16, 17, 4, 10, 20, 7, 8, 9, 12, 13, 14, 15, 18, 19, 1};
    imprimirarreglo(ramdomquicksortarray, tamano); // arreglo sin ordenar
    ramdomquickSort(ramdomquicksortarray, tamano);
    imprimirarreglo(ramdomquicksortarray, tamano); // arreglo ordenado
}

void ordenarburbuja(int arreglo[], int tamano)
{
    auto begin = std::chrono::high_resolution_clock::now();
    int auxiliar;
    for (int i = 0; i < tamano; i++)
    {
        for (int j = 0; j < tamano; j++)
        {
            if (arreglo[i] < arreglo[j])
            {
                auxiliar = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = auxiliar;
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
}

void selectionSort(int arreglo[], int tamano)
{
    int menor, posicionmenor;
    auto begin = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < tamano; i++)
    {
        menor = arreglo[i];
        posicionmenor = i;
        for (int j = i + 1; j < tamano; j++)
        {
            if (arreglo[j] < menor)
            {
                menor = arreglo[j];
                posicionmenor = j;
            }
        }
        arreglo[posicionmenor] = arreglo[i];
        arreglo[i] = menor;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
}

void merge(int arr[], int p, int q, int r)
{

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    auto begin = std::chrono::high_resolution_clock::now();

    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
}

void quickSort(int arreglo[], int tamano)
{
    auto begin = std::chrono::high_resolution_clock::now();

    int i, j, p, aux;
    i = 0;
    j = tamano - 1;
    p = 0;
    while (i < j)
    {
        while (arreglo[i] < arreglo[p])
            i++;
        while (arreglo[j] > arreglo[p])
            j--;
        if (i <= j)
        {
            aux = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = aux;
            i++;
            j--;
        }
    }
    if (j > p)
        quickSort(arreglo, j);
    if (i < p)
        quickSort(arreglo + i, tamano - i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
}

void ramdomquickSort(int arreglo[], int tamano)
{
    auto begin = std::chrono::high_resolution_clock::now();
    int i, j, p, aux;
    i = 0;
    j = tamano - 1;
    p = rand() % tamano;
    while (i < j)
    {
        while (arreglo[i] < arreglo[p])
            i++;
        while (arreglo[j] > arreglo[p])
            j--;
        if (i <= j)
        {
            aux = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = aux;
            i++;
            j--;
        }
    }
    if (j > p)
        ramdomquickSort(arreglo, j);
    if (i < p)
        ramdomquickSort(arreglo + i, tamano - i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
}

void imprimirarreglo(int arreglo[], int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}