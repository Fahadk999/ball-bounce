#include "drawchar.h"

void DrawChar::move (int newX, int newY)
{
    pos.x += newX;
    pos.y += newY;
}
void DrawChar::setPosition(int x, int y) { pos.x = x; pos.y = y; }
