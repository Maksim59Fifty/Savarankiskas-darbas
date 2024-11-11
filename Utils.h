#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

class Student {
public:
  std::string vardas;
  std::string pavarde;
  std::vector<int> nd_balai;
  int egzaminas;

  Student(const std::string &v, const std::string &p,
          const std::vector<int> &nd, int egz)
      : vardas(v), pavarde(p), nd_balai(nd), egzaminas(egz) {}
};

#endif
