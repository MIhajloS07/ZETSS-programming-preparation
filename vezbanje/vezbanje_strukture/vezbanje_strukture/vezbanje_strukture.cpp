#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct Student {
    string ime, prezime;
    int poeni;
};

int main()
{
    int n; cin >> n;
    vector<Student> studenti(n);
    for (int i = 0; i < n; i++) {
        cin >> studenti[i].ime >> studenti[i].prezime >> studenti[i].poeni;
    }
    sort(studenti.begin(), studenti.end(), [](Student s1, Student s2) {
        return s1.poeni > s2.poeni;
    });
    string naziv; cout << "Unesi naziv studenta koga trazis: "; 
    cin >> naziv;
    for (Student s : studenti) {
        if (s.ime == naziv)
            cout << s.ime << "," << s.prezime << "," << s.poeni;
    }
    auto najbolji = max_element(studenti.begin(), studenti.end(), [](Student s1, Student s2) {
        return s1.poeni < s2.poeni;
    });
    auto najgori = min_element(studenti.begin(), studenti.end(),
    	[](const Student& a, const Student& b) {
    		return a.poeni < b.poeni;
    	});
    // prvi koji ima broj poena preko 25
    auto prvi = find_if(studenti.begin(), studenti.end(), [](Student s1) {
        return s1.poeni > 25;
    });
    cout << "Najbolji student sa najvecim brojem poena: " << najbolji->ime << endl;
    cout << "Najgori student sa najmanjim brojem poena: " << najgori->ime << endl;
    cout << "Prvi sa vise od 25 poena: " << prvi->ime << endl;
    ofstream izlaz("studenti.txt");
    for (Student st : studenti)
        izlaz << st.ime << " | " << st.prezime << " | " << st.poeni << endl;
    izlaz.close();
    return 0;
}

