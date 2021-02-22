#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>

using namespace std;

struct Studentas {
	string vardas;
	string pavarde;
	int ND[11];
	int NdSkaicius;
	int egzaminas;
	double galutinisrez;
	double median;

	double galutinis(int egzaminas, int NdSkaicius, int ND[], double galutinisrez) {
		int ndSuma=0;
		for (int i = 0; i < NdSkaicius; i++) {
			ndSuma = +ND[i];
		}
		galutinisrez = (egzaminas * 0.6) + (ndSuma * 0.4);
		return galutinisrez;
	};

	void swap(int* xp, int* yp) {
		int tmp = *xp;
		*xp = *yp;
		*yp = tmp;
	}

	double mediana(int egzaminas, int NdSkaicius, int ND[], double median) {
		ND[NdSkaicius + 1] = egzaminas;
		int i, j;
		bool swapped;
		for (int i = 0; i < NdSkaicius; i++) {
			swapped = false;
			for (int j = 0; j < NdSkaicius - 1; j++) {
				if (ND[j] > ND[j + 1]) {
					swap(&ND[j], &ND[j + 1]);
					swapped = true;
				}
			}
		}

		if ((NdSkaicius + 1) % 2 == 0) {
			double firstNumber = (double) ND[NdSkaicius / 2 -1];
			double secondNumber = (double)ND[NdSkaicius / 2];
			median =  (firstNumber + secondNumber) / 2;
		}

		else {
			NdSkaicius = NdSkaicius / 2;
			for (int i = 0; i < NdSkaicius; i++) {
				median = ND[i];
			}
		}
		return median;
	}
};

bool isInBoundaries(int number) {
	return number > 0 && number <= 10;
}

bool isNumber(const string& s) {
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

bool isValidNumber(string a) {
	return isNumber(a) && isInBoundaries(stoi(a));
}


int inputNumber() {
	string input;
	do {
		cin >> input;
		if (!isValidNumber(input)) {
			cout << "Ivestas netinkamas simbolis! (Prasome ivesti skaiciu tarp 1 ir 10)" << endl;
		}
	} while (!isValidNumber(input));
	return stoi(input);
}


int main() {
	time_t t;
	srand((unsigned)time(&t));
	int done = false;
	Studentas* studentas = new Studentas[100];
	int studentuSkaicius = 0;
	char sutikimas;

	while (done == false) {


		cout << "Iveskite studento varda: ";
		cin >> studentas[studentuSkaicius].vardas;
		cout << "Iveskite studento pavarde: ";
		cin >> studentas[studentuSkaicius].pavarde;
		cout << "Ar studento atliktu namu darbu skaicius yra zinomas? (Iveskite 'T', arba 'N')" << endl;
		do {
			cin >> sutikimas;
			if (sutikimas != 'T' && sutikimas != 'N' && sutikimas != 't' && sutikimas != 'n')
				cout << "Ivestas netinkamas simbolis! (Prasome ivesti 'T', arba 'N')" << endl;
		} while (sutikimas != 'T' && sutikimas != 'N' && sutikimas != 't' && sutikimas != 'n');
		if (sutikimas == 'T' || sutikimas == 't') {
			cout << "Iveskite namu darbu skaiciu: ";
			studentas[studentuSkaicius].NdSkaicius = inputNumber();
		}
		else {
			cout << "Namu darbu skaicius jums bus automatiskai sugeneruotas, ar sutinkate? (Iveskite 'T', arba 'N')" << endl;

			do {
				cin >> sutikimas;
				if (sutikimas != 'T' && sutikimas != 'N' && sutikimas != 't' && sutikimas != 'n') {
					cout << "Ivestas netinkamas simbolis! (Prasome ivesti 'T', arba 'N')" << endl;
				}
			} while (sutikimas != 'T' && sutikimas != 'N' && sutikimas != 't' && sutikimas != 'n');
			if (sutikimas == 'T' || sutikimas == 't') {
				studentas[studentuSkaicius].NdSkaicius = 1 + rand() % 10;
				cout << "Jusu sugeneruotas skaicius yra: " << studentas[studentuSkaicius].NdSkaicius << endl;
			}
			else {
				cout << "Iveskite namu darbu skaiciu: ";
				studentas[studentuSkaicius].NdSkaicius = inputNumber();

			}
		}
		cout << "Ar norite ivesti namu darbu rezultatus? Jei nenorite, iveskite 'N', ir jums rezultatai bus automatiskai sugeneruojami. (Iveskite tik 'T' arba 'N')" << endl;
		do {
			cin >> sutikimas;
			if (sutikimas != 'T' && sutikimas != 'N' && sutikimas != 't' && sutikimas != 'n') {
				cout << "Ivestas netinkamas simbolis! (Prasome ivesti 'T', arba 'N')" << endl;
			}
		} while (sutikimas != 'T' && sutikimas != 'N' && sutikimas != 't' && sutikimas != 'n');

		if (sutikimas == 'n' || sutikimas == 'N') {
			for (int i = 0; i < studentas[studentuSkaicius].NdSkaicius; i++) {
				studentas[studentuSkaicius].ND[i] = 1 + rand() % 10;
				cout << studentas[studentuSkaicius].ND[i] << " ";
			}
			cout << endl;

		}

		else {
			for (int i = 0; i < studentas[studentuSkaicius].NdSkaicius; i++) {
				cout << i+1 << " pazymys: ";
				studentas[studentuSkaicius].ND[i] = inputNumber();

			}
		}

		cout << "Ar norite ivesti egzamino rezultata? Jei nenorite, iveskite 'N' ir jums rezultatas bus automatiskai sugeneruojamas. (iveskite tik 'T', arba 'N')" << endl;
		do {
			cin >> sutikimas;
			if (sutikimas != 'T' && sutikimas != 'N' && sutikimas != 't' && sutikimas != 'n') {
				cout << "Ivestas netinkamas simbolis! (Prasome ivesti 'T', arba 'N')" << endl;
			}
		} while (sutikimas != 'T' && sutikimas != 'N' && sutikimas != 't' && sutikimas != 'n');
		if (sutikimas == 'n' || sutikimas == 'N') {
			studentas[studentuSkaicius].egzaminas = 1 + rand() % 10;

		}
		else {
			cout << "Egzamino pazymys: ";
			studentas[studentuSkaicius].egzaminas = inputNumber();

		}
		cout << "Jusu egzamino rezultatas yra: " << studentas[studentuSkaicius].egzaminas << endl;
		cout << "Ar norite ivesti dar vieno studento duomenis?" << endl;
		do {
			cin >> sutikimas;
			if (sutikimas != 'T' && sutikimas != 'N' && sutikimas != 't' && sutikimas != 'n') {
				cout << "Ivestas netinkamas simbolis! (Prasome ivesti 'T', arba 'N')" << endl;
			}
		} while (sutikimas != 'T' && sutikimas != 'N' && sutikimas != 't' && sutikimas != 'n');
		if (sutikimas == 't' || sutikimas == 'T') {
			done = false;
		}
		else {
			done = true;
		}
		studentuSkaicius++;

	}
	cout << "Jeigu norite pamatyti studento pazymiu vidurki: iveskite V, jei norite pamatyti studento pazymiu mediana: iveskite M." << endl;
	do {
		cin >> sutikimas;
		if (sutikimas != 'M' && sutikimas != 'V' && sutikimas != 'm' && sutikimas != 'v') {
			cout << "Ivestas netinkamas simbolis! (Prasome ivesti 'm', arba 'v')" << endl;
		}
	} while (sutikimas != 'M' && sutikimas != 'V' && sutikimas != 'm' && sutikimas != 'v');
	if (sutikimas == 'V' || sutikimas == 'v') {
	cout << left << setw(15) << "Vardas" << "Pavarde" << right << setw(50) << "galutinis (vid.)/mediana(med.)" << endl;
	for (int i = 0; i < studentuSkaicius; i++) {
		cout << "------------------------------------------------------------------------------------------" << endl;
		cout << left << setw(15) << studentas[i].vardas << studentas[i].pavarde;
		cout << right << setw(35) << studentas[i].galutinis(studentas[i].egzaminas, studentas[i].NdSkaicius, studentas[i].ND, studentas[i].galutinisrez) << endl;
		}
	}
	else {
	cout << left << setw(15) << "Vardas" << "Pavarde" << right << setw(50) << "galutinis (vid.)/mediana(med.)" << endl;
	for (int i = 0; i < studentuSkaicius; i++) {
		cout << "------------------------------------------------------------------------------------------" << endl;
		cout << left << setw(15) << studentas[i].vardas << studentas[i].pavarde;
		cout << right << setw(50) << setprecision(2) << studentas[i].mediana(studentas[i].egzaminas, studentas[i].NdSkaicius, studentas[i].ND, studentas[i].median) << endl;
	}
	}
	return 0;
}
