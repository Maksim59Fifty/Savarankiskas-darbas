#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <vector>
#include <list>
#include <deque>
#include "Utils.h"

void generuotiDuomenis(int kiekis, const std::string& failoPavadinimas);
void nuskaitytiDuomenis(const std::string& failoPavadinimas, std::vector<Student>& studentai);
void nuskaitytiDuomenis(const std::string& failoPavadinimas, std::list<Student>& studentai);
void nuskaitytiDuomenis(const std::string& failoPavadinimas, std::deque<Student>& studentai);
double skaiciuotiGalutiniBala(const std::vector<int>& nd_balai, int egzaminas);
void rusiavimas(const std::vector<Student>& studentai, std::vector<Student>& vargsiukai, std::vector<Student>& kietiakai);
void rusiavimas(const std::list<Student>& studentai, std::list<Student>& vargsiukai, std::list<Student>& kietiakai);
void rusiavimas(const std::deque<Student>& studentai, std::deque<Student>& vargsiukai, std::deque<Student>& kietiakai);
void isvestiDuomenis(const std::string& failoPavadinimas, const std::vector<Student>& studentai);
void isvestiDuomenis(const std::string& failoPavadinimas, const std::list<Student>& studentai);
void isvestiDuomenis(const std::string& failoPavadinimas, const std::deque<Student>& studentai);

#endif
