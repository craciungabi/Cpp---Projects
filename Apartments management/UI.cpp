#include "UI.h"
#include "Cheltuiala.h"
#include <iostream>
using namespace std;

void addCheltuiala(Service& s) {
	Cheltuiala c;
	cout << "Dati cheltuiala: ";
	cin >> c;
	s.addCheltuiala(c);
	cout << "Cheltuiala a fost adaugata cu succes!" << endl;
}

void delCheltuiala(Service& serv) {
	int id;
	cout << "Dati id-ul cheltuielii de sters: ";
	cin >> id;
	serv.delCheltuiala(id);
	cout << "Cheltuiala a fost  stearsa cu succes!" << endl;
}

void updateCheltuiala(Service& serv) {
	int id, new_zi, new_suma;
	char* new_tip = new char[10];
	cout << "Dati id-ul cheltuielii de modificat: "; cin >> id;
	cout << "Dati noua zi a cheltuielii: "; cin >> new_zi;
	cout << "Dati noua suma a cheltuielii: "; cin >> new_suma;
	cout << "Dati noul tip al cheltuielii: "; cin >> new_tip;
	serv.update(id, new_zi, new_suma, new_tip);
	cout << " Cheltuiala a fost modificata cu succes!" << endl;
}

void showAll(Service& serv) {
	vector<Cheltuiala> chel = serv.getAll();
	for (Cheltuiala c : chel)
		cout << c;
}

void FilteredCheltuieli(Service& serv) {
	serv.filter_by_mancare();
}

void FilteredCheltuieli2(Service& serv) {
	serv.filter_by_menaj_suma();
}

void elimina_ziua_15(Service& serv) {
	serv.sterge_zi_15();
}

void elimina_ziua_2_9(Service& serv) {
	serv.sterge_zi_2_9();
}

void afisare_mancare_mai_mare_5(Service& serv) {
	vector<Cheltuiala> chel = serv.afisare_mancare_mai_mare_5();
	for (Cheltuiala c : chel)
		cout << c;
}

void ui_suma_mancare(Service& serv) {
	cout << "Suma cheltuielilor pentru mancare este: " << serv.suma_mancare() << endl;
}

void ui_max_zi(Service& serv) {
	cout << "Ziua cu cele mai mari cheltuieli este: " << serv.max_zi() << endl;
}

void ui_sume_zilnice(Service& serv) {
	for (int i = 1; i <= 30;i++)
		cout << serv.sortare_descr_sume_zilnice()[i] << " lei;  ";
	cout << endl;
}



void show_menu() {
	cout << endl;
	cout << "OPTIUNI: " << endl;
	cout << "	1. Adauga cheltuiala " << endl;
	cout << "	2. Afiseaza cheltuielile " << endl;
	cout << "   3. Stergere cheltuiala " << endl;
	cout << "   4. Modificare cheltuiala " << endl;
	cout << "   5. Filtrare mancare " << endl;
	cout << "   6. Filtrare menaj < 100 " << endl;
	cout << "   7. Stergere cheltuieli din ziua 15" << endl;
	cout << "   8. Afisare cheltuieli pentru mancare >5 RON" << endl;
	cout << "   9. Stergere cheltuieli din zilele 2-9" << endl;
	cout << "  10. Suma cheltuielilor din categoria mancare" << endl;
	cout << "  11. Ziua cu cele mai mari cheltuieli" << endl;
	cout << "  12. Afisare sume cheltuite zilnic descrescator" << endl;
	cout << "  13. Undo" << endl;
	cout << "	0. EXIT!" << endl;
}

void showUI(Service& serv)
{
	bool gata = false;
	while (!gata) {
		show_menu();
		cout << "Introduceti optiunea (prin numarul ei): " << endl;
		int opt;
		cin >> opt;
		switch (opt) {
		case 1: {addCheltuiala(serv); break; }
		case 2: {showAll(serv); break; }
		case 3: {delCheltuiala(serv); break; }
		case 4: {updateCheltuiala(serv); break; }
		case 5: {FilteredCheltuieli(serv); break; }
		case 6: {FilteredCheltuieli2(serv); break; }
		case 7: {elimina_ziua_15(serv); break; }
		case 8: {afisare_mancare_mai_mare_5(serv); break;}
		case 9: {elimina_ziua_2_9(serv); break; }
		case 10: {ui_suma_mancare(serv); break; }
		case 11: {ui_max_zi(serv); break; }
		case 12: {ui_sume_zilnice(serv); break; }
			   //case 13: {undo(serv); break; }
		case 0: {gata = true; cout << "EXIT!" << endl; }
		}
	}
}
