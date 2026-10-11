#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Proces {
    int i;  // jednoznacni identifikator procesa
    int t1; // trenutak u kom proces pocinje da se izvrsava
    int t2; // vreme potrebno da se proces izvrsi 
};

int main()
{
    int n; //broj procesa
    ifstream ulaz("ulaz.txt");
    //ULAZ
    ulaz >> n;
    if (n > 20) return 1;
    vector<Proces> procesi;
    for (int i = 0; i < n; i++) {
        Proces p;
        ulaz >> p.i >> p.t1 >> p.t2;
        procesi.push_back(p);
    }
    ulaz.close();

    // sortiranje identifikaora u rastucem poretku
    sort(procesi.begin(), procesi.end(), [](const Proces& p1, const Proces& p2) {
        return p1.i < p2.i;
    });

    ofstream izlaz("izlaz.txt");
    bool ima = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int kraj1 = procesi[i].t1 + procesi[i].t2;
            int kraj2 = procesi[j].t1 + procesi[j].t2;
            if (procesi[i].t1 < kraj2 && procesi[j].t1 < kraj1) {
                izlaz << procesi[i].i << " " << procesi[j].i << endl;
                ima = true;
            }
        }
    }
    if (!ima) izlaz << "X" << endl;
    izlaz.close();

    return 0;
}
