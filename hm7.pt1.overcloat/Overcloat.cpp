#include "Overcloat.h"

int Overcloat::count = 0;

Overcloat::Overcloat()
	:type(nullptr), size(nullptr), color(nullptr), price(0) {}

Overcloat::~Overcloat()	{

	if (this->type != nullptr)
		delete[]type;

	if (this->size != nullptr)
		delete[]size;

	if (this->color != nullptr)
		delete[]color;

	count--;
}

void Overcloat::SetType(const char* type)	{

	if (this->type != nullptr) 
		delete[]this->type;

	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);	
}

void Overcloat::SetSize(const char* size) {

	if (this->size != nullptr) 
		delete[]this->size;

	this->size = new char[strlen(size) + 1];
	strcpy_s(this->size, strlen(size) + 1, size);
}

void Overcloat::SetColor(const char* color) {

	if (this->color != nullptr) 
		delete[]this->color;

	this->color = new char[strlen(color) + 1];
	strcpy_s(this->color, strlen(color) + 1, color);	
}

void Overcloat::SetPrice(int price) {

	this->price = price;
}

const char* Overcloat::GetType() const {

	return type;
}

const char* Overcloat::GetSize() const {

	return size;
}

const char* Overcloat::GetColor() const {

	return color;
}

int Overcloat::GetPrice() const {

	return price;
}

int Overcloat::GetCount()
{
	return count;
}

Overcloat& Overcloat::operator=(const Overcloat& object) {

	SetType(object.type);
	SetSize(object.size);
	SetColor(object.color);
	SetPrice(object.price);

	return *this;
}

bool Overcloat::operator==(const Overcloat& object) const {

	if (strcmp(this->type, object.type) == 0)
		return true;

	return false;
}

bool Overcloat::operator>(const Overcloat& other) const {

	return price > other.price;
}

void Overcloat::InitType() {

	short x = 8, y = 0;
	const char* types[]{ "Пальто    ", "Плащ        ", "Куртка    ", "Тренчкот", "Жилет      "};
	SetType(LogicSelectStr(types, x, y));
}

void Overcloat::InitSize() {

	short x = 8, y = 1;
	const char* sizes[]{ "XS", "S ", "M ", "L ", "XL" };
	SetSize(LogicSelectStr(sizes, x, y));
}

void Overcloat::InitColor() {

	short x = 8, y = 2;
	const char* colors[]{ "чорний", "білий  ", "сірий  ", "беж      ", "синій  " };
	SetColor(LogicSelectStr(colors, x, y));
}

void Overcloat::InitPrice() {

	int price, min = 1, max = 999999;
	LogicSafeInput(price, min, max);
	SetPrice(price);
}

void Overcloat::AddObject(Overcloat*& list) {

	Overcloat* temp = new Overcloat[Overcloat::GetCount() + 1];

	for (int i = 0; i < Overcloat::GetCount(); i++)
		temp[i] = list[i];

	temp[Overcloat::GetCount()].InitType();
	temp[Overcloat::GetCount()].InitSize();
	temp[Overcloat::GetCount()].InitColor();
	temp[Overcloat::GetCount()].InitPrice();

	delete[] list;
	list = temp;
	++count;
}

void Overcloat::Print() const {

	cout << "тип   : " << type << endl;
	cout << "розмір: " << size << endl;
	cout << "колір : " << color << endl;
	cout << "ціна  : " << price << endl;
}