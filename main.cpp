#include "gameengine.h"

const unsigned int WIDTH = 80;
const unsigned int HEIGHT = 20;

void ballMotion (DrawChar&, int&, int&, int&, int&, int&);

int main ()
{
    RenderWindow window(WIDTH, HEIGHT);
    window.drawBoundary = true;
    DrawChar line[4] =
    {
        {5,3, '|'},
        {5,4, '|'},
        {5,5, '|'},
        {5,6, '|'}
    };
    bool right = false;
    int x = 70;
    int y = HEIGHT-1;
    
    DrawChar ball(x, y, 'O');

    int prevX = -1;
    int prevY = -1;
    int directionX = 1; 
    while (true)
    {
        window.clear();
        prevX = x;
        prevY = y;

        ball.move(1*directionX, -1);
        ballMotion(ball, x, y, prevX, prevY, directionX);
        window.drawAll(line, 4);
        window.draw(ball);
        window.render(); 
    }
}

void ballMotion (DrawChar& ball, int& x, int& y, int& prevX, int& prevY, int& directionX)
{
    // x or y is -1 , -2 respectivly then rebound
    int ballX = ball.getPosition().x;
    int ballY = ball.getPosition().y;

    int top = 1;
    int bottom = HEIGHT-1;
    int left = 1;
    int right = WIDTH-1;

    if (ballX == left || ballY == top || ballX == right || ballY == bottom)
    {
        if (ballX == right && prevX-x == -1 && prevY-y == 1)
        {
            y += 2;
            directionX *= -1;
        }
    }
}


