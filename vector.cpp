#include "vector.h"
#include <chrono>
#pragma GCC optimize("Ofast")
using namespace std;

int main() {
	time_t t;
	srand((unsigned)time(&t));
	vector<Studentas> *studentas = new vector<Studentas>;
	char sutikimas;
	int studentuSkaicius = 0;

    cout << "jei norite patys pasirinkti duomenis iveskite t, o jei norite kad duomenys butu automatiskai sugeneruojami ir isskirstomi pagal studentu gabumus, iveskite n." << endl;
    sutikimas = inputChar();
    if(sutikimas == 't' || sutikimas == 'T'){
	rankinisGeneravimas(*studentas,studentuSkaicius, sutikimas);
    }
    else {
    for (int i=1000; i<=10000000; i=i*10){
        workWithGeneratedFile(i);
        cout << "failas uzdaromas, tesiama su 10 kartu didesniu failu." << endl;
    }
    }
	return 0;
}
