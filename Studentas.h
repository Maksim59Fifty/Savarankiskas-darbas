#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <vector>
#include <string>

class Studentas {
private:
    std::string vardas, pavarde;
    std::vector<int> namu_darbai;
    int egzaminas;
    double galutinis_vidurkis;
    double galutinis_mediana;

public:
    Studentas(); // Konstruktorius
    ~Studentas(); // Destruktorius

    // Atsitiktinių balų generavimas
    void generuotiAtsitiktiniusDuomenis();

    // Galutinio balo skaičiavimas
    void skaiciuotiGalutiniusBalus();
    double skaiciuotiVidurki();
    double skaiciuotiMediana();

    // Duomenų išvedimas
    void spausdintiRezultata() const;

    // Failo duomenų įvedimas
    void nuskaitytiIsFailo(std::ifstream &in);

    // Pavardės gavimas
    std::string gautiPavarde() const;
};

#endif
