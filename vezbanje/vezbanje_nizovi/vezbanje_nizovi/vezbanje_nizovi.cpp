#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    // ulaz i ogranicenja
    int N; cin >> N;
    if (N > 100) return 1;
    vector<int> niz(N);
    for (int i = 0; i < N; i++) cin >> niz[i];
#pragma region zad_1
    // najduzi rastuci podniz u nizu
    vector<int> trenutni, najbolji;
    trenutni.push_back(niz[0]); // dodajemo prvi element bez obzira da li je rastuci ili ne
    for (int i = 1; i < N; i++) {
        if (niz[i] > niz[i - 1]) { trenutni.push_back(niz[i]); }
        else {
            if (trenutni.size() > najbolji.size())
                najbolji = trenutni;
            trenutni.clear();
            trenutni.push_back(niz[i]);
        }
    }
    if (trenutni.size() > najbolji.size())
        najbolji = trenutni;
    for (int el : najbolji)
        cout << el << " ";
    cout << endl;
#pragma endregion
#pragma region zad_3
    // sve elemente koji se pojavljuju vise od dva puta -> frekvencija niza
    vector<int> bezD;
    int freq[1000] = { 0 };
    for (int x : niz) freq[x]++;      
    for (int x : niz)
        if (freq[x] <= 2) bezD.push_back(x);          
    for (int el : bezD)
        cout << el << " ";
    cout << endl;
#pragma endregion
#pragma region zad_4
    // da li se niz moze podeliti na dva dela jednakom sumom
    int sumaLeve = 0, sumaDesne = 0;
    for (int i = 0; i < N / 2; i++) 
        sumaLeve += niz[i];
    for (int i = N / 2; i < niz.size(); i++)
        sumaDesne += niz[i];
    if (sumaLeve == sumaDesne && N%2 == 0)
        cout << "Moze";
    else cout << "Ne moze";
    cout << endl;
#pragma endregion
#pragma region zad_5
    // izbacivanje duplikata iz niza niz
    set<int> bezDuplikata(niz.begin(), niz.end());
    for (int el : bezDuplikata) cout << el << " ";
    cout << endl;
#pragma endregion
#pragma region zad_6
    // binarna pretraga odredjenog elementa u nizu
    sort(niz.begin(), niz.end());
    int element; cin >> element;
    if (binary_search(niz.begin(), niz.end(), element)) {
        auto it = lower_bound(niz.begin(), niz.end(), element); // vraca iterator na prvi element
        cout << "Postoji na indeksu: " << (it - niz.begin()) << endl;
    }
    else {
        cout << "Ne postoji" << endl;
    }        
#pragma endregion
#pragma region zad_7
    // drugi najveci element
    int max1 = niz[0], max2 = niz[0];
    for (int el : niz) {
        if (el > max1) {
            max2 = max1;
            max1 = el;
        }
        else if (el > max2 && el != max1) max2 = el;
    }
    cout << "Drugi najveci element u nizu: " << max2 << endl;
#pragma endregion
#pragma region zad_8
    // okretanje niza
    vector<int> kopijaNiz = niz;
    for (int i = 0; i < kopijaNiz.size() / 2; i++)
        swap(kopijaNiz[i], kopijaNiz[kopijaNiz.size() - i - 1]);
    // okrenut niz (kopija):
    for (int el : kopijaNiz)
        cout << el << " ";
    cout << endl;
#pragma endregion
#pragma region zad_9
    // prefiksni zbir niza
    vector<int> pref(N);
    pref[0] = niz[0];
    for (int i = 1; i < N; i++)
        pref[i] = pref[i - 1] + niz[i];

    for (int el : pref)
        cout << el << " ";
    cout << endl;
#pragma endregion
    return 0;
}
