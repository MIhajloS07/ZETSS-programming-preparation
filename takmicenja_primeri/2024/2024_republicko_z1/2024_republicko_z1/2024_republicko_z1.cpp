#include <iostream>
#include <string>
using namespace std;

void ispisMatrice(int mat[50][50][50], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cout << mat[i][j][k] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
}

int main()
{
	int N; cin >> N;
	if (N <= 1 || N >= 20) return 1;
	int mat[50][50][50];

	// Popunjavanje vrednosti u poljima kao sumu indeksa i j k
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				mat[i][j][k] = i + j + k;

#pragma region 1.1
	cout << "****** odgovor 1.1 ******" << endl;
	ispisMatrice(mat, N);
#pragma endregion
	string naredba; 
	do {
		cin >> naredba;
		for (char& c : naredba) c = toupper(c);
#pragma region 1.2
		if (naredba == "UPDATE") {
			int i1, j1, k1, novaVrednost;
			cin >> i1 >> j1 >> k1 >> novaVrednost;
			if (i1 >= 0 && i1 < N && j1 >= 0 && j1 < N && k1 >= 0 && k1 < N) {
				mat[i1][j1][k1] = novaVrednost;
				cout << "****** odgovor 1.2 ******" << endl;
				ispisMatrice(mat, N);
			}
			else cout << "Indeksi van opsega" << endl;
		}
#pragma endregion
#pragma region 1.3
		else if (naredba == "SUM") {
			int ip, jp, kp, ik, jk, kk;
			cin >> ip >> jp >> kp >> ik >> jk >> kk;
			if (ip >= 0 && ip < N && jp >= 0 && jp < N && kp >= 0 && kp < N &&
				ik >= 0 && ik < N && jk >= 0 && jk < N && kk >= 0 && kk < N) {
				int suma = 0;
				for (int i = ip; i <= ik; i++) 
					for (int j = jp; j <= jk; j++) 
						for (int k = kp; k <= kk; k++) 
							suma += mat[i][j][k];
				cout << "****** odgovor 1.3 ******" << endl;
				cout << "suma: " << suma << endl;
			}
		}
#pragma endregion
#pragma region 1.4
		else if (naredba == "NEW") {
			int novaMat[50][50][50] = {0};
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					for (int k = 0; k < N; k++) {
						int suma = 0;
						// X
						if (i - 1 >= 0) suma += mat[i - 1][j][k];
						if (i + 1 < N) suma += mat[i + 1][j][k];
						// Y
						if (j - 1 >= 0) suma += mat[i][j - 1][k];
						if (j + 1 < N) suma += mat[i][j + 1][k];
						// Z
						if (k - 1 >= 0) suma += mat[i][j][k - 1];
						if (k + 1 < N) suma += mat[i][j][k + 1];
						novaMat[i][j][k] = suma;
					}
				}
			}
			cout << "****** odgovor 1.4 ******" << endl;
			ispisMatrice(novaMat, N);
		}
#pragma endregion
#pragma region 1.5
		else if (naredba == "MOVE") {
			//int i1, j1, k1;
			//int dx, dy, dz;
			//cin >> i1 >> j1 >> k1 >> dx >> dy >> dz;

			//int pomerena[50][50][50] = { 0 };
			//// kopiraj originalnu matricu
			//for (int i = 0; i < N; i++)
			//	for (int j = 0; j < N; j++)
			//		for (int k = 0; k < N; k++)
			//			pomerena[i][j][k] = mat[i][j][k];

			//// X osa
			//for (int i = 0; i < N; i++) {
			//	int ni = (i + dx + N) % N;
			//	pomerena[ni][j1][k1] = mat[i][j1][k1];
			//}
			//// Y osa
			//for (int j = 0; j < N; j++) {
			//	int nj = (j + dy + N) % N;
			//	pomerena[i1][nj][k1] = mat[i1][j][k1];
			//}
			//// Z osa
			//for (int k = 0; k < N; k++) {
			//	int nk = (k + dz + N) % N;
			//	pomerena[i1][j1][nk] = mat[i1][j1][k];
			//}
			//cout << "****** odgovor 1.5 ******" << endl;
			//ispisMatrice(pomerena, N);
		}
#pragma endregion
	} while (naredba != "QUIT");
	return 0;
}