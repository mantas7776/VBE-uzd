#include <iostream>
#include <fstream>

using namespace std;

struct balsavimas
{
    int balsai[3];
    int taskai[3];
};

void skaitymas(balsavimas bals[], int direktorius[], int& skyriai);
void vertinimas(balsavimas bals);
int didzsk(int balsai[]);
int kartojasi(int sk[]);

int main()
{
    balsavimas bals[10];
    int direktorius[3], skyriai;
    skaitymas(bals, direktorius, skyriai);

    cout << kartojasi(bals[0].balsai);
    //vertinimas(bals[0]);

    //for (int i = 0; i < skyriai; i++) vertinimas(bals[i]);


    return 0;
}

void skaitymas(balsavimas bals[], int direktorius[], int& skyriai)
{
    ifstream iv("U1.txt");
    iv >> skyriai;
    //skyriu balsai
    for (int i = 0; i < skyriai; i++)
    {
        for (int j = 0; j < 3; j++) iv >> bals[i].balsai[j];
    }
    //direktoriaus taskai
    for (int i = 0; i < 3; i++) iv >> direktorius[i];
}

void vertinimas(balsavimas bals)
{
    for (int i = 0; i < 3; i++) bals.taskai[i] = 0;
    int kart = kartojasi(bals.balsai);
    // neduodame tasku jeigu kartojasi 3 kartus
    if (kart == 3) return;
    // skiriame taskus
    else if (kart == 2 && kart == 1)
    {
        int didz = didzsk(bals.balsai)
        for (int i = 0; i < 3; i++)
        if (bals.balsai[i] == didz && kart == 2) bals.taskai[i] += 2;
        else if (bals.balsai[i] == didz && kart == 1) bals.taskai[i] += 4;
    }
}

int didzsk(int sk[])
{
    int didzsk = sk[0];
    for (int i = 1; i < 3; i++)
    {
        if (didzsk < sk[i]) didzsk = sk[i];
    }
    return didzsk;
}

int kartojasi(int sk[])
{
    int skaicius = didzsk(sk);
    int karto = 0;
    for (int i = 0; i < 3; i++)
    {
        if (sk[i] == skaicius) karto++;
    }
    return karto;
}
