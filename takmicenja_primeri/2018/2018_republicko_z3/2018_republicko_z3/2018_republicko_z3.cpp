#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Tacka {
    int x, y;
    char ime;
};

double povrsinaPravougaonika(const Tacka& t1, const Tacka& t2) {
    int a = abs(t1.x - t2.x);
    int b = abs(t1.y - t2.y);
    return a * b;
}

double rastojanjeTacaka(const Tacka& t1, const Tacka& t2) {
    return sqrt((pow(t1.x - t2.x, 2) + pow(t1.y - t2.y, 2)));
}

double povrsinaTrougla(const Tacka& t1, const Tacka& t2, const Tacka& t3) {
    return ((t2.x - t1.x) * (t2.y - t1.y) + (t3.x - t2.x) * (t3.y - t2.y) + (t1.x - t3.x) * (t1.y + t3.y)) / 2;
}

int main()
{
    int n;
    cin >> n;
    if (n < 3 || n > 10) return 1;
    vector<Tacka> tacke(n);
    // ulaz
    for (int i = 0; i < n; i++) {
        Tacka t;
        cin >> t.x >> t.y >> t.ime;
        if (t.x <= 0 || t.x > 20 || t.y <= 0 || t.y >= 20 || t.ime < 'a' || t.ime > 'z') return 1;
        tacke.push_back(t);
    }

#pragma region 3.1
    int MAX = 21;
    vector<vector<char>> koordinatniSistem(MAX, vector<char>(MAX, '.'));
    for (int i = 0; i < MAX; i++) {
        koordinatniSistem[0][i] = '- ';
        koordinatniSistem[i][0] = '|';
    }
    koordinatniSistem[0][0] = '+';
    for (auto& t : tacke) {
        koordinatniSistem[t.y][t.x] = t.ime;
    }
    // ispis
    for (int i = MAX - 1; i >=0 ; i--) {
        for (int j = 0; j < MAX; j++) {
            cout << koordinatniSistem[i][j] << " ";
        }
        cout << endl;
    }
#pragma endregion
#pragma region 3.2
    Tacka p1, p2;
    double maxDist = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double d = rastojanjeTacaka(tacke[i], tacke[j]);
            if (d > maxDist) {
                maxDist = d;
                p1 = tacke[i];
                p2 = tacke[j];
            }
        }
    }
    cout << "3.2 Najduze rastojanje: " << maxDist
        << " izmedju tacaka " << p1.ime << " i " << p2.ime << endl;
#pragma endregion
#pragma region 3.3
    Tacka r1, r2;
    double minP = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double d = povrsinaPravougaonika(tacke[i], tacke[j]);
            if (d > maxDist) {
                minP = d;
                r1 = tacke[i];
                r2 = tacke[j];
            }
        }
    }
    cout << "3.3 Najmanja povrsina pravougaonika: " << minP
        << " izmedju tacaka " << r1.ime << " i " << r2.ime << endl;
#pragma endregion
    return 0;
}
