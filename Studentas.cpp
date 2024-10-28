#include "Studentas.h"
#include <random>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <stdexcept>

using namespace std;

Studentas::Studentas() : vardas(""), pavarde(""), egzaminas(0), galutinis_vidurkis(0.0), galutinis_mediana(0.0) {}
Studentas::~Studentas() {}

void Studentas::generuotiAtsitiktiniusDuomenis() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10);

    cout << "Įveskite studento vardą: ";
    cin >> vardas;
    cout << "Įveskite studento pavardę: ";
    cin >> pavarde;

    namu_darbai.clear();
    for (int i = 0; i < 5; ++i) {
        namu_darbai.push_back(dist(gen)); // Atsitiktiniai namų darbų balai
    }
    egzaminas = dist(gen); // Atsitiktinis egzamino balas
}

void Studentas::skaiciuotiGalutiniusBalus() {
    galutinis_vidurkis = skaiciuotiVidurki();
    galutinis_mediana = skaiciuotiMediana();
}

double Studentas::skaiciuotiVidurki() {
    if (namu_darbai.empty()) throw runtime_error("Nėra namų darbų balų");
    double suma = 0;
    for (int balas : namu_darbai) {
        suma += balas;
    }
    double vidurkis = suma / namu_darbai.size();
    return 0.4 * vidurkis + 0.6 * egzaminas;
}

double Studentas::skaiciuotiMediana() {
    if (namu_darbai.empty()) throw runtime_error("Nėra namų darbų balų");
    sort(namu_darbai.begin(), namu_darbai.end());
    double mediana;
    size_t size = namu_darbai.size();
    if (size % 2 == 0) {
        mediana = (namu_darbai[size / 2 - 1] + namu_darbai[size / 2]) / 2.0;
    } else {
        mediana = namu_darbai[size / 2];
    }
    return 0.4 * mediana + 0.6 * egzaminas;
}

void Studentas::spausdintiRezultata() const {
    cout << setw(15) << pavarde << setw(15) << vardas
         << setw(20) << fixed << setprecision(2) << galutinis_vidurkis
         << setw(20) << fixed << setprecision(2) << galutinis_mediana << endl;
}

void Studentas::nuskaitytiIsFailo(ifstream &in) {
    in >> pavarde >> vardas;
    namu_darbai.resize(5);
    for (int &nd : namu_darbai) {
        if (!(in >> nd)) throw runtime_error("Neteisingi namų darbų duomenys");
    }
    if (!(in >> egzaminas)) throw runtime_error("Neteisingi egzamino duomenys");
    skaiciuotiGalutiniusBalus();
}

std::string Studentas::gautiPavarde() const {
    return pavarde;
}
