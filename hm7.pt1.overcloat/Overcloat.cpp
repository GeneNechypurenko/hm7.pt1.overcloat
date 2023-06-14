#include "Overcloat.h"

int Overcloat::count = 0;

HANDLE Overcloat::hSettings = GetStdHandle(STD_OUTPUT_HANDLE);

Overcloat::Overcloat()
	:type(nullptr), size(nullptr), color(nullptr), price(0) {}

Overcloat::~Overcloat()	{

	if (this->type != nullptr)
		delete[]type;

	if (this->size != nullptr)
		delete[]size;

	if (this->color != nullptr)
		delete[]color;
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

//void Overcloat::SetCount(int count) {
//
//	this->count = count;
//}

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

	return (strcmp(this->type, object.type) == 0);
}

bool Overcloat::operator==(int price) const {

	return this->price == price;
}

bool Overcloat::operator>(const Overcloat& object) const {

	return price > object.price;
}

void Overcloat::InitType() {

	short x = 8, y = 0;
	const char* types[]{ "Пальто  ", "Плащ    ", "Куртка  ", "Тренчкот", "Жилет   "};
	SetType(LogicSelectStr(types, x, y));
}

void Overcloat::InitSize() {

	short x = 8, y = 1;
	const char* sizes[]{ "XS", "S ", "M ", "L ", "XL" };
	SetSize(LogicSelectStr(sizes, x, y));
}

void Overcloat::InitColor() {

	short x = 8, y = 2;
	const char* colors[]{ "чорний", "білий ", "сірий ", "беж   ", "синій " };
	SetColor(LogicSelectStr(colors, x, y));
}

void Overcloat::InitPrice() {

	int price, min = 1, max = 999999;
	LogicHideCursor(TRUE);
	LogicSafeInput(price, min, max);
	SetPrice(price);
}

void Overcloat::PrintItem() const {

	cout << "тип   : " << type << endl;
	cout << "розмір: " << size << endl;
	cout << "колір : " << color << endl;
	cout << "ціна  : " << price << endl;
}

void Overcloat::AddObject(Overcloat*& object) {

	Overcloat* temp = new Overcloat[count + 1];

	for (int i = 0; i < count; i++)
		temp[i] = object[i];

	temp[GetCount()].InitType();
	temp[GetCount()].InitSize();
	temp[GetCount()].InitColor();
	temp[GetCount()].InitPrice();

	delete[] object;
	object = temp;
	++count;
}

void Overcloat::RemoveObject(Overcloat*& object, int index) {

	Overcloat* temp = new Overcloat[count - 1];
	int j = 0;

	for (int i = 0; i < count; i++)
		if (i != index) {
			temp[j] = object[i];
			j++;
		}

	delete[]object;
	object = temp;
	--count;
}

void Overcloat::PrintList(const Overcloat* object) const {

	for (int i = 0; i < count; i++) {

		cout << "--- ТОВАР №[" << i + 1 << "] ---" << endl;
		object[i].PrintItem();
		cout << "___________________" << endl;
	}
}

void Overcloat::EditObject(Overcloat*& object, int index) {

	int row = 4;
	const char* str[]{ "тип   : ", "розмір: ", "колір : ", "ціна  : " };

	for (int i = 0; i < row; i++)
		cout << str[i] << endl;

	object[index].InitType();
	object[index].InitSize();
	object[index].InitColor();
	object[index].InitPrice();
}



const char* Overcloat::LogicSelectStr(const char* str[], short x, short y) {

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



void Overcloat::LogicHideCursor(bool hide) {

	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hSettings, &structCursorInfo);
	structCursorInfo.bVisible = hide;
	SetConsoleCursorInfo(hSettings, &structCursorInfo);
}
void Overcloat::LogicSetCoords(short x, short y) {

	SetConsoleCursorPosition(hSettings, { x,y });
}
void Overcloat::LogicTextColor(int textcolor) {

	SetConsoleTextAttribute(hSettings, textcolor);
}
void Overcloat::LogicPause() {

	const short x = 40, y = 26;
	SetConsoleCursorPosition(hSettings, { x,y });
	system("pause");
}
void Overcloat::LogicCleanBuffer() {

	if (cin.rdbuf()->in_avail() != 0) {
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	}
}
void Overcloat::LogicSafeInput(int& value, int min, int max) {

	short x = 8, y = 3;
	LogicSetCoords(x, y);

	while (!(cin >> value) || value < min || value > max) {
		cout << "помилка, невірно задане значення.. спробуйте знову: ";
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	}
}

void Overcloat::LogicSaveData(FILE* file, Overcloat*& object, const char* filename) {

	const int typeLen = 9;
	const int sizeLen = 3;
	const int colorLen = 7;

	fopen_s(&file, filename, "wb");

	if (file == nullptr) {
		cout << "Помилка відкриття файлу!" << endl;
		return;
	}

	fwrite(&count, sizeof(count), 1, file);

	for (int i = 0; i < count; i++) {

		const char* type = object[i].GetType();
		const char* size = object[i].GetSize();
		const char* color = object[i].GetColor();
		int price = object[i].GetPrice();

		fwrite(type, sizeof(char), typeLen, file);
		fwrite(size, sizeof(char), sizeLen, file);
		fwrite(color, sizeof(char), colorLen, file);
		fwrite(&price, sizeof(price), 1, file);
	}

	fclose(file);
}


void Overcloat::LogicReadData(FILE* file, Overcloat*& object, const char* filename) {

	const int typeLen = 9;
	const int sizeLen = 3;
	const int colorLen = 7;

	fopen_s(&file, filename, "rb");

	if (file == nullptr) {
		cout << "Помилка відкриття файлу!" << endl;
		return;
	}

	fread(&count, sizeof(count), 1, file);

	Overcloat* data = new Overcloat[count];

	for (int i = 0; i < count; i++) {

		char type[typeLen];
		char size[sizeLen];
		char color[colorLen];
		int price;

		fread(type, sizeof(char), typeLen, file);
		fread(size, sizeof(char), sizeLen, file);
		fread(color, sizeof(char), colorLen, file);
		fread(&price, sizeof(price), 1, file);

		data[i].SetType(type);
		data[i].SetSize(size);
		data[i].SetColor(color);
		data[i].SetPrice(price);
	}

	fclose(file);
	object = data;
}