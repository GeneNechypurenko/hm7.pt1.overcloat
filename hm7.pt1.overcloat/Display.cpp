#include "Display.h"

void DisplayMenu(const char* menu[], int row, int select) {

	char marker = 149;
	system("cls");

	for (int i = 0; i < row; i++) {

		Overcloat::LogicTextColor(STANDART);

		if (i == select) {
			Overcloat::LogicTextColor(HIGHLIGHT);
			cout << " " << marker << " ";
			cout << menu[i] << endl;
		}

		else {
			Overcloat::LogicTextColor(STANDART);
			cout << "   ";
			cout << menu[i] << endl;
		}
	}
}

void DisplayAdd(Overcloat*& list) {

	system("cls");
	Overcloat::LogicTextColor(STANDART);

	int row = 4;
	const char* str[]{ "тип   : ", "розм≥р: ", "кол≥р : ", "ц≥на  : " };

	for (int i = 0; i < row; i++)
		cout << str[i] << endl;

	list->AddObject(list);

	Overcloat::LogicTextColor(HIGHLIGHT);
	cout << endl << "новий товар додано" << endl;

	Overcloat::LogicTextColor(STANDART);
	Overcloat::LogicPause();
}

void DisplayPrint(const Overcloat* list) {

	system("cls");
	Overcloat::LogicTextColor(STANDART);

	if (Overcloat::GetCount() != 0)
		list->PrintList(list);

	else
		cout << "список порожн≥й..." << endl;

	Overcloat::LogicPause();
}

void DisplayRemove(Overcloat*& list) {

	system("cls");
	Overcloat::LogicTextColor(STANDART);

	if (Overcloat::GetCount() != 0) {

		list->PrintList(list);
		Overcloat::LogicPause();
		system("cls");

		short x = 0, y = 3;
		int index = 0, min = 1, max = Overcloat::GetCount();

		cout << "дл€ виделенн€ введ≥ть номер товару у списку.." << endl;
		Overcloat::LogicSetCoords(x, y);
		Overcloat::LogicHideCursor(TRUE);
		cout << "≥ндекс: ";
		Overcloat::LogicSafeInput(index, min, max);

		index -= 1;
		list->RemoveObject(list, index);

		Overcloat::LogicTextColor(HIGHLIGHT);
		cout << endl << "товар видаленно" << endl;
	}

	else
		cout << "список порожн≥й..." << endl;

	Overcloat::LogicTextColor(STANDART);
	Overcloat::LogicPause();
}

void DisplayEdit(Overcloat*& list) {

	system("cls");
	Overcloat::LogicTextColor(STANDART);

	if (Overcloat::GetCount() != 0) {

		list->PrintList(list);
		Overcloat::LogicPause();
		system("cls");

		short x = 0, y = 3;
		int index = 0, min = 1, max = Overcloat::GetCount();

		cout << "дл€ редагуванн€ введ≥ть номер товару у списку.." << endl;
		Overcloat::LogicSetCoords(x, y);
		Overcloat::LogicHideCursor(TRUE);
		cout << "≥ндекс: ";
		Overcloat::LogicSafeInput(index, min, max);
		system("cls");
		Overcloat::LogicHideCursor(FALSE);

		index -= 1;
		list->EditObject(list, index);

		Overcloat::LogicTextColor(HIGHLIGHT);
		cout << endl << "список в≥дредагованно" << endl;
	}

	else
		cout << "список порожн≥й..." << endl;

	Overcloat::LogicTextColor(STANDART);
	Overcloat::LogicPause();
}

void DisplayTypesCmp(Overcloat*& list) {

	system("cls");
	Overcloat::LogicTextColor(STANDART);

	if (Overcloat::GetCount() > 1) {

		list->PrintList(list);
		Overcloat::LogicPause();
		system("cls");

		short x = 0, y = 3;
		int indexFirst = 0, indexSec = 0, min = 1, max = Overcloat::GetCount();

		cout << "дл€ пор≥вн€нн€ тип≥в од€гу введ≥ть номер товару ≥з списку.." << endl;
		Overcloat::LogicSetCoords(x, y);
		Overcloat::LogicHideCursor(TRUE);
		cout << "≥ндекс: ";
		Overcloat::LogicSafeInput(indexFirst, min, max);
		system("cls");
		Overcloat::LogicHideCursor(FALSE);
		indexFirst -= 1;

		cout << "вибер≥ть наступний товар дл€ пор≥вн€нн€ ≥з списку.." << endl;
		Overcloat::LogicSetCoords(x, y);
		Overcloat::LogicHideCursor(TRUE);
		cout << "≥ндекс: ";
		Overcloat::LogicSafeInput(indexSec, min, max);
		system("cls");
		Overcloat::LogicHideCursor(FALSE);
		indexSec -= 1;

		list[indexFirst].PrintItem();
		cout << endl;
		list[indexSec].PrintItem();
		cout << endl;

		Overcloat::LogicTextColor(HIGHLIGHT);
		if (list[indexFirst] == list[indexSec])
			cout << "од€г однакового типу";
		else
			cout << "од€г р≥зних тип≥в";
	}

	else
		cout << "недостатньо товар≥в дл€ пор≥вн€нн€..." << endl;

	Overcloat::LogicTextColor(STANDART);
	Overcloat::LogicPause();
}

void DisplayPriceCmp(Overcloat*& list) {

	system("cls");
	Overcloat::LogicTextColor(STANDART);

	if (Overcloat::GetCount() > 1) {

		list->PrintList(list);
		Overcloat::LogicPause();
		system("cls");

		short x = 0, y = 3;
		int indexFirst = 0, indexSec = 0, min = 1, max = Overcloat::GetCount();

		cout << "дл€ пор≥вн€нн€ ц≥н введ≥ть номер товару ≥з списку.." << endl;
		Overcloat::LogicSetCoords(x, y);
		Overcloat::LogicHideCursor(TRUE);
		cout << "≥ндекс: ";
		Overcloat::LogicSafeInput(indexFirst, min, max);
		system("cls");
		Overcloat::LogicHideCursor(FALSE);
		indexFirst -= 1;

		cout << "вибер≥ть наступний товар дл€ пор≥вн€нн€ ≥з списку.." << endl;
		Overcloat::LogicSetCoords(x, y);
		Overcloat::LogicHideCursor(TRUE);
		cout << "≥ндекс: ";
		Overcloat::LogicSafeInput(indexSec, min, max);
		system("cls");
		Overcloat::LogicHideCursor(FALSE);
		indexSec -= 1;

		if (list[indexFirst] > list[indexSec]) {

			Overcloat::LogicTextColor(HIGHLIGHT);
			list[indexFirst].PrintItem();
			cout << endl;
			cout << "дорожчий за ц≥ною: " << endl << endl;
			Overcloat::LogicTextColor(STANDART);
			list[indexSec].PrintItem();
		}
		else if (list[indexFirst] == list[indexSec].GetPrice()) {

			Overcloat::LogicTextColor(STANDART);
			list[indexFirst].PrintItem();
			cout << endl;
			Overcloat::LogicTextColor(HIGHLIGHT);
			cout << "однаков≥ за ц≥ною: " << endl << endl;
			Overcloat::LogicTextColor(STANDART);
			list[indexSec].PrintItem();
		}
		else {

			Overcloat::LogicTextColor(STANDART);
			list[indexFirst].PrintItem();
			cout << endl;
			Overcloat::LogicTextColor(HIGHLIGHT);
			cout << "дорожчий за ц≥ною: " << endl << endl;
			list[indexSec].PrintItem();
		}
	}

	else
		cout << "недостатньо товар≥в дл€ пор≥вн€нн€..." << endl;

	Overcloat::LogicTextColor(STANDART);
	Overcloat::LogicPause();
}