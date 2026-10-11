#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

//1
int sumNums(ifstream& f) {
	int n, sum = 0;
	while (f >> n)
		sum += n;
	return sum;
}
//2
double averageNums(ifstream& f) {
	int n, numsCount = 0;
	long long sum = 0;
	while (f >> n) {
		numsCount++;
		sum += n;
	}
	if (numsCount == 0) return 0;
	return (double)sum / numsCount;
}
//3
int maxNum(ifstream& f) {
	int n, max;
	if (!(f >> max)) return 0;
	while (f >> n)
		if (n > max)
			max = n;
	return max;
}
//4
int minNum(ifstream& f) {
	int n, min;
	if (!(f >> min)) return 0;
	while (f >> n)
		if (n < min)
			min = n;
	return min;
}
// 5
vector<int> evenNums(ifstream& f) {
	int n;
	vector<int> even;
	while (f >> n)
		if (n % 2 == 0)
			even.push_back(n);
	return even;
}
// 6
vector<int> oddNums(ifstream& f) {
	int n;
	vector<int> odd;
	while (f >> n)
		if (n % 2 != 0)
			odd.push_back(n);
	return odd;
}
// 7 
size_t numsInFile(ifstream& f) {
	size_t numsCount = 0;
	int n;
	while (f >> n)
		numsCount++;
	return numsCount;
}
// 8 
size_t linesCountFile(ifstream& f) {
	string line;
	size_t lineCount = 0;
	while (getline(f, line))
		lineCount++;
	return lineCount;
}
//9
string longestWord(ifstream& f) {
	string word, longest;
	while (f >> word)
		if (word.size() > longest.size())
			longest = word;
	return longest;
}
//10
string shortestWord(ifstream& f) {
	string word, shortest;
	while (f >> word)
		if (shortest.empty() || word.size() < shortest.size())
			shortest = word;
	return shortest;
}
//11
size_t countWords(ifstream& f) {
	string word;
	size_t wordCount = 0;
	while (f >> word)
		wordCount++;
	return wordCount;
}
//12
void copyFile(ifstream& in, ofstream& out) {
	string line;
	while (getline(in, line))
		out << line << '\n';
}
//13
vector<int> sortNums(ifstream& f) {
	int num;
	vector<int> numbers;
	while (f >> num)
		numbers.push_back(num);
	sort(numbers.begin(), numbers.end());
	return numbers;
}
//14
vector<int> countMorethan100(ifstream& f){
	vector<int> numbers;
	int num;
	while (f >> num)
		if (num > 100)
			numbers.push_back(num);
	return numbers;
}
//15
int sumEvenNums(ifstream& f) {
	int num, evenSum = 0;
	while (f >> num)
		if (num % 2 == 0)
			evenSum += num;
	return evenSum;
}
//16
int sumOddNums(ifstream& f) {
	int num, oddSum = 0;
	while (f >> num)
		if (num % 2 != 0)
			oddSum += num;
	return oddSum;
}
//17
vector<int> firstTenNums(ifstream& f) {
	vector<int> numbers;
	int num;
	while (f >> num && numbers.size() < 10)
		numbers.push_back(num);
	return numbers;
}
//18
size_t countChars(ifstream& f) {
	string word;
	size_t charCount = 0;
	while (f >> word)
		for (char ch : word)
			charCount++;
	return charCount;
}
//19
string maxLineLength(ifstream& f) {
	string line, longestLine;
	size_t maxWords = 0;
	while (getline(f, line)) {
		string word;
		size_t wordCount = 0;
		stringstream ss(line);
		while (ss >> word)
			wordCount++;
		if (wordCount > maxWords) {
			maxWords = wordCount;
			longestLine = line;
		}
	}
	return longestLine;
}
//20
vector<string> wordSizeMorethanFive(ifstream& f) {
	string word;
	vector<string> words;
	while (f >> word)
		if (word.length() > 5)
			words.push_back(word);
	return words;
}

vector<int> loadNums(ifstream& f) {
	vector<int> v; int x;
	while (f >> x) v.push_back(x);
	return v;
}

int main() {
	ifstream f("brojevi.txt");
	if (!f) {
		cout << "Greska pri otvaranju datoteke";
	}
	else {
		cout << "Suma brojeva je: " << sumNums(f) << endl;
		f.clear();
		f.seekg(0);
		cout << "Prosek brojeva je: " << averageNums(f) << endl;
		f.clear();
		f.seekg(0);
		cout << "Max broj je: " << maxNum(f) << endl;
		f.clear();
		f.seekg(0);
		cout << "Min broj je: " << minNum(f) << endl;
		f.clear();
		f.seekg(0);
		cout << "Parni brojevi su: ";
		vector<int> ev = evenNums(f);
		for (int x : ev) cout << x << " ";
		cout << endl;
		f.clear();
		f.seekg(0);
		cout << "Neparni brojevi su: ";
		vector<int> odd = oddNums(f);
		for (int x : odd) cout << x << " ";
		cout << endl;
		f.clear();
		f.seekg(0);
		cout << "Broj cifara u fajlu: " << numsInFile(f) << endl;
		f.clear();
		f.seekg(0);
		cout << "Broj linija u fajlu: " << linesCountFile(f) << endl;
	}
	f.close();
	return 0;
}