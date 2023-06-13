#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Globals.h"
#include "Overcloat.h"
#include "Logic.h"
#include "Display.h"

using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Overcloat* list = new Overcloat[Overcloat::GetCount()];

	//char filename[MAX_PATH] = "save.bin";
	//FILE* file = nullptr;
	//LogicReadData(file, reservoir, filename, size);

	char select = 0;

	const char* menu[]
	{
		"Додати одяг   ",
		"Вивести список",
		"Видалити одяг ",
		"Редагувати    ",
		"Порівняти типи",
		"Порівняти ціни",
		"Вихід         "
	};

	while (true) {

		LogicHideCursor(FALSE);
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
				//DisplayRemove(reservoir, size);
				break;

			case EDIT:
				//DisplayEdit(reservoir, size);
				break;

			case TYPES:

				break;

			case PRISES:

				break;

			case EXIT:
				//LogicSaveData(file, reservoir, filename, size);
				delete[]list;
				return 0;
			}
			break;

		case ESC:
			//LogicSaveData(file, reservoir, filename, size);
			delete[]list;
			return 0;
		}
	}

	return 0;
}