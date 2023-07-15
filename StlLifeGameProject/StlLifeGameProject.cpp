#include <iostream>
#include "Console.h"

int main()
{
    Console console;
    
    int row{ 0 };
    int column{ 0 };

    Key key;
    bool isExit{ false };
    
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
            break;
        case Key::Esc:
            isExit = true;
            break;
        case Key::Enter:
            break;
        default:
            break;
        }
        if (isExit) break;
        console.SetPosition(row, column);
    }
}
