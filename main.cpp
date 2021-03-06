#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::vector;
using std::invalid_argument;
using std::getline;
using std::to_string;
using std::setw;
using std::setprecision;
using std::fixed;
using std::left;

struct studentas {
    string Vardas;
    string Pavarde;
    int egzamino_rezultatas;
    float galutinis_rezultatas = 0;
    vector<int> nd_rezultatai;
    float mediana;
};

int random() {
    int randomNumber = rand() % 10 + 1;
    return randomNumber;
}

int patikrink_egzamino_pazymi(string skaicius_string) {
    while (true) {
        try {
            int ivestas_skaicius = stoi(skaicius_string);
            if (ivestas_skaicius > 0 & ivestas_skaicius <= 10) {
                return ivestas_skaicius;
            } else {
                cout << "Klaida! Skaicius nera tarp 1 ir 10. Pabandykite dar karta!" << endl;
                cin >> skaicius_string;
                continue;
            }
        }
        catch (invalid_argument &e) {
            cout << "Klaida! Jus ivedete ne skaiciu. Pabandykite dar karta!" << endl;
            cin >> skaicius_string;
            continue;
        }
    }
}

bool konvertuok_pazymius(string token) {
    bool tesk = false;
    int skaicius;
    try {
        skaicius = stoi(token);
        if (skaicius <= 0 | skaicius > 10) {
            cout << "Klaida pazymys  turi buti nuo 0 iki 10" << endl;
            tesk = true;
        }
    } catch (invalid_argument &e) {
        cout << "Klaida. Jus ivedete ne skaiciu. Pabandykite dar karta!" << endl;
        tesk = true;
    }
    return tesk;
}

vector<int> pazymiu_nuskaitymas() {
    vector<int> pazymiai;
    string delimiter = " ";
    size_t pos = 0;
    string token;
    string pazymiai_string;
    while (true) {
        int kiek = 0;
        bool tesk = true;
        cout << "Iveskite studento namu darbu rezultatus:" << endl;
        getline(cin >> std::ws, pazymiai_string);
        if (pazymiai_string.size() == 1) {
            cout << "Turi buti ivestas bent du pazymiai" << endl;
        } else {
            while ((pos = pazymiai_string.find(delimiter)) != string::npos) {
                token = pazymiai_string.substr(0, pos);
                tesk = konvertuok_pazymius(token);
                if (tesk) {
                    break;
                }
                pazymiai.push_back(stoi(token));
                pazymiai_string.erase(0, pos + delimiter.length());
                kiek++;
            }
            if (!tesk) {
                pazymiai.push_back(stoi(token));
                if (!konvertuok_pazymius(token)) {
                    return pazymiai;
                }
            }
        }
    }
}

float galutinisRezultatas(studentas st) {
    float galutinis_rezultatas = 0;
    float suma = 0;
    float vidurkis = 0;
    int nd_skaicius = st.nd_rezultatai.size();
    for (int i = 0; i < nd_skaicius; i++) {
        suma = suma + st.nd_rezultatai[i];
    }
    vidurkis = suma / nd_skaicius;
    galutinis_rezultatas = vidurkis * (float) 0.4 + st.egzamino_rezultatas * (float) 0.6;
    return galutinis_rezultatas;
}

float mediana(studentas st) {
    float mediana = 0;
    int size = st.nd_rezultatai.size();
    sort(st.nd_rezultatai.begin(), st.nd_rezultatai.end());
    if (size % 2 == 0) {
        mediana = ((st.nd_rezultatai[size / 2 - 1] + st.nd_rezultatai[size / 2]) / 2.0);
        return mediana;
    } else {
        mediana = st.nd_rezultatai[size / 2];
        return mediana;
    }
}

string ar_generuoti() {
    string klausimas;
    cout << "Ar norite, kad pazymiai ir egzamino rezultatas butu sugeneruotas atsitiktinai?" << endl
         << "(Iveskite taip arba ne)";
    cin >> klausimas;
    return klausimas;
}

int ivesti_nauja_studenta() {
    string atsakymas;
    cout << "Ar ivesti nauja studenta?Iveskite taip arba ne" << endl;
    while (true) {
        cin >> atsakymas;
        if (atsakymas == "Taip" || atsakymas == "taip" || atsakymas == "TAIP")
            return 1;
        else if (atsakymas == "ne" || atsakymas == "Ne" || atsakymas == "NE")
            return 0;
        else {
            cout << "Klaida. Iveskite taip arba ne." << endl;
            continue;
        }
    }
}

int sugeneruotu_pazymiu_kiekis() {
    string pazymiu_kiekis;
    cout << "Kiek pazymiu sugeneruoti?";
    while (true) {
        cin >> pazymiu_kiekis;
        try {
            if (!pazymiu_kiekis.find_first_not_of(" 0123456789")) {
                cout << "Klaida. Ivedete ne skaicius" << endl;
                continue;
            } else {
                int skaicius = stoi(pazymiu_kiekis);
                return skaicius;
            }
        } catch (invalid_argument &e) {
            cout << "Klaida. Ivedete ne skaicius. Pabandykite dar karta!" << endl;
        }
    }
}

vector<int> generuojami_skaiciai() {
    vector<int> nd_rezultatai;
    int pazymiu_kiekis = 0;
    while (true) {
        pazymiu_kiekis = sugeneruotu_pazymiu_kiekis();
        if (pazymiu_kiekis > 0 & pazymiu_kiekis < 100) {
            srand(time(NULL));
            for (int i = 0; i < pazymiu_kiekis; i++) {
                nd_rezultatai.push_back(random());
            }
            srand(time(NULL));
            return nd_rezultatai;
        } else {
            cout << "Skaicius turi buti didesnis uz 0 ir mazesnis nei 100" << endl;
        }
    }
}

vector<studentas> sukurti_ivesta_studenta(vector<studentas> studentai, struct studentas students) {
    studentai.push_back(students);
    return studentai;
}
vector<studentas> ivesti_studentai() {
    vector<studentas> studentai;
    studentai.reserve(1000000);
    studentas student;
    string skaicius_string;
    while (ivesti_nauja_studenta() == 1) {
        cout << "Iveskite studento varda, pavarde: " << endl;
        cin >> student.Vardas >> student.Pavarde;
        while (true) {
            string klausimas = ar_generuoti();
            if (klausimas == "ne" || klausimas == "Ne" || klausimas == "NE") {
                string egzaminas;
                student.nd_rezultatai = pazymiu_nuskaitymas();
                cout << "Iveskite egzamino rezultata: " << endl;
                cin >> skaicius_string;
                student.egzamino_rezultatas = patikrink_egzamino_pazymi(skaicius_string);
                student.galutinis_rezultatas = galutinisRezultatas(student);
                student.mediana = mediana(student);
                studentai = sukurti_ivesta_studenta(studentai, student);
                break;
            } else if (klausimas == "taip" || klausimas == "Taip" || klausimas == "TAIP") {
                student.nd_rezultatai = generuojami_skaiciai();
                student.egzamino_rezultatas = random();
                student.galutinis_rezultatas = galutinisRezultatas(student);
                student.mediana = mediana(student);
                studentai = sukurti_ivesta_studenta(studentai, student);
                break;
            } else {
                cout << "Klaida. " << endl;
                continue;
            }
        }
    }
    return studentai;
}

void informacijos_isvedimas(const vector<studentas> &studentai) {
    cout.width(20);
    cout << left << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis vidurkis"
         << setw(20) << "Galutine mediana" << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    for (auto st : studentai) {
        st.galutinis_rezultatas = galutinisRezultatas(st);
        st.mediana = mediana(st);
        cout.width(20);
        cout << st.Vardas << std::setw(20) << st.Pavarde << std::setw(20) << std::setprecision(2) << std::fixed
             << std::left << std::setw(20) <<
             st.galutinis_rezultatas << std::setw(20) << std::setprecision(2)
             << std::fixed
             << st.mediana << endl;
    }
}

int main() {
    vector<studentas> studentai = ivesti_studentai();
    informacijos_isvedimas(studentai);
}