#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Vojska {
	int pesadija, konjica, specijalci;
	int snaga() const {
		return pesadija * 1 + konjica * 2 + specijalci * 3;
	}
};

bool mozePobeda(Vojska& a, Vojska& b) { return a.snaga() >= 2 * b.snaga(); }

int main()
{
	vector<Vojska> vojske(3);
	for (int i = 0; i < 3; i++) 
		cin >> vojske[i].pesadija >> vojske[i].konjica >> vojske[i].specijalci;

	int n; cin >> n; // dani

	for (int dan = 0; dan < n; dan++) {
		for (int i = 0; i < 3; i++) {
			int j = (i + 1) % 3;
			int k = (i + 2) % 3;
			if (mozePobeda(vojske[i], vojske[j])) {
				Vojska& tmp = vojske[i];
				tmp.pesadija += vojske[j].pesadija;
				tmp.konjica += vojske[j].konjica;
				tmp.specijalci += vojske[j].specijalci;
				if (mozePobeda(tmp, vojske[k])) {
					cout << i + 1 << " " << dan << endl;
					return 0;
				}
			}
		}
		if (dan == n) break;

		// obrada prebega
		int info, iz, u, broj, tip;
		cin >> info >> iz >> u >> broj >> tip;
		if (info == 1) {
			//stvarni prebeg
			if (tip == 1) {vojske[iz - 1].pesadija -= broj; vojske[u - 1].pesadija += broj; }
			if (tip == 2) {vojske[iz - 1].konjica -= broj; vojske[u - 1].konjica += broj; }
			if (tip == 3) {vojske[iz - 1].specijalci -= broj; vojske[u - 1].specijalci += broj; }
		}
	}
	cout << "Primirje" << endl;
	return 0;
}

