#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

vector<int> napraviNiz(int n) {
    int x = abs(n);
    vector<int> niz;
    if (x <= 9) {
        niz.push_back(x);
    }
    else {
        string s = to_string(x);
        for (int i = 0; i < (int)s.size() - 1; i++) {
            int broj = (s[i] - '0') * 10 + (s[i + 1] - '0');
            niz.push_back(broj);
        }
    }
    return niz;
}

vector<int> napraviSkup(const vector<int>& niz) {
    vector<int> skup;
    for (int i = 0; i < (int)niz.size(); i++) {
        bool postoji = false;
        for (int j = 0; j < (int)skup.size(); j++) {
            if (niz[i] == skup[j]) {
                postoji = true;
                break;
            }
        }
        if (!postoji) skup.push_back(niz[i]);
    }
    return skup;
}

int main()
{
    ifstream ulaz("datoteka.txt");
    
    // ZAHTEV 1A
    /*#pragma region 1A
    int n;
    ulaz >> n;
    ulaz.close();
    if (n > 1000000 || n < -1000000) return 1;
    vector<int> a;
    int x = abs(n);
    if (x >= 9) {
        string s = to_string(x);
        for (int i = 0; i < (int)s.size(); i++) {
            int broj = (s[i] - '0') * 10 + (s[i + 1] - '0');
            a.push_back(broj);
        }
    }
    else if (x >= 0 && x <= 9) {
        a.push_back(x);
    }
    ofstream izlaz("izlaz.txt");
    for (int broj : a)
        izlaz << broj << " ";
    #pragma endregion*/
    #pragma region 1B
    int n1, n2;
    //ULAZ
    ulaz >> n1 >> n2;
    ulaz.close();
    if (n1 >= 100000 || n1 <= -1000000 || n2 >= 100000 || n2 <= -100000) return 1;
    
    vector<int> skupCelihN1 = napraviSkup(napraviNiz(n1));
    vector<int> skupCelihN2 = napraviSkup(napraviNiz(n2));
    
    //presek
    int presek = 0;
    for (int i = 0; i < (int)skupCelihN1.size(); i++) {
        for (int j = 0; j < (int)skupCelihN2.size(); j++) {
            if (skupCelihN1[i] == skupCelihN2[i]) presek++;
        }
    }
    //unija
    int unija = skupCelihN1.size();
    for (int j = 0; j < (int)skupCelihN2.size(); j++) {
        bool postoji = false;
        for (int i = 0; i < (int)skupCelihN1.size(); i++) {
            if (skupCelihN2[j] == skupCelihN1[i]) {
                postoji = true;
                break;
            }
        }
        if (!postoji) unija++;
    }
    double s = (double)presek / (double)unija;

    ofstream izlaz("izlaz.txt");
    izlaz << s << endl;
    izlaz.close();
    #pragma endregion
    return 0;
}
