#include "Display.h"

void DisplayMenu(const char* menu[], int row, int select) {

	char marker = 149;
	system("cls");

	for (int i = 0; i < row; i++) {

		LogicTextColor(STANDART);

		if (i == select) {
			LogicTextColor(HIGHLIGHT);
			cout << " " << marker << " ";
			cout << menu[i] << endl;
		}

		else {
			LogicTextColor(STANDART);
			cout << "   ";
			cout << menu[i] << endl;
		}
	}
}

void DisplayAdd(Overcloat*& list) {

	system("cls");
	LogicTextColor(STANDART);

	int row = 4;
	const char* str[]{ "тип   : ", "розмір: ", "колір : ", "ціна  : " };

	for (int i = 0; i < row; i++)
		cout << str[i] << endl;

	list->AddObject(list);

	LogicTextColor(HIGHLIGHT);
	cout << endl << "новий товар додано" << endl;

	LogicTextColor(STANDART);
	LogicPause();
}

void DisplayPrint(const Overcloat* list) {

	system("cls");
	LogicTextColor(STANDART);

	if (Overcloat::GetCount() != 0) {

		for (int i = 0; i < Overcloat::GetCount(); i++) {
			cout << "--- ТОВАР №[" << i + 1 << "] ---" << endl;
			list[i].Print();
			cout << "___________________" << endl;
		}
	}

	else
		cout << "список порожній..." << endl;

	LogicPause();
}
