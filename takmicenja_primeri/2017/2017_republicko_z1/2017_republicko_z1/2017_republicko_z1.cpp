#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void zahtev1A(double& a, double& d, int& k) {
	double rezultat = 0;
	for (int i = 0; i < k; i++) {
		rezultat += a + d * i;
	}
	ofstream izlaz1A("rezultat1A.txt");
	izlaz1A << rezultat;
	izlaz1A.close();
}

void zahtev1B(double& a, double& d, int& k) {
	double rezultat = 0;
	for (int i = 0; i < k; i++) {
		rezultat += a * pow(d, i);
	}
	ofstream izlaz1B("rezultat1B.txt");
	izlaz1B << rezultat;
	izlaz1B.close();
}

int main()
{
	ifstream ulaz("datoteka.txt");
	double a, d;
	int k;
	// citanje a iz prve linije, b iz druge i k iz trece linije
	ulaz >> a >> d >> k;
	ulaz.close();
	// ZAHTEV 1A
	zahtev1A(a, d, k);
	// ZAHTEV 1B
	zahtev1B(a, d, k);
    return 0;
}


