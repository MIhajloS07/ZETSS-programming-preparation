#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Ucenik {
	string ime;
	string prezime;
	int godine;
	double prosek;
};	

void ispisiUcenike(const vector<Ucenik>& ucenici) {
	for (const Ucenik& u : ucenici) {
		cout << u.ime << " " << u.prezime
			<< " | " << u.prosek << endl;
	}
}

void unesiUcenike(vector<Ucenik>& ucenici, size_t brojUcenika) {
	for (size_t i = 0; i < brojUcenika; i++) {
		Ucenik u;
		cout << "Ucenik " << i + 1 << endl;
		cout << "Ime: ";
		cin >> u.ime;
		cout << "Prezime: ";
		cin >> u.prezime;
		cout << "Godine: ";
		cin >> u.godine;
		cout << "Prosek: ";
		cin >> u.prosek;
		ucenici.push_back(u);
	}
}
int main() {
	//1
	//vector<Ucenik> ucenici;
	//size_t brojUcenika, n = 0;
	//cout << "Unesi broj ucenika: ";
	//cin >> brojUcenika;
	//unesiUcenike(ucenici, brojUcenika);
	//// Svi ucenici sa prosekom preko 4.5
	//cout << "\nUcenici sa prosekom preko 4.5:\n";
	//for (const Ucenik& u : ucenici) {
	//	if (u.prosek > 4.5) {
	//		cout << u.ime << " " << u.prezime
	//			<< " | " << u.prosek << endl;
	//		n++;
	//	}
	//}
	//cout << "Broj ucenika sa prosekom preko 4.5: " << n << endl;
	// 
	//2
	//vector<Ucenik> ucenici;
	//size_t brojUcenika;
	//cout << "Unesi broj ucenika: ";
	//cin >> brojUcenika;
	//unesiUcenike(ucenici, brojUcenika);
	//// Sortiranje ucenika
	//sort(ucenici.begin(), ucenici.end(), 
	//	[](const Ucenik& a, const Ucenik& b) {
	//		if (a.prosek == b.prosek)
	//			return a.prezime < b.prezime; // Sortiraj po prezimenu ako je prosek isti
	//		return a.prosek > b.prosek; // Sortiraj po proseku opadajuce
	//	});
	//// Ispis sortiranih ucenika
	//ispisiUcenike(ucenici);
	//
	//3
	//vector<Ucenik> ucenici;
	//size_t brojUcenika;
	//cout << "Unesi broj ucenika: ";
	//cin >> brojUcenika;
	//unesiUcenike(ucenici, brojUcenika);
	//// Ucenik sa najvecim prosekom
	//auto maxProsek = max_element(ucenici.begin(), ucenici.end(),
	//	[](const Ucenik& a, const Ucenik& b) {
	//		return a.prosek < b.prosek; // Trazi ucenika sa najveciim prosekom
	//	});
	//// Ucenik sa najmanjim prosekom
	//auto minProsek = min_element(ucenici.begin(), ucenici.end(),
	//	[](const Ucenik& a, const Ucenik& b) {
	//		return a.prosek < b.prosek; // Trazi ucenika sa najmanjim prosekom
	//	});
	//// Prosecan prosek svih ucenika
	//double sumaProseka = 0.0;
	//for (const Ucenik& u : ucenici) 
	//	sumaProseka += u.prosek;
	//double prosecniProsek = sumaProseka / ucenici.size();
	//cout << "Prosecan prosek svih ucenika: " << prosecniProsek << endl;
	//cout << "Ucenik sa najveciim prosekom: " << maxProsek->ime << " " << maxProsek->prezime << " | " << maxProsek->prosek << endl;
	//cout << "Ucenik sa najmanjim prosekom: " << minProsek->ime << " " << minProsek->prezime << " | " << minProsek->prosek << endl;
	//
	//4
	//vector<Ucenik> ucenici;
	//vector<Ucenik> punoletniUcenici;
	//size_t brojUcenika;
	//cout << "Unesi broj ucenika: ";
	//cin >> brojUcenika;
	//unesiUcenike(ucenici, brojUcenika);
	//// punoletni ucenici (18 godina i vise)
	//for (const Ucenik& u : ucenici) {
	//	if (u.godine >= 18) {
	//		punoletniUcenici.push_back(u);
	//	}
	//}
	//// sortiranje novog vektora punoletnih ucenika	
	//sort(punoletniUcenici.begin(), punoletniUcenici.end(),
	//	[](const Ucenik& a, const Ucenik& b) {
	//		return a.godine < b.godine; // Sortiraj po godinama rastuce
	//	});
	//// Ispis punoletnih ucenika sortiranih po godinama
	//cout << "\nPunoletni ucenici (18 godina i vise), sortirani po godinama:\n";
	//ispisiUcenike(punoletniUcenici);
	//
	//5
	vector<Ucenik> ucenici;
	size_t brojUcenika;
	cout << "Unesi broj ucenika: ";
	cin >> brojUcenika;
	unesiUcenike(ucenici, brojUcenika);
	// izbacivanje svih ucenika ciji je prosek manji od 2.0
	auto veciProsek = remove_if(ucenici.begin(), ucenici.end(),
		[](const Ucenik& u) {
			return u.prosek < 2.0; // Ucenici sa prosekom manjim od 2.0 ce biti uklonjeni
		});
	ucenici.erase(veciProsek, ucenici.end()); // Uklanjanje izbacenih ucenika iz vektora
	// Prvi ucenik kome pocinje slovo na m
	auto prviM = find_if(ucenici.begin(), ucenici.end(),
		[](const Ucenik& u) {
			if(u.ime.find('m') == 0 || u.ime.find('M') == 0) // Provera da li ime pocinje na 'm' ili 'M'
				return true;
			return false;
		});
	// sortiranje po godinama opadajuce
	sort(ucenici.begin(), ucenici.end(),
		[](const Ucenik& a, const Ucenik& b) {
			if (a.godine == b.godine)
				return a.prosek > b.prosek; // sortiranje po proseku opadajuce 
			return a.godine > b.godine; // sortiranje po godinama opadajuce
		});
	if (ucenici.empty()) {
		cout << "Nema ucenika nakon izbacivanja onih sa prosekom manjim od 2.0." << endl;
		return 0;
	}
	ispisiUcenike(ucenici);
	cout << "\nPrvi ucenik kome ime pocinje na 'm' ili 'M': ";
	if (prviM != ucenici.end()) {
		cout << prviM->ime << " " << prviM->prezime << " | " << prviM->prosek << endl;
	}
	else {
		cout << "Nema ucenika kome ime pocinje na 'm' ili 'M'." << endl;
	}
	return 0;
}
