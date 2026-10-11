#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    // ULAZ
    cin >> n;
    if (n < 1 || n > 100) return 1;
    vector<int> y(n), x1(n), x2(n);
    //ULAZ
    for (int i = 0; i < n; i++) {
        cin >> y[i];
        cin >> x1[i];
        cin >> x2[i];
        if (y[i] > 10000 || x1[i] > 10000 || x2[i] > 10000 || x2[i] < x1[i] + 1) return 1;
    }
    // sortiranje po visini
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (y[i] > y[j]) {
                swap(y[i], y[j]);
                swap(x1[i], x1[j]);
                swap(x2[i], x2[j]);
            }
        }
    }

    int ukupno = 0;

    for (int i = 0; i < n; i++) {
        // levi stub
        int lx = x1[i] - 0.5;
        int visinaLevo = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (lx >= x1[j] && lx <= x2[j]) {
                visinaLevo = y[j];
                break;
            }
        }
        ukupno += y[i] - visinaLevo;
        // desni stub
        double dx = x2[i] + 0.5;
        int visinaDesno = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (dx >= x1[j] && dx <= x2[j]) {
                visinaDesno = y[j];
                break;
            }
        }
        ukupno += y[i] - visinaDesno;
    }
    cout << ukupno + 1 << endl;
    return 0;
}
