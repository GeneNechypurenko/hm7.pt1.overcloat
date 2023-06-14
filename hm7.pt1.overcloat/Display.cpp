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
	const char* str[]{ "���   : ", "�����: ", "���� : ", "����  : " };

	for (int i = 0; i < row; i++)
		cout << str[i] << endl;

	list->AddObject(list);

	Overcloat::LogicTextColor(HIGHLIGHT);
	cout << endl << "����� ����� ������" << endl;

	Overcloat::LogicTextColor(STANDART);
	Overcloat::LogicPause();
}

void DisplayPrint(const Overcloat* list) {

	system("cls");
	Overcloat::LogicTextColor(STANDART);

	if (Overcloat::GetCount() != 0)
		list->PrintList(list);

	else
		cout << "������ �������..." << endl;

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

		cout << "��� ��������� ������ ����� ������ � ������.." << endl;
		Overcloat::LogicSetCoords(x, y);
		Overcloat::LogicHideCursor(TRUE);
		cout << "������: ";
		Overcloat::LogicSafeInput(index, min, max);

		index -= 1;
		list->RemoveObject(list, index);

		Overcloat::LogicTextColor(HIGHLIGHT);
		cout << endl << "����� ���������" << endl;
	}

	else
		cout << "������ �������..." << endl;

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

		cout << "��� ����������� ������ ����� ������ � ������.." << endl;
		Overcloat::LogicSetCoords(x, y);
		Overcloat::LogicHideCursor(TRUE);
		cout << "������: ";
		Overcloat::LogicSafeInput(index, min, max);
		system("cls");
		Overcloat::LogicHideCursor(FALSE);

		index -= 1;
		list->EditObject(list, index);

		Overcloat::LogicTextColor(HIGHLIGHT);
		cout << endl << "������ �������������" << endl;
	}

	else
		cout << "������ �������..." << endl;

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

		cout << "��� ��������� ���� ����� ������ ����� ������ �� ������.." << endl;
		Overcloat::LogicSetCoords(x, y);
		Overcloat::LogicHideCursor(TRUE);
		cout << "������: ";
		Overcloat::LogicSafeInput(indexFirst, min, max);
		system("cls");
		Overcloat::LogicHideCursor(FALSE);
		indexFirst -= 1;

		cout << "������� ��������� ����� ��� ��������� �� ������.." << endl;
		Overcloat::LogicSetCoords(x, y);
		Overcloat::LogicHideCursor(TRUE);
		cout << "������: ";
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
			cout << "���� ���������� ����";
		else
			cout << "���� ����� ����";
	}

	else
		cout << "����������� ������ ��� ���������..." << endl;

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

		cout << "��� ��������� ��� ������ ����� ������ �� ������.." << endl;
		Overcloat::LogicSetCoords(x, y);
		Overcloat::LogicHideCursor(TRUE);
		cout << "������: ";
		Overcloat::LogicSafeInput(indexFirst, min, max);
		system("cls");
		Overcloat::LogicHideCursor(FALSE);
		indexFirst -= 1;

		cout << "������� ��������� ����� ��� ��������� �� ������.." << endl;
		Overcloat::LogicSetCoords(x, y);
		Overcloat::LogicHideCursor(TRUE);
		cout << "������: ";
		Overcloat::LogicSafeInput(indexSec, min, max);
		system("cls");
		Overcloat::LogicHideCursor(FALSE);
		indexSec -= 1;

		if (list[indexFirst] > list[indexSec]) {

			Overcloat::LogicTextColor(HIGHLIGHT);
			list[indexFirst].PrintItem();
			cout << endl;
			cout << "�������� �� �����: " << endl << endl;
			Overcloat::LogicTextColor(STANDART);
			list[indexSec].PrintItem();
		}
		else if (list[indexFirst] == list[indexSec].GetPrice()) {

			Overcloat::LogicTextColor(STANDART);
			list[indexFirst].PrintItem();
			cout << endl;
			Overcloat::LogicTextColor(HIGHLIGHT);
			cout << "������� �� �����: " << endl << endl;
			Overcloat::LogicTextColor(STANDART);
			list[indexSec].PrintItem();
		}
		else {

			Overcloat::LogicTextColor(STANDART);
			list[indexFirst].PrintItem();
			cout << endl;
			Overcloat::LogicTextColor(HIGHLIGHT);
			cout << "�������� �� �����: " << endl << endl;
			list[indexSec].PrintItem();
		}
	}

	else
		cout << "����������� ������ ��� ���������..." << endl;

	Overcloat::LogicTextColor(STANDART);
	Overcloat::LogicPause();
}