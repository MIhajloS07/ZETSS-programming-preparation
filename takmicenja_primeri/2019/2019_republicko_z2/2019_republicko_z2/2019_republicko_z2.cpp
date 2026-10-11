#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool daLiJePalindrom(const string& s) {
    string okrenut = s;
    reverse(okrenut.begin(), okrenut.end());
    return okrenut == s;
}

int main()
{
    string s;
    cout << "***** ULAZ *****" << endl;
    cout << "Unesite string" << endl;
    getline(cin, s);
    int N = s.size() / 4;

    for (int i = 0; i < (int)s.size() - 1; i++) {
        if (isdigit(s[i]) && isdigit(s[i + 1]))
            return 1;
    }
    if (isdigit(s.back())) return 1;
    cout << "***** IZLAZI *****" << endl;
#pragma region 2.1
    cout << "***** odgovor 1 *****" << endl;
    if (daLiJePalindrom(s))
        cout << "String je palindrom" << endl;
    else cout << "String nije palindrom" << endl;
#pragma endregion
#pragma region 2.2
    string s2;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i]) && isupper(s[i + 1]) && islower(s[i + 2])) {
            int cifra = s[i] - '0';
            char veliko = s[i + 1];

            // ASCII kod velikog slova
            int kod = cifra + (int)veliko;
            while (kod > 'Z') {
                kod = 'A' + (kod - 'Z' - 1);
            }
            s2 += to_string(cifra);
            s2 += (char)kod;
        }
    }
    cout << "***** odgovor 2 *****" << endl;
    cout << s2 << endl;
#pragma endregion
#pragma region 2.3
    string s3 = s;
    for (int i = 0; i < s3.size(); i++) {
        if (isdigit(s3[i])) {
            int cifra = s3[i] - '0';
            s3[i] = 'a' + cifra;
        }
        else if (isupper(s3[i])) {
            s3[i] = tolower(s3[i]);
        }
        // ASCII mapiranje
        if (s3[i] >= 97 && s3[i] <= 103) s3[i] = 'a';
        if (s3[i] >= 104 && s3[i] <= 110) s3[i] = 'b';
        if (s3[i] >= 111 && s3[i] <= 117) s3[i] = 'c';
        if (s3[i] >= 118 && s3[i] <= 122) s3[i] = 'd';
    }
    int freq[4] = { 0 };
    for (char c : s3) {
        if (c == 'a') freq[0]++;
        else if (c == 'b') freq[1]++;
        else if (c == 'c') freq[2]++;
        else if (c == 'd') freq[3]++;
    }
    int ideal = s3.size() / 4;

    int izmene = 0;
    for (int i = 0; i < 4; i++)
        if (freq[i] > ideal) izmene += freq[i] - ideal;

    cout << "***** odgovor 3 *****" << endl;
    cout << s3 << endl;
    cout << "Broj izmena: " << izmene << endl;
#pragma endregion
#pragma region 2.4
    string s4 = s;
    if (!isdigit(s4[0]))
        s4 = "0" + s4;
    vector<string> sekvence;
    string trenutna;
    for (char c : s4) {
        if (isdigit(c)) {
            if (!trenutna.empty()) {
                sekvence.push_back(trenutna);
                trenutna.clear();
            }
        }
        else {
            trenutna += c;
        }
    }
    if (!trenutna.empty()) sekvence.push_back(trenutna);
    auto tezinskiFaktor = [](const string& s) {
        int suma = 0;
        for (char c : s) suma += (int)c;
        return suma;
        };
    sort(sekvence.begin(), sekvence.end(), [&](const string& a, const string& b) {
        return tezinskiFaktor(a) > tezinskiFaktor(b);
        });
    s4.clear();
    for (int i = 0; i < (int)sekvence.size(); i++) {
        s4 += to_string(i); // koristi indeks kao separator
        s4 += sekvence[i];
    }
    cout << "***** odgovor 4 *****" << endl;
    cout << s4 << endl;
#pragma endregion
#pragma region 2.5
    string s5 = s;
    if (!isdigit(s5[0])) s5 = '0' + s5;
    for (char c : s5) {
        if (isdigit(c)) {
            if (!trenutna.empty()) {
                sekvence.push_back(trenutna);
                trenutna.clear();
            }
        }
        else {
            trenutna += c;
        }
    }
    if (!trenutna.empty()) sekvence.push_back(trenutna);
    vector<int> zajednicka(26, 1);
    for (const string& sekv : sekvence) {
        vector<int> prisutna(26, 0);
        for (char c : sekv)
            if (isalpha(c)) prisutna[tolower(c) - 'a'] = 1;
        for (int i = 0; i < 26; i++) 
            zajednicka[i] &= prisutna[i];
    }

    // Izbacivanje zajednickih slova iz s5
    string rezultat;
    for (char c : s5) {
        if (isalpha(c)) {
            if (zajednicka[tolower(c) - 'a'] == 1) continue; // preskoci zajednicka
        }
        rezultat += c;
    }

    s5 = rezultat;

    cout << "***** odgovor 5 *****" << endl;
    cout << s5 << endl;

#pragma endregion
    return 0;
}
