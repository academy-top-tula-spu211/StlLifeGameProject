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
