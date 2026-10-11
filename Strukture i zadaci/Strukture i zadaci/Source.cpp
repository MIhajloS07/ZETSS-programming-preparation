#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Ucenik {
	string ime;
	string prezime;
	short godine;
	double prosek;
};

int main() {
	//// deklaracija
	//vector<Ucenik> ucenici;
	///*Ucenik u[100];*/
	//int brojUcenika;

	//cout << "Unesi broj ucenika: ";
	//cin >> brojUcenika;

	//for (int i = 0; i < brojUcenika; i++) {
	//	Ucenik u;
	//	cout << "Ucenik " << i + 1 << endl;
	//	cout << "Ime: ";
	//	cin >> u.ime;
	//	cout << "Prezime: ";
	//	cin >> u.prezime;
	//	cout << "Godine: ";
	//	cin >> u.godine;
	//	cout << "Prosek: ";
	//	cin >> u.prosek;
	//	// dodaj u vector
	//	ucenici.push_back(u);
	//}

	//if (ucenici.empty()) return 0;

	//cout << "\nPre sortiranja:\n";
	//for (const Ucenik& u : ucenici)
	//	cout << u.ime << " | " << u.prezime << " | " << u.godine << " | " << u.prosek << endl;

	//// sortiranje ucenika prema godinama
	//sort(ucenici.begin(), ucenici.end(), [](const Ucenik& a, const Ucenik& b) {
	//	return a.godine > b.godine;
	//	});
	//// najbolji po proseku
	//auto najboljiPoProseku = max_element(ucenici.begin(), ucenici.end(),
	//	[](const Ucenik& a, const Ucenik& b) {
	//		return a.prosek < b.prosek;
	//	});
	//// najgori po proseku
	//auto najgoriPoProseku = min_element(ucenici.begin(), ucenici.end(),
	//	[](const Ucenik& a, const Ucenik& b) {
	//		return a.prosek < b.prosek;
	//	});
	//// prvi koji ima prosek preko 4.5
	//auto it = find_if(ucenici.begin(), ucenici.end(), 
	//	[](const Ucenik& u) {
	//		return u.prosek > 4.5;
	//	});
	//// broj ucenika koji imaju preko 18 godina
	//auto brojPunoletnih = count_if(ucenici.begin(), ucenici.end(),
	//	[](const Ucenik& u) {
	//		return u.godine > 18;
	//	});

	//cout << "\nNajbolji po proseku:\n";
	//cout << najboljiPoProseku->ime << " " << najboljiPoProseku->prezime
	//	<< " | " << najboljiPoProseku->prosek << endl;

	//cout << "\nNajgori po proseku:\n";
	//cout << najgoriPoProseku->ime << " " << najgoriPoProseku->prezime
	//	<< " | " << najgoriPoProseku->prosek << endl;
	//if (it != ucenici.end()){
	//	cout << "\nPrvi sa prosekom preko 4.5:\n";
	//	cout << it->ime << " " << it->prezime
	//		<< " | " << it->prosek << endl;
	//}
	//else {
	//	cout << "Nema ucenika sa prosekom preko 4.5" << endl;
	//}
	//cout << "\nBroj punoletnih ucenika:\n";
	//cout << brojPunoletnih << endl;

	//cout << "\nPosle sortiranja:\n";
	//for (const Ucenik& u : ucenici)
	//	cout << u.ime << " | " << u.prezime << " | "
	//	<< u.godine << " | " << u.prosek << endl;

	//1
	vector<Ucenik> ucenici;
	size_t brojUcenika, n = 0;
	cout << "Unesi broj ucenika: ";
	cin >> brojUcenika;
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
	// Svi ucenici sa prosekom preko 4.5
	cout << "\nUcenici sa prosekom preko 4.5:\n";
	for (const Ucenik& u : ucenici) {
		if (u.prosek > 4.5) {
			cout << u.ime << " " << u.prezime
				<< " | " << u.prosek << endl;
			n++;
		}
	}
	cout << "\nBroj ucenika sa prosekom preko 4.5: " << n << endl;
	
	//2

	return 0;
}