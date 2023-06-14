#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Globals.h"

using namespace std;

class Overcloat
{
private:
	char* type;
	char* size;
	char* color;
	int price;
	static int count;
	static HANDLE hSettings;

public:
	explicit Overcloat();

	Overcloat(const Overcloat& object) = delete;

	~Overcloat();

	void SetType(const char* type);
	void SetSize(const char* size);
	void SetColor(const char* color);
	void SetPrice(int price);
	//void SetCount(int count);

	const char* GetType() const;
	const char* GetSize() const;
	const char* GetColor() const;
	int GetPrice() const;
	static int GetCount();

	Overcloat& operator=(const Overcloat& object);
	bool operator==(const Overcloat& object) const;
	bool operator==(int price) const;
	bool operator>(const Overcloat& object) const;

	void InitType();
	void InitSize();
	void InitColor();
	void InitPrice();

	void PrintItem() const;
	void AddObject(Overcloat*& object);
	void RemoveObject(Overcloat*& object, int index);
	void PrintList(const Overcloat* object) const;
	void EditObject(Overcloat*& object, int index);

private:
	const char* LogicSelectStr(const char* str[], short x, short y);

public:
	static void LogicHideCursor(bool hide);
	static void LogicSetCoords(short x, short y);
	static void LogicTextColor(int textcolor);
	static void LogicPause();
	static void LogicCleanBuffer();
	static void LogicSafeInput(int& value, int min, int max);
	static void LogicSaveData(FILE* file, Overcloat*& object, const char* filename);
	static void LogicReadData(FILE* file, Overcloat*& object, const char* filename);
};