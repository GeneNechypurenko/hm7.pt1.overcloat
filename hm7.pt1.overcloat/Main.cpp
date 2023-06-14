#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Globals.h"
#include "Overcloat.h"
#include "Display.h"

using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Overcloat* list = nullptr;

	char filename[MAX_PATH] = "save.bin";
	FILE* file = nullptr;
	Overcloat::LogicReadData(file, list, filename);

	char select = 0;

	const char* menu[]
	{
		"Додати товар  ",
		"Вивести список",
		"Видалити товар",
		"Редагувати    ",
		"Порівняти типи",
		"Порівняти ціни",
		"Вихід         "
	};

	while (true) {

		Overcloat::LogicHideCursor(FALSE);
		DisplayMenu(menu, MENU_ROW, select);

		char action = _getch();
		if (action == 0 || action == 224)
			action = _getch();

		switch (action) {

		case UP:
			select = (select - 1 + MENU_ROW) % MENU_ROW;
			break;

		case DOWN:
			select = (select + 1) % MENU_ROW;
			break;

		case ENTER:
			switch (select) {

			case ADD:
				DisplayAdd(list);
				break;

			case PRINT:
				DisplayPrint(list);
				break;

			case REMOVE:
				DisplayRemove(list);
				break;

			case EDIT:
				DisplayEdit(list);
				break;

			case TYPES:
				DisplayTypesCmp(list);
				break;

			case PRISES:
				DisplayPriceCmp(list);
				break;

			case EXIT:
				Overcloat::LogicSaveData(file, list, filename);
				delete[]list;
				return 0;
			}
			break;

		case ESC:
			Overcloat::LogicSaveData(file, list, filename);
			delete[]list;
			return 0;
		}
	}

	return 0;
}