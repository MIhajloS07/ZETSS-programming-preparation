#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool jeProst(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

int main()
{
    int a;
    cin >> a;
    if (a <= 100000 || a >= 200000) return 1;
#pragma region 1.1
    int b = a;
    // najmanja i najveca cifra broja b
    int minCifra = 9;
    int maxCifra = 0;
    vector<int> cifre;
    while (b > 0) {
        int cifra = b % 10;
        if (cifra < minCifra) minCifra = cifra;
        if (cifra > maxCifra) maxCifra = cifra;
        cifre.push_back(cifra);
        b /= 10;
    }
    cout << "Najmanja cifra broja b: " << minCifra << endl;
    cout << "Najveca cifra broja b: " << maxCifra << endl;
    // provera da li je b palindrom
    vector<int> obrnuto = cifre;
    reverse(obrnuto.begin(), obrnuto.end());
    if (cifre == obrnuto)
        cout << "Uneti broj b je palindrom";
    else
        cout << "Uneti broj b nije palindrom";
    cout << endl;
#pragma endregion
#pragma region 1.2
    int c = a;
    // 1. 3. i 5. cifra predstavljaju levu polovinju broja
    // 2. 4. i 6. cifra predstavljaju desnu polovinu broja 
    vector<int> leva;
    vector<int> desna;
    string s = to_string(c);
    for (int i = 0; i < 6; i++) {
        int cifra = s[i] - '0';
        // nemarne cifre dodaj u novi vektor
        if (i % 2 == 0) leva.push_back(cifra);
        else desna.push_back(cifra);
    }
    vector<int> broj = leva;
    broj.insert(broj.end(), desna.begin(), desna.end());
    for (auto c : broj)
        cout << c;
    cout << endl;
    size_t brojProstih = 0;
    cout << "Prosti brojevi" << endl;
    for (int i = 2; i <= c; i++) {
        if (jeProst(i)) {
            cout << i << " ";
            ++brojProstih;
        }
    }
    cout << endl;
    cout << "Broj prostih brojeva: " << brojProstih << endl;
#pragma endregion
#pragma region 1.3
    vector<int> d(8);
    int zbirParnih = 0, brojParnih = 0;
    for (auto x : broj) {
        if (x % 2 == 0) {
            zbirParnih += x;
            brojParnih++;
        }
    }
    double prosekParnih = (double)zbirParnih / brojParnih;
    d[0] = floor(prosekParnih);
    // od drugog do sedmog elementa 
    for (int i = 0; i < broj.size(); i++)
        d[i + 1] = broj[i];
    // osmi element
    int zbirNaparnih = 0, brojNeparnih = 0;
    for (auto x : broj) {
        if (x % 2 != 0) {
            zbirNaparnih += x;
            brojNeparnih++;
        }
    }
    double prosekNeparnih = (double)zbirNaparnih / brojNeparnih;
    d[7] = ceil(prosekNeparnih);

    // prikaz niza d
    for (int i = 0; i < d.size(); i++)
        cout << d[i] << " ";
    cout << endl;
#pragma endregion
#pragma region 1.4
    int maxVisina = *max_element(d.begin(), d.end());
    for (auto stub : d)
        cout << stub << " ";
    cout << endl;
    for (int nivo = maxVisina; nivo > 0; nivo--) {
        for (auto stub : d) {
            if (stub >= nivo) cout << "| ";
            else cout << "  ";
        }
        cout << endl;
    }
#pragma endregion
#pragma region 1.5
    int maxPovrsina = 0;
    int bestL = 0, bestR = 0;
    for (int i = 0; i < d.size(); i++) {
        for (int j = i + 1; i < d.size(); i++){
            int visina = min(d[i], d[j]);
            int sirina = j - i;
            int povrsina = visina * sirina;
            if (povrsina > maxPovrsina) {
                maxPovrsina = povrsina;
                bestL = i; bestR = j;               
            }
        }
    }
    cout << "Najveca povrsina vode: " << maxPovrsina << endl;
    cout << "Stubovi: " << bestL << " i " << bestR << endl;

    // graficki prikaz
    int maxVisinaStub = max(d[bestL], d[bestR]);
    for (int nivo = maxVisinaStub; nivo > 0; nivo--) {
        if (d[bestL] >= nivo) cout << "| ";
        else cout << "  ";
        for (int k = bestL + 1; k < bestR; k++) {
            if (nivo <= min(d[bestL], d[bestR])) cout << "~ ";
            else cout << "  ";
        }
        if (d[bestR] >= nivo) cout << "|";
        else cout << " ";
        cout << endl;
    }
#pragma endregion
    return 0;
}
