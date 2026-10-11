#include <iostream>

const int rows = 100, columns = 100;

void printMatrix(int matrix[rows][columns], int n) {
	// Ispis elemenata matrice
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	// Glavna (main) dijagonala
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				std::cout << matrix[i][j] << std::endl;
		}
		std::cout << "\t";
	}*/
	// Efikasniji nacin za ispis glavne dijagonale
	for (int i = 0; i < n; i++) {
		std::cout << matrix[i][i] << "\t";
	}
	std::cout << std::endl;
	// Sporedna (secondary) dijagonala
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j == n - 1)
				std::cout << matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

void enterMatrix(int matrix[rows][columns], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> matrix[i][j];
		}
	}
}

int sumMainDiagonal(int matrix[rows][columns], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += matrix[i][i];
	}
	return sum;
}

int sumSecondaryDiagonal(int matrix[rows][columns], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += matrix[i][n - 1 - i];
	}
	return sum;
}

void sumRows(int matrix[rows][columns], int n) {
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += matrix[i][j];
		}
		std::cout << "Suma reda " << i << " = " << sum << std::endl;
	}
}

void sumColumns(int matrix[rows][columns], int n) {
	for (int j = 0; j < n; j++) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += matrix[i][j];
		}
		std::cout << "Suma kolone " << j << " = " << sum << std::endl;
	}
}

void sumElementsUnderMainDiagonal(int matrix[rows][columns], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) { // Prolazimo samo kroz elemente ispod glavne dijagonale
			// i > j jer su elementi ispod glavne dijagonale oni za koje je indeks reda veci od indeksa kolone
			sum += matrix[i][j];
		}
	}
	std::cout << "Suma elemenata ispod glavne dijagonale = " << sum << std::endl;
}

void sumElementsAboveMainDiagonal(int matrix[rows][columns], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) { // Prolazimo samo kroz elemente iznad glavne dijagonale
			// i < j jer su elementi iznad glavne dijagonale oni za koje je indeks kolone veci od indeksa reda
			sum += matrix[i][j];
		}
	}
	std::cout << "Suma elemenata iznad glavne dijagonale = " << sum << std::endl;
}

void transposeMatrix(int matrix[rows][columns], int n) {
	int transposed[rows][columns]; // Dvodimenzionalni niz za transponovanu matricu
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			transposed[j][i] = matrix[i][j];
		}
	}
	// Ispis transponovane matrice
	printMatrix(transposed, n);
}
/// <summary>
/// Tranponovanje matrice je proces zamene redova i kolona. 
/// Na primer, element na poziciji (i, j) u originalnoj matrici
/// postaje element na poziciji (j, i) u transponovanoj matrici. 
/// Rotacija matrice za 90 stepeni u smeru kazaljke na satu se 
/// postiže tako što se element na poziciji (i, j) u originalnoj 
/// matrici postavlja na poziciju (j, n - 1 - i) u rotiranoj matrici. 
/// Rotacija za 90 stepeni u smeru suprotnom od kazaljke na satu se 
/// postiže tako što se element na poziciji (i, j) u originalnoj matrici
/// postavlja na poziciju (n - 1 - j, i) u rotiranoj matrici. Rotacija za
/// 180 stepeni se postiže tako što se element na poziciji (i, j) u originalnoj
/// matrici postavlja na poziciju (n - 1 - i, n - 1 - j) u rotiranoj matrici.
/// </summary>
/// <param name="matrix"></param>
/// <param name="n"></param>

void rotateMatrix90Degrees(int matrix[rows][columns], int n) {
	int rotated[rows][columns]; // Dvodimenzionalni niz za rotiranu matricu
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			rotated[j][n - 1 - i] = matrix[i][j]; // Rotacija za 90 stepeni u smeru kazaljke na satu
		}
	}
	// Ispis rotirane matrice
	printMatrix(rotated, n);
}

void rotateMatrix90CounterClockwise(int matrix[rows][columns], int n) {
	// Dvodimenzionalni niz za rotiranu matricu
	int rotated[rows][columns];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			rotated[n - 1 - j][i] = matrix[i][j]; // Rotacija za 90 stepeni u smeru suprotnom od kazaljke na satu
		}
	}
	// Ispis rotirane matrice
	printMatrix(rotated, n);
}

void rotateMatrix180Degrees(int matrix[rows][columns], int n) {
	int rotated[rows][columns]; // Dvodimenzionalni niz za rotiranu matricu
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			rotated[n - 1 - i][n - 1 - j] = matrix[i][j]; // Rotacija za 180 stepeni
		}
	}
	// Ispis rotirane matrice
	printMatrix(rotated, n);
}

bool isSymetric(int matrix[rows][columns], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) { // Proveravamo samo elemente iznad glavne dijagonale
			if (matrix[i][j] != matrix[j][i]) return false;
		}
	}
	return true;
}
///
/// Provera da li je matrica simetricna se vrsi tako sto se uporedjuju elementi
/// iznad glavne dijagonale sa odgovarajucim elementima ispod glavne dijagonale.
///


// 1 2 3
// 4 5 6
// 7 8 9

int main() {
	int matrix[rows][columns]; // Deklaracija dvodimenzionalnog niza
	int n; // Broj redova i kolona matrice
	// Unos elemenata matrice
	std::cout << "Unesite broj redova i kolona matrice: ";
	std::cin >> n;
	std::cout << "Unesite elemente matrice:" << std::endl;
	enterMatrix(matrix, n);
	// Ispis elemenata matrice
	//printMatrix(matrix, n);
	// Suma elemenata glavne dijagonale
	std::cout << "Suma elemenata glavne dijagonale = " << sumMainDiagonal(matrix, n) << std::endl;
	// Suma elemenata sporedne dijagonale
	std::cout << "Suma elemenata sporedne dijagonale = " << sumSecondaryDiagonal(matrix, n) << std::endl;
	// Suma elemenata redova
	sumRows(matrix, n);
	// Transponovanje matrice
	std::cout << "Transponovana matrica:" << std::endl;
	transposeMatrix(matrix, n);
	// Provera da li je matrica simetricna
	if (isSymetric(matrix, n)) {
		std::cout << "Matrica je simetricna." << std::endl;
	}
	else {
		std::cout << "Matrica nije simetricna." << std::endl;
	}
	// Rotacija matrice za 90 stepeni u smeru kazaljke na satu
	std::cout << "Matrica rotirana za 90 stepeni u smeru kazaljke na satu:" << std::endl;
	rotateMatrix90Degrees(matrix, n);
	// Rotacija matrice za 90 stepeni u smeru suprotnom od kazaljke na satu
	std::cout << "Matrica rotirana za 90 stepeni u smeru suprotnom od kazaljke na satu:" << std::endl;
	rotateMatrix90CounterClockwise(matrix, n);
	// Rotacija matrice za 180 stepeni
	std::cout << "Matrica rotirana za 180 stepeni:" << std::endl;
	rotateMatrix180Degrees(matrix, n);
	return 0;
}