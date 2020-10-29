#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <list>
#include "Cell.h"
#include <windows.h> /* WinAPI */

const int TMATRIX = 100;
const int TIMECICLE = 500;
const int TCELL = 5;
const int INFECTED = 50;

int matrix[TMATRIX][TMATRIX];
int cicleNumber = 0;

std::list<Cell> infectedCells;
std::list<Cell>::iterator it;

void start()
{
    srand((unsigned)time(NULL));

    for (int x = 0; x < TMATRIX; x++)
    {
        for (int y = 0; y < TMATRIX; y++)
        {
            matrix[x][y] = 0;
        }
    }
}

void randomCell(int type)
{
    int x = rand() % TMATRIX;
    int y = rand() % TMATRIX;

    Cell newCell(x, y, 1);
    switch (type)
    {
    case 1:
        infectedCells.push_back(newCell);
        break;
    default:
        break;
    }
}

void simulation()
{
    for (int i = 0; i < INFECTED; i++)
    {
        randomCell(1);
    }
}

// 0 = up
// 1 = right
// 2 = down
// 3 = left
int randomDirection()
{
    return rand() % 4;
}

int moviment(int x, int y)
{
    return x + y;
}

void cicle()
{

    for (it = infectedCells.begin(); it != infectedCells.end(); it++)
    {
        matrix[it->x][it->y] = 0;
        it->switchMove(randomDirection(), TMATRIX);
        matrix[it->x][it->y] = 1;
    }

    cicleNumber++;
}

void drawMatrix(sf::RenderWindow *window)
{

    for (int x = 0; x < TMATRIX; x++)
    {
        for (int y = 0; y < TMATRIX; y++)
        {
            sf::RectangleShape cell(sf::Vector2f(TCELL, TCELL));
            cell.setPosition(sf::Vector2f((float)x * TCELL, (float)y * TCELL));
            if (matrix[x][y] == 0)
            {
                cell.setFillColor(sf::Color(0, 255, 255, 255));
            }
            else if (matrix[x][y] == 1)
            {
                cell.setFillColor(sf::Color(0, 0, 0, 0));
            }
            window->draw(cell);
        }
    }
}

void draw(sf::RenderWindow *window)
{
    drawMatrix(window);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Zombie vs Humans");

    start();
    simulation();
    while (window.isOpen())
    {
        std::cout << "Ciclo " << cicleNumber << std::endl;
        cicle();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        draw(&window);
        window.display();

        Sleep(TIMECICLE);
    }

    return 0;
}