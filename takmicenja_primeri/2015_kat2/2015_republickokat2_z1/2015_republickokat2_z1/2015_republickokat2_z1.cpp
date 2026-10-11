#include <iostream>
#include <vector>
using namespace std;


int main()
{
    // matrica nxn
	int n;
	//ULAZ
	cin >> n;
	if (n > 10) return 1;

	vector<vector<int>> lavirint(n, vector<int>(n));
	int startX, startY, ciljX, ciljY;
	
	// ULAZ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> lavirint[i][j];
			if (lavirint[i][j] == 3) { startX = i; startY = j; }
			if (lavirint[i][j] == 2) { ciljX = i; ciljY = j; }
		}
	}

	// 0 - slobodno polje
	// 1 - blok
	// 2 - jabuka
	// 3-  cikica

	// IZLAZ
    return 0;
}
