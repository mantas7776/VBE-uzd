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

struct vector2
{
	int x;
	int y;
};

void ivedimas(vector2& pradz, vector2& tikslas, int& sekos, komandos komandos[]);
void vykdytiseka(vector2 pradz, vector2& tikslas, komandos komanda);
void isvedimas(bool tikslas, string padarytosKom);
int main()
{
	int sekos;
	vector2 pradzia, tikslas;
	komandos komandos[10];
	ivedimas(pradzia , tikslas, sekos, komandos);
	for (int i = 0; i < sekos; i++)
	{
		vykdytiseka(pradzia , tikslas, komandos[i]);
	}

	return 0;
}

void ivedimas(vector2& pradz, vector2& tikslas, int& sekos, komandos komandos[])
{
	ifstream ivedimas("U2.txt");
	ivedimas >> pradz.x >> pradz.y >> tikslas.x >> tikslas.y >> sekos;

	for (int i = 0; i < sekos; i++) {
		ivedimas >> komandos[i].ilg;
		for (int c = 0; c < komandos[i].ilg; c++)
		{
			ivedimas >> komandos[i].sk[c];
		}
	}
}

void vykdytiseka(vector2 pradz, vector2& tikslas, komandos komanda)
{
	int ivykdytaKomSk = 0;
	stringstream ivykdytaKom;
	bool pasiekta = false;
	for (int i = 0; i < komanda.ilg; i++)
	{
		if (pradz.x == tikslas.x && pradz.y == tikslas.y) { pasiekta = true; break; } // baigta
		switch (komanda.sk[i])
		{
		case 1:
			pradz.y++;
			break;
		case 2:
			pradz.x++;
			break;
		case 3:
			pradz.y--;
			break;
		case 4:
			pradz.x--;
			break;
		}
		ivykdytaKom << komanda.sk[i] << " ";
		ivykdytaKomSk++;
	}
	if (pradz.x == tikslas.x && pradz.y == tikslas.y) pasiekta = true;
	ivykdytaKom << ivykdytaKomSk;
	isvedimas(pasiekta, ivykdytaKom.str());
}

void isvedimas(bool tikslas, string padarytosKom)
{
	ofstream isv("U2rez.txt", ios::app);
	if (tikslas) isv << "pasiektas tikslas ";
	else isv << "sekos pabaiga ";
	isv << padarytosKom << endl;
}
