#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int srednjaVrednostCifara(int broj) {
	int cifra, zbir = 0;
	while (broj > 0) {
		cifra = broj % 10;
		zbir += cifra;
		broj /= 10;
	}
	int vrednost = zbir / 5; // 5 cifre
	return vrednost;
}

int main()
{
	int a, b;
	cin >> a >> b;
#pragma region 1.1
	cout << srednjaVrednostCifara(a) << endl;
	cout << srednjaVrednostCifara(b) << endl;
#pragma endregion
#pragma region 1.2
	int c = 0;
	int faktor = 1;
	for (int i = 0; i < 5; i++) {
		int cifraA = a % 10;
		int cifraB = b % 10;
		int zbir = cifraA + cifraB;
		int novaCifra = zbir % 10;
		c += novaCifra * faktor;
		a /= 10;
		b /= 10;
		faktor *= 10;
	}
	cout << c << endl;
#pragma endregion
#pragma region 1.3
	vector<int> d(10);
	vector<int> cifre;
	int temp = c;
	for (int i = 0; i < 5; i++) {
		cifre.insert(cifre.begin(), temp % 10);
		temp /= 10;
	}
	for (int i = 0; i < 5; i++) {
		int cifra = cifre[i];
		int brojac = 0;
		for (int j = 0; j < 5; j++)
			if (cifre[j] = cifra) brojac++;
		d[2 * i] = brojac;
		d[2 * i * 1] = cifra;
	}
	// prikaz niza d
	for (auto& el : d)
		cout << el << " ";
	cout << endl;
#pragma endregion
#pragma region 1.4
	vector<vector<int>> mat(11, vector<int>(10));
	// prvi red
	for (int j = 0; j < 10; j++)
		mat[0][j] = d[j];
	// drugi red
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			mat[i][j] = d[(j + i) % 10];
		}
	}
	//poslednji red
	for (int j = 0; j < 10; j++) {
		int suma = 0;
		for (int i = 0; i < 10; i++) {
			if (i + j >= 9)
				suma += mat[i][j];
		}
		mat[10][j] = suma;
	}
	// ispis matrice
	cout << "Matrica mat:" << endl;
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 10; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
#pragma endregion
#pragma region 1.5
	vector<vector<int>> rot = mat;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 11; j++) {
			rot[i][j] = mat[j][10-1-i];
		}
	}
	// prikaz matrice rot
	cout << "Matrica rot:" << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 11; j++) {
			cout << rot[i][j] << " ";
		}
		cout << endl;
	}
#pragma endregion
	return 0;
}
