#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
    ifstream ulaz("datoteka.txt");
    if (!ulaz) { cout << "Greska pri otvaranju fajla"; return 1; }
    /*int broj, br = 0; vector<int> brojevi;
    while (ulaz >> broj) {
        brojevi.push_back(broj);
        ++br;
    }
    ulaz.close();
    int suma = 0;
    for (int i = 0; i < brojevi.size(); i++)
        suma += brojevi[i];
    double ars = (double)suma / br;
    cout << "Suma: " << suma << endl;
    cout << "Ars: " << ars << endl;
    ofstream izlaz("izlaz.txt");
    for (int br : brojevi)
        izlaz << br << " ";
    izlaz.close();*/
    string linija;
    size_t brojRedova = 0, brojReci = 0;
    while (getline(ulaz, linija)) {
        brojRedova++;
        istringstream ss(linija);
        string rec;
        while (ss >> rec) brojReci++;
    }
    cout << "Broj redova: " << brojRedova << endl;
    cout << "Broj reci: " << brojReci << endl;
    return 0;
}

