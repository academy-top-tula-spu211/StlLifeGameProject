#pragma once
#include "Console.h"
#include <vector>
#include <algorithm>
#include <thread>

enum class CellState
{
	Empty,
	Life,
	Dead,
	Born
};

struct CellStruct
{
	int row;
	int column;
};

class Cell
{
	int row;
	int column;
	CellState state;
	int neighbors;
public:
	Cell(int row, int column)
		: row{ row }, column{ column }, state{ CellState::Life }, neighbors{} {}
	int Row() const { return row; }
	int Column() const { return column; }

	int& Neighbors() { return neighbors; }

	CellState& State() { return state; }

	friend bool operator==(Cell c1, Cell c2);
	friend bool operator!=(Cell c1, Cell c2);
};



class Life
{
	Console console;
	std::vector<Cell> colony;
	std::vector<CellStruct> offset {{ -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 }};
public:
	Life() {}

	bool SetColony();
	void Step();
	void Play();

	std::vector<Cell>::iterator IsColonyCell(int row, int column);
	void PrintColony();
	
};

