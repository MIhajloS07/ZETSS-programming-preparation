#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// IDEJA
// prolazak kroz naslove pesme pa uporedjivanje da li postoji takav string u recima pesme i ako postoji onda pogodjene reci povecamo kroz neki 
// brojac i na kraju ukoliko je taj broj veci ili jednak od upolaBrojReci onda ispisujemo tacno indeks + 1 reci gde je pogodjeno

void ogranicenje(const string& rec) {
    if (rec.size() > 15) 
        exit(1);
    for (char ch : rec)
        if (!islower(ch)) 
            exit(1);
}

int main()
{
    int n; // broj reci u naslovu pesme
	cin >> n;
    if (n < 1 || n > 50) return 1;
    vector<string> reciNaslovaPesme(n);
    // PRVI RED ULAZA
    for (int i = 0; i < n; i++)
    {
        cin >> reciNaslovaPesme[i];
		// svaka rec mora biti mala i ne sme biti duza od 15 karaktera
        ogranicenje(reciNaslovaPesme[i]);
	}
    // DRUGI RED ULAZA
    int m; // broj reci u tekstu pesme
    cin >> m;
    if (m < 1 || m > 10000) return 1;
    vector<string> reciPesme(m);
    for (int i = 0; i < m; i++) {
        cin >> reciPesme[i];
        // svaka rec mora biti mala i ne sme biti duza od 15 karaktera
        ogranicenje(reciPesme[i]);
    }
    size_t pogodjeneReci = 0;
    vector<bool> vecPogodjena(n, false);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!vecPogodjena[j] && reciPesme[i] == reciNaslovaPesme[j]) {
                pogodjeneReci++;
                vecPogodjena[j] = true;
            }
        }
        // IZLAZ
        if (pogodjeneReci >= (size_t)(n + 1) / 2) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    return 0;
}

