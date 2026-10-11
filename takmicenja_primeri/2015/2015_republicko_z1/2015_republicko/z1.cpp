#include <iostream>
using namespace std;

int main() {
	// Jedan dan ima 24 sata, 60 minuta i 60 sekundi, sto znaci da ima 24*60*60 = 86400 sekundi.
	int x1, y1, z1; // vreme kada je avion uzleteo
	int q; // broj sekundi koji su proveli u letu
	int x2, y2, z2; // vreme kada su putnici otisli u buducnost
	
	// PRVI RED UNOSA
	cin >> x1 >> y1 >> z1;
	if (x1 < 0 || x1 > 23 || y1 < 0 || y1 > 59 || z1 < 0 || z1 > 59) return 1;
		
	// DRUGI RED UNOSA
	cin >> q;
	if (q < 0 || q > 1000000) return 1;
	
	// TRECI RED UNOSA
	cin >> x2 >> y2 >> z2;
	if (x2 < 0 || x2 > 1000 || y2 < 0 || y2 > 1000 || z2 < 0 || z2 > 1000) return 1;	

	// Odredjivanje trenutjka vremena u nekom danu u buducnosti u koji je vremenska masina prenela putnike
	int ukupnoSekundi = x1 * 3600 + y1 * 60 + z1 + q; // ukupno sekundi od pocetka dana

	
	int ukupnoSekundiVremenskeMasine = x2 * 3600 + y2 * 60 + z2; // ukupno sekundi od pocetka dana u buducnosti
	int novoUkupnoSekundi = ukupnoSekundiVremenskeMasine + ukupnoSekundi; // ukupno sekundi od pocetka dana u buducnosti nakon sabiranja

	// format sati, minuta i sekundi
	int noviSati = (novoUkupnoSekundi / 3600) % 24; // dobijamo broj sati i uzimamo ostatak pri deljenju sa 24 da bismo dobili format sati
	int noviMinuti = (novoUkupnoSekundi / 60) % 60; // dobijamo broj minuta i uzimamo ostatak pri deljenju sa 60 da bismo dobili format minuta
	int noveSekundi = novoUkupnoSekundi % 60; // dobijamo broj sekundi i uzimamo ostatak pri deljenju sa 60 da bismo dobili format sekundi
	
	// IZLAZ
	cout << noviSati << " " << noviMinuti << " " << noveSekundi << endl;

	return 0;
}