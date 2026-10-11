#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //ULAZ
	int n; // kucni broj Gordanine kuce
	cin >> n;
	if (n < 1 || n > 10000)
		return 1;

	//okrug
	int k = 0;
	while ((2*k+1)*(2*k+1) < n)
		k++;
	int brojKucaUOkrugu = 8 * k; // broj kuca u okrugu k

	int m = 2 * k + 1; // broj kuca u okrugu k + 1
	vector<vector<int>> grad(m, vector<int>(m, 0));

	//IZLAZ



    return 0;
}

