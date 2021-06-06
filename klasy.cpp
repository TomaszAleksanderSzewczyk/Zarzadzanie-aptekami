#include <iostream>
#include <list>
#include <iterator>
#include <regex>
#include "klasy.h"
using namespace std;

//iteratory
void Apteka::pokaz_liste_pracownikow()
{ 
	list<Pracownik> ::iterator ptr;
	cout << "Lista pracownikow w aptece " << nazwa_apteki << ": "<<  endl;

	for (ptr = lista_pracownikow.begin(); ptr != lista_pracownikow.end(); ptr++)
	{
		cout << ptr->nazwisko << " " << endl;
	}
}
// lambda
void Apteka::usun_pracownika_RODO(int numer_pracownika)
{

	auto ptr = remove_if(lista_pracownikow.begin(), lista_pracownikow.end(), [numer_pracownika](Pracownik x) {
		return (x.numer_pracownika == numer_pracownika);
		});
	cout << "Usuwanie pracownika o numerze " << numer_pracownika <<endl;
	lista_pracownikow.erase(ptr, lista_pracownikow.end());
	
	cout << "Pomyslnie usunieto pracownika o numerze " << numer_pracownika << endl<<endl;
}
//regex
void Apteka::dodaj_pracownika_do_apteki(Pracownik &nazwa_pracownika, string email)
{
	cout << "Dodawanie pracownika "<< nazwa_pracownika.nazwisko <<" do apteki  " <<nazwa_apteki <<endl;
	std::regex email_regex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	if (std::regex_match(email, email_regex))
	{
		std::cout << "Email jest poprawny." << endl << "Udalo sie dodac pracownika do apteki."<<endl <<endl;
		lista_pracownikow.push_back(nazwa_pracownika);

		list<Pracownik> ::iterator ptr;
		cout << "Lista pracownikow w aptece " << nazwa_apteki << ": " << endl;

		for (ptr = lista_pracownikow.begin(); ptr != lista_pracownikow.end(); ptr++)
		{
			cout << ptr->nazwisko << " " << endl;
		}
		cout << endl; 
	}
	else
		std::cout << "Invalid email." << " Spróbuj ponownie wpisuj¹c poprawny mail" << endl;
}
	


//utworzenie nowego obiektu klasy syrop i dodanie do listy
void Apteka::dodaj_syrop_do_apteki(string nazwa, bool recepta, int cena, double pojemnosc)
{
	
lista_lekarstw.push_back(new Syrop(nazwa, recepta, cena,pojemnosc));


}
//utworzenie nowego obiektu klasy tabletka i dodanie do listy
void Apteka::dodaj_tabletki_do_apteki(string nazwa, bool recepta, int cena, int pojemnosc)
{
	lista_lekarstw.push_back(new Tabletka(nazwa, recepta, cena, pojemnosc));
}
//Wyj¹tki
void Apteka::wypisz_liste_lekarstw()
{
	try {
		cout << "Lista lekarstw w aptece: " << endl;
		for (int a = 0; a < lista_lekarstw.size(); a++)

		{
			std::list<Lekarstwo*>::iterator i = lista_lekarstw.begin();

			advance(i, a);
			Lekarstwo* totry = *i;
			cout << *totry;

		}
		cout << endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}

void Apteka::usun_lekarstwo_z_apteki(string nazwa_lekarstwa, Apteka apteka)
{
	
	cout << "Usuwanie lekarstwa z apteki " << apteka.nazwa_apteki << endl;
	auto ptr = remove_if(lista_lekarstw.begin(), lista_lekarstw.end(), [nazwa_lekarstwa](Lekarstwo* x) {
		return (x->nazwa==nazwa_lekarstwa);
		});
	lista_lekarstw.erase(ptr, lista_lekarstw.end());
	cout << "Pomyslnie usunieto lekarstwo " << nazwa_lekarstwa << ".Sukces." << endl << endl;

}

//Wyj¹tki, iteratory
void Miasto::wypisz_apteki()
{
	try {
		list<Apteka> ::iterator ptr;

		cout << "Apteki w miescie " << nazwa_miasta << ":" << endl;

		for (ptr = apteki.begin(); ptr != apteki.end(); ptr++) {
			cout << ptr->nazwa_apteki << endl;
		}
		cout << endl;
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}
}

void Miasto::dodaj_apteke(Apteka nazwa_apteki)
{
	apteki.push_back(nazwa_apteki);
}
//Wykorzystanie funkcji lambda
void Miasto::usun_apteke(string nazwa_apteki)
{
	cout << "Usuwanie apteki " << nazwa_apteki << endl;
	auto ptr = remove_if(apteki.begin(), apteki.end(), [nazwa_apteki](Apteka x) {
		return (x.nazwa_apteki == nazwa_apteki);
		});
	apteki.erase(ptr, apteki.end());
	cout << "Pomyslnie usunieto apteke " << nazwa_apteki << ".Sukces." << endl<<endl;

}

void Syrop::pokaz_informacje()
{
	cout << "===========INFORMACJE O SYROPIE==============" << endl;
	cout << "Nazwa: " << nazwa << endl;
	
	if (recepta == 0)
	{
		cout << "Lek wydawany bez repcety" << endl;
	}
	else cout << "Lek na recepte" << endl;
	cout << "Cena: " << cena << endl;
	cout << "Pojemnosc: " << pojemnosc << "ml" << endl << endl;
}

void Tabletka::pokaz_informacje()
{
	cout << endl;
	cout << "===INFORMACJE O TABLETCE===" << endl;
	cout << "Nazwa: " << nazwa << endl;
	cout << "Recepta:";
	if (recepta == 0)
	{
		cout << "Lek wydawany bez repcety" << endl;
	}
	else cout << "Lek na recepte" << endl;
	cout << "Cena: " << cena << endl;
	cout << "Pojemnosc: " << pojemnosc << "tabletek " << endl<<endl;
}

ostream& operator<<(ostream& wyjscie, const Pracownik& s)
{
	return wyjscie << "======Pracownik======" << endl << "Nazwisko pracownika: " << s.nazwisko << endl << "Numer pracownika: " << s.numer_pracownika << endl <<"Email: " << s.email << endl<<endl;
}

ostream& operator<<(ostream& wyjscie, const Lekarstwo& s)
{
	
	return wyjscie <<   endl << "Lekarstwo: " << s.nazwa << endl << "Cena: " << s.cena  ;
}
