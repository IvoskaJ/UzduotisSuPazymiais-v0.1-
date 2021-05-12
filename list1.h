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
#include <list>
#include <iterator>

using namespace std::chrono;

void visuDuomenuSkaiciavimas(list<Studentas>& studentas, int studentuSkaicius, string file) {
    ofstream fr;
    fr.open(file);
    fr << left << setw(20) << "Vardas" << "Pavarde" << right << setw(35) << "galutinis (vid.)" << right << setw(35) << "mediana(med.)" << endl;
    list<Studentas>::iterator it;
    for (it = studentas.begin(); it != studentas.end(); it++) {
        fr << left << setw(20) << it->vardas << it->pavarde;
        fr << right << setw(30) << it->galutinis(it->egzaminas, 10, &it->ND);
        fr << right << setw(30) << it->mediana(it->egzaminas, 10, &it->ND) << endl;
    }
    fr.close();
}

void workWithGeneratedFile(int studentuSkaicius) {

    list<Studentas> studentai;
    list<Studentas> dundukas;
    list<Studentas> malacius;
    string file;
    string studentuSkaiciusFaile = to_string(studentuSkaicius);
    ifstream fd(studentuSkaiciusFaile + "studentu.txt");
    string vardas; string pavarde; string nd; string egz;
    auto start = high_resolution_clock::now();

    fd >> vardas >> pavarde;
    for (int i = 0; i < 10; i++) fd >> nd;
    fd >> egz;
    for (int i = 0; i < studentuSkaicius; i++) {
        Studentas studentas;
        fd >> studentas.vardas >> studentas.pavarde;

        for (int j = 0; j < 10; j++) {
            int temp;
            fd >> temp;
            studentas.ND.push_back(temp);
        }
        fd >> studentas.egzaminas;

        studentai.push_back(studentas);
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start) * 1.0 / 1000000;

    cout << "studento duomenu is sugeneruoto failo nuskaitymas uztruko: " << duration.count() << endl;

    fd.close();
    start = high_resolution_clock::now();
    cout << studentai.size();
    list<Studentas>::iterator it;
    for (it = studentai.begin(); it != studentai.end(); it++) {
        if (it->galutinis(it->egzaminas, 10, &it->ND) >= 5) {
            malacius.push_back(*it);
        }
        else {
            dundukas.push_back(*it);
        }
    }
    studentai.clear();

    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start) * 1.0 / 1000000;

    cout << "studento duomenu is sugeneruoto failo paskirstymas i dvi grupes uztruko: " << duration.count() << endl;

    start = high_resolution_clock::now();

    file = studentuSkaiciusFaile + "dundukai.txt";
    visuDuomenuSkaiciavimas(dundukas, dundukas.size(), file);

    dundukas.clear();


    file = studentuSkaiciusFaile + "malaciai.txt";

    visuDuomenuSkaiciavimas(malacius, malacius.size(), file);

    malacius.clear();

    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start) * 1.0 / 1000000;

    cout << "Studentu paskirstytu i dvi grupes duomenu failu generavimas uztruko: " << duration.count() << endl;

}
