#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	string s1; cin >> s1;
	if (s1.size() <= 2 || s1.size() >= 30) return 1;
#pragma region 2.1
	vector<string> brojeviNiz; // ASCII vrednost karaktera
	for (char& c : s1) {
		int ascii = (int)c;
		string broj = to_string(ascii);
		if (broj.size() == 2)
			broj += "0";
		if (broj.size() == 1)
			broj += "00";
		brojeviNiz.push_back(broj);
	}
	vector<string> izmenjeni;
	for (int i = 0; i < brojeviNiz.size(); i++) {
		if (i % 2 == 0) {
			string stari = brojeviNiz[i];
			int suma = 0;
			for (char c : stari) suma += c - '0';
			int sredina = (int)ceil((double)suma / stari.size());
			string novi = stari[0] + to_string(sredina) + 
					      stari[1] + to_string(sredina) + 
						  stari[2];
			izmenjeni.push_back(novi);
		}
	}
	cout << "***** odgovor 2.1 *****" << endl;
	for (string&s : izmenjeni)
			cout << s << endl;
#pragma endregion
#pragma region 2.2
	// provera da li je string pravilan
	int freqq[256] = { 0 };
	for (char c : s1)
		freqq[(unsigned char)c]++;
	bool pravilan = true;
	for (int i = 0; i < 256; i++) {
		if (freqq[i] > 0 && freqq[i] != 1) {
			pravilan = false;
			break;
		}
	}
	cout << "***** odgovor 2.2 *****" << endl;
	if (pravilan)
		cout << "String je pravilan." << endl;
	else
		cout << "String nije pravilan." << endl;
#pragma endregion
#pragma region 2.3
	string s2;
	for (char& c : s1) {
		if (c == 'A' || c == 'a' || 
			c == 'C' || c == 'c' || 
			c == 'T' || c == 't' || 
			c == 'G' || c == 'g') {
			s2 += toupper(c);
		}
	}
	cout << "***** odgovor 2.3 *****" << endl;
	cout << s2;
#pragma endregion
#pragma region 2.4
	// provera da li je gen stabilan
	bool gen = true;
	if (s2.size() % 4 != 0)
		gen = false;

	cout << "***** odgovor 2.4 *****" << endl;
	// Ucestalog pojavljivanja svakog slova -> frekvencija karaktera
	int freq[256] = { 0 };
	for (char c : s2)
		freq[(unsigned char)c]++;
	for (int i = 0; i < 256; i++) {
		if (freq[i] > 0)
			cout << (char)i << ". " << freq[i] << endl;
	}
	int aa = freq['A'];
	int cc = freq['C'];
	int tt = freq['T'];
	int gg = freq['G'];
	if (!(aa == cc && cc == tt && tt == gg)) gen = false;
	if (gen) cout << "String s2 je stabilan gen" << endl;
	else cout << "String s2 nije stabilan gen" << endl;
#pragma endregion
#pragma region 2.5
	cout << "***** odgovor 2.5 *****" << endl;
	int a = 0, c = 0, t = 0, g = 0;
	for (char ch : s2) {
		if (ch == 'A') a++;
		else if (ch == 'C') c++;
		else if (ch == 'T') t++;
		else if (ch == 'G') g++;
	}
	int maxF = max({a,c,t,g});
	string dodatak;
	// dodavanje potrebnih karaktera da se izjednace
	while (a < maxF) { dodatak += 'A'; a++; }
	while (c < maxF) { dodatak += 'C'; c++; }
	while (t < maxF) { dodatak += 'T'; t++; }
	while (g < maxF) { dodatak += 'G'; g++; }
	int ostatak = (s2.size() + dodatak.size()) % 4;
	if (ostatak != 0) {
		int dodaj = 4 - ostatak;
		dodatak.append(dodaj, 'A');
	}

	// sortiraj podniz po abecedi
	sort(dodatak.begin(), dodatak.end());

	cout << "Najkraci podniz za dodavanje: " << dodatak << endl;
#pragma endregion
	return 0;
}
