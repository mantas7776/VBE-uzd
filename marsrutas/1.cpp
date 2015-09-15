#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <locale>

using namespace std;
const int Cmax=100;

struct mar
{
    int marsrutas;
    int keliaiviai;
};

void ivedimas(mar marsrutas[], int & viso);
void ilipoislipo(mar marsrutas[], mar marsrutas2[], int & viso1, int & viso2, int tipas);
void rikiuoti(mar marsrutas[], int & viso);
void isvedimas(mar marsrutas[], mar marsdaug[], mar marsmaz[], int & viso, int & viso2, int & viso3);
int ilipo(mar marsrutas[], int & viso, int marsrutonr);
int islipo(mar marsrutas[], int & viso, int marsrutonr);
int maratrinkimas(mar marsrutas[], int & viso, int marsrutonr);
//------------------------------------
int main()
{
    setlocale(LC_ALL,"Lithuanian");
    int viso;
    mar marsrutas[Cmax];
    ivedimas(marsrutas, viso);
    mar marsrutas2[Cmax], marsrutas3[Cmax];
    int viso2, viso3;
    ilipoislipo(marsrutas, marsrutas2, viso, viso2, 1);
    //ilipoislipo(marsrutas, marsrutas3, viso, viso3, 2);
    rikiuoti(marsrutas, viso);
    isvedimas(marsrutas, marsrutas2, marsrutas3, viso, viso2, viso3);

    return 0;
}
//-----------------------------------

void ivedimas(mar marsrutas[], int & viso)
{
    ifstream iv("U1.txt");
    iv >> viso;
    for (int i = 0; i < viso; i++)
    {
        iv >> marsrutas[i].marsrutas >> marsrutas[i].keliaiviai;
    }
    iv.close();
}

void ilipoislipo(mar marsrutas[], mar marsrutas2[], int & viso1, int & viso2, int tipas) // tipas = 1 ilipo, 2 islipo;
{
    viso2 = 0;
    for (int i = 0; i < Cmax; i++)
    {
        marsrutas2[i].keliaiviai = 0;
        marsrutas2[i].marsrutas = 0;
    }
    for (int i = 0; i < viso1; i++)
    {
        if (marsrutas[i].keliaiviai<0 && tipas == 1) continue;
        //if (marsrutas[i].keliaiviai<0 && tipas == 2) continue;
        viso2++;
        marsrutas2[viso2].marsrutas == marsrutas[i].marsrutas;
        marsrutas2[viso2].keliaiviai += marsrutas[i].keliaiviai;
    }
}

void rikiuoti(mar marsrutas[], int & viso)
{
    while (true)
    {
        bool swapped = false;
        for (int i = 0; i<viso-1; i++)
        {
            if (marsrutas[i].marsrutas>marsrutas[i+1].marsrutas)
            {
                swapped = true;
                swap(marsrutas[i].marsrutas, marsrutas[i+1].marsrutas);
                swap(marsrutas[i].keliaiviai, marsrutas[i+1].keliaiviai);
            }
        }
        if (!swapped) break;
    }
}

int maratrinkimas(mar marsrutas[], int & viso, int marsrutonr)
{
    for (int y = 0; y < viso; y++)
    {
        bool yra=false;
        if (marsrutonr == marsrutas[y].marsrutas)
        {
            yra = true;
            //cout << "Return: " << marsrutonr << " = " << marsrutas[y].marsrutas;
            return marsrutas[y].keliaiviai;
            break;
        }
        if (!yra) return 0;
    }
}

int ilipo(mar marsrutas[], int & viso, int marsrutonr)
{
    int kel = 0;
    for (int i = 0; i < viso; i++)
    {
        if (marsrutas[i].keliaiviai>0 && marsrutas[i].marsrutas == marsrutonr)
        {
            kel += marsrutas[i].keliaiviai;
        }
    }
    return kel;
}

int islipo(mar marsrutas[], int & viso, int marsrutonr)
{
    int kel = 0;
    for (int i = 0; i < viso; i++)
    {
        if (marsrutas[i].keliaiviai<0 && marsrutas[i].marsrutas == marsrutonr)
        {
            kel += marsrutas[i].keliaiviai;
        }
    }
    return kel;
}

void isvedimas(mar marsrutas[], mar marsdaug[], mar marsmaz[], int & viso, int & viso2, int & viso3)
{
    ofstream is("U1rez.txt");
    /*
    for (int i = 0; i < viso; i++)
    {
        cout << "Marsrutas: " << marsrutas[i].marsrutas << " keliaiviai: " << marsrutas[i].keliaiviai << endl;
    }
    */
    // marsrutu isspausdinimas
    int praeitas = -1;
    for (int i = 0; i < viso; i++)
    {
        if (praeitas == marsrutas[i].marsrutas)
        {
            continue;
        }
        else
        {
            praeitas = marsrutas[i].marsrutas;
            is << setw(5) << marsrutas[i].marsrutas;
        }
    }
    is << endl;

    //didziausiu isspausdinimas

    praeitas = -1;
    for (int i = 0; i < viso; i++)
    {
        if (praeitas == marsrutas[i].marsrutas)
        {
            continue;
            praeitas = marsrutas[i].marsrutas;
        }
        else
        {
            //is << setw(5) << maratrinkimas(marsdaug, viso2, marsrutas[i].marsrutas);
            is << setw(5) << ilipo(marsrutas, viso, marsrutas[i].marsrutas);
            praeitas = marsrutas[i].marsrutas;
        }
    }
    is << endl;
    //maziausiu isspausdinimas
    praeitas = -1;
    for (int i = 0; i < viso; i++)
    {
        if (praeitas == marsrutas[i].marsrutas) continue;
        else
        {
            is << setw(5) << islipo(marsrutas, viso, marsrutas[i].marsrutas);
            praeitas = marsrutas[i].marsrutas;
        }
    }
    is << endl;
}

int didzmar(mar marsrutas[], int & viso)
{
    int didz = 0; // didziausias marsrutas ind
    for (int i = 1; i < viso; i++)
    {
        if (marsrutas[i].keliaiviai > marsrutas[didz].keliaiviai)
        {
            didz = i;
        }
    }

}
