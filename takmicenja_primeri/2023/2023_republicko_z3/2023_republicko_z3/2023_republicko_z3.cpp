#include <iostream>
#include <iomanip>
using namespace std;

// sirina i visina baste 20x20
#define xB 20
#define yB 20

void ispisiBastu(char basta[20][20]) {
	for (int i = 0; i < xB; i++) {
		for (int j = 0; j < yB; j++) {
			cout << basta[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int Xp, Yp; // koordinate lokacije psa
	int Xz, Yz; // koordinate lokacije zeca
	cin >> Xp >> Yp >> Xz >> Yz;
	char basta[20][20];

	// popunjavanje baste '-' karakterom
	for (int i = 0; i < xB; i++)
		for (int j = 0; j < yB; j++)
			basta[i][j] = '-';
		
#pragma region 3.1
	cout << "***** odgovor 3.1 *****" << endl;
	ispisiBastu(basta);
#pragma endregion
#pragma region 3.2
	basta[Xp][Yp] = 'P';
	basta[Xz][Yz] = 'Z';
	cout << "***** odgovor 3.2 *****" << endl;
	ispisiBastu(basta);
#pragma endregion
#pragma region 3.3
	// simulacija kretanja psa i zeca
	bool tragZeca[20][20] = { false };
	bool tragPsa[20][20] = { false };
	while (true) {
		tragZeca[Xz][Yz] = true;
		tragPsa[Xp][Yp] = true;
		// da li su se sreli
		if (Xp == Xz && Yp == Yz) {
			basta[Xp][Yp] = 'W'; // pas uhvatio zeca
			break;
		}
		// zec se pomera ka ivici
		if (Xz == 0 || Xz == xB - 1 || Yz == 0 || Yz == yB - 1) {
			basta[Xz][Yz] = 'L';
			break;
		}
		// Kretanje zeca ka blizoj polovini
		if (Xz < xB / 2) Xz--; else if (Xz > xB / 2) Xz++;
		if (Yz < yB / 2) Yz--; else if (Yz > yB / 2) Yz++;
		//pas se pomera ka zecu
		if (Xp < Xz) Xp++;
		else if (Xp > Xz) Xp--;
		if (Yp < Yz) Yp++;
		else if (Yp < Yz) Yp--;
	}
	// ispis matrice sa ishodom
	cout << "***** odgovor 3.3 *****" << endl;
	ispisiBastu(basta);
#pragma endregion
#pragma region 3.4
	char rezultat[20][20];
	for (int i = 0; i < xB; i++) {
		for (int j = 0; j < yB; j++) {
			if (tragZeca[i][j] && tragPsa[i][j])
				rezultat[i][j] = 'Y';
			else if (tragZeca[i][j])
				rezultat[i][j] = 'O';
			else if (tragPsa[i][j])
				rezultat[i][j] = 'X';
			else
				rezultat[i][j] = '-';
		}
	}
	cout << "***** odgovor 3.4 *****" << endl;
	ispisiBastu(rezultat);
#pragma endregion
#pragma region 3.5
	int brojPolja = 0;
	for (int i = 0; i < xB; i++) {
		for (int j = 0; j < yB; j++) {
			if (rezultat[i][j] == 'Y' ||
				rezultat[i][j] == 'O' ||
				rezultat[i][j] == 'X') {
				brojPolja++;
			}
		}
	}
	double procenat = (brojPolja * 100.0) / (xB * yB); // 400 ukupan broj polja 20x20
	cout << "***** odgovor 3.5 *****" << endl;
	cout.precision(2);
	cout << "Procenat unistenosti: " << procenat << "%" << endl;
#pragma endregion
	return 0;
}
