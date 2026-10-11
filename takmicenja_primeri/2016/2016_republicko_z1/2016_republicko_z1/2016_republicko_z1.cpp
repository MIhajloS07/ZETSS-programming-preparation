#include <iostream>
using namespace std;

int upustvoPetocifrenogBroja(int& br)
{   
	int levi = br / 10; 
	int desni = br % 10; 
	return levi * 100 + 3 * 10 + desni; // spajanje desne cifre i levog dela u novi broj
}

int upustvoSestocifrenogBroja(int& br)
{
    //zamena cifara stotice i jedinice
	int jedinica = br % 10;
	int stotica = (br / 100) % 10;
	br = br - jedinica + stotica; // uklanjanje jedinice i dodavanje stotice
	br = br - stotica * 100 + jedinica * 100; // uklanjanje stotice i dodavanje jedinice
	return br;
}

int upustvoSedmocifrenogBroja(int& br)
{
	// oduzimanje cifre na mesto hiljadarki
	int levi = br / 10000; // levi deo broja bez poslednje cifre
	int desni = br % 1000; // desni deo broja bez prve cifre
	return levi * 1000 + desni; // spajanje levog i desnog dela u novi broj
}

int srednjeDveCifre(int& br)
{
	// izdvajanje cifara stotice i hiljadarke
	int stotica = (br / 100) % 10;
	int hiljadarka = (br / 1000) % 10;
	return hiljadarka * 10 + stotica; // spajanje stotice i hiljadarke u novi broj
}

int main()
{
	int petocifreni, sestrocifreni, sedmocifreni;
    // ULAZ
	cin >> sedmocifreni >> petocifreni >> sestrocifreni;
	// PROVERA ISPRAVNOSTI
	if (petocifreni < 10000 || petocifreni > 99999 ||
		sestrocifreni < 100000 || sestrocifreni > 999999 ||
		sedmocifreni < 1000000 || sedmocifreni > 9999999)
		return 1;

	// OBRADA
	int noviPetocifreni = upustvoPetocifrenogBroja(petocifreni);
	int noviSestocifreni = upustvoSestocifrenogBroja(sestrocifreni);
	int noviSedmocifreni = upustvoSedmocifrenogBroja(sedmocifreni);
	// IZDVAJANJE PODATAKA
	int brojMinutaZaDolazakTihomir = srednjeDveCifre(noviSedmocifreni);
	int brojMinutaDoPrveStaniceAgent = srednjeDveCifre(noviPetocifreni);
	int brojMinutaOdPrveDoDrugeStaniceAgent = srednjeDveCifre(noviSestocifreni);

	int brojMinutaDoDrugeStaniceAgent = brojMinutaDoPrveStaniceAgent + brojMinutaOdPrveDoDrugeStaniceAgent;

	// broj minuta koliko ce tihomir cekati na stanici 1
	int cekanje1 = brojMinutaDoPrveStaniceAgent - brojMinutaZaDolazakTihomir;
	// broj minuta koliko ce tihomir cekati na stanici 2
	int cekanje2 = brojMinutaDoDrugeStaniceAgent - brojMinutaZaDolazakTihomir;

	// IZLAZ
	cout << noviSedmocifreni << "\n";
	cout << noviPetocifreni << "\n";
	cout << noviSestocifreni << "\n";
	if (brojMinutaDoPrveStaniceAgent < brojMinutaZaDolazakTihomir)
		cout << "STANICA 1:KASNI" << endl;
	else 
		cout << "STANICA 1:" << cekanje1 << endl;
	if (brojMinutaDoDrugeStaniceAgent < brojMinutaZaDolazakTihomir)
		cout << "STANICA 2:KASNI" << endl;
	else
		cout << "STANICA 2:" << cekanje2 << endl;
    return 0;
}

