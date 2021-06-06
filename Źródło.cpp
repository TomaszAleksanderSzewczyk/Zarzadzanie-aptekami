#include <iostream>
#include <string>
#include "klasy.h"
using namespace std;

int main() {

	Miasto Bukowno("Bukowno", "32-332");

	Apteka Sloneczna("Sloneczna");
	Apteka Dino("Dino");


	Bukowno.dodaj_apteke(Sloneczna);
	Bukowno.wypisz_apteki();
	Bukowno.dodaj_apteke(Dino);
	Bukowno.wypisz_apteki();


	Bukowno.usun_apteke("Dino");
	Bukowno.wypisz_apteki();
	

	Pracownik Jurij_Bubka("Bubka", 1111, "jurbub@gmail.com");
	cout << Jurij_Bubka;


	Pracownik Vieslav_Pubka("Pubka", 2222, "pubka@gmail.com");
	Pracownik Szewczenko("Szewczenko", 2233, "szewczenkosz@gmail.com");

	Sloneczna.dodaj_pracownika_do_apteki(Jurij_Bubka, "jurbub@gmail.com" );
	Sloneczna.dodaj_pracownika_do_apteki(Vieslav_Pubka, "pubka@gmail.com");
	Sloneczna.dodaj_pracownika_do_apteki(Szewczenko, "szewczenkosz@gmail.com");

	Sloneczna.pokaz_liste_pracownikow();

	Sloneczna.usun_pracownika_RODO(1111);

	Sloneczna.pokaz_liste_pracownikow();
	Sloneczna.dodaj_syrop_do_apteki("Tiamazol", 1, 22, 220);
	Sloneczna.dodaj_tabletki_do_apteki("Probiotyk A", 1, 22, 33);
	Sloneczna.dodaj_syrop_do_apteki("Zan", 0, 44, 22.5);
	
	Syrop Tiamina("Tiamina", 1, 23.5, 22.333);

	Tabletka Fenta("Fentanyl", 1, 11.2, 45);
	Fenta.pokaz_informacje();
	Tiamina.pokaz_informacje();

	Sloneczna.wypisz_liste_lekarstw();

	Dino.dodaj_syrop_do_apteki("Zotac", 1, 22, 33);

	Sloneczna.usun_lekarstwo_z_apteki("Probiotyk A", Sloneczna);
	Sloneczna.wypisz_liste_lekarstw();



}