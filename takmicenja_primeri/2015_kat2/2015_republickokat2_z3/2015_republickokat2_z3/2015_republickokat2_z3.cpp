#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cekajSprat(int trenutnoVreme, int sprat) {
	int ciklus = 4 * sprat;
	int mod = trenutnoVreme % ciklus; 
    // Sijalice su upaljene, nema cekanja
    if (mod < 2 * sprat) return 0;    
    else return ciklus - mod; // Sijalice su ugašene, cekaj do sledeceg paljenje
}

int main()
{
    int n, m;
    //ULAZ
	cin >> n >> m;

    // OGRANICENJA
    if (n > 10) return 1;
	if (m < 4 || m > 10) return 1;

	vector<int> vremenaKupaca;

    for (int i = 0; i < m; i++)
    {
        int brojPosecenihSpratova;
		cin >> brojPosecenihSpratova;
        vector<int> spratovi(brojPosecenihSpratova);
        for (int j = 0; j < brojPosecenihSpratova; j++)
            cin >> spratovi[j];
        int vreme = 0;
        // u kupovinu svaki kupac provede 3 * redniBrojSprata minuta
		// sijalice u godniku se naizmenicno pale i gase u trajanju od  2 * redniBrojSprata minuta
        for (int k = 0; k < brojPosecenihSpratova; k++)
        {
            int sprat = spratovi[k];
            vreme += 3 * sprat; // vreme provedeno u kupovini
            if (k > 0) 
                vreme += cekajSprat(vreme, sprat); // vreme cekanja na spratu
		}
		vremenaKupaca.push_back(vreme);
	}

    sort(vremenaKupaca.begin(), vremenaKupaca.end());
    // Zbirno vreme tri kupca koji su najmanje cekali
    int zbir = vremenaKupaca[0] + vremenaKupaca[1] + vremenaKupaca[2];
    cout << zbir << endl;
    return 0;
}