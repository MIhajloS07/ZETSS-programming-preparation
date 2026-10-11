#include <iostream>
using namespace std;

int main()
{
    long long n;
	cin >> n;
	//UNOS
    if (n < 1 || n > 100000000) return 1;

	long long ukupno = 0;
	long long granica = 9;
	int cifre = 1;

	while (n > granica) {
		ukupno += granica * cifre;
		cifre++;
		granica = granica * 10 + 9;
	}

	long long start = 1;
	for (int i = 1; i < cifre; i++) start *= 10;
	ukupno += (n - start + 1) * cifre;
	cout << ukupno << endl;
    return 0;
}
