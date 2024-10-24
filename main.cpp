#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // setprecision

using namespace std;

class Studentas {
    string vardas, pavarde;
    vector<int> namu_darbai;
    int egzaminas;
    double galutinis;

public:
    // Konstruktorius
    Studentas() : vardas(""), pavarde(""), egzaminas(0), galutinis(0.0) {}

    // Destruktorius
    ~Studentas() {}

    // Kopijavimo konstruktorius
    Studentas(const Studentas& kitas) {
        vardas = kitas.vardas;
        pavarde = kitas.pavarde;
        namu_darbai = kitas.namu_darbai;
        egzaminas = kitas.egzaminas;
        galutinis = kitas.galutinis;
    }

    // Priskyrimo operatorius
    Studentas& operator=(const Studentas& kitas) {
        if (this != &kitas) {
            vardas = kitas.vardas;
            pavarde = kitas.pavarde;
            namu_darbai = kitas.namu_darbai;
            egzaminas = kitas.egzaminas;
            galutinis = kitas.galutinis;
        }
        return *this;
    }

    // Duomenų įvedimas
    void ivestiDuomenis() {
        cout << "Įveskite studento vardą: ";
        cin >> vardas;
        cout << "Įveskite studento pavardę: ";
        cin >> pavarde;

        int balas;
        cout << "Įveskite namų darbų balus (spauskite -1, kad baigtumėte įvesti): ";
        while (true) {
            cin >> balas;
            if (balas == -1) break;
            namu_darbai.push_back(balas);
        }

        cout << "Įveskite egzamino balą: ";
        cin >> egzaminas;
    }

    // Galutinio balo skaičiavimas (vidurkis arba mediana)
    double skaiciuotiGalutini(bool naudoti_medianai) {
        if (naudoti_medianai) {
            return skaiciuotiMediana();
        } else {
            return skaiciuotiVidurki();
        }
    }

    // Vidurkio skaičiavimas
    double skaiciuotiVidurki() {
        double suma = 0;
        for (int balas : namu_darbai) {
            suma += balas;
        }
        double vidurkis = suma / namu_darbai.size();
        galutinis = 0.4 * vidurkis + 0.6 * egzaminas;
        return galutinis;
    }

    // Medianos skaičiavimas
    double skaiciuotiMediana() {
        sort(namu_darbai.begin(), namu_darbai.end());
        double mediana;
        size_t size = namu_darbai.size();
        if (size % 2 == 0) {
            mediana = (namu_darbai[size / 2 - 1] + namu_darbai[size / 2]) / 2.0;
        } else {
            mediana = namu_darbai[size / 2];
        }
        galutinis = 0.4 * mediana + 0.6 * egzaminas;
        return galutinis;
    }

    // Duomenų išvedimas
    void spausdintiRezultata() const {
        cout << setw(15) << pavarde << setw(15) << vardas 
             << setw(20) << fixed << setprecision(2) << galutinis << endl;
    }
};

int main() {
    Studentas studentas;

    studentas.ivestiDuomenis();
    char pasirinkimas;
    cout << "Naudoti medianą galutiniam balui skaičiuoti? (y/n): ";
    cin >> pasirinkimas;

    double galutinis = studentas.skaiciuotiGalutini(pasirinkimas == 'y');
    cout << "Pavardė          Vardas         Galutinis (Vid./Med.)" << endl;
    cout << "--------------------------------------------------" << endl;
    studentas.spausdintiRezultata();

    return 0;
}
