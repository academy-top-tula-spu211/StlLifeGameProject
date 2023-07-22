#include <iostream>
#include "Life.h"

int main()
{
    Life life;
    
    if (life.SetColony())
        life.Play();
}
