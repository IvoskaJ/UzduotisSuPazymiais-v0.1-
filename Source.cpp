#include "Funkcijos.cpp"

using namespace std;

int main() {
	time_t t;
	srand((unsigned)time(&t));
	Studentas* studentas = new Studentas[10000];
	char sutikimas;
	int studentuSkaicius = 0;

	cout << "Jeigu norite ivesti studentu duomenis, iveskite T, jeigu nenorite spauskite n, ir studentu duomenys bus paiimti is tekstinio failo 'kursiokai'.(Iveskite tik 'T' arba 'N')" << endl;
	sutikimas = inputChar();
	if (sutikimas == 'N' || sutikimas == 'n') {
		ReadFile(studentas, studentuSkaicius);
	}

	else {
		inputData(studentas,studentuSkaicius);
	}
		
	cout << "Jeigu norite pamatyti studento pazymiu vidurki: iveskite V, jei norite pamatyti studento pazymiu mediana: iveskite M, jei norite pamatyti abu rezultatus, iveskite A." << endl;
	do {
		cin >> sutikimas;
		if (sutikimas == 'a' && sutikimas == 'A' && sutikimas == 'm' && sutikimas == 'M' && sutikimas == 'v' && sutikimas == 'V') {
			cout << "prasome ivesti tinkama simboli! (a - abiems reiksmems, m - tik medianai, v - vidurkiui)" << endl;
		}
	} while (sutikimas == 'a' && sutikimas == 'A' && sutikimas == 'm' && sutikimas == 'M' && sutikimas == 'v' && sutikimas == 'V');

	if (sutikimas == 'a' || sutikimas == 'A') {
		visuDuomenuSkaiciavimas(studentas, studentuSkaicius);
	}
	else if (sutikimas == 'V' || sutikimas == 'v') {
		vidurkioSkaiciavimas(studentas, studentuSkaicius);
	}
	else {
		medianosSkaiciavimas(studentas, studentuSkaicius);
	}
	return 0;
}