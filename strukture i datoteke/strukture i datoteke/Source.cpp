#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

struct Ucenik {
    string ime;
    string prezime;
    int godine;
    double prosek;
};

int main() {
    vector<Ucenik> ucenici;
    ifstream ulaz("ucenici.txt");
    if (!ulaz) {
        cout << "Ne mogu otvoriti datoteku!" << endl;
        return 1;
    }
    Ucenik temp;
    while (ulaz >> temp.ime >> temp.prezime >> temp.godine >> temp.prosek)
        ucenici.push_back(temp);

    ulaz.close();

    // Sortiranje po imenu ukoliko su prezimena ista, sortiraj po prezimenu
    sort(ucenici.begin(), ucenici.end(), [](const Ucenik& a, const Ucenik& b) {
        if (a.prezime == b.prezime)
            return a.ime < b.ime;
        return a.prezime < b.prezime;
        });

    // Najbolji ucenik po proseku
    auto najboljiPoProseku = max_element(ucenici.begin(), ucenici.end(), [](const Ucenik& a, const Ucenik& b) {
        return a.prosek < b.prosek;
        });
    auto najgoriPoProseku = min_element(ucenici.begin(), ucenici.end(), [](const Ucenik& a, const Ucenik& b) {
        return a.prosek < b.prosek;
        });
    // Prosecan prosek svih ucenika
    double sumaProseka = 0;
    for (Ucenik u : ucenici)
        sumaProseka += u.prosek;
    double prosecniProsek = sumaProseka / ucenici.size();


    // Prvi ucenik cije ime pocinje na slovo 'A'
    auto prviNaA = find_if(ucenici.begin(), ucenici.end(), [](const Ucenik& u){
        if (!u.ime.empty() && u.ime[0] == 'A')
                return true;
			return false;
        });

	// ispis ucenika cije ime pocinje na slovo 'A'
	if (prviNaA != ucenici.end())
		cout << "Prvi ucenik cije ime pocinje na slovo 'A': " << prviNaA->ime << " " << prviNaA->prezime << " " << prviNaA->godine << " " << prviNaA->prosek << endl;

    // Svi ucenici koji imaju prosek preko 4.5
    vector<Ucenik> iznadProseka;
    for (Ucenik u : ucenici)
        if (u.prosek > 4.5)
			iznadProseka.push_back(u);  

	ofstream izlaz("izlaz.txt");
	for (Ucenik u : iznadProseka)
		izlaz << u.ime << " " << u.prezime << " " << u.godine << " " << u.prosek << endl;

    // ispis svih ucenika
    for (Ucenik u : ucenici)
		cout << u.ime << " " << u.prezime << " " << u.godine << " " << u.prosek << endl;

	// Ispis rezultata
	cout << "Najbolji ucenik: " << najboljiPoProseku->ime << " " << najboljiPoProseku->prezime << " sa prosekom " << najboljiPoProseku->prosek << endl;
	cout << "Najgori ucenik: " << najgoriPoProseku->ime << " " << najgoriPoProseku->prezime << " sa prosekom " << najgoriPoProseku->prosek << endl;
	cout << "Prosecan prosek svih ucenika: " << prosecniProsek << endl;
    

    return 0;

}