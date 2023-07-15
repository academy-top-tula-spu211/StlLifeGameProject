#include "Console.h"

void Console::SetPosition(int row, int column)
{
	COORD position;
	position.X = column;
	position.Y = row;
	SetConsoleCursorPosition(descriptor, position);
}

void Console::SetForeground(Colors color)
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(descriptor, &info);

	WORD colorCurrent = info.wAttributes;
	WORD colorNew = ((colorCurrent >> 4) << 4) | (unsigned char)color;

	SetConsoleTextAttribute(descriptor, colorNew);
}

void Console::SetBackground(Colors color)
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(descriptor, &info);

	WORD colorCurrent = info.wAttributes;
	WORD colorNew = (colorCurrent & 0b1111) | ((unsigned char)color << 4);

	SetConsoleTextAttribute(descriptor, colorNew);
}

void Console::SetColors(Colors back, Colors fore)
{
	SetForeground(fore);
	SetBackground(back);
}

void Console::Write(std::string message)
{
	std::cout << message;
}

void Console::WriteLine(std::string message)
{
	std::cout << message << "\n";
}

void Console::WritePosition(int row, int column, std::string message)
{
	SetPosition(row, column);
	Write(message);
}

void Console::Clear()
{
	system("cls");
}

Key Console::ReadKey()
{
	if(_kbhit())
		return (Key)_getch();
}

