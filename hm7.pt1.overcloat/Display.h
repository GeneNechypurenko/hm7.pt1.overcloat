#pragma once
#include "Overcloat.h"
#include "Globals.h"

void DisplayMenu(const char* menu[], int row, int select);

void DisplayAdd(Overcloat*& list);

void DisplayPrint(const Overcloat* list);

void DisplayRemove(Overcloat*& list);

void DisplayEdit(Overcloat*& list);

void DisplayTypesCmp(Overcloat*& list);

void DisplayPriceCmp(Overcloat*& list);