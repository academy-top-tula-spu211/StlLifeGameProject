#include "Life.h"

bool operator==(Cell c1, Cell c2)
{
    return c1.Row() == c2.Row() && c1.Column() == c2.Column();
}

bool operator!=(Cell c1, Cell c2)
{
    return !(c1 == c2);
}

bool Life::SetColony()
{
    {
        int row{ 0 };
        int column{ 0 };

        Key key;
        bool isExit{ false };
        bool isContinue{ false };

        while (true)
        {
            key = console.ReadKey();
            switch (key)
            {
            case Key::ArrowLeft:
                if (column > 0)
                    column--;
                break;
            case Key::ArrowRight:
                column++;
                break;
            case Key::ArrowUp:
                if (row > 0)
                    row--;
                break;
            case Key::ArrowDown:
                row++;
                break;
            case Key::Space:
            {
                auto it = IsColonyCell(row, column);
                if (it == colony.end())
                    colony.push_back(Cell(row, column));
                else
                    colony.erase(it);
                PrintColony();
                break;
            }
            case Key::Esc:
                isExit = true;
                break;
            case Key::Enter:
                isExit = true;
                isContinue = true;
                break;
            default:
                break;
            }
            if (isExit) break;
            console.SetPosition(row, column * 2);
        }
        return isContinue;
    }
}



void Life::Step()
{
    for (auto cell = colony.begin(); cell != colony.end(); cell++)
    {
        cell->Neighbors() = 0;
        for (auto off : offset)
        {
            int row = cell->Row() + off.row;
            int column = cell->Column() + off.column;
            if (IsColonyCell(row, column) != colony.end())
                cell->Neighbors()++;
        }
        if (cell->Neighbors() < 2 || cell->Neighbors() > 3)
            cell->State() = CellState::Dead;
    }

    int index{};
    while (index < colony.size())
    {
        for (auto off : offset)
        {
            int row = colony[index].Row() + off.row;
            int column = colony[index].Column() + off.column;
            Cell cellCandidat(row, column);
            if (IsColonyCell(row, column) == colony.end())
            {
                for (auto offCandidat : offset)
                {
                    int rowOff = row + offCandidat.row;
                    int columnOff = column + offCandidat.column;
                    
                    auto cellFind = IsColonyCell(rowOff, columnOff);
                    if (cellFind != colony.end() && cellFind->State() != CellState::Born)
                        cellCandidat.Neighbors()++;
                }
                if (cellCandidat.Neighbors() == 3)
                {
                    cellCandidat.State() = CellState::Born;
                    colony.push_back(cellCandidat);
                }
            }
        }
        index++;
    }

    index = 0;
    while (index < colony.size())
    {
        if (colony[index].State() == CellState::Dead)
            colony.erase(colony.begin() + index);
        else
            colony[index++].State() = CellState::Life;
    }
}

void Life::Play()
{
    using namespace std;

    Key key;
    while (true)
    {
        key = console.ReadKey();
        if (key == Key::Esc)
            break;
        PrintColony();
        Step();
        this_thread::sleep_for(200ms);
    }
}



std::vector<Cell>::iterator Life::IsColonyCell(int row, int column)
{
    Cell cell(row, column);
    return find_if(colony.begin(), colony.end(), [&cell](auto item) 
        {
            return cell == item;
        });
}

void Life::PrintColony()
{
    console.Clear();

    for (auto cell : colony)
    {
        console.WritePosition(cell.Row(), cell.Column() * 2, std::string(2, (char)178));
    }
}
