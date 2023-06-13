#pragma once
#include <iostream>
#include <conio.h>

#include "Globals.h"
#include "Logic.h"

using namespace std;

class Overcloat
{
	char* type;
	char* size;
	char* color;
	int price;
	static int count;
public:
	explicit Overcloat();

	Overcloat(const Overcloat& object) = delete;

	~Overcloat();

	void SetType(const char* type);
	void SetSize(const char* size);
	void SetColor(const char* color);
	void SetPrice(int price);

	const char* GetType() const;
	const char* GetSize() const;
	const char* GetColor() const;
	int GetPrice() const;
	static int GetCount();

	Overcloat& operator=(const Overcloat& object);
	bool operator==(const Overcloat& object) const;
	bool operator>(const Overcloat& object) const;

	void InitType();
	void InitSize();
	void InitColor();
	void InitPrice();

	void AddObject(Overcloat*& list);

	void Print() const;
};

