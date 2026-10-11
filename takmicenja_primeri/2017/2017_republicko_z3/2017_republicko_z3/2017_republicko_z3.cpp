#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

bool palindrom(int n)
{
    int obrnut = 0, temp = n;
    while (temp > 0)
    {
        obrnut = obrnut * 10 + temp % 10;
        temp /= 10;
    }
    return obrnut == n;
}

void zahtev3A(int& n) {
    int zbir = 0;
    for (int i = 2; i < n; i++)
    {
        if (palindrom(i))
        {
            bool prost = true;
            for (int j = 2; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    prost = false;
                    break;
                }
            }
            if (prost) zbir += i;
        }
    }
    ofstream izlaz("rezultat3A.txt");
    izlaz << zbir << endl;
    izlaz.close();
}

void zahtev3B(int& n) {
	vector<int> prostiCinioci;
    // svi prosti cinioci broja n
    for (int i = 2; i <= n; i++) {
        while (n % i == 0)
        {
            prostiCinioci.push_back(i);
            n /= i;
        }
    }
    // sortiranje neopadajuce
    sort(prostiCinioci.begin(), prostiCinioci.end());
    ofstream izlaz("rezultat3B.txt");
    for (int c : prostiCinioci) {
        izlaz << c << " ";
	}
    izlaz.close(); 
}

int main()
{
    int n;
    ifstream ulaz("datoteka.txt");  
	ulaz >> n;
    if (n < 1) return 1; // broj mora da bude veci od 1
	ulaz.close();
	// Zahtev 3A
	zahtev3A(n);
	// Zahtev 3B
	zahtev3B(n);
    return 0;
}

