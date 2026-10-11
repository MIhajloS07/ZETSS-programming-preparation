#include <iostream>
#include <iomanip>
using namespace std;

	// 1. sprat RRRRRRRRRRR -> radnje na svakom spratu
	// 2. sprat RRRRRRRRRRR
	// 3. sprat RRRRRRRRRRR
	// 4. sprat RRRRRRRRRRR
	//...

#define Xtc 10 // redovi (spratovi) trznog centra
#define Ytc 18 // kolone (radnji u jednom spratu) trznog centra

#pragma region helper_funkcije
void ispisiMatricu(char mat[][Ytc]) {
	for (int i = 0; i < Xtc; i++) {
		for (int j = 0; j < Ytc; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int brojRadnji(char mat[][Ytc]) {
	int brojRadnji = 0;
	for (int i = 0; i < Xtc; i++)
		for (int j = 0; j < Ytc; j++)
			if (mat[i][j] == 'R')
				brojRadnji++;
	return brojRadnji;
}
#pragma endregion

int main()
{
	int Xp, Yp, Xl, Yl; // pocetne lokacije kao indeksi matrice
	char trzniCentar[Xtc][Ytc]; // mapa trznog centra -> matrica
	cout << "***** ULAZ *****" << endl;
	cin >> Xp >> Yp >> Xl >> Yl;
	// ogranicenje
	if (Xp < 0 || Xp > Xtc ||
		Yp < 0 || Yp > Ytc ||
		Xl < 0 || Xl > Xtc ||
		Yl < 0 || Yl > Ytc) return 1;

#pragma region 3.1
	// RADNJE
	for (int i = 0; i < Xtc; i++) 
		for (int j = 0; j < Ytc; j++) 
			trzniCentar[i][j] = 'R'; // Radnje

	int brR = brojRadnji(trzniCentar);
	// STEPENICE
	for (int i = 0; i < Xtc; i++) {
		trzniCentar[i][0] = 'S';
		trzniCentar[i][Ytc - 1] = 'S';
	}
	// IZLAZI
	trzniCentar[0][0] = 'E';
	trzniCentar[0][Ytc - 1] = 'E';
	trzniCentar[Xtc - 1][0] = 'E';
	trzniCentar[Xtc - 1][Ytc - 1] = 'E';
	cout << "\n***** ODGOVOR 3.1 *****\n";
	ispisiMatricu(trzniCentar);
#pragma endregion
#pragma region 3.2
	// OZNACAVANJE POLICAJCA I LOPOVA U TRZNOM CENTRU
	trzniCentar[Xp][Yp] = 'P';
	trzniCentar[Xl][Yl] = 'L';
	cout << "\n***** ODGOVOR 3.2 *****\n";
	ispisiMatricu(trzniCentar);
#pragma endregion
#pragma region 3.3
	// Kretanje lopova po spratu
	bool lopovPobegao = false;
	bool ideDesno = (Ytc - 1 - Yl < Yl); // odredi smer

	while (!lopovPobegao && Xl < Xtc) {
		if (trzniCentar[Xl][Yl] == 'R')
			trzniCentar[Xl][Yl] = '-';
		if (ideDesno && Yl < Ytc - 1) {
			Yl++;
		}
		else if (!ideDesno && Yl > 0) {
			Yl--;
		}
		if (trzniCentar[Xl][Yl] == 'E') {
			lopovPobegao = true;
		}
		else if (trzniCentar[Xl][Yl] == 'S') {
			if (Xl < Xtc - 1) {
				Xl++;              
				ideDesno = !ideDesno; 
			}
			else {
				lopovPobegao = true;
			}
		}
	}
	cout << "\n***** ODGOVOR 3.3 *****\n";
	ispisiMatricu(trzniCentar);
#pragma endregion
#pragma region 3.4
	// Ako policajac uhvati lopova
	bool uhvacen = false;
	// Ako policajac vidi lopova na istom spratu (ako su na istom spratu)
	if (Xp == Xl) {
		while (!uhvacen && Yp != Yl) {
			if (Yp < Yl) {
				Yp += 2;
				if (Yp >= Yl) uhvacen = true;
			}
			else {
				Yp -= 2;
				if (Yp <= Yl) uhvacen = true;
			}	
		}
	}
	if (uhvacen) {
		trzniCentar[Xl][Yl] = 'X';
		cout << "Koordinate pronalaska: (" << Xl << "," << Yl << ")" << endl;
	}
	else {
		cout << "Lopov je pobegao, sve radnje su opljackane." << endl;
	}
#pragma endregion
#pragma region 3.5
	int opljackaneR = 0;
	for (int i = 0; i < Xtc; i++) 
		for (int j = 0; j < Ytc; j++) 
			if (trzniCentar[i][j] == '-')
				++opljackaneR;
	if (uhvacen && opljackaneR > 0) opljackaneR--;
	double uspesnost = (double)opljackaneR / (double)brR * 100.0;
	cout << fixed << setprecision(2);
	cout << "Uspesnost pljacke: " << uspesnost << "%" << endl;
#pragma endregion
	return 0;
}