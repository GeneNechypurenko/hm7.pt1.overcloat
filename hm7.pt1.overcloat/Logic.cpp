#include "Logic.h"

HANDLE hSettings = GetStdHandle(STD_OUTPUT_HANDLE);

void LogicHideCursor(bool hide) {

	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hSettings, &structCursorInfo);
	structCursorInfo.bVisible = hide;
	SetConsoleCursorInfo(hSettings, &structCursorInfo);
}

void LogicSetCoords(short x, short y) {

	SetConsoleCursorPosition(hSettings, { x,y });
}

void LogicTextColor(int textcolor) {

	SetConsoleTextAttribute(hSettings, textcolor);
}

void LogicPause() {

	const short x = 40, y = 26;
	SetConsoleCursorPosition(hSettings, { x,y });
	system("pause");
}

void LogicCleanBuffer() {

    if (cin.rdbuf()->in_avail() != 0) {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    }
}

void LogicSafeInput(int& value, int min, int max) {

	short x = 8, y = 3;
	LogicSetCoords(x, y);

    while (!(cin >> value) || value < min || value > max) {
        cout << "помилка, невірно задане значення.. спробуйте знову: ";
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    }
}

const char* LogicSelectStr(const char* str[], short x, short y) {

	int index = 0;

	LogicSetCoords(x, y);
	cout << str[index];

	while (true) {

		char action = _getch();
		if (action == 0 || action == 224)
			action = _getch();

		if (action == UP) {
			LogicSetCoords(x, y);
			index = (index - 1 + ROW) % ROW;
			cout << str[index];
		}

		else if (action == DOWN) {
			LogicSetCoords(x, y);
			index = (index + 1) % ROW;
			cout << str[index];
		}

		else if (action == ENTER)
			break;
	}

	return str[index];
}
