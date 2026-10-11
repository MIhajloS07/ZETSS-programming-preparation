#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool uravnotezen(const string& s) {
    int freq[26] = { 0 };
    int ukupnoSlova = 0;
    for (char c : s) {
        if (isalpha(c)) {
            freq[tolower(c) - 'a']++;
            ukupnoSlova++;
        }
    }
    if (ukupnoSlova == 0) return false;
    int target = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            target = freq[i];
            break;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0 && freq[i] != target)
            return false;
    }
    return true;
}

int main()
{
    string s1;
    int n;
    cin >> n;
    if (n <= 2 || n >= 10) return 1;
    cin.ignore();
    cin >> s1;
    if (s1.size() != 4 * n) return 1;
    for (int i = 0; i < s1.size() - 1; i++)
        if (isdigit(s1[i]) && s1[i] == s1[i + 1]) return 1;            
    if (isdigit(s1.front()) || isdigit(s1.back())) return 1;
#pragma region 2.1
    if (uravnotezen(s1))
        cout << "String s1 je uravnotezen" << endl;
    else cout << "String s1 nije uravnotezen" << endl;
#pragma endregion
#pragma region 2.2
    int maxDuzina = 0, trenutna = 0;
    for (char c : s1) {
        if (isdigit(c)) {
            maxDuzina = max(maxDuzina, trenutna);
            trenutna = 0;
        }
        else ++trenutna;
    }
    maxDuzina = max(maxDuzina, trenutna);
    cout << "Najduza sekvenca ima: " << maxDuzina << " slova." << endl;
#pragma endregion
#pragma region 2.3
    string s2;
    int suma = 0;
    for (char c : s1) {
        if (isalpha(c)) {
            s2 += c;
            suma += (int)c;
        }
        else if (isdigit(c)) {
            int cifra = c - '0';
            int vrednost = suma + cifra;
            s2 += to_string(vrednost);
        }
    }
    cout << s2 << endl;
#pragma endregion
#pragma region 2.4
    string s3 = s1;
    // Cezarova sifra

    for (int i = 0; i < s3.size(); i++) {
        char c = s3[i];
        if (isalpha(c)) {
            if (isupper(c)) {
                // pomeraj u okviru 'A'..'Z'
                s3[i] = 'A' + ((c - 'A' + 3) % 26);
            }
            else {
                // pomeraj u okviru 'a'..'z'
                s3[i] = 'a' + ((c - 'a' + 3) % 26);
            }
        }
        else if (isdigit(c)) {
            // pomeraj cifru u okviru '0'..'9'
            s3[i] = '0' + ((c - '0' + 3) % 10);
            if (s3[i] == '0') s3[i] = '1';
        }
    }
    cout << s3 << endl;
#pragma endregion
#pragma region 2.5
    string s4;
    for (char c : s4) 
        if (isalpha(c))
            s4 += tolower(c);
    //substring
    int maxD = 0;
    for (int i = 0; i < s4.size(); i++) {
        bool vidjen[256] = { false };
        int duzina = 0;
        for (int j = i; j < s4.size(); j++) {
            if (vidjen[(unsigned char)s4[j]]) break;
            vidjen[(unsigned char)s4[j]] = true;
            duzina++;
        }
        maxD = max(maxD, duzina);
    }
    cout << "Najduzi podtekst bez ponavljajucih karaktera ima "
        << maxD << " karaktera." << endl; 
#pragma endregion
    return 0;
}
