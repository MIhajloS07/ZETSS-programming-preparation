#include <iostream>
using namespace std;

bool validanPotez(int x, int y) { return x >= 1 && x <= 6 && y >= 1 && y <= 6; }

bool moze_za_1(int sr, int sc, int tr, int tc) {
	int dr[] = { 2,2,-2,-2,1,1,-1,-1 };
	int dc[] = { 1,-1,1,-1,2,-2,2,-2 };

	for (int i = 0; i < 8; i++) {
		int nr = sr + dr[i];
		int nc = sc + dc[i];

		if (validanPotez(nr, nc) && nr == tr && nc == tc)
			return true;
	}
	return false;
}

bool moze_za_2(int sr, int sc, int tr, int tc) {
	int dr[] = { 2,2,-2,-2,1,1,-1,-1 };
	int dc[] = { 1,-1,1,-1,2,-2,2,-2 };

	for (int i = 0; i < 8; i++) {
		int nr = sr + dr[i];
		int nc = sc + dc[i];

		if (validanPotez(nr, nc)) {
			if (moze_za_1(nr, nc, tr, tc))
				return true;
		}
	}
	return false;
}

int main()
{
	// zadato polje koje predstavlja cilj trke skakaca
	int ciljRed, ciljKolona;
	// Pocetne pozicije
	// pozicija skakaca jednog je na (1,6) a drugog na (6,1)
	int beliX = 1, beliY = 6;
	int crniX = 6, crniY = 1;
	
	//ULAZ polja koje predstavlja cilj trke skakaca
	cin >> ciljRed >> ciljKolona;
	if (!validanPotez(ciljRed, ciljKolona))
		return 1;

	bool beli1 = moze_za_1(beliX, beliY, ciljRed, ciljKolona);
	bool crni1 = moze_za_1(crniX, crniY, ciljRed, ciljKolona);
	
	if (beli1) {
		cout << "Beli" << endl;
		return 0;
	}
	if (crni1) {
		cout << "Crni" << endl;
		return 0;
	}

	bool beli2 = moze_za_2(beliX, beliY, ciljRed, ciljKolona);
	bool crni2 = moze_za_2(crniX, crniY, ciljRed, ciljKolona);

	if (beli2 && !crni2)
		cout << "Beli" << endl;
	else if (crni1 && !beli2)
		cout << "Crni" << endl;
	else if (beli2 && crni2)
		cout << "Beli" << endl;
	else 
		cout << "Remi" << endl;	
	return 0;
}
