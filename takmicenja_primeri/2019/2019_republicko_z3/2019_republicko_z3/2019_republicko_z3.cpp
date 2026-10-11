#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Figura {
    char s; // simbol
    int x, y; // pozicije
    char k; // nacin kretanja
};

int main()
{
    int brojFigura;
    cin >> brojFigura;
    if (brojFigura <= 3 || brojFigura >= 10) return 1;
    int n, m; // kolone, redovi table
    cin >> n >> m;
    if (n <= 2 || n >= 10 || m <= 2 || m >= 10) return 1;

    vector<Figura> figure;

    for (int i = 0; i < brojFigura; i++) {
        Figura f;
        cin >> f.s >> f.x >> f.y >> f.k;
        if (f.s >= 'A' && f.s <= 'Z' &&
            f.x > 0 && f.x <= n &&
            f.y > 0 && f.y <= m &&
            f.k == 'X' || f.k == '/' || f.k == '\\' || f.k == '+') {
            figure.push_back(f); // dodajemo svaku figuru u vektor svih figura
        }
        else return 1;
    }

    // Kreiranje table
    vector<vector<char>> tabla(m, vector<char>(n, '='));

    // Postavljanje figura na tablu
    for (auto& f : figure) {
        tabla[f.y - 1][f.x - 1] = f.s; // -1 jer indeksi krecu od 0
    }

    // Ispis kolona
    cout << "   ";
    for (int j = 0; j < n; j++) {
        cout << j + 1 << " ";
    }
    cout << endl;

    // Ispis redova
    for (int i = 0; i < m; i++) {
        cout << i + 1 << " ";
        if (i + 1 < 10) cout << " "; // poravnanje
        for (int j = 0; j < n; j++) {
            cout << tabla[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
