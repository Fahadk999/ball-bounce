#include "gameengine.h"

#ifdef _WIN32
#include <windows.h>

void moveCursorTo(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {(SHORT)y, (SHORT)x};
    SetConsoleCursorPosition(hOut, pos);
}
#else
void moveCursorTo(int x, int y)
{
    std::cout << "\033[" << x + 1 << ";" << y + 1 << "H";
}
#endif

void RenderWindow::setWindow(unsigned int width, unsigned int height)
{
    WIDTH = width;
    HEIGHT = height;
    frontBuffer.assign(HEIGHT, std::vector<char>(WIDTH, ' '));
    backBuffer = frontBuffer;
}

void RenderWindow::clear()
{
    for (auto& row : frontBuffer)
        std::fill(row.begin(), row.end(), ' ');
}

void RenderWindow::render()
{
    for (unsigned int y = 0; y < HEIGHT; ++y)
    {
        for (unsigned int x = 0; x < WIDTH; ++x)
        {
            char ch = frontBuffer[y][x];

            if (drawBoundary && (x == 0 || y == 0 || y == HEIGHT - 1 || x == WIDTH - 1))
                ch = boundary;

            if (backBuffer[y][x] != ch)
            {
                moveCursorTo(y, x);
                std::cout << ch;
                backBuffer[y][x] = ch;
            }
        }
    }

    std::cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(framedelay));
}

void RenderWindow::draw(DrawChar& _char)
{
    int x = _char.getPosition().x;
    int y = _char.getPosition().y;

    if (x >= 0 && x < (int)WIDTH && y >= 0 && y < (int)HEIGHT)
        frontBuffer[y][x] = _char.getChar();
}

void RenderWindow::drawAll(DrawChar* arr, size_t size)
{ for (int i = 0; i < size; i++) draw(arr[i]); }

void RenderWindow::setBoundaryChar(char ch)
{
    if (drawBoundary)
        boundary = ch;
    else
        std::cout << "Set <yourWindow>.drawBoundary = true before changing boundary character.\n";
}
