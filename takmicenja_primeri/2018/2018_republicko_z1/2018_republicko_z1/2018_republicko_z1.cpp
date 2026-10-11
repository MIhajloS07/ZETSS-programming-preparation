#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

void stampajNiz(const vector<int>& v) {
    for (auto& el : v)
        cout << el << " ";
}

bool daLiJeJednocifren(int& broj) { return (broj >= -9 && broj <= 9); }

int main()
{
    int n, x, y, z;
    //ULAZ
    cin >> n;
    if (n >= 50 || n < 5) return 1;
    // niz a[n]
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // X - vrednost
    cin >> x;
    if (x <= -50 || x >= 50) return 1;
    // Y - broj izmena
    cin >> y;
    if (y > 10 || y < 1) return 1;
    // Z - broj rotacija
    cin >> z;
    if (z < 0) return 1;

    #pragma region 1.1
    vector<int> b = a;
    b.push_back(x);
    sort(b.begin(), b.end());
    stampajNiz(b);
    #pragma endregion

    #pragma region 1.2
    vector<int> c = a;
    int zbir = 0;
    for (int i = 0; i < c.size(); i++) {
        zbir += c[i];
        if (c[i] % 2 != 0 && i % 2 == 0)
            c[i] = c[i] xor i;
    }
    // srednja vrednost niza c -> vektora
    int srednjaV = zbir / c.size();
    int idx = 0;
    int min = abs(c[0] - srednjaV);
    for (int i = 1; i < c.size(); i++) {
        int dist = abs(c[i] - srednjaV);
        if (dist < min) {
            min = dist;
            idx = i;
        }
    }
    c.erase(c.begin() + idx);
    stampajNiz(c);
    #pragma endregion

    #pragma region 1.3
    vector<int> d;
    // provera da li je a[i] jednocifren broj
    for (int i = 0; i < a.size(); i++) {
        if (daLiJeJednocifren(a[i])) {
            d.push_back(abs(a[i]));
        }
        // cifra najmanje tezine
        else {
            d.push_back(abs(a[i] % 10));
        }
    }
    // dodatna provera za vektor d
    if (d[0] == 0) d[0] = 1;

    // provera da li se moze napraviti palindrom
    int potrebeIzmene = 0;
    for (int i = 0; i < d.size() / 2; i++) {
        if (d[i] != d[d.size() - 1 - i])
            potrebeIzmene++;
    }
    if (potrebeIzmene > y) {
        cout << "Nije moguce napraviti palindrom za dati broj izmena";
    }
    #pragma endregion

    #pragma region 1.4
    vector<vector<int>> f(n, vector<int>(n + 1));
    // suma elemenata niza a
    int suma = 0;
    for (int i = 0; i < n; i++) suma += a[i];
    f[0][0] = suma;
    for (int j = 0; j < n; j++) f[0][j + 1] = a[j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    #pragma endregion

    #pragma region 1.5
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    #pragma endregion
    return 0;
}

