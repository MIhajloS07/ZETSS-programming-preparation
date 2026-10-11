#include <iostream>
#include <fstream> 
using namespace std;

bool prestupna(int godina)
{
    if ((godina % 4 == 0 && godina % 100 != 0) || (godina % 400 == 0))
        return true;
    return false;
}

int daniUMesecu(int mesec, int godina) {
    int meseci[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (mesec == 2 && prestupna(godina)) return 29;
    return meseci[mesec - 1];
}

long long brojDana(int d, int m, int g) {
    long long ukupno = 0;
    for (int i = 0; i < g; i++) {
        ukupno += prestupna(i) ? 366 : 365;
	}   
    for (int i = 1; i < m; i++) {
        ukupno += daniUMesecu(i, g);
	}
	ukupno += d;
    return ukupno;
}

int main()
{
    int d1, m1, g1; // dan mesec i godina prva tri reda tekstualne datoteke
	int d2, m2, g2; // dan mesec i godina druga tri red tekstualne datoteke
    ifstream ulaz("datoteka.txt");
    // ULAZ
	ulaz >> d1 >> m1 >> g1 >> d2 >> m2 >> g2;
    ulaz.close();
	long long dan1 = brojDana(d1, m1, g1);
	long long dan2 = brojDana(d2, m2, g2);
	long long razlika = llabs(dan2 - dan1) + 1;
    ofstream izlaz("izlaz.txt");
    izlaz << razlika;
    izlaz.close();
    return 0;
}


