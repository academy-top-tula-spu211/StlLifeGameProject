#pragma once
#include <Windows.h>
#include <string>
#include <iostream>
#include <conio.h>

enum class Key
{
	ArrowLeft	= 75,
	ArrowRight	= 77,
	ArrowUp		= 72,
	ArrowDown	= 80,
	Space		= 32,
	Esc			= 27,
	Enter		= 13,
};

enum class Colors
{
	Black		= 0b0000,
	DarkBlue	= 0b0001,
	DarkGreen	= 0b0010,
	DarkCyan	= 0b0011,
	DarkRed		= 0b0100,
	DarkMagenta = 0b0101,
	DarkYellow	= 0b0110,
	Gray		= 0b0111,

	DarkGray	= 0b1000,
	Blue		= 0b1001,
	Green		= 0b1010,
	Cyan		= 0b1011,
	Red			= 0b1100,
	Magenta		= 0b1101,
	Yellow		= 0b1110,
	White		= 0b1111,
};

class Console
{
	HANDLE descriptor;
public:
	Console()
		: descriptor{ GetStdHandle(STD_OUTPUT_HANDLE) } {};

	void SetPosition(int row, int column);

	void SetForeground(Colors color);
	void SetBackground(Colors color);
	void SetColors(Colors back, Colors fore);

	void Write(std::string message);
	void WriteLine(std::string message);

	void WritePosition(int row, int column, std::string message);

	void Clear();

	Key ReadKey();
};

