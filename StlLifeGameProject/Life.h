#pragma once
enum class CellState
{
	Empty,
	Life,
	Dead,
	Born
};

class Cell
{
	int row;
	int column;
	CellState state;
public:
	Cell(int row, int column)
		: row{ row }, column{ column }, state{ CellState::Life } {}
	int Row() const { return row; }
	int Column() const { return column; }

	CellState& State() { return state; }

	friend bool operator==(Cell c1, Cell c2);
	friend bool operator!=(Cell c1, Cell c2);
};

class Life
{
};

