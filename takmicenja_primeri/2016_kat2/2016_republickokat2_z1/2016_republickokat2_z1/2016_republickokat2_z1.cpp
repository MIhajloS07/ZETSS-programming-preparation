#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dr[10] = { 0, 1, 1, 1, 0, 0, 0, -1, -1, -1 };
int dc[10] = { 0, -1, 0, 1, -1, 0, 1, -1, 0, 1 };

int main() {
    int t, s;
    cin >> t >> s;
    if (t < 1 || t > 100 || s < 1 || s > 100) return 1;

    vector<string> tabla(t);
    for (int i = 0; i < t; i++) cin >> tabla[i];

    string potezi;
    cin >> potezi;

    int igracR, igracC;
    vector<int> robotiR, robotiC;

    // pronalazak igrača i robota
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < s; j++) {
            if (tabla[i][j] == 'I') { igracR = i; igracC = j; }
            if (tabla[i][j] == 'R') { robotiR.push_back(i); robotiC.push_back(j); }
        }
    }

    for (int p = 0; p < (int)potezi.size(); p++) {
        int move = potezi[p] - '0';
        igracR += dr[move];
        igracC += dc[move];

        // ako igrač stane na robota
        for (int i = 0; i < (int)robotiR.size(); i++) {
            if (robotiR[i] == igracR && robotiC[i] == igracC) {
                cout << "kraj " << p + 1 << endl;
                return 0;
            }
        }

        // pomeranje robota
        for (int i = 0; i < (int)robotiR.size(); i++) {
            if (robotiR[i] < igracR) robotiR[i]++;
            else if (robotiR[i] > igracR) robotiR[i]--;
            if (robotiC[i] < igracC) robotiC[i]++;
            else if (robotiC[i] > igracC) robotiC[i]--;
        }

        // eksplozije
        vector<bool> unisteni(robotiR.size(), false);
        for (int i = 0; i < (int)robotiR.size(); i++) {
            for (int j = i + 1; j < (int)robotiR.size(); j++) {
                if (robotiR[i] == robotiR[j] && robotiC[i] == robotiC[j]) {
                    unisteni[i] = true;
                    unisteni[j] = true;
                }
            }
        }

        // ako robot stane na igrača
        for (int i = 0; i < (int)robotiR.size(); i++) {
            if (!unisteni[i] && robotiR[i] == igracR && robotiC[i] == igracC) {
                cout << "kraj " << p + 1 << endl;
                return 0;
            }
        }

        // ukloni uništene robote
        vector<int> noviR, noviC;
        for (int i = 0; i < (int)robotiR.size(); i++) {
            if (!unisteni[i]) {
                noviR.push_back(robotiR[i]);
                noviC.push_back(robotiC[i]);
            }
        }
        robotiR = noviR;
        robotiC = noviC;
    }

    // ako preživi sve poteze
    vector<string> rez(t, string(s, '.'));
    rez[igracR][igracC] = 'I';
    for (int i = 0; i < (int)robotiR.size(); i++) rez[robotiR[i]][robotiC[i]] = 'R';
    for (int i = 0; i < t; i++) cout << rez[i] << endl;

    return 0;
}
