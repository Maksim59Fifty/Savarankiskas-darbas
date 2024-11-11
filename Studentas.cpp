#include "Studentas.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <random>
#include <iostream>

void generuotiDuomenis(int kiekis, const std::string& failoPavadinimas) {
    std::ofstream out(failoPavadinimas);
    out << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde";
    for (int i = 1; i <= 15; ++i) {
        out << std::setw(10) << "ND" + std::to_string(i);
    }
    out << std::setw(10) << "Egz." << "\n";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);

    for (int i = 1; i <= kiekis; ++i) {
        std::string vardas = "Vardas" + std::to_string(i);
        std::string pavarde = "Pavarde" + std::to_string(i);
        out << std::setw(20) << vardas << std::setw(20) << pavarde;

        std::vector<int> nd_balai(15);
        for (int& nd : nd_balai) {
            nd = dist(gen);
            out << std::setw(10) << nd;
        }

        int egzaminas = dist(gen);
        out << std::setw(10) << egzaminas << "\n";
    }
    out.close();
}

void nuskaitytiDuomenis(const std::string& failoPavadinimas, std::vector<Student>& studentai) {
    std::ifstream in(failoPavadinimas);
    std::string eilute;
    std::getline(in, eilute);  // Pirma eilutė - antraštė, ją praleidžiame

    while (std::getline(in, eilute)) {
        std::istringstream ss(eilute);
        std::string vardas, pavarde;
        ss >> vardas >> pavarde;

        std::vector<int> nd_balai(15);
        for (int& nd : nd_balai) {
            ss >> nd;
        }

        int egzaminas;
        ss >> egzaminas;

        studentai.emplace_back(vardas, pavarde, nd_balai, egzaminas);
    }
    in.close();
}

double skaiciuotiGalutiniBala(const std::vector<int>& nd_balai, int egzaminas) {
    double ndVidurkis = std::accumulate(nd_balai.begin(), nd_balai.end(), 0.0) / nd_balai.size();
    return 0.4 * ndVidurkis + 0.6 * egzaminas;
}

void rusiavimas(const std::vector<Student>& studentai, std::vector<Student>& vargsiukai, std::vector<Student>& kietiakai) {
    for (const auto& studentas : studentai) {
        double galutinisBalas = skaiciuotiGalutiniBala(studentas.nd_balai, studentas.egzaminas);
        if (galutinisBalas < 5.0)
            vargsiukai.push_back(studentas);
        else
            kietiakai.push_back(studentas);
    }
}

void isvestiDuomenis(const std::string& failoPavadinimas, const std::vector<Student>& studentai) {
    std::ofstream out(failoPavadinimas);
    out << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde";
    for (int i = 1; i <= 15; ++i) {
        out << std::setw(10) << "ND" + std::to_string(i);
    }
    out << std::setw(10) << "Egz." << std::setw(10) << "Galutinis" << "\n";

    for (const auto& studentas : studentai) {
        out << std::setw(20) << studentas.vardas << std::setw(20) << studentas.pavarde;
        for (const auto& nd : studentas.nd_balai) {
            out << std::setw(10) << nd;
        }
        out << std::setw(10) << studentas.egzaminas;

        double galutinisBalas = skaiciuotiGalutiniBala(studentas.nd_balai, studentas.egzaminas);
        out << std::setw(10) << std::fixed << std::setprecision(2) << galutinisBalas << "\n";
    }
    out.close();
}
