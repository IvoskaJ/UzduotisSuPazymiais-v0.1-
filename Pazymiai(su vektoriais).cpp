#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <vector>

using namespace std;

struct Studentas {
	string vardas;
	string pavarde;
	vector<double> ND;
	int NdSkaicius;
	int egzaminas;
	double vidurkis;

	double galutinis(int egzaminas, int NdSkaicius, vector<double> ND[]) {
		double ndSuma=0;
		double vidurkis;
		for (int i = 0; i < NdSkaicius; i++) {
			ndSuma =ndSuma+ND->at(i);
		}
		vidurkis = (egzaminas * 0.6) + (ndSuma * 0.4);
		return vidurkis;
	};

	double mediana(int egzaminas, int NdSkaicius, vector<double> ND[]) {
		double median;
		ND->resize(NdSkaicius+1);
		ND->back()=egzaminas;
		int i, j;
		bool swapped;
		for (int i = 0; i < NdSkaicius; i++) {
			swapped = false;
			for (int j = 0; j < ND->size() - 1; j++) {
				if (ND->at(j) > ND->at(j+1)) {
					swap(ND->at(j), ND->at(j+1));
					swapped = true;
				}
			}
		}

		int pazymiuSkaicius = ND->size();

		if ((pazymiuSkaicius) % 2 == 0) {
			double firstNumber = ND->at(pazymiuSkaicius/2-1);
			double secondNumber = ND->at((pazymiuSkaicius/2));
			median = ((firstNumber + secondNumber) / 2 );
		}

		else {
			for (int i = 0; i < pazymiuSkaicius/2; i++) {
				median = ND->at(i+1);
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

bool isValidCharacter(char a) {
	if (a == 't' || a == 'T' || a == 'n' || a == 'N') {
		return true;
	}
	else return false;
}

char inputChar() {
	char input;
	do {
		cin >> input;
		if (!isValidCharacter(input)) {
			cout << "Ivestas netinkamas simbolis! (prasome ivesti 't' arba 'n')" << endl;
		}
	} while (!isValidCharacter(input));
	return (input);
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
		sutikimas = inputChar();
		if (sutikimas == 'T' || sutikimas == 't') {
			cout << "Iveskite namu darbu skaiciu: ";
			studentas[studentuSkaicius].NdSkaicius = inputNumber();
			studentas[studentuSkaicius].ND.resize(studentas[studentuSkaicius].NdSkaicius);
		}
		else {
			cout << "Namu darbu skaicius jums bus automatiskai sugeneruotas, ar sutinkate? (Iveskite 'T', arba 'N')" << endl;

			sutikimas = inputChar();
			if (sutikimas == 'T' || sutikimas == 't') {
				studentas[studentuSkaicius].NdSkaicius = 1 + rand() % 10;
				cout << "Jusu sugeneruotas skaicius yra: " << studentas[studentuSkaicius].NdSkaicius << endl;
				studentas[studentuSkaicius].ND.resize(studentas[studentuSkaicius].NdSkaicius);
			}
			else {
				cout << "Iveskite namu darbu skaiciu: ";
				studentas[studentuSkaicius].NdSkaicius = inputNumber();
				studentas[studentuSkaicius].ND.resize(studentas[studentuSkaicius].NdSkaicius);

			}
		}
		cout << "Ar norite ivesti namu darbu rezultatus? Jei nenorite, iveskite 'N', ir jums rezultatai bus automatiskai sugeneruojami. (Iveskite tik 'T' arba 'N')" << endl;

		sutikimas = inputChar();

		if (sutikimas == 'n' || sutikimas == 'N') {
			for (int i = 0; i < studentas[studentuSkaicius].NdSkaicius; i++) {
				studentas[studentuSkaicius].ND.at(i) = (1 + rand() % 10);
				cout << studentas[studentuSkaicius].ND[i] << " ";

			}
			cout << endl;

		}

		else {
			for (int i = 0; i < studentas[studentuSkaicius].NdSkaicius; i++) {
				cout << i + 1 << " pazymys: ";
				studentas[studentuSkaicius].ND.at(i) = inputNumber();

			}
		}

		cout << "Ar norite ivesti egzamino rezultata? Jei nenorite, iveskite 'N' ir jums rezultatas bus automatiskai sugeneruojamas. (iveskite tik 'T', arba 'N')" << endl;
		sutikimas = inputChar();
		if (sutikimas == 'n' || sutikimas == 'N') {
			studentas[studentuSkaicius].egzaminas = 1 + rand() % 10;

		}
		else {
			cout << "Egzamino pazymys: ";
			studentas[studentuSkaicius].egzaminas = inputNumber();

		}
		cout << "Jusu egzamino rezultatas yra: " << studentas[studentuSkaicius].egzaminas << endl;
		cout << "Ar norite ivesti dar vieno studento duomenis?" << endl;
		sutikimas = inputChar();
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
		cout << left << setw(15) << "Vardas" << "Pavarde" << right << setw(35) << "galutinis (vid.)" << endl;
		for (int i = 0; i < studentuSkaicius; i++) {
			cout << "------------------------------------------------------------------------------------------" << endl;
			cout << left << setw(15) << studentas[i].vardas << studentas[i].pavarde;
			cout << right << setw(35) << studentas[i].galutinis(studentas[i].egzaminas, studentas[i].NdSkaicius, &studentas[i].ND) << endl;
		}
	}
	else {
		cout << left << setw(15) << "Vardas" << "Pavarde" << right << setw(50) << "mediana(med.)" << endl;
		for (int i = 0; i < studentuSkaicius; i++) {
			cout << "------------------------------------------------------------------------------------------" << endl;
			cout << left << setw(15) << studentas[i].vardas << studentas[i].pavarde;
			cout << right << setw(50) << setprecision(2) << studentas[i].mediana(studentas[i].egzaminas, studentas[i].NdSkaicius, &studentas[i].ND) << endl;
		}
	}
	return 0;
}
