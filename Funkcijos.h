#pragma once
#include "Studentas.h"
#include <random>
#include <time.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <chrono>
#include <fstream>

using namespace std::chrono;

bool isInBoundaries(int number) {
	return number > 0 && number <= 10;
}
bool isPositiveNumber(int number) {
	return number > 0 && number <= INT_MAX;
}
bool isNumber(const string& s) {
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}
bool isValidNumber(string a) {
	return isNumber(a) && isInBoundaries(stoi(a));
}
bool isMoreThan0(string a) {
	return isNumber(a) && isPositiveNumber(stoi(a));
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
int inputAllowedNumber() {
	string input;
	do {
		cin >> input;
		if (!isMoreThan0(input)) {
			cout << "Ivestas netinkamas simbolis! (Ivestas skaicius turi buti didesnis uz 1, taciau mazesnis uz 2147483647)" << endl;
		}
	} while (!isMoreThan0(input));
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
void inputData(vector<Studentas> &studentas, int& studentuSkaicius) {


	bool done = false;
	char sutikimas;
	studentas.resize(sizeof(Studentas));
	while (done == false) {
        studentas.resize((studentuSkaicius+1)*sizeof(Studentas));
        cout << studentas.size() << "<- cia dydis pries while loopa" << endl;
		cout << "Iveskite studento varda: ";
		cin >> studentas.at(studentuSkaicius).vardas;
		cout << "Iveskite studento pavarde: ";
		cin >> studentas.at(studentuSkaicius).pavarde;
		cout << "Ar studento atliktu namu darbu skaicius yra zinomas? (Iveskite 'T', arba 'N')" << endl;
		sutikimas = inputChar();
		if (sutikimas == 'T' || sutikimas == 't') {
			cout << "Iveskite namu darbu skaiciu: ";
			studentas.at(studentuSkaicius).NdSkaicius = inputNumber();
			studentas.at(studentuSkaicius).ND.resize(studentas.at(studentuSkaicius).NdSkaicius);
		}
		else {
			cout << "Namu darbu skaicius jums bus automatiskai sugeneruotas, ar sutinkate? (Iveskite 'T', arba 'N')" << endl;

			sutikimas = inputChar();
			if (sutikimas == 'T' || sutikimas == 't') {
				studentas.at(studentuSkaicius).NdSkaicius = 1 + rand() % 10;
				cout << "Jusu sugeneruotas skaicius yra: " << studentas.at(studentuSkaicius).NdSkaicius << endl;
				studentas.at(studentuSkaicius).ND.resize(studentas.at(studentuSkaicius).NdSkaicius);
			}
			else {
				cout << "Iveskite namu darbu skaiciu: ";
				studentas.at(studentuSkaicius).NdSkaicius = inputNumber();
				studentas.at(studentuSkaicius).ND.resize(studentas.at(studentuSkaicius).NdSkaicius);

			}
		}
		cout << "Ar norite ivesti namu darbu rezultatus? Jei nenorite, iveskite 'N', ir jums rezultatai bus automatiskai sugeneruojami. (Iveskite tik 'T' arba 'N')" << endl;

		sutikimas = inputChar();

		if (sutikimas == 'n' || sutikimas == 'N') {
			for (int i = 0; i < studentas.at(studentuSkaicius).NdSkaicius; i++) {
				studentas.at(studentuSkaicius).ND.at(i) = (1 + rand() % 10);
				cout << studentas.at(studentuSkaicius).ND[i] << " ";

			}
			cout << endl;

		}

		else {
			for (int i = 0; i < studentas.at(studentuSkaicius).NdSkaicius; i++) {
				cout << i + 1 << " pazymys: ";
				studentas.at(studentuSkaicius).ND.at(i) = inputNumber();

			}
		}

		cout << "Ar norite ivesti egzamino rezultata? Jei nenorite, iveskite 'N' ir jums rezultatas bus automatiskai sugeneruojamas. (iveskite tik 'T', arba 'N')" << endl;
		sutikimas = inputChar();
		if (sutikimas == 'n' || sutikimas == 'N') {
			studentas.at(studentuSkaicius).egzaminas = 1 + rand() % 10;

		}
		else {
			cout << "Egzamino pazymys: ";
			studentas.at(studentuSkaicius).egzaminas = inputNumber();

		}
		cout << "Jusu egzamino rezultatas yra: " << studentas.at(studentuSkaicius).egzaminas << endl;
		cout << "Ar norite ivesti dar vieno studento duomenis? ( iveskite T, jeigu norite toliau ivedineti duomenis, ivedus N, programa isves jusu rezultatus). " << endl;
		sutikimas = inputChar();
		if (sutikimas == 't' || sutikimas == 'T') {
			done = false;
		}
		else {
			done = true;
		}
		studentuSkaicius++;

	}
	studentas.resize(studentuSkaicius*sizeof(Studentas));
}
void ReadFile(vector<Studentas> &studentas, int& studentuSkaicius) {


	string file;
	cout << "Iveskite failo pavadinima (failo pavadinimas turi buti irasomas su '.txt'): ";
	cin >> file;
	cout << "Studentu skaicius faile: ";
	studentuSkaicius = inputAllowedNumber();
	cout << endl;
	studentas.resize(studentuSkaicius*sizeof(Studentas));

	int ndSkaicius = 0;
	try {
		ifstream fd;
		fd.open(file);
		if (!fd.is_open()) {
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
			studentas.at(i).ND.resize(ndSkaicius - 1);
			studentas.at(i).NdSkaicius = studentas.at(i).ND.size();
			fd >> studentas.at(i).vardas;
			fd >> studentas.at(i).pavarde;
			try {
				for (int j = 0; j < studentas.at(i).NdSkaicius; j++) {
					fd >> studentas.at(i).ND.at(j);
					if (studentas.at(i).ND.at(j) < 1 || studentas.at(i).ND.at(j) > 10) { throw(studentas.at(i).ND.at(j)); }
				}
				fd >> studentas.at(i).egzaminas;
				if(studentas.at(i).egzaminas<1 || studentas.at(i).egzaminas > 10) {throw(studentas.at(i).egzaminas);}
			}
			catch (double exception) {
				cout << "faile yra ivestas netinkamas skaicius, prasome patikrinti ar visi ivesti skaiciai yra didesni uz tarp 1 ir 10!" << endl;
				break;
			}
		}
		fd.close();
	}
	catch (string exception) {
		cout << "nerastas failas, programa uzdaroma" << endl;
		terminate;
	}

}
void vidurkioSkaiciavimas(vector<Studentas> &studentas, int studentuSkaicius, string file) {

	ofstream fr;
	fr.open(file);
	fr << left << setw(15) << "Vardas" << "Pavarde" << right << setw(30) << "galutinis (vid.)" << endl;
	for (int i = 0; i < studentuSkaicius; i++) {
        if(studentas.at(i).NdSkaicius == NULL) studentas.at(i).NdSkaicius = 10;
		fr << left << setw(15) << studentas.at(i).vardas << studentas.at(i).pavarde;
		fr << right << setw(30) << studentas.at(i).galutinis(studentas.at(i).egzaminas, studentas.at(i).NdSkaicius, &studentas.at(i).ND) << endl;
	}
	fr.close();
}
void medianosSkaiciavimas(vector<Studentas> &studentas, int studentuSkaicius, string file) {
	ofstream fr;
	fr.open(file);
	fr << left << setw(15) << "Vardas" << "Pavarde" << right << setw(30) << "mediana(med.)" << endl;
	for (int i = 0; i < studentuSkaicius; i++) {
        if(studentas.at(i).NdSkaicius == NULL) studentas.at(i).NdSkaicius = 10;
		fr << left << setw(15) << studentas.at(i).vardas << studentas.at(i).pavarde;
		fr << right << setw(30) << setprecision(2) << studentas.at(i).mediana(studentas.at(i).egzaminas, studentas.at(i).NdSkaicius, &studentas.at(i).ND) << endl;
	}
	fr.close();
}
void visuDuomenuSkaiciavimas(vector<Studentas> &studentas, int studentuSkaicius, string file) {
	ofstream fr;
	fr.open(file);
	fr << left << setw(20) << "Vardas" << "Pavarde" << right << setw(35) << "galutinis (vid.)" << right << setw(35) << "mediana(med.)" << endl;
	for (int i = 0; i < studentuSkaicius; i++) {
        if(studentas.at(i).NdSkaicius == NULL) studentas.at(i).NdSkaicius = 10;
		fr << left << setw(20) << studentas.at(i).vardas << studentas.at(i).pavarde;
		fr << right << setw(30) << studentas.at(i).galutinis(studentas.at(i).egzaminas, studentas.at(i).NdSkaicius, &studentas.at(i).ND);
		fr << right << setw(30) << studentas.at(i).mediana(studentas.at(i).egzaminas, studentas.at(i).NdSkaicius, &studentas.at(i).ND) << endl;
	}
	fr.close();
}
void rankinisGeneravimas(vector<Studentas> studentas, int studentuSkaicius, char sutikimas){
    cout << "Jeigu norite ivesti studentu duomenis, iveskite T, jeigu nenorite spauskite n, ir studentu duomenys bus paiimti is tekstinio failo 'kursiokai'.(Iveskite tik 'T' arba 'N')" << endl;
	sutikimas = inputChar();
	string file = "rezultatai.txt";
	if (sutikimas == 'N' || sutikimas == 'n') {
		ReadFile(studentas, studentuSkaicius);
	    }

	else {
		inputData(studentas, studentuSkaicius);
	}
	cout << "Jeigu norite pamatyti studento pazymiu vidurki: iveskite V, jei norite pamatyti studento pazymiu mediana: iveskite M, jei norite pamatyti abu rezultatus, iveskite A." << endl;
	do {
		cin >> sutikimas;
		if (sutikimas == 'a' && sutikimas == 'A' && sutikimas == 'm' && sutikimas == 'M' && sutikimas == 'v' && sutikimas == 'V') {
			cout << "prasome ivesti tinkama simboli! (a - abiems reiksmems, m - tik medianai, v - vidurkiui)" << endl;
		}
	} while (sutikimas == 'a' && sutikimas == 'A' && sutikimas == 'm' && sutikimas == 'M' && sutikimas == 'v' && sutikimas == 'V');

	if (sutikimas == 'a' || sutikimas == 'A') {
		visuDuomenuSkaiciavimas(studentas, studentuSkaicius, file);
	}
	else if (sutikimas == 'V' || sutikimas == 'v') {
		vidurkioSkaiciavimas(studentas, studentuSkaicius, file);
	}
	else {
		medianosSkaiciavimas(studentas, studentuSkaicius, file);
	}
	cout << "jusu rezultatai yra isvesti i textini faila 'rezultatai' " << endl;
}
void generateFiles(int studentuSkaicius){
    auto start = high_resolution_clock::now();
    ofstream fr;
    string studentuKiekisFaile = to_string(studentuSkaicius);
    string file = studentuKiekisFaile + ".txt";
    fr.open(file);
    fr <<setw(15) << left << "vardas" << setw(15) << left <<  " pavarde";
    for (int i=0; i<10; i++){
        fr << setw(9) << right <<  "ND" << i+1;
    }
    fr << setw(10) << right <<  "Egz." << endl;
    for(int i=0; i<studentuSkaicius; i++){
    string indeksas = to_string(i+1);
    fr << setw(15) <<  left << "Vardas" + indeksas << setw(15) << left << "Pavarde" + indeksas;
    for (int j=0; j<10; j++){

        fr << setw(10) << right << 1 + rand() % 10;
    }
    fr << setw(10) << right << 1 + rand() % 10 << endl;
    }
    fr.close();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start)*1.0/1000000;
    cout << "failo generavimas uztruko: " << duration.count() << endl;
}
void workWithGeneratedFile(int studentuSkaicius){

    vector<Studentas> studentas;
    vector<Studentas> dundukas;
	vector<Studentas> malacius;
    string file;
    string studentuSkaiciusFaile = to_string(studentuSkaicius);
    ifstream fd(studentuSkaiciusFaile + ".txt");
    string vardas; string pavarde; string nd; string egz;
    auto start = high_resolution_clock::now();
    fd >> vardas >> pavarde;
    for (int i = 0; i<10; i++) fd >> nd;
    fd >> egz;
    studentas.resize(studentuSkaicius);
    for(int i=0; i<studentuSkaicius; i++){
        fd >> studentas.at(i).vardas >> studentas.at(i).pavarde;

        for (int j = 0; j<10; j++){
            int temp;
            fd >> temp;
            studentas.at(i).ND.push_back(temp);
        }
        fd >> studentas.at(i).egzaminas;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start)*1.0/1000000;

    cout << "studento duomenu is sugeneruoto failo nuskaitymas uztruko: " << duration.count() << endl;

    fd.close();
    int malaciuSkaicius=0;
    int dundukuSkaicius=0;
    start = high_resolution_clock::now();
    for (int i=0; i<studentas.size(); i++){
            if(studentas.at(i).galutinis(studentas.at(i).egzaminas,10, &studentas.at(i).ND)>=5){
            malacius.push_back(studentas.at(i));
            malaciuSkaicius++;
            studentas.erase(studentas.begin()+i);
            }
            else {
                dundukas.push_back(studentas.at(i));
                dundukuSkaicius++;
                studentas.erase(studentas.begin()+i);
            }
    }
    studentas.clear();

    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start)*1.0/1000000;

    cout << "studento duomenu is sugeneruoto failo paskirstymas i dvi grupes uztruko: " << duration.count() << endl;

    start = high_resolution_clock::now();

    file = studentuSkaiciusFaile + "dundukai.txt";
    visuDuomenuSkaiciavimas(dundukas, dundukuSkaicius, file);

	dundukas.clear();
	dundukas.resize(0);

   file = studentuSkaiciusFaile + "malaciai.txt";

    visuDuomenuSkaiciavimas(malacius, malaciuSkaicius, file);

	malacius.clear();
	malacius.resize(0);

    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start)*1.0/1000000;

    cout << "Studentu paskirstytu i dvi grupes duomenu failu generavimas uztruko: " << duration.count() << endl;

}
