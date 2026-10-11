#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

double srednjaVrednostCifara(int broj) {
    int suma = 0, brojCifara = 0;
    while (broj != 0) {
        suma += broj % 10;
        brojCifara++;
        broj /= 10;
    }
    return (double)suma / brojCifara;
}


bool prost(int broj) {
    // broj je prost kad se deli samo sa 1 i samim sobom
    if (broj < 2) return false;
    for (int i = 2; i < broj; i++)
        if (broj % i == 0) 
            return false;
    return true;
}

int main()
{
    int a, z;
    cout << "***** ULAZ *****" << endl;
    cout << "Unesite 10-cifreni broj" << endl;
    cin >> a;
    cout << endl;
    cout << "Unesite broj rotiranja" << endl;
    cin >> z;
    if (a <= 1000000000 || a >= 2000000000) return 1;
    cout << endl;
    cout << "***** IZLAZI *****" << endl;
    cout << endl;
#pragma region 1.1
    int b = a;
    cout << "***** odgovor 1 *****" << endl;
    cout << "Srednja vrednost svih cifara je:" << srednjaVrednostCifara(b) << endl;
#pragma endregion
#pragma region 1.2
    int c = a;
    vector<int> cifre(10);
    cout << "***** odgovor 2 *****" << endl;
    // upis cifara u niz
    for (int i = 9; i >= 0; i--) {
        cifre[i] = c % 10;
        c /= 10;
    }
    for (int i = 0; i < 5; i++) {
        int broj = cifre[i] * 10 + cifre[9 - i];
        if (prost(broj))
            cout << "Broj " << broj << " je prost broj" << endl;
    }
#pragma endregion
#pragma region 1.3
    vector<int> d(10);
    int freq[10] = { 0 };
    string s = to_string(a);
    for (char c : s)
        freq[c - '0']++;
    cout << "***** odgovor 3 *****" << endl;
    for (int i = 0; i < 10; i++) {
        if (freq[i] == 0)
            d[i] = s[i] - '0';
        else
            d[i] = freq[i];
        cout << i << ": " << d[i] << endl;
    }
    cout << endl;
#pragma endregion
#pragma region 1.4
    int f[5][5];
    for (int i = 0; i < 5; i++) {
        f[0][i] = d[i];
        f[1][i] = d[i + 5];
    }

    for (int i = 2; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            f[i][j] = f[i - 1][j] + f[i - 2][j];
        }
    }

    for (int j = 0; j < 5; j++) {
        int suma = 0;
        for (int i = 0; i < 5; i++) {
            suma += f[i][j];
        }
        f[j][j] = suma;
    }

    cout << "***** odgovor 4 *****" << endl;
    // ispis matrice
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << f[i][j] << "\t";
        }
        cout << endl;
    }
#pragma endregion
    return 0;
}