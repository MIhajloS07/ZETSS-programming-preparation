#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

void frekvencija(const string& s) {
    int freq[26] = { 0 };
    for (char ch : s)
        if (isalpha(ch))
            freq[tolower(ch) - 'a']++;
    for (int i = 0; i < 26; i++)
        if (freq[i] > 0)
            cout << char('a' + i) << ". " << freq[i] << endl;
}

int main()
{
    string s; getline(cin, s);
#pragma region 1
    string okrenut = s;
    reverse(okrenut.begin(), okrenut.end());
    if (okrenut == s) cout << "Uneti string je palindrom" << endl;
    else cout << "Uneti string nije palindrom" << endl;
#pragma endregion
#pragma region 2
    frekvencija(s);
#pragma endregion
#pragma region 3
    // karakter sa najvecom frekvencijom
    int freq[26] = { 0 };
    for (char ch : s) if (isalpha(ch)) freq[tolower(ch) - 'a']++;
    int maxFreq = freq[0];
    char maxChar = 'a';
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxChar = 'a' + i;
        }
    }
    cout << "Najcesce slovo: " << maxChar << " (" << maxFreq << " puta)" << endl;
#pragma endregion
#pragma region 4
    // provera da li su dve reci anagrami
    istringstream ss(s);
    string rec;
    vector<string> reci;
    while (ss >> rec)
        reci.push_back(rec);
    if (reci.size() != 2) {
        cout << "Moraju biti unete dve reci!" << endl;
    }
    else {
        if (reci[0].size() != reci[1].size()) {
            cout << "Nije anagram" << endl;
        }
        else {
            sort(reci[0].begin(), reci[0].end());
            sort(reci[1].begin(), reci[1].end());
            cout << (reci[0] == reci[1] ? "Anagram" : "Nije anagram") << endl;
        }
    }
#pragma endregion
#pragma region 5
    vector<char> slova;
    vector<int> cifre;
    for (char ch : s) {
        if (isalpha(ch)) slova.push_back(ch);
        else if (isdigit(ch)) cifre.push_back(ch - '0');
    }
    for (char ch : slova)
        cout << ch << " ";
    cout << endl;
    for (int n : cifre)
        cout << n << " ";
    cout << endl;
#pragma endregion
    return 0;
}
