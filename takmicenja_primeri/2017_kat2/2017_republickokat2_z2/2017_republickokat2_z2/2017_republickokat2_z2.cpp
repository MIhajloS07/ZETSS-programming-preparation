#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool dozvoljen(char ch) {
    string dozvoljeni = "abc*/+-()";
    for (char d : dozvoljeni) if (ch == d) return true;
    return false;
}

int main()
{
    string str;
    ifstream ulaz("datoteka.txt");
    ulaz >> str;
    ulaz.close();
    if (str.empty()) return 1;


    for (char ch : str) {
        if (!dozvoljen(ch)) {
            ofstream izlaz("izlaz.txt");
            izlaz << "X" << endl;
            izlaz.close();
            return 0;
        }
    }

    int balans = 0;
    for (char ch : str) {
        if (ch == '(') balans++;
        if (ch == ')') balans--;
        if (balans < 0) {
            ofstream izlaz("izlaz.txt");
            izlaz << "X" << endl;
            izlaz.close();
            return 0;
        }
    }
    if (balans != 0) {
        ofstream izlaz("izlaz.txt");
        izlaz << "X" << endl;
        izlaz.close();
        return 0;
    }
    ofstream izlaz("izlaz.txt");
    izlaz << "I" << endl;
    izlaz.close();
    return 0;
}
