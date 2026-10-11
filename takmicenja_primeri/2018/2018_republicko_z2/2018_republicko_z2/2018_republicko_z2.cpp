#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void frekvencija(const string& s) {
    int freq[256] = { 0 }; // ASCII tabela
    for (char c : s)
        freq[(unsigned char)c]++;
    // prolazak kroz ASCII tabelu
    for (int i = 0; i < 256; i++)
        if (freq[i] > 0)
            cout << (char)i << ":" << freq[i] << endl;
}

int main()
{
    string s;
    // ULAZ
    getline(cin, s);
    if (s.size() > 80) return 1;
    for (char c : s) if (!islower(c)) return 1;

#pragma region 2.1
    string s1;
    for (int i = 0; i < s.size(); i++)
        if ((int)s[i] >= 100 && (int)s[i] <= 110)
            s1 += s[i];
    cout << "********* odgovor 1 *********" << endl;
    cout << s1 << endl;
#pragma endregion
    cout << "\n\n";
#pragma region 2.2
    string s2;
    for (int i = 0; i < s.size(); i++) {
        if ((int)s[i] >= 97 && (int)s[i] <= 100) s2 += 'a';
        if ((int)s[i] >= 101 && (int)s[i] <= 104) s2 += 'b';
        if ((int)s[i] >= 105 && (int)s[i] <= 108) s2 += 'c';
        if ((int)s[i] >= 109 && (int)s[i] <= 112) s2 += 'd';
        if ((int)s[i] >= 113 && (int)s[i] <= 116) s2 += 'e';
        if ((int)s[i] >= 117 && (int)s[i] <= 120) s2 += 'f';
        if ((int)s[i] >= 121) s2 += 'x';
    }
    cout << "********* odgovor 2 *********" << endl;
    cout << s2 << endl;
#pragma endregion
    cout << "\n\n";
#pragma region 2.3  
    string s3 = s;
    int duzina = s3.length();
    int n = ceil(sqrt(duzina));
    vector<vector<char>> mat(n, vector<char>(n));
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (k < duzina)
                mat[i][j] = s3[k++];
            else
                mat[i][j] = '#';
        }
    }
    s3.clear();
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            s3 += mat[i][j];
        }
    }
    cout << "********* odgovor 3 *********" << endl;
    cout << s3 << endl;
    #pragma endregion
    cout << "\n\n";
#pragma region 2.4
    cout << "********* odgovor 4 *********" << endl;
    frekvencija(s);
#pragma endregion
    cout << "\n\n";
#pragma region 2.5
    cout << "********* odgovor 5 *********" << endl;
    int freq[256] = { 0 };
    for (char c : s)
        freq[(unsigned char)c]++;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            cout << (char)i << ": ";
            if (freq[i] <= 3) {
                cout << string(freq[i], '*');
            } else {
                cout << "+";
            }
            cout << endl;
        }
    }
#pragma endregion
    return 0;
}
