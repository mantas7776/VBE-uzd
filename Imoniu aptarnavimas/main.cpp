#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct imone
{
    string Pav;
    int x,y;
};

void atstumas(imone imones[], int& siumtos, int& limitas);
void ivedimas(imone imones[], int& siumtos, int& limitas);

int main()
{
    imone imones[50];
    int siumtos, limitas;
    return 0;
}

void ivedimas(imone imones[], int& siumtos, int& limitas)
{
    ifstream iv("U1.txt");
    iv >> siumtos >> limitas;
    for (int i = 0; i < siumtos; i++)
    {
        iv >> imones[i].Pav >> imones[i].x >> imones[i].y;
    }
}

void atstumas(imone imones[], int& siumtos, int& limitas)
{
    int nuvaziuota = 0, aptarnavo = 0;
    string pask;
    for (int i = 0; i < siumtos; i++)
    {
        int atstumas = imones[i].x+imones[i].y;
        if (nuvaziuota+atstumas <= limitas) break;

        aptarnavo++;
        nuvaziuota+=atstumas;
        pask = imones[i].Pav;
    }
}

void isvedimas(string pav, int aptarnavo, int nuvaziuota)
{

}
