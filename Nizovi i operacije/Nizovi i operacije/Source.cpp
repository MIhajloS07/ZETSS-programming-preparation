#include <iostream>
#include <stdexcept>
#include <algorithm>

// Duzina niza
const int ArrSize = 10;

// Ispis niza
void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) 
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

// Unos niza
void enterArray(int arr[], int size) {
	for (int i = 0; i < size; i++) 
		std::cin >> arr[i];
}

// Zbir elemenata niza
int sumArray(int arr[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += arr[i];
	return sum;
}

// Proizvod elemenata niza
long long productArray(int arr[], int size) {
	long long productVal = 1;
	for (int i = 0; i < size; i++)
		productVal *= arr[i];
	return productVal;
}

// Max element niza
int maxElement(int arr[], int size) {
	int max = arr[0]; // max element je prvi element niza
	for (int i = 0; i < size; i++) 
		// Ako je trenutni element veci od max, onda je on novi max
		if (arr[i] > max) max = arr[i];	
	//std::max_element(arr, arr + size); // Moze i ovako da se nadje max element niza, ali je potrebno ukljuciti algoritam
	return max;
}

// Min element niza
int minElement(int arr[], int size) {
	int min = arr[0]; // min element je prvi element niza
	for (int i = 0; i < size; i++) 
	// Ako je trenutni element manji od min, onda je on novi min
		if (arr[i] < min) min = arr[i];
	//std::min_element(arr, arr + size); // Moze i ovako da se nadje min element niza, ali je potrebno ukljuciti algoritam
	return min;
}

// Brojanje ponavljanja elementa x u nizu (Linearna pretraga)
int countRepeated(int arr[], int size, int x) {
	int count = 0; //brojac
	for (int i = 0; i < size; i++)
		if (arr[i] == x) ++count;
	return count;
}

// Linearna pretraga elementa element u nizu
bool linearSearch(int arr[], int size, int element) {
	for (int i = 0; i < size; i++) 
		if (arr[i] == element)
			return true; 
	return false;
}

// Drugi najveci element niza
int secondMax(int arr[], int size) {
	// Implementacija algoritma za pronalazenje drugog najveceg elementa niza
	int max1 = arr[0], max2 = arr[0]; 
	for (int i = 0; i < size; i++) {
		if (arr[i] > max1) {
			max2 = max1;
			max1 = arr[i];
		}
		else if (arr[i] > max2 && arr[i] != max1) max2 = arr[i];
	}
	return max2;
	/// Imamo niz arr = {1, 2, 3, 4, 5} i radimo pronalazenje drugog najvecih elementa nad njim. 
	/// Nakon izvrsavanja funkcije, dobijamo drugi najveci element niza, koji je 4, zato sto je 
	/// 5 najveci element niza, a 4 je drugi najveci element niza. Na primer, max1 = 5, max2 = 4
	/// nakon izvrsavanja funkcije.
}

// Obrtanje niza
void reverseArray(int arr[], int size) {
	for (int i = 0; i < size / 2; i++)
		std::swap(arr[i], arr[size-i-1]);
	///
	/// Imamo niz arr = {1, 2, 3, 4, 5} i radimo obrtanje niza nad njim. Nakon izvrsavanja funkcije, dobijamo niz arr = {5, 4, 3, 2, 1 }, 
	/// zato sto prvi element niza postaje poslednji, drugi element postaje pretposlednji, itd. Na primer, arr[0] = 1 postaje arr[4] = 1, 
	/// arr[1] = 2 postaje arr[3] = 2, itd.
	///
}

// Prefiksni zbir
void prefixSum(int arr[], int size) {
	int pref[ArrSize];
	pref[0] = arr[0];
	for (int i = 1; i < size; i++)
		pref[i] = pref[i - 1] + arr[i];
	for (int i = 0; i < size; i++)       
		std::cout << pref[i] << " ";
	std::cout << std::endl;
	///
	/// Imamo niz arr = {1, 2, 3, 4, 5} i radimo prefix sum nad njim. Nakon izvrsavanja funkcije, 
	/// dobijamo niz pref = {1, 3, 6, 10, 15}, zato sto prvi element sabiramo sa svakim sledecim elementom niza. 
	/// Na primer, pref[1] = pref[0] + arr[1] = 1 + 2 = 3, pref[2] = pref[1] + arr[2] = 3 + 3 = 6, itd.
	///
}

// Sortiranje niza (algortimi)
// Bubble sort algoritam -> O(n^2)
void bubbleSort(int arr[], int size) { 
	for (int i = 0; i < size; i++) {
		bool swapped = false; // Da li je doslo do zamene elemenata
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				auto temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = true; // Doslo je do zamene elemenata
			}
			// Ili moze i
			/*std::swap(arr[j], arr[j + 1]);*/
		}
		if (!swapped) break; 
	}	
	///
	/// Algoritam bubble sort radi tako sto prolazi kroz niz i uporedjuje susedne elemente. 
	/// Ako je trenutni element veci od sledeceg, onda se ta dva elementa zamene. Tako se 
	/// nastavlja dok se ne prodje kroz ceo niz bez zamene elemenata, sto znaci da je niz sortiran.
	///
}

// Najduzi rastuci podniz (uzastopni)
int longestIncreasingSubarray(int arr[], int size) {
	int maxLength = 1; // Maksimalna duzina rastuceg podniza
	int currentLength = 1; // Trenutna duzina rastuceg podniza	
	for (int i = 1; i < size; i++) {
		if (arr[i] > arr[i-1]) currentLength++;
		else currentLength = 1;
		if (currentLength > maxLength)
			maxLength = currentLength;
	}			
	return maxLength;	
}

void sortArray(int arr[], int size) {
	std::sort(arr, arr + size);
	/// Algoritam std::sort koristi introsort algoritam, koji je kombinacija quicksort, heaps sort i insertion sort algoritama. 
	/// On radi tako sto koristi quicksort algoritam za vecinu elemenata, ali se prebacuje na heaps sort algoritam kada dubina 
	/// rekurzije postane prevelika, a na insertion sort algoritam kada je broj elemenata manji od odredjene vrednosti. Zato je 
	/// std::sort efikasan i brz algoritam za sortiranje niza.
}

int main() {
	try {
		int n; std::cout << "Enter number of elements: "; std::cin >> n;
		int arr[ArrSize];
		// 0, 1, 2 - indeksi niza
		enterArray(arr, n);
		printArray(arr, n);
		if (n > 0 && n <= ArrSize) {
			// Zbir elemenata niza
			std::cout << "Sum of array elements: " << sumArray(arr, n) << std::endl;
			// Min i max
			std::cout << "Max element: " << maxElement(arr, n) << std::endl;
			std::cout << "Min element: " << minElement(arr, n) << std::endl;
			std::cout << "Second max element: " << secondMax(arr, n) << std::endl;
			// Brojanje ponavljanja
			std::cout << "Enter element to count: "; int x; std::cin >> x;
			std::cout << "Element " << x << " is repeated " << countRepeated(arr, n, x) << " times." << std::endl;
			// Linearna pretraga
			std::cout << "Enter element to search: "; int element; std::cin >> element;
			if (linearSearch(arr, n, element))
				std::cout << "Element " << element << " is found in the array." << std::endl;
			else std::cout << "Element " << element << " is not found in the array." << std::endl;
			// Obrtanje niza
			reverseArray(arr, n);
			std::cout << "Reversed array: "; printArray(arr, n);
			// Prefix sum
			prefixSum(arr, n); 
			// Ispis prefix sum niza
			std::cout << "Prefix sum array: "; printArray(arr, n);
			// Sortiranje niza
			//bubbleSort(arr, n);
			//std::cout << "Sorted array: "; printArray(arr, n);
			// Ili moze i
			sortArray(arr, n);
			std::cout << "Sorted array: "; printArray(arr, n);
			// Najduzi rastuci podniz
			std::cout << "Longest increasing subarray length: " << longestIncreasingSubarray(arr, n) << std::endl;
		}
	}
	catch(...) {
		std::cout << "Greska" << std::endl;
	}
	return 0;
}