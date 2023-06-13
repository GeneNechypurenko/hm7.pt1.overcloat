#pragma once
#include "windows.h"

#include "Globals.h"
#include "Overcloat.h"

extern HANDLE hSettings;

void LogicHideCursor(bool hide);
void LogicSetCoords(short x, short y);
void LogicTextColor(int textcolor);
void LogicPause();
void LogicCleanBuffer();

void LogicSafeInput(int& value, int min, int max);

const char* LogicSelectStr(const char* str[], short x, short y);
