#include <iostream>
#include <vector>
#include "Studentas.h"

int pasirinktasDydis() {
    int pasirinkimas;
    std::cout << "Pasirinkite studentų sąrašo dydį (1 - 1000, 2 - 10000, 3 - 100000, 4 - 1000000, 5 - 10000000): ";
    std::cin >> pasirinkimas;

    switch (pasirinkimas) {
        case 1: return 1000;
        case 2: return 10000;
        case 3: return 100000;
        case 4: return 1000000;
        case 5: return 10000000;
        default: 
            std::cout << "Netinkamas pasirinkimas! Pasirinktas dydis 1000." << std::endl;
            return 1000;
    }
}

int main() {
    int dydis = pasirinktasDydis();
    std::string failoPavadinimas = "studentai_" + std::to_string(dydis) + ".txt";

    // 1. Generuojame duomenų failą
    std::cout << "Generuojamas failas su " << dydis << " studentais...\n";
    generuotiDuomenis(dydis, failoPavadinimas);
    std::cout << "Failas " << failoPavadinimas << " sėkmingai sukurtas!\n";

    // 2. Nuskaitymas į vektorių
    std::vector<Student> studentai;
    nuskaitytiDuomenis(failoPavadinimas, studentai);

    // 3. Rūšiavimas į dvi kategorijas
    std::vector<Student> vargsiukai;
    std::vector<Student> kietiakai;
    rusiavimas(studentai, vargsiukai, kietiakai);

    // 4. Išvedimas į atskirus failus
    isvestiDuomenis("vargsiukai.txt", vargsiukai);
    isvestiDuomenis("kietiakai.txt", kietiakai);

    std::cout << "Failai su vargšiukais ir kietiakais sukurti!\n";

    return 0;
}
