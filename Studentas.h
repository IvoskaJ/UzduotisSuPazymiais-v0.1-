#pragma once
#include <iostream>
#include <string>
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
		double ndSuma = 0;
		double vidurkis;
		for (int i = 0; i < NdSkaicius; i++) {
			ndSuma = ndSuma + ND->at(i);
		}
		int ndRez = ndSuma / NdSkaicius;
		vidurkis = (egzaminas * 0.6) + (ndRez * 0.4);
		return vidurkis;
	};

	double mediana(int egzaminas, int NdSkaicius, vector<double> ND[]) {
		double median;
		ND->resize(NdSkaicius + 1);
		ND->back() = egzaminas;
		int i, j;
		bool swapped;
		for (int i = 0; i < NdSkaicius; i++) {
			swapped = false;
			for (int j = 0; j < ND->size() - 1; j++) {
				if (ND->at(j) > ND->at(j + 1)) {
					swap(ND->at(j), ND->at(j + 1));
					swapped = true;
				}
			}
		}

		int pazymiuSkaicius = ND->size();

		if ((pazymiuSkaicius) % 2 == 0) {
			double firstNumber = ND->at(pazymiuSkaicius / 2 - 1);
			double secondNumber = ND->at((pazymiuSkaicius / 2));
			median = ((firstNumber + secondNumber) / 2);
		}

		else {
			for (int i = 0; i < pazymiuSkaicius / 2; i++) {
				median = ND->at(i + 1);
			}
		}

		return median;
	}
};