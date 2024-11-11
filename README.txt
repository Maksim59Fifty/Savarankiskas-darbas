Studentų Sąrašas V0.1

Ši programa leidžia generuoti atsitiktinius studentų duomenis arba nuskaityti juos iš failo "kursiokai.txt". Programa apskaičiuoja ir išveda kiekvieno studento galutinį balą pagal namų darbų ir egzamino rezultatus, apskaičiuojant vidurkį ir medianą.

Naudojimosi instrukcijos:

Pavyksta pasirinkti, ar generuoti atsitiktinius duomenis (paspaudus g) ar nuskaityti iš failo kursiokai.txt (paspaudus f).
Jei pasirenkama atsitiktinių duomenų generavimas, programa prašo įvesti studentų skaičių ir kiekvienam studentui atsitiktinai sugeneruoja vardą, pavardę, namų darbų rezultatus ir egzamino balą.
Jei pasirenkama nuskaityti iš failo, programa skaito studentų duomenis iš failo kursiokai.txt.


Programos funkcionalumas:

Studentų rūšiavimas pagal pavardę: Programa surūšiuoja studentų sąrašą pagal pavardes.
Galutinių balų skaičiavimas:
Galutinis balas apskaičiuojamas dviem būdais – kaip vidurkis ir kaip mediana, naudojant formulę: 0.4 * namų darbų vidurkis + 0.6 * egzaminas.
Galutinio balo vidurkis ir mediana pateikiami šalia studento vardo ir pavardės.


Programos failų struktūra:

main.cpp:

Aprašo pagrindinę programos logiką:
Vartotojas gali pasirinkti, ar generuoti duomenis, ar skaityti iš failo.
Programa apdoroja studentų duomenis, iškviesdama klasių ir funkcijų metodus, ir surūšiuoja sąrašą pagal pavardes.
Galiausiai išvedami studentų vardai, pavardės ir galutiniai balai (vidurkis ir mediana).

Studentas.h:

Aprašo Studentas klasę, kurioje yra studento duomenų laukai:
vardas, pavarde – studento vardas ir pavardė.
namu_darbai – vektorius, skirtas namų darbų rezultatams saugoti.
egzaminas – egzamino balas.
galutinis_vidurkis ir galutinis_mediana – galutiniai balai (vidurkis ir mediana), apskaičiuoti pagal namų darbų ir egzamino rezultatus.

Studentas.cpp:

Aprašo metodus, kurie apdoroja studento duomenis:
generuotiAtsitiktiniusDuomenis: sugeneruoja studento vardą, pavardę ir atsitiktinius balus.
skaiciuotiGalutiniusBalus: apskaičiuoja galutinius balus, iškviesdamas metodus skaiciuotiVidurki ir skaiciuotiMediana.
skaiciuotiVidurki: apskaičiuoja galutinį balą pagal vidurkį.
skaiciuotiMediana: apskaičiuoja galutinį balą pagal medianą.
spausdintiRezultata: išveda vieno studento rezultatus (pavardę, vardą, galutinį balą pagal vidurkį ir medianą).
nuskaitytiIsFailo: nuskaito studento duomenis iš failo.

kursiokai.txt
Failas su pradiniais studentų duomenimis: kiekviena eilutė turi studento pavardę, vardą, penkis namų darbų rezultatus ir egzamino balą.
Reikalavimai
Ši programa naudoja C++ STL bibliotekas, tokias kaip <vector>, <iostream>, <fstream>, <algorithm>, <random>, ir <iomanip>.

Norint paleisti programą, rekomenduojama naudoti C++11 arba naujesnę versiją(Rekomenduoju naudoti Replit'o kompiliatoriu).

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Studentų Sąrašas V0.2

Ši versija patobulinta, kad galėtų apdoroti daug didesnius duomenų kiekius ir leistų duomenis tvarkyti skirtinguose konteineriuose (pvz., vector, list, deque). Programa generuoja studentų duomenų failą su pasirinktu skaičiumi studentų, nuskaito duomenis, apskaičiuoja galutinį balą pagal namų darbų ir egzamino rezultatus, o po to studentus suskirsto į „vargšiukus“ ir „kietiakus“ pagal pasiektus balus.

Naudojimosi instrukcijos

Studentų skaičiaus pasirinkimas: Pirmiausia vartotojas pasirenka norimą studentų kiekį (nuo 1000 iki 10 milijonų). Atsižvelgiant į šį pasirinkimą, sugeneruojamas duomenų failas su studentų vardais, pavardėmis, namų darbų rezultatais ir egzamino balu.

Studentų duomenų generavimas ir skirstymas:

Programa automatiškai sugeneruoja studentų duomenų failą pagal pasirinktą skaičių.
Vėliau duomenys iš failo nuskaitomi į pasirinkto tipo konteinerį (vector, list, arba deque), kur apskaičiuojamas kiekvieno studento galutinis balas.
Studentų skirstymas į kategorijas:

Pagal galutinį balą studentai suskirstomi į „vargšiukus“ (balas < 5.0) ir „kietiakus“ (balas ≥ 5.0).
Rezultatai įrašomi į atskirus failus: vargsiukai.txt ir kietiakai.txt.

Programos funkcionalumas

Duomenų generavimas ir failo kūrimas: Programa sukuria atsitiktinių duomenų failą su studentų vardais, pavardėmis, 15 namų darbų rezultatų ir egzamino balu.


Studentų duomenų nuskaitymas ir rūšiavimas: Nuskaityti duomenys laikomi vector, list arba deque konteineryje, priklausomai nuo poreikio, o studentai rūšiuojami pagal jų galutinį balą.

Galutinis balas apskaičiuojamas formule: 0.4 * namų darbų vidurkis + 0.6 * egzaminas.

Rezultatų skirstymas ir išvedimas: Studentai suskirstomi į kategorijas ir jų rezultatai išvedami į atskirus failus.


Studentų Sąrašas V.1(90% pabaigta): Nuo praeitos versijos nėra skirtumo

naudojama 1 strategija: Bendro studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų". Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų (vargšiukai arba kietiakai). Nesunku pastebėti, kad tokia strategija yra neefektyvi užimamos atminties atžvilgiu (įsitikinkite tuo!), tačiau šiame žingsnyje svarbiausia yra patyrinėti, kaip programos veikimo sparta priklauso nuo konteinerio tipo?

beliko pabaigti cmake CMakeLists.txt padaryti.