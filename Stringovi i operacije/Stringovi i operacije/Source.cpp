#include <iostream>
// Biblioteke za rad sa algoritmima i stringovima
#include <algorithm>
#include <sstream>
#include <cctype>
// Biblioteke za rad sa stringovima
#include <string>
#include <cstring>
using namespace std;

void printString(const string& s) {
	cout << s << endl;
}
/// <summary>
/// Stampanje stringa - funkcija koja prima string kao argument i ispisuje ga na ekran.
/// </summary>
/// <param name="s"></param>

void enterString(string& str) {
	cout << "Unesite string: ";
	getline(cin, str); // Ucitava ceo red, ukljucujuci i razmake
}
/// <summary>
/// Unos stringa - funkcija koja omogucava korisniku da unese string sa tastature. Funkcija koristi getline
/// </summary>
/// <param name="str"></param>

void concatenateStrings(const string& s1, const string& s2, string& result) {
	result = s1 + s2; // Konkatenacija stringova
}
/// <summary>
/// Konkatenacija stringova - funkcija koja prima dva stringa i vraca novi string koji je rezultat
/// konkatenacije (spajanja) ta dva stringa. Na primer, za stringove "Hello" i " World" funkcija bi vratila "Hello World".
/// </summary>
/// <param name="s1"></param>
/// <param name="s2"></param>
/// <param name="result"></param>

void numberOfCharactersRepeated(const string& s, char repeatedChar) {
	short numberOfRepetitions = 0;
	for (auto ch : s) 
		if (ch == repeatedChar) numberOfRepetitions++;
	cout << "Broj ponavljanja karaktera '" << repeatedChar << "' u stringu \"" << s << "\" je: " << numberOfRepetitions << endl;
}
/// <summary>
/// Brojanje ponavljanja karaktera u stringu - funkcija koja broji koliko puta se odredjeni karakter
/// pojavljuje u stringu. Na primer, za string "Hello World" i karakter 'o' funkcija bi vratila 2, a 
/// za karakter 'x' funkcija bi vratila 0.
/// </summary>
/// <param name="s"></param>
/// <param name="repeatedChar"></param>

bool linearSearch(const string& s, char target) {
	for (auto ch : s) 
		if (ch == target) return true;
	return false;
}
/// <summary>
/// Pretraga karaktera u stringu - funkcija koja proverava da li se
/// odredjeni karakter nalazi u stringu.
/// </summary>
/// <param name="s"></param>
/// <param name="target"></param>
/// <returns></returns>

string reverseString(string& s) {
	string temp = s; // Napravimo kopiju stringa da ne bismo menjali originalni string
	reverse(temp.begin(), temp.end());
	// Obrce string koristeci algoritam reverse iz biblioteke <algorithm>
	return temp; 
}
/// <summary>
/// Obrtanje stringa - funkcija koja prima string i vraca novi string koji
/// je obrnuti od originalnog. Na primer, za string "Hello" funkcija bi vratila "olleH".
/// </summary>
/// <param name="s"></param>
/// <returns></returns>

bool isPalindrome(const string& s) {
	string reversed = s;
	// Obrce string i uporedjuje sa originalnim stringom
	reverse(reversed.begin(), reversed.end());
	// Ako su isti, onda je string palindrom
	return s == reversed; 
}
/// <summary>
/// Proverava da li je string palindrom - funkcija koja proverava da li je dati string palindrom,
/// odnosno da li se isti string cita isto s leva na desno i s desna na levo.
/// </summary>
/// <param name="s"></param>
/// <returns></returns>

bool searchSubString(const string& s, const string& substr) {
	return s.find(substr) != string::npos;
}
/// <summary>
/// Pretraga podstringa u stringu - funkcija koja proverava da li se
/// odredjeni podstring nalazi u stringu. Na primer, za string "Hello World"
/// i podstring "World" funkcija bi vratila true, a za podstring "Test"
/// funkcija bi vratila false.
/// </summary>
/// <param name="s"></param>
/// <param name="substr"></param>
/// <returns></returns>

void changeCharacter(string& s, char oldChar, char newChar) {
	for (auto& ch : s) 
		if (ch == oldChar) 
			ch = newChar;
}
/// <summary>
/// Zamena karaktera u stringu - funkcija koja zamenjuje sve pojave
/// odredjenog karaktera u stringu sa drugim karakterom. Na primer, 
/// za string "Hello World", karakter 'o' i novi karakter 'x', funkcija
/// bi vratila "Hellx Wxrld".
/// </summary>
/// <param name="s"></param>
/// <param name="oldChar"></param>
/// param name="newChar"></param>

//1. nacin
int countWords(const string& s) {
	int wordCount = 0;
	bool inWord = false;
	for (char ch : s) {
		if (ch != ' ' && !inWord) {
			inWord = true;
			wordCount++;
		} else if (ch == ' ' && inWord) {
			inWord = false;
		}
	}
	return wordCount;
}
//2. nacin
//size_t countWords(const string& s) {
//	istringstream stream(s);
//	string word;
//	size_t wordCount = 0;
//	while (stream >> word) {
//		wordCount++;
//	}
//	return wordCount;
//}
/// <summary>
/// Brojanje reci u stringu - funkcija koja broji broj reci u stringu, gde se reci odvajaju razmakom.
/// Na primer, za string "Hello World" funkcija bi vratila 2, a za string "This is a test" funkcija bi vratila 4.
/// </summary>
/// <returns></returns>

string removeDuplicates(string s) {
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	return s;
}
/// <summary>
///  Brisanje duplikata karaktera u stringu - funkcija koja uklanja sve
/// duplikate karaktera iz stringa i vraca novi string koji sadrzi samo 
/// jedinstvene karaktere.
/// </summary>
/// <param name="s"></param>
/// <returns></returns>

string longestWord(const string& s) {
	istringstream stream(s);
	string word, longest;
	while (stream >> word) 
		if(word.size() > longest.size()) 
			longest = word;
	return longest;
}
/// <summary>
///  Pretraga najduze reci u stringu - funkcija koja pronalazi i vraca
/// najduzu rec u stringu. Na primer, za string "Hello World" funkcija
/// bi vratila "Hello", a za string "This is a test" funkcija bi vratila "This".
/// </summary>
/// <param name="s"></param>
/// <returns></returns>

size_t countOccurrences(const string& s, const string& target) {
	istringstream stream(s);
	string word;
	size_t count = 0;
	while (stream >> word)
		if (word == target)
			count++;
	return count;
}
/// <summary>
/// Brojanje ponavljanja reci u stringu - funkcija koja broji koliko puta se
/// odredjena rec pojavljuje u stringu. Na primer, za string "Hello World Hello"
/// i rec "Hello" funkcija bi vratila 2, a za string "This is a test" i rec "test"
/// funkcija bi vratila 1.
/// </summary>
/// <param name="s"></param>
/// <param name="target"></param>
/// <returns></returns>

string toLower(string s){
	for (auto& ch : s) ch = tolower(ch);
	return s;
}
/// <summary>
/// Postavljanje svakog karaktera u stringu u mala slova 
/// </summary>
/// <param name="s"></param>
/// <returns></returns>

void frequency(const string& s) {
	int freq[256] = {0}; // niz od 256 mesta (ASCII tabela)
	for (char c : s)
		freq[c]++;
	// prolazak kroz celu ascii tabelu odnosno niz freq
	for (int i = 0; i < 256; i++)
		if (freq[i])
			cout << (char)i << " -> " << freq[i] << endl;
}
/// <summary>
/// Frekvencija karaktera - funkcija koja predstavlja string kroz
/// ascii tabelu, i koristi se za brojanje karaktera i slicne operacije
/// </summary>
/// <param name="s"></param>
/// <returns></returns>

string toAscii(string& s) {
	string encrypted;
	for (auto ch : s)
		encrypted += to_string((int)ch) + " ";
	return encrypted;
}
/// <summary>
/// Funkcija koja predstavja uneti string kao enkriptovan
/// tako sto svaki karakter se predstavi kao ASCII varijanta 
/// broja tog karaktera
/// </summary>
/// <param name="s"></param>
/// <returns></returns>

bool isAnagram(string a, string b) {
	if (a.size() != b.size()) return false;
	int freq[256] = { 0 };
	for (char ch : a)
		freq[ch]++;
	for (char ch : b)
		freq[ch]--;
	// ASCII
	for (int i = 0; i < 256; i++)
		if (freq[i] != 0)
			return false;
	return true;
}
/// <summary>
///  Funkcija koja proverava da li su dva stringa Anagram,
/// odnosno da li oba stringa imaju iste karaktere i istu kolicinu sloba,
/// ako nemaju ili nemaju iste karaktera onda nisu anagram.
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>

int main() {
	//#pragma region CStyleString 
	//// C -style string
	//char str1[20] = "Hello";
	//cout << str1[0] << endl; // H
	//cout << str1 << endl; // Hello
	//// strlen - duzina stringa
	//strlen(str1); // 5
	//// strcat - konkatenacija stringova
	////strcat(str1, " World"); // Hello World
	//// strcmp - poredi stringove
	//char str2[20] = "Hello World";
	//if (strcmp(str1, str2) == 0) {
	//	cout << "Stringovi su isti" << endl;
	//}
	//else {
	//	cout << "Stringovi nisu isti" << endl;
	//}
	//// strcpy - kopira string
	//char str3[20];
	////strcpy(str3, str1); // str3 = "Hello World"
	////cout << str3 << endl; // Hello World
	//#pragma endregion
	//#pragma region c++String
	//// Deklaracija i inicijalizacija stringa
	//string s = "Hello";
	//// Dodavanje karaktera na kraj stringa
	//s.push_back('w'); // Hellow
	//// Ispis stringa
	//cout << s << endl;
	//// Duzina stringa
	//cout << s.length() << endl; // 6
	//// Izvlacenje podstringa
	//cout << s.substr(0, 3) << endl; // Hel
	//// Proverava da li string sadrzi podstring "lo"
	//cout << s.find("lo") << endl; // 3
	//// Proverava da li je string prazan
	//if (s.empty()) cout << "String je prazan" << endl;
	//else cout << "String nije prazan" << endl;
	//// Brisanje stringa
	//// clear i erase imaju isti efekat, ali clear je brzi jer ne mora da pomera karaktere
	///*s.clear();*/
	////s.erase(); // s = ""
	//cout << s << " -> "<< s.length() << endl; // prazan string
	//// Dodavanje stringa na pocetak
	//s.insert(0, "Hi"); // Hi
	//cout << s << endl;

	//// Konkatenacija stringova
	//string s1 = "Hello";
	//string s2 = " World";
	//s1 += s2; // Hello World

	//// Ucitavanje stringa sa tastature
	//string input;
	//cout << "Unesite string: ";
	//getline(cin, input); // Ucitava ceo red, ukljucujuci i razmake
	//cout << "Uneli ste: " << input << endl;
	//#pragma endregion

	// Funkcije
	//string s1, s2, result;
	//enterString(s1);
	//printString(s1);
	//enterString(s2);
	//concatenateStrings(s1, s2, result);
	//printString(result);
	//char repeatedChar;
	//cout << "Unesite karakter koji zelite da prebrojite: ";
	//cin >> repeatedChar;
	//numberOfCharactersRepeated(result, repeatedChar);
	//char target;
	//cout << "Unesite karakter koji zelite da pretrazite: ";
	//cin >> target;
	//if (linearSearch(result, target)) {
	//	cout << "Karakter '" << target << "' je pronadjen u stringu \"" << result << "\"" << endl;
	//}
	//else {
	//	cout << "Karakter '" << target << "' nije pronadjen u stringu \"" << result << "\"" << endl;
	//}
	//string reversed = reverseString(result);
	//cout << "Obrnuti string: " << reversed << endl;
	//if (isPalindrome(result)) {
	//	cout << "String \"" << result << "\" je palindrom" << endl;
	//}
	//else {
	//	cout << "String \"" << result << "\" nije palindrom" << endl;
	//}
	//string substr;
	//cout << "Unesite podstring koji zelite da pretrazite: ";
	//cin.ignore(); // Ignorisanje prethodnog unosa karaktera
	//getline(cin, substr);
	//if (searchSubString(result, substr)) {
	//	cout << "Podstring \"" << substr << "\" je pronadjen u stringu \"" << result << "\"" << endl;
	//}
	//else {
	//	cout << "Podstring \"" << substr << "\" nije pronadjen u stringu \"" << result << "\"" << endl;
	//}
	//char oldChar, newChar;
	//cout << "Unesite karakter koji zelite da zamenite: ";
	//cin >> oldChar;
	//cout << "Unesite karakter koji zelite da stavite umesto '" << oldChar << "': ";
	//cin >> newChar;
	//changeCharacter(result, oldChar, newChar);
	//cout << "Novi string nakon zamene karaktera: " << result << endl;
	// Frekvencija karaktera
	/*string s = "De si kume";
	cout << toAscii(s) << endl;
	cout << s << endl;*/
	//cout << isAnagram("aab", "abaa"); // 0
	frequency("abala");
	return 0;
}