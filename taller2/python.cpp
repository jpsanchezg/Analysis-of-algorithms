#include <iostream>
using namespace std;

int calcularcostoboletas(int numeroboletas, string sala, bool hora, bool pago, bool reserva);

int main()
{

    int costo = calcularcostoboletas(1, "2D", false, true, false);
    cout << costo << endl;
}
int calcularcostoboletas(int numeroboletas, string sala, bool hora, bool pago, bool reserva)
{
    int tarifa = 0, costototal = 0;
    if (sala == "2D")
    {
        tarifa = 11300 * numeroboletas;
    }
    else if (sala == "3D")
    {
        tarifa = 15500 * numeroboletas;
    }
    else if (sala == "4D")
    {
        tarifa = 18800 * numeroboletas;
    }
    if (hora == true)
    {
        tarifa = tarifa + (tarifa * 0.10);
    }
    if (hora == false)
    {
        tarifa = tarifa - (tarifa * 0.10);
    }
    if (pago == true)
    {
        tarifa = tarifa - (tarifa * 0.05);
    }
    if (reserva == true)
    {
        tarifa = tarifa - (tarifa * 0.10);
    }
    return tarifa;
}