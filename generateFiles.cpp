#include <fstream>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

void generateFiles(int studentuSkaicius) {
    ofstream fr;
    string studentuKiekisFaile = to_string(studentuSkaicius);
    string file = studentuKiekisFaile + "studentu" + ".txt";
    fr.open(file);
    fr << setw(15) << left << "vardas" << setw(15) << left << " pavarde";
    for (int i = 0; i < 10; i++) {
        fr << setw(9) << right << "ND" << i + 1;
    }
    fr << setw(10) << right << "Egz." << endl;
    for (int i = 0; i < studentuSkaicius; i++) {
        string indeksas = to_string(i + 1);
        fr << setw(15) << left << "Vardas" + indeksas << setw(15) << left << "Pavarde" + indeksas;
        for (int j = 0; j < 10; j++) {

            fr << setw(10) << right << 1 + rand() % 10;
        }
        fr << setw(10) << right << 1 + rand() % 10 << endl;
    }
    fr.close();
}

int main() {

    for (int i = 1000; i <= 10000000; i = i * 10) {
        auto start = high_resolution_clock::now();
        string studentuSkaiciusPaduodamasFailui = to_string(i);
        cout << "generuojamas failas su" << " " << studentuSkaiciusPaduodamasFailui << " studentu." << endl;
        generateFiles(i);
        cout << "failas uzdaromas, tesiama su 10 kartu didesniu failu." << endl;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start) * 1.0 / 1000000;

        cout << i << "failo kurimas uztruko: " << duration.count() << endl;
    }

}
