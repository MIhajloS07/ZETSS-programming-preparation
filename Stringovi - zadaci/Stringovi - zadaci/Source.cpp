#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

// 1
size_t brojReci(const string& s) {
	istringstream stream(s);
	size_t words = 0;
	string word;
	while (stream >> word) {
		words++;
	}
	return words;
}
// 2
size_t countVowels(const string& s) {
	size_t vowelCount = 0;
	for (auto& ch : s)
		if (tolower(ch) == 'a' 
			|| tolower(ch) == 'e' 
			|| tolower(ch) == 'i' 
			|| tolower(ch) == 'o' 
			|| tolower(ch) == 'u')
			vowelCount++;
	return vowelCount;
}
// 3
string reverseString(string& s) {
	string temp = s;
	reverse(temp.begin(), temp.end());
	return temp;
}
// 4
bool isPalindrome(const string& s) {
	string reversed = s;
	reverse(reversed.begin(), reversed.end());
	return reversed == s; 
}
// 5
string longestWord(const string& s) {
	istringstream stream(s);
	string longest, word;
	while (stream >> word) 
		if (word.size() > longest.size())
			longest = word;
	return longest;
}
// 6
string shortestWord(const string& s) {
	istringstream stream(s);
	string shortest, word;
	while (stream >> word)
		if (shortest.empty() || word.size() < shortest.size())
			shortest = word;
	return shortest;
}
// 7
string changeChars(string& s, char target = 'a') {
	for (auto& ch : s)
		if (ch == target) ch = '@';
	return s;
}
// 8
string removeSpace(string& s) {
	string result;
	for (auto& ch : s)
		if (ch != ' ')
			result += ch;
	return result;
}
// 9
size_t countNumbers(const string& s) {
	size_t numberCount = 0;
	for (auto& ch : s)
		if (isdigit(ch))
			numberCount++;
	return numberCount;
}
//10
char mostRepeatedNum(const string& s) {
	int freq[256] = { 0 };
	for (auto ch : s)
		freq[ch]++;
	int maxFreq = 0;
	char mostChar = '\0';
	for (int i = 0; i < 256; i++){
		if (freq[i] > maxFreq) {
			maxFreq = freq[i];
			mostChar = (char)i;
		}
	}
	return mostChar;
}
//11
bool isAnagram(const string& s1, const string& s2) {
	if (s1.size() != s2.size()) return false;
	int freq[256] = { 0 };
	for (char ch : s1)
		freq[ch]++;
	for (char ch : s2)
		freq[ch]--;
	for (int i = 0; i < 256; i++)
		if (freq[i] != 0) return false;
	return true;
}
//12
string sortCharsString(string s) {
	sort(s.begin(), s.end());
	return s;
}
//13
string sortWordsString(const string& s) {
	istringstream stream(s);
	string word, result;
	while (stream >> word) {
		sort(word.begin(), word.end());
		result += word + ' ';
	}
	if (!result.empty())
		result.pop_back();
	return result;
}
//14
size_t firstFindChar(const string& s, char target) {
	return s.find(target);
}
//15
size_t LastFindChar(const string& s, char target) {
	return s.rfind(target);
}
//16
size_t countUpperCaseChars(const string& s) {
	size_t upperCaseCharCount = 0;
	for (char ch : s)
		if (isupper(ch))
			upperCaseCharCount++;
	return upperCaseCharCount;
}
//17
size_t countLowerCaseChars(const string& s) {
	size_t lowerCaseCharCount = 0;
	for (char ch : s)
		if (islower(ch))
			lowerCaseCharCount++;
	return lowerCaseCharCount;
}
//18
string removeExtraSpaces(const string& s) {
	string result;
	bool space = false;
	for (char ch : s) {
		if (ch != ' ') {
			result += ch;
			space = false;
		}
		else {
			if (!space) {
				result += ' ';
				space = true;
			}
		}
	}
	return result;
}
//19
string nameInitials(const string& s){
	bool newWord = true;
	string result;
	for (char ch : s) {
		if (isalpha(ch) && newWord) {
			result += toupper(ch);
			result += ' ';
			newWord = false;
		}
		else if (isspace(ch))
			newWord = true;
	}	
	return result;
}
//20
vector<string> splitWords(const string& s) {
	istringstream stream(s);
	vector<string> words;
	string word;
	while (stream >> word)
		words.push_back(word);
	return words;
}
//21
bool isNumber(const string& s) {
	if (s.empty()) return false;
	for (char ch : s)
		if (!isdigit(ch))
			return false;
	return true;
}

int main() {
	string s, ss;

	cout << "Unesi string s: ";
	getline(cin, s);
	cout << "Unesi string ss: ";
	getline(cin, ss);

	cout << "---------------ODGOVORI-----------------" << endl;

	cout << "Broj reci u stringu: " << brojReci(s) << endl;
	cout << "Broj samoglasnika u stringu: " << countVowels(s) << endl;
	cout << "Najduza rec: " << longestWord(s) << endl;
	cout << "Najkraca rec: " << shortestWord(s) << endl;
	cout << "Palindrom: " << isPalindrome(s) << endl;
	cout << "Inicijali: " << nameInitials(s) << endl;

	cout << "Bez razmaka: " << removeSpace(s) << endl;
	cout << "Broj cifara: " << countNumbers(s) << endl;
	cout << "Najcesce slovo: " << mostRepeatedNum(s) << endl;
	vector<string> words = splitWords(s);
	cout << "Deljenje stringa() na reci: " << endl;
	for (const auto& w : words) cout << w << ", " << endl;

	cout << "Anagram: " << isAnagram(s, ss) << endl;
	cout << "Da li je string broj: " << isNumber(s) << endl;


	cout << "Sortiran string: " << sortCharsString(s) << endl;
	cout << "Sortirane reci: " << sortWordsString(s) << endl;

	cout << "Prvo 'a': " << firstFindChar(s, 'a') << endl;
	cout << "Poslednje 'a': " << LastFindChar(s, 'a') << endl;

	cout << "Normalizacija razmaka: " << removeExtraSpaces(s) << endl;

	cout << "Zamena a->@: " << changeChars(s) << endl;
	cout << "Obrnuto: " << reverseString(s) << endl;
	return 0;
}