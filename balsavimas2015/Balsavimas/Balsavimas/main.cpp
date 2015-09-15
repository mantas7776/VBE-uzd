#include <iostream>
#include <fstream>

using namespace std;

struct balsavimas
{
	int balsai[3];
	int taskai[3];
};

void skaitymas(balsavimas bals[], int direktorius[], int& skyriai);
void vertinimas(balsavimas& bals);
int didzsk(int sk[]);
int kartojasi(int sk[]);
balsavimas sumavimas(balsavimas bals[], const int& skyriai);
void vienoduTikrinimas(balsavimas& bals, int direktorius[]);
int laimetojas(balsavimas& bals);
void isvedimas(balsavimas& bals);

int main()
{
	balsavimas bals[10], suma;
	int direktorius[3], skyriai;
	skaitymas(bals, direktorius, skyriai);
	for (int i = 0; i < skyriai; i++) vertinimas(bals[i]);
	suma = sumavimas(bals, skyriai);
	vienoduTikrinimas(suma, direktorius);
	isvedimas(suma);


	return 0;
}

void isvedimas(balsavimas& bals)
{
	ofstream is("U1rez.txt");
	for (int i = 0; i < 3; i++) is << bals.balsai[i] << " ";
	is << endl;
	for (int i = 0; i < 3; i++) is << bals.taskai[i] << " ";
	is << endl;
	is << laimetojas(bals);
}

int laimetojas(balsavimas& bals)
{
	int laimetojas;
	int sk = didzsk(bals.taskai);
	for (int i = 0; i < 3; i++)
	{
		if (bals.taskai[i] == sk) {
			laimetojas = i;
			break;
		}
	}
	laimetojas++;
	return laimetojas;
}

void vienoduTikrinimas(balsavimas& bals, int direktorius[])
{
	int kart = kartojasi(bals.taskai);
	if (kart == 3 || kart == 2)
		for (int i = 0; i < 3; i++)
			bals.taskai[i] += direktorius[i];
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

void vertinimas(balsavimas& bals)
{
	for (int i = 0; i < 3; i++) bals.taskai[i] = 0;
	int kart = kartojasi(bals.balsai);
	// neduodame tasku jeigu kartojasi 3 kartus
	if (kart == 3) return;
	// skiriame taskus
	else if (kart == 2 || kart == 1)
	{
		int didz = didzsk(bals.balsai);
		for (int i = 0; i < 3; i++)
		{
			if (bals.balsai[i] == didz && kart == 2) bals.taskai[i] += 2;
			else if (bals.balsai[i] == didz && kart == 1) bals.taskai[i] += 4;
		}
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

balsavimas sumavimas(balsavimas bals[], const int& skyriai)
{
	balsavimas suma;
	for (int i = 0; i < 3; i++) { suma.balsai[i] = 0; suma.taskai[i] = 0; }
	for (int i = 0; i < skyriai; i++)
	{
		for (int j = 0; j < 3; j++)  {
			suma.balsai[j] += bals[i].balsai[j];
			suma.taskai[j] += bals[i].taskai[j];
		}
	}
	return suma;
}