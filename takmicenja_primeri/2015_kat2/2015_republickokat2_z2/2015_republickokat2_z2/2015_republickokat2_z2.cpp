#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> frekvencija(const string& str) {
	vector<int> freq(26, 0);
    for (char c : str)
        freq[c - 'A']++;
    return freq;
}

int nedostajuSlova(const vector<int>& baza, const vector<int>& rec) {
    int nedostaje = 0;
    for (int i = 0; i < 26; i++) 
        if (rec[i] > baza[i]) 
            nedostaje += rec[i] - baza[i];
    return nedostaje;
	// Ova funkcija racuna koliko slova nedostaje da bi se formirala rec iz baze.
}

int main()
{
    vector<string> ponudjeneReci(10);
    string besmislenaRec;

    // ULAZ
	cin >> besmislenaRec;
    for (int i = 0; i < 10; i++) cin >> ponudjeneReci[i];

    // OGRANCENJE
    for (const string& rec : ponudjeneReci) {
        if (rec.size() > 20) return 1;
    }

	vector<int> fbesmislena = frekvencija(besmislenaRec);

	int najbolja = 0; // duzina najbolje reci
	int minNedostaje = 100; // minimalan broj nedostajucih slova 

    for (const string& s : ponudjeneReci) {
		vector<int> f = frekvencija(s);
        int nedostaje = nedostajuSlova(fbesmislena, f);
        if (nedostaje == 0) {
            najbolja = max(najbolja, (int)s.size());
        }
        else {
			minNedostaje = min(minNedostaje, nedostaje);    
        }
    }

    if (najbolja == 0) {
        for (string s : ponudjeneReci) {
            vector<int> f = frekvencija(s);
            int nedostaje = nedostajuSlova(fbesmislena, f);
            if (nedostaje == minNedostaje) {
                najbolja = max(najbolja, (int)s.size());
			}
        }
    }

    // broj slova trazene smislene reci
	cout << najbolja << endl;
    return 0;
}

