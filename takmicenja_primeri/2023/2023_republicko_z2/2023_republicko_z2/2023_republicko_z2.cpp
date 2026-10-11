#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool daLiJePalindrom(string s) {
	for (char c : s) c = tolower(c);
	string okrenut = s;
	reverse(okrenut.begin(), okrenut.end());
	return okrenut == s;
}

int main()
{
	cout << "***** UNOS *****" << endl;
	int N; cin >> N;
	if (N <= 2 || N >= 10) return 1;
	cin.ignore();
	string s1;
	getline(cin, s1);
	if (s1.size() != 4 * N) return 1;
	cout << "\n***************\n";
#pragma region 2.1
	cout << "\nOdgovor 2.1\n";
	if (daLiJePalindrom(s1))
		cout << "String s1 je palindrom" << endl;
	else 
		cout << "String s1 nije palindrom" << endl;
#pragma endregion
#pragma region 2.2
	vector<string> sekvence(N); // vektor N sekvenci stringa
	for (int i = 0; i < N; i++) {
		for (int j = i; j < 4 * N; j += N) {
			sekvence[i] += s1[j];
		}
	}
	cout << "\nOdgovor 2.2\n";
	for (int i = 0; i < N; i++) 
		cout << sekvence[i] << "  ";
#pragma endregion
#pragma region 2.3
	for (int i = 0; i < N;  i++) {
		for (int j = 0; j < sekvence[i].size(); j++) {
			if (isdigit(sekvence[i][j])) {
				sekvence[i].erase(j, 1);
				j--;
			}
			else if (islower(sekvence[i][j])) {
				sekvence[i][j] += 10;
				if (sekvence[i][j] > 'z')
					sekvence[i][j] -= 26;
			}
			else if (isupper(sekvence[i][j])) {
				sekvence[i][j] += 10;
				if (sekvence[i][j] > 'Z')
					sekvence[i][j] -= 26;
			}
		}
	}
	// prikaz nove sekvence
	cout << "\nOdgovor 2.3\n";
	for (int i = 0; i < N; i++) 
		cout << sekvence[i] << endl;
#pragma endregion
#pragma region 2.4
	string s4;
	// dodavanje svih sekveci u string s4
	for (int i = 0; i < N; i++) s4 += sekvence[i];
	cout << "\nOdgovor 2.4\n";
	int freq[26] = { 0 };

	for (char c : s4) {
		if (isalpha(c)) {
			c = toupper(c);
			freq[c - 'A']++;
		}
	}
	for (int i = 0; i < 26; i++)
		if (freq[i] > 0)
			cout << char('A' + i) << ". " << freq[i] << endl;

	// min i max
	int minFreq = INT_MAX, maxFreq = 0;
	for (int i = 0; i < 26; i++) {
		if (freq[i] > 0) {
			minFreq = min(minFreq, freq[i]);
			maxFreq = max(maxFreq, freq[i]);
		}
	}

	cout << "\nNajmanje puta se pojavljuju:\n";
	for (int i = 0; i < 26; i++) {
		if (freq[i] == minFreq)
			cout << char('A' + i) << " (" << freq[i] << " puta)\n";
	}
	cout << "\Najvise puta se pojavljuju:\n";
	for (int i = 0; i < 26; i++) {
		if (freq[i] == maxFreq)
			cout << char('A' + i) << " (" << freq[i] << " puta)\n";
	}
#pragma endregion
#pragma region 2.5
	string velikaSamo;
	for (char c : s4)
		if (isupper(c))
			velikaSamo += c;

	int n = ceil(sqrt(s4.size()));
	char mat[50][50];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mat[i][j] = '#';
	
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (k < s4.size()) {
				char c = s4[k++];
				if (isupper(c)) mat[i][j] += c + j;
				else if (islower(c)) mat[i][j] += c - j;
				else mat[i][j] = c;
			}
		}
	}
	// ispis matrice
	cout << "\nOdgovor 2.5\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
#pragma endregion
	return 0;
}
