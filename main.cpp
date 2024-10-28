#include "Studentas.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdexcept>

using namespace std;

// Rūšiuoti pagal pavardę
bool lygintiPavarde(const Studentas &a, const Studentas &b) {
    return a.gautiPavarde() < b.gautiPavarde();
}

int main() {
    vector<Studentas> studentai;
    char pasirinkimas;
    cout << "Norite generuoti atsitiktinius duomenis (g) ar nuskaityti iš failo (f)? (g/f): ";
    cin >> pasirinkimas;

    try {
        if (pasirinkimas == 'g') {
            int studentu_skaicius;
            cout << "Įveskite studentų skaičių: ";
            cin >> studentu_skaicius;

            for (int i = 0; i < studentu_skaicius; ++i) {
                Studentas studentas;
                studentas.generuotiAtsitiktiniusDuomenis();
                studentas.skaiciuotiGalutiniusBalus();
                studentai.push_back(studentas);
            }
        } else if (pasirinkimas == 'f') {
            ifstream in("kursiokai.txt");
            if (!in) throw runtime_error("Nepavyko atidaryti failo kursiokai.txt");

            while (!in.eof()) {
                Studentas studentas;
                studentas.nuskaitytiIsFailo(in);
                studentai.push_back(studentas);
            }
            in.close();
        }

        // Surūšiuoti studentus pagal pavardes
        sort(studentai.begin(), studentai.end(), lygintiPavarde);

        // Išvedimas
        cout << "Pavardė          Vardas         Galutinis (Vid.)   Galutinis (Med.)" << endl;
        cout << "------------------------------------------------------------------" << endl;
        for (const Studentas &studentas : studentai) {
            studentas.spausdintiRezultata();
        }

    } catch (const exception &e) {
        cerr << "Klaida: " << e.what() << endl;
    }

    return 0;
}
