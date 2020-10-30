#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <list>
#include "Infected.h"
#include "People.h"
#include "Wall.h"
#include <windows.h> /* WinAPI */

const int WALL = -1;
const int CLEAR = 0;
const int PEOPLE = 1;
const int INFECTED = 2;

const int TMATRIX = 100;
const int TIMECICLE = 500;
const int TCELL = 5;

const int TINFECTED = 50;
const int TPEOPLE = 30;
const int TWALL = 4;

int matrix[TMATRIX][TMATRIX];
int cicleNumber = 0;

std::list<Infected> infectedCells;
std::list<Infected>::iterator iInfected;

std::list<Wall> wallCells;
std::list<Wall>::iterator iWall;

std::list<People> peopleCells;
std::list<People>::iterator iPeople;

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

    Wall newWall(x, y, 1);
    People newPeople(x, y, 1);
    Infected newInfected(x, y, 1);
    switch (type)
    {
    case -1:
        // std::cout << "PEOPLE [" << x << "," << y << "]" << std::endl;
        wallCells.push_back(newWall);
        matrix[x][y] = WALL;
        break;
    case 1:
        // std::cout << "PEOPLE [" << x << "," << y << "]" << std::endl;
        peopleCells.push_back(newPeople);
        matrix[x][y] = PEOPLE;
        break;
    case 2:
        // std::cout << "INFECTED [" << x << "," << y << "]" << std::endl;
        infectedCells.push_back(newInfected);
        matrix[x][y] = INFECTED;
        break;
    default:
        break;
    }
}

void simulation()
{
    for (int i = 0; i < TWALL; i++)
    {
        randomCell(-1);
    }
    for (int i = 0; i < TPEOPLE; i++)
    {
        randomCell(1);
    }
    for (int i = 0; i < TINFECTED; i++)
    {
        randomCell(2);
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

void cicle()
{

    for (iInfected = infectedCells.begin(); iInfected != infectedCells.end(); ++iInfected)
    {
        matrix[iInfected->x][iInfected->y] = CLEAR;
        iInfected->ableToMove(randomDirection(), TMATRIX);
        matrix[iInfected->x][iInfected->y] = INFECTED;
    }

    for (iPeople = peopleCells.begin(); iPeople != peopleCells.end(); ++iPeople)
    {
        matrix[iPeople->x][iPeople->y] = CLEAR;
        iPeople->ableToMove(randomDirection(), TMATRIX);
        matrix[iPeople->x][iPeople->y] = PEOPLE;
    }

    for (iWall = wallCells.begin(); iWall != wallCells.end(); ++iWall)
    {
        matrix[iWall->x][iWall->y] = CLEAR;
        iWall->ableToMove(randomDirection(), TMATRIX);
        matrix[iWall->x][iWall->y] = WALL;
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
            if (matrix[x][y] == CLEAR)
            {
                cell.setFillColor(sf::Color::Black);
            }
            else if (matrix[x][y] == PEOPLE)
            {
                cell.setFillColor(sf::Color::Cyan);
            }
            else if (matrix[x][y] == INFECTED)
            {
                cell.setFillColor(sf::Color::Red);
            }
            else if (matrix[x][y] == WALL)
            {
                cell.setFillColor(sf::Color::Green);
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