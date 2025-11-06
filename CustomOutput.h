#pragma once
#include <iostream>
#include <Windows.h>

class CustomOutput
{
	const int WIDTH;
	const int HEIGHT;
	unsigned int count = 0;

	static const char* COLORS;
	static CustomOutput* output;

	CustomOutput(int width, int height);
public:
	static void Init(int width, int height);
	static CustomOutput& Get();

	CustomOutput& operator << (const char* value);
	CustomOutput& operator << (char value);

	CustomOutput& operator << (int value);
	CustomOutput& operator << (float value);
};

