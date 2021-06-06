/**@file*/
#pragma once
#include <iostream>
#include <list>

using namespace std;
class Pracownik;
class Apteka;

class Lekarstwo;

/**Klasa reprezentuj�ca miasto */
class Miasto {
private:
	
	string kod_pocztowy;//!<Zmienna reprezentuj�ca kod pocztowy
	string nazwa_miasta;//!<Zmienna reprezentuj�ca nazwe miasta
public:
	list <Apteka>apteki;//!<Kontener stl typu lista reprezentuj�ca apteki

	/**Konstruktor
	@param miasto Nazwa miasta
	@param zip_code Kod pocztowy
		*/
	Miasto(string miasto, string zip_code):kod_pocztowy(zip_code),nazwa_miasta(miasto) {};

	/**Metoda wypisuj�ca list� aptek */
	void wypisz_apteki();

	/**Metoda usuwaj�ca apteke z listy 
	@param nazwa_apteki Przekazanie nazwy apteki do usuni�cia*/
	void usun_apteke(string nazwa_apteki);

	/**Metoda dodaj�ca apteke do listy
	@param nazwa_apteki obiekt typu Apteka*/
	void dodaj_apteke(Apteka nazwa_apteki);

	/**Destruktor klasy Miasto*/
	~Miasto() {
		apteki.clear();
	};


};
/**Klasa reprezentuj�ca Apteke */
class Apteka {
public:
	string nazwa_apteki;//!<Zmienna reprezentuj�ca nazwe apteki
	list<Pracownik>lista_pracownikow;//!<Kontener stl reprezentuj�cy liste przechowujaca liste pracownikow
	list<Lekarstwo*>lista_lekarstw;//!<Kontener stl reprezentuj�cy liste przechowujaca liste lekarstw

	/**Konstruktor
	@param apteka Nazwa apteki
		*/
	Apteka(string apteka) :nazwa_apteki(apteka) {};
	/**Metoda pokazuj�ca liste pracownikow */
	void pokaz_liste_pracownikow();

	/**Metoda usuwaj�ca pracownikow po numerze pracownika
	@param numer_pracownika Numer pracowniczy*/
	void usun_pracownika_RODO(int numer_pracownika);

	/**Metoda dodaj�ca pracownika do apteki 
	@param nazwa_pracownika Przekazanie obiektu typu Pracownik
	@param email przekazanie emailu pracownika w celu walidacji regex*/
	void dodaj_pracownika_do_apteki(Pracownik& nazwa_pracownika, string email);

	/**Metoda tworz�ca obiekt typu syrop i dodaj�ca go do listy Lekarstw
	@param nazwa Nazwa lekarstwa
	@param recepta zmienna bool 1-na recepte 0- bez recepty
	@param cena zmienna typu int reprezentuj�ca cene
	@param pojemnosc zmienna typu double reprezentujaca pojemnosc*/
	void dodaj_syrop_do_apteki(string nazwa, bool recepta, int cena, double pojemnosc);

	/**Metoda tworz�ca obiekt typu tabletka i dodaj�ca go do listy Lekarstw
	@param nazwa Nazwa lekarstwa
	@param recepta zmienna bool 1-na recepte 0- bez recepty
	@param cena zmienna typu int reprezentuj�ca cene
	@param pojemnosc zmienna typu int reprezentujaca pojemnosc*/
	void dodaj_tabletki_do_apteki(string nazwa, bool recepta, int cena, int pojemnosc);

	/**Metoda wypisuj�ca liste lekarstw*/
	void wypisz_liste_lekarstw();

	/**Metoda usuwaj�ca lekarstwo z listy lekarstw
	@param nazwa_lekarstwa Nazwa lekarstwa typ string
	@param apteka Obiekt typu Apteka*/
	void usun_lekarstwo_z_apteki(string nazwa_lekarstwa, Apteka apteka);

	/**Destruktor klasy apteka */
	~Apteka() {	

		lista_lekarstw.clear();//!<Kontener stl reprezentuj�cy liste przechowujaca liste pracownikow
		lista_pracownikow.clear();//!<Kontener stl reprezentuj�cy liste przechowujaca liste pracownikow
	}
	
};

/**Klasa reprezentuj�ca Pracownika */
class Pracownik {
public:
	string nazwisko;//!<Zmienna reprezentuj�ca nazwisko
	int numer_pracownika;//!<Zmienna reprezentuj�ca numer pracownika
	string email;//!<Zmienna reprezentuj�ca email

	/**Konstruktor
	@param nazwisko_prac nazwisko pracownika typ string
	@param numer_prac reprezentuje numer pracowniczy typ int
	@param email email typu string*/
	Pracownik(string nazwisko_prac, int numer_prac, string email):nazwisko(nazwisko_prac), numer_pracownika(numer_prac), email(email) {};

	/**Przeci��ony operator wypisywania  */
	friend ostream& operator<< (ostream& wyjscie, const Pracownik& s);

	
};
/**Klasa absrakcyjna reprezentuj�ca lekarstwo */
class Lekarstwo {

public:
	string nazwa;//!<Zmienna reprezentuj�ca nazwe leku
	bool recepta;//!<Zmienna reprezentuj�ca recepte
	int cena;//!<Zmienna reprezentuj�ca cene

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

/**Klasa reprezentuj�ca Syrop */
class Syrop :public Lekarstwo {
private:
	double pojemnosc; //!<Zmienna reprezentuj�ca pojemnosc
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


/**Klasa reprezentuj�ca Tabletki */
class Tabletka :public Lekarstwo {
private:
	int pojemnosc;//!<Zmienna reprezentuj�ca pojemnosc lekarstwa
	
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
