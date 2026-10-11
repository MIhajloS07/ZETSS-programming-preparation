#include <iostream>
#include <vector>
using namespace std;

struct Clan {
	char s; // simbol
	int x, y; // pozicija
};

int main()
{
	int n, m;
	cin >> n >> m;
	if (n <= 3 || n >= 10 || m <= 3 || m >= 10) return 1;
	int k; // faktor
	cin >> k;
	if (k <= 2 || k >= 10) return 1;
	vector<Clan> clanovi;
	int brojClanova; cin >> brojClanova;
	for (int i = 0; i < brojClanova; i++) {
		Clan c;
		cin >> c.s >> c.x >> c.y;
		if ((c.s == 'Z' || c.s == 'O') && c.x > 1 && c.x <= n && c.y > 1 && c.y <= m) clanovi.push_back(c);
		else return 1;
	}
	vector<vector<char>> tabla(m, vector<char>(n, '='));
	for (int y = 1; y <= m; y++) {
		for (int x = 1; x <= n; x++) {
			double val = x * y * k;
			if (sin(val) > 0 && cos(val) < 0)
				tabla[y-1][x-1] = 'C';
		}
	}
	return 0;
}