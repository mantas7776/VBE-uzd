#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

struct komandos
{
	int ilg;
	int sk[30];
};

void ivedimas(int& x, int& y, int& tikx, int& tiky, int& sekos, komandos komandos[]);
void vykdytiseka(int pradzx, int pradzy, int& tikx, int& tiky, int& sekos, komandos komanda);
void isvedimas(bool tikslas, string padarytosKom);
int main()
{
	int sekos, x, y, tikx, tiky;
	komandos komandos[10];
	ivedimas(x, y, tikx, tiky, sekos, komandos);
	for (int i = 0; i < sekos; i++)
	{
		vykdytiseka(x, y, tikx, tiky, sekos, komandos[i]);
	}

	return 0;
}

void ivedimas(int& x, int& y, int& tikx, int& tiky, int& sekos, komandos komandos[])
{
	ifstream ivedimas("U2.txt");
	ivedimas >> x >> y >> tikx >> tiky >> sekos;

	for (int i = 0; i < sekos; i++) {
		ivedimas >> komandos[i].ilg;
		for (int c = 0; c < komandos[i].ilg; c++)
		{
			ivedimas >> komandos[i].sk[c];
		}
	}
}

void vykdytiseka(int pradzx, int pradzy, int& tikx, int& tiky, int& sekos, komandos komanda)
{
	int ivykdytaKomSk = 0;
	stringstream ivykdytaKom;
	bool pasiekta = false;
	for (int i = 0; i < komanda.ilg; i++)
	{
		if (pradzx == tikx && pradzy == tiky) { pasiekta = true; break; } // baigta
		switch (komanda.sk[i])
		{
		case 1:
			pradzy++;
			break;
		case 2:
			pradzx++;
			break;
		case 3:
			pradzy--;
			break;
		case 4:
			pradzx--;
			break;
		}
		ivykdytaKom << komanda.sk[i] << " ";
		ivykdytaKomSk++;
	}
	if (pradzx == tikx && pradzy == tiky) pasiekta = true;
	ivykdytaKom << ivykdytaKomSk;
	isvedimas(pasiekta, ivykdytaKom.str());
}

void isvedimas(bool tikslas, string padarytosKom)
{
	ofstream isv("U2rez.txt", ios::app);
	if (tikslas)
	{
		isv << "pasiektas tikslas ";
	}
	else{
		isv << "sekos pabaiga ";
	}
	isv << padarytosKom << endl;
}
