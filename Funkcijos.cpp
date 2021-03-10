#include "Studentas.h"
#include <random>
#include <time.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <fstream>
#include <unistd.h>

static bool isInBoundaries(int number) {
	return number > 0 && number <= 10;
}

static bool isPositiveNumber(int number) {
	return number > 0 && number <= INT_MAX;
}

static bool isNumber(const string& s) {
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

static bool isValidNumber(string a) {
	return isNumber(a) && isInBoundaries(stoi(a));
}

static bool isMoreThan0(string a) {
	return isNumber(a) && isPositiveNumber(stoi(a));
}

static int inputNumber() {
	string input;
	do {
		cin >> input;
		if (!isValidNumber(input)) {
			cout << "Ivestas netinkamas simbolis! (Prasome ivesti skaiciu tarp 1 ir 10)" << endl;
		}
	} while (!isValidNumber(input));
	return stoi(input);
}

static int inputAllowedNumber() {
	string input;
	do {
		cin >> input;
		if (!isMoreThan0(input)) {
			cout << "Ivestas netinkamas simbolis! (Ivestas skaicius turi buti didesnis uz 1, taciau mazesnis uz 2147483647)" << endl;
		}
	} while (!isMoreThan0(input));
	return stoi(input);
}


static bool isValidCharacter(char a) {
	if (a == 't' || a == 'T' || a == 'n' || a == 'N') {
		return true;
	}
	else return false;
}

static char inputChar() {
	char input;
	do {
		cin >> input;
		if (!isValidCharacter(input)) {
			cout << "Ivestas netinkamas simbolis! (prasome ivesti 't' arba 'n')" << endl;
		}
	} while (!isValidCharacter(input));
	return (input);
}

static void inputData(Studentas studentas[], int& studentuSkaicius) {
	bool done = false;
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
}


static void ReadFile(Studentas studentas[], int& studentuSkaicius) {
	cout << "Studentu skaicius faile: ";
	studentuSkaicius = inputAllowedNumber();
	char file[]= "text.txt";
	int ndSkaicius = 0;
	try {
		ifstream fd(file);
		if (access(file, F_OK)!=0) {
			throw(file);
		}

			string vardas; string pavarde;
			fd >> vardas >> pavarde;
			string nd;
			do {
				fd >> nd;
				ndSkaicius++;
			} while (nd != "Egz.");
			for (int i = 0; i < studentuSkaicius; i++) {
				studentas[i].ND.resize(ndSkaicius - 1);
				studentas[i].NdSkaicius = studentas[i].ND.size();
				fd >> studentas[i].vardas;
				fd >> studentas[i].pavarde;
				for (int j = 0; j < studentas[i].NdSkaicius; j++) {
					fd >> studentas[i].ND.at(j);
				}
				fd >> studentas[i].egzaminas;
			}
			fd.close();
		}
		catch (char exception) {
		}

}

static void vidurkioSkaiciavimas(Studentas studentas[], int studentuSkaicius) {
	cout << left << setw(15) << "Vardas" << "Pavarde" << right << setw(35) << "galutinis (vid.)" << endl;
	for (int i = 0; i < studentuSkaicius; i++) {
		cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << left << setw(15) << studentas[i].vardas << studentas[i].pavarde;
		cout << right << setw(35) << studentas[i].galutinis(studentas[i].egzaminas, studentas[i].NdSkaicius, &studentas[i].ND) << endl;
	}
}

static void medianosSkaiciavimas(Studentas studentas[], int studentuSkaicius) {
	cout << left << setw(15) << "Vardas" << "Pavarde" << right << setw(35) << "mediana(med.)" << endl;
	for (int i = 0; i < studentuSkaicius; i++) {
		cout << "------------------------------------------------------------------------------------------" << endl;
		cout << left << setw(15) << studentas[i].vardas << studentas[i].pavarde;
		cout << right << setw(35) << setprecision(2) << studentas[i].mediana(studentas[i].egzaminas, studentas[i].NdSkaicius, &studentas[i].ND) << endl;
	}
}
static void visuDuomenuSkaiciavimas(Studentas studentas[], int studentuSkaicius) {
	cout << left << setw(15) << "Vardas" << "Pavarde" << right << setw(35) << "galutinis (vid.)" << right << setw(45) << "mediana(med.)" << endl;
	for (int i = 0; i < studentuSkaicius; i++) {
		cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << left << setw(15) << studentas[i].vardas << studentas[i].pavarde;
		cout << right << setw(35) << studentas[i].galutinis(studentas[i].egzaminas, studentas[i].NdSkaicius, &studentas[i].ND);
		cout << right << setw(45) << studentas[i].mediana(studentas[i].egzaminas, studentas[i].NdSkaicius, &studentas[i].ND) << endl;
	}
}
