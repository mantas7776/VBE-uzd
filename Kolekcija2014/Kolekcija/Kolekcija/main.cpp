#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


void ivedimas(vector<int>& lina, vector<int>& jurgis); // funkcija skirta linos ir jurgio duomenu ivedimui is failo
vector<int> mainai(vector<int>& siulo, vector<int>& kam); // funkcija atliekanti mainus, siulo- kas siulo zaislus, kam- kam siuloma zaislai
void isvedimas(vector<int>& lina, vector<int>& jurgis, vector<int>& bendri); // jurgio ir linos mainu rezultatams skirta isvesti funkcija ir bendriems zaislu numeriams
vector<int> bendri(vector<int>& lina, vector<int>& jurgis); // bendru zaisliuku numeriu gavimas

int main()
{
	vector<int> lina, jurgis;
	ivedimas(lina, jurgis);
	sort(lina.begin(), lina.end());
	sort(jurgis.begin(), jurgis.end());
	vector<int> linamain = mainai(lina, jurgis);
	vector<int> jurgismain = mainai(jurgis, lina);
	vector<int> bendrizais = bendri(lina, jurgis);
	isvedimas(linamain, jurgismain, bendrizais);
	return 0;
}

void isvedimas(vector<int>& lina, vector<int>& jurgis, vector<int>& bendri)
{
	ofstream is("U1rez.txt");
	for (int i = 0; i < lina.size(); i++) is << lina[i] << " ";
	is << endl;
	for (int i = 0; i < jurgis.size(); i++) is << jurgis[i] << " ";
	is << endl;
	for (int i = 0; i < bendri.size(); i++) is << bendri[i] << " ";
}

vector<int> bendri(vector<int>& lina, vector<int>& jurgis)
{
	vector<int> bendrizais = lina;
	for (int i = 0; i < jurgis.size(); i++) bendrizais.push_back(jurgis[i]);
	sort(bendrizais.begin(), bendrizais.end());
	
	vector<int> bepasikartojimu;
	int sk = bendrizais[0], kartojasi = 1;
	bepasikartojimu.push_back(bendrizais[0]);
	for (int i = 1; i < bendrizais.size(); i++)
	{
		if (sk != bendrizais[i])
		{
			sk = bendrizais[i];
			bepasikartojimu.push_back(sk);
		}
	}
	return bepasikartojimu;
}

void ivedimas(vector<int>& lina, vector<int>& jurgis)
{
	int linSk, jurSk;
	ifstream iv("U1duom.txt");
	iv >> linSk >> jurSk;
	for (int i = 0; i < linSk; i++)
	{
		int laik;
		iv >> laik;
		lina.push_back(laik);
	}
	for (int i = 0; i < jurSk; i++)
	{
		int laik;
		iv >> laik;
		jurgis.push_back(laik);
	}
}

vector<int> mainai(vector<int>& siulo, vector<int>& kam)
{
	vector<int> kartojasi;
	int sk = siulo[0], kartas = 1, i = 1;
	while (true)
	{
		if (i == siulo.size()) break;
		if (sk == siulo[i] && kartas == 1)
		{
			kartas++;
			kartojasi.push_back(siulo[i]);
		}
		else if (sk != siulo[i])
		{
			kartas = 1;
			sk = siulo[i];
		}
		i++;
	}
	vector<int> mainai;
	if (kartojasi.size() == 0)
	{
		kartojasi.push_back(0);
		return kartojasi;
	}
	for (int i = 0; i < kartojasi.size(); i++)
	{
		bool netinka = false;
		for (int j = 0; j < kam.size(); j++)
		{
			if (kartojasi[i] == kam[j]) netinka = true;
		}
		if (!netinka)
		{
			mainai.push_back(kartojasi[i]);
		}
	}
	if (mainai.size() == 0) mainai.push_back(0);

	return mainai;
}