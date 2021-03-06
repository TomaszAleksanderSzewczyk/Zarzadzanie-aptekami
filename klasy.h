/**@file*/
#pragma once
#include <iostream>
#include <list>

using namespace std;
class Pracownik;
class Apteka;

class Lekarstwo;

/**Klasa reprezentująca miasto */
class Miasto {
private:
	
	string kod_pocztowy;//!<Zmienna reprezentująca kod pocztowy
	string nazwa_miasta;//!<Zmienna reprezentująca nazwe miasta
public:
	list <Apteka>apteki;//!<Kontener stl typu lista reprezentująca apteki

	/**Konstruktor
	@param miasto Nazwa miasta
	@param zip_code Kod pocztowy
		*/
	Miasto(string miasto, string zip_code):kod_pocztowy(zip_code),nazwa_miasta(miasto) {};

	/**Metoda wypisująca listę aptek */
	void wypisz_apteki();

	/**Metoda usuwająca apteke z listy 
	@param nazwa_apteki Przekazanie nazwy apteki do usunięcia*/
	void usun_apteke(string nazwa_apteki);

	/**Metoda dodająca apteke do listy
	@param nazwa_apteki obiekt typu Apteka*/
	void dodaj_apteke(Apteka nazwa_apteki);

	/**Destruktor klasy Miasto*/
	~Miasto() {
		apteki.clear();
	};


};
/**Klasa reprezentująca Apteke */
class Apteka {
public:
	string nazwa_apteki;//!<Zmienna reprezentująca nazwe apteki
	list<Pracownik>lista_pracownikow;//!<Kontener stl reprezentujący liste przechowujaca liste pracownikow
	list<Lekarstwo*>lista_lekarstw;//!<Kontener stl reprezentujący liste przechowujaca liste lekarstw

	/**Konstruktor
	@param apteka Nazwa apteki
		*/
	Apteka(string apteka) :nazwa_apteki(apteka) {};
	/**Metoda pokazująca liste pracownikow */
	void pokaz_liste_pracownikow();

	/**Metoda usuwająca pracownikow po numerze pracownika
	@param numer_pracownika Numer pracowniczy*/
	void usun_pracownika_RODO(int numer_pracownika);

	/**Metoda dodająca pracownika do apteki 
	@param nazwa_pracownika Przekazanie obiektu typu Pracownik
	@param email przekazanie emailu pracownika w celu walidacji regex*/
	void dodaj_pracownika_do_apteki(Pracownik& nazwa_pracownika, string email);

	/**Metoda tworząca obiekt typu syrop i dodająca go do listy Lekarstw
	@param nazwa Nazwa lekarstwa
	@param recepta zmienna bool 1-na recepte 0- bez recepty
	@param cena zmienna typu int reprezentująca cene
	@param pojemnosc zmienna typu double reprezentujaca pojemnosc*/
	void dodaj_syrop_do_apteki(string nazwa, bool recepta, int cena, double pojemnosc);

	/**Metoda tworząca obiekt typu tabletka i dodająca go do listy Lekarstw
	@param nazwa Nazwa lekarstwa
	@param recepta zmienna bool 1-na recepte 0- bez recepty
	@param cena zmienna typu int reprezentująca cene
	@param pojemnosc zmienna typu int reprezentujaca pojemnosc*/
	void dodaj_tabletki_do_apteki(string nazwa, bool recepta, int cena, int pojemnosc);

	/**Metoda wypisująca liste lekarstw*/
	void wypisz_liste_lekarstw();

	/**Metoda usuwająca lekarstwo z listy lekarstw
	@param nazwa_lekarstwa Nazwa lekarstwa typ string
	@param apteka Obiekt typu Apteka*/
	void usun_lekarstwo_z_apteki(string nazwa_lekarstwa, Apteka apteka);

	/**Destruktor klasy apteka */
	~Apteka() {	

		lista_lekarstw.clear();//!<Kontener stl reprezentujący liste przechowujaca liste pracownikow
		lista_pracownikow.clear();//!<Kontener stl reprezentujący liste przechowujaca liste pracownikow
	}
	
};

/**Klasa reprezentująca Pracownika */
class Pracownik {
public:
	string nazwisko;//!<Zmienna reprezentująca nazwisko
	int numer_pracownika;//!<Zmienna reprezentująca numer pracownika
	string email;//!<Zmienna reprezentująca email

	/**Konstruktor
	@param nazwisko_prac nazwisko pracownika typ string
	@param numer_prac reprezentuje numer pracowniczy typ int
	@param email email typu string*/
	Pracownik(string nazwisko_prac, int numer_prac, string email):nazwisko(nazwisko_prac), numer_pracownika(numer_prac), email(email) {};

	/**Przeciążony operator wypisywania  */
	friend ostream& operator<< (ostream& wyjscie, const Pracownik& s);

	
};
/**Klasa absrakcyjna reprezentująca lekarstwo */
class Lekarstwo {

public:
	string nazwa;//!<Zmienna reprezentująca nazwe leku
	bool recepta;//!<Zmienna reprezentująca recepte
	int cena;//!<Zmienna reprezentująca cene

	/**Konstruktor
	@param nazwa Nazwa lekarstwa
	@param recepta Zmienna typu bool 1-recepta 0- bez recepty
	@param cena Cena lekarstwa
		*/
	Lekarstwo(std::string nazwa, bool recepta, int cena) : nazwa(nazwa), recepta(recepta), cena(cena) {};

	/**Wirtualna metoda pokazujaca infromacje nt. lekarstwa */
	virtual void pokaz_informacje()=0;

	/**Operator przeciazony wypisywania */
	friend ostream& operator<< (ostream& wyjscie, const Lekarstwo& s);
	
};

/**Klasa reprezentująca Syrop */
class Syrop :public Lekarstwo {
private:
	double pojemnosc; //!<Zmienna reprezentująca pojemnosc
public:
	/**Konstruktor
	@param nazwa Nazwa lekarstwa
	@param recepta Zmienna typu bool 1-recepta 0- bez recepty
	@param cena Cena lekarstwa
	@param pojemnosc zmienna okreslajaca pojemnosc leku
		*/
	Syrop(string nazwa, bool recepta, int cena, double pojemnosc) : Lekarstwo(nazwa, recepta, cena), pojemnosc(pojemnosc) {};
	
	/**Wirtualna metoda pokazujaca infromacje nt. lekarstwa */
	virtual void pokaz_informacje();
};


/**Klasa reprezentująca Tabletki */
class Tabletka :public Lekarstwo {
private:
	int pojemnosc;//!<Zmienna reprezentująca pojemnosc lekarstwa
	
public:

	/**Wirtualna metoda pokazujaca infromacje nt. lekarstwa */
	virtual void pokaz_informacje();

	/**Konstruktor
	@param nazwa Nazwa lekarstwa
	@param recepta Zmienna typu bool 1-recepta 0- bez recepty
	@param cena Cena lekarstwa
	@param pojemnosc zmienna okreslajaca pojemnosc leku
		*/
	Tabletka(string nazwa, bool recepta, int cena, int pojemnosc) : Lekarstwo(nazwa, recepta, cena), pojemnosc(pojemnosc) {};
};
