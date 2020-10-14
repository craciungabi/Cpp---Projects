#include "UI.h"
#include "Cheltuiala.h"
#include <iostream>
using namespace std;

void addCheltuiala(Service& s) {
	Cheltuiala c;
	cout << "Give the expense: ";
	cin >> c;
	s.addCheltuiala(c);
	cout << "The expense was added successfully!" << endl;
}

void delCheltuiala(Service& serv) {
	int id;
	cout << "Give the expense ID to deletes: ";
	cin >> id;
	serv.delCheltuiala(id);
	cout << "The expense was successfully deleted!" << endl;
}

void updateCheltuiala(Service& serv) {
	int id, new_zi, new_suma;
	char* new_tip = new char[10];
	cout << "Give the id of the expense to change: "; cin >> id;
	cout << "Give the new day of spending: "; cin >> new_zi;
	cout << "Give the new amount of the expense: "; cin >> new_suma;
	cout << "Enter the new type of expenditure: "; cin >> new_tip;
	serv.update(id, new_zi, new_suma, new_tip);
	cout << " The expense has been successfully changed!" << endl;
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
	cout << "The amount of food expenses is: " << serv.suma_mancare() << endl;
}

void ui_max_zi(Service& serv) {
	cout << "The day with the highest expenses is: " << serv.max_zi() << endl;
}

void ui_sume_zilnice(Service& serv) {
	for (int i = 1; i <= 30;i++)
		cout << serv.sortare_descr_sume_zilnice()[i] << " lei;  ";
	cout << endl;
}



void show_menu() {
	cout << endl;
	cout << "OPTIONS: " << endl;
	cout << "	1. Add expense " << endl;
	cout << "	2. Show  expenses " << endl;
	cout << "   3. Delete expense " << endl;
	cout << "   4. Modify expenses " << endl;
	cout << "   5. Filter by a expenses " << endl;
	cout << "   6. Filter with cost< 100 " << endl;
	cout << "   7. Delete all expenses from the 15th of the month" << endl;
	cout << "   8. Show food expenses >5 RON" << endl;
	cout << "   9. Delete expenses from the days 2-9" << endl;
	cout << "  10. The amount of expenses in the food category" << endl;
	cout << "  11. The day with the highest expenses" << endl;
	cout << "  12. Display amounts spent daily decreasing" << endl;
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
		case 13: {undo(serv); break; }
		case 0: {gata = true; cout << "EXIT!" << endl; }
		}
	}
}
