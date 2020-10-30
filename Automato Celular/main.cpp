#include <SFML/Graphics.hpp>
#include <list>
#include <windows.h>
#include <stdio.h>
#include "Infected.h"
#include "People.h"
#include "Wall.h"
#include "ReturnType.h"
#include "Settings.h"

int matrix[TMATRIX][TMATRIX];
long int cicleNumber = 0;
int ciclePrint = 0;

bool fI, fP, fW = false;

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

// 0 = up
// 1 = right
// 2 = down
// 3 = left
int randomDirection()
{
    return rand() % 4;
}

void randomCell(int type)
{
    int x;
    int y;
    do
    {
        x = rand() % TMATRIX;
        y = rand() % TMATRIX;

    } while (matrix[x][y] != CLEAR);

    Wall newWall(x, y, 1);
    People newPeople(x, y, 1);
    Infected newInfected(x, y, 1);

    switch (type)
    {
    case -1:
        // std::cout << "PEOPLE [" << x << "," << y << "]" << std::endl;
        wallCells.push_back(newWall);
        matrix[x][y] = WALL;
        newWall.buildWall(matrix, randomDirection());
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

void printArchive(int pessoa, int zumbi)
{
    errno_t err;
    FILE *stream;
    err = fopen_s(&stream, "teste1.csv", "a+");

    fprintf(stream, "%d, %d, %d\n", cicleNumber, pessoa, zumbi);
    fclose(stream);
}

void searchInfected(int x, int y)
{
    for (iInfected = infectedCells.begin(); iInfected != infectedCells.end(); ++iInfected)
    {
        if ((iInfected->x == x) && (iInfected->y == y))
        {
            infectedCells.erase(iInfected++);
            // infectedCells.erase(iInfected);
        }
    }
}

void searchPeople(int x, int y)
{
    for (iPeople = peopleCells.begin(); iPeople != peopleCells.end(); ++iPeople)
    {
        if ((iPeople->x == x) && (iPeople->y == y))
        {
            peopleCells.erase(iPeople);
            Infected newInfected(x, y, 1);
            infectedCells.push_back(newInfected);
            matrix[x][y] = INFECTED;
            break;
        }
    }
}

void randomToMove()
{
    int x;
    int y;
    int sorteio = rand() % 100;
    do
    {
        x = rand() % 100;
        y = rand() % 100;

    } while ((matrix[x][y] == CLEAR) || (matrix[x][y] == WALL));

    // if (matrix[x][y] == PEOPLE)
    // {
    //     for (iPeople = peopleCells.begin(); iPeople != peopleCells.end(); ++iPeople)
    //     {
    //         if ((iPeople->x == x) && (iPeople->y == y))
    //         {
    //             matrix[iPeople->x][iPeople->y] = CLEAR;
    //             ReturnType response = iPeople->ableToMove(randomDirection(), matrix);
    //             if (response.status)
    //             {
    //                 if (sorteio <= PESGAMMA)
    //                 {
    //                     std::cout << "Zumbi morto!" << std::endl;
    //                     searchInfected(response.x, response.y);
    //                 }
    //             }
    //             matrix[iPeople->x][iPeople->y] = PEOPLE;
    //         }
    //     }
    // }
    if (matrix[x][y] == INFECTED)
    {
        for (iInfected = infectedCells.begin(); iInfected != infectedCells.end(); ++iInfected)
        {
            if ((iInfected->x == x) && (iInfected->y == y))
            {

                matrix[iInfected->x][iInfected->y] = CLEAR;
                ReturnType response = iInfected->ableToMove(randomDirection(), matrix);
                if (response.status)
                {
                    if (sorteio <= GAMMA)
                    {
                        searchPeople(response.x, response.y);
                    }
                }
                matrix[iInfected->x][iInfected->y] = INFECTED;
            }
        }
    }
}

void buildWalls()
{
    for (iWall = wallCells.begin(); iWall != wallCells.end(); ++iWall)
    {
        matrix[iWall->x][iWall->y] = CLEAR;
        iWall->ableToMove(randomDirection());
        matrix[iWall->x][iWall->y] = WALL;
    }
}

void cicle()
{

    buildWalls();
    randomToMove();

    cicleNumber++;
    ciclePrint++;
}

void drawMatrix(sf::RenderWindow *window)
{
    if (ciclePrint == 100)
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
}

void draw(sf::RenderWindow *window)
{
    drawMatrix(window);
}

int main()
{
    // sf::RenderWindow window(sf::VideoMode(500, 500), "Zombie vs Humans");

    start();
    simulation();
    // while (window.isOpen())
    while (1)
    {
        std::cout << cicleNumber << " Infectados: " << infectedCells.size() << " Pessoas: " << peopleCells.size() << std::endl;
        if (ciclePrint == 100)
        {
            printArchive(infectedCells.size(), peopleCells.size());
            ciclePrint = 0;
        }
        cicle();

        // sf::Event event;
        // while (window.pollEvent(event))
        // {
        //     if (event.type == sf::Event::Closed)
        //         window.close();
        // }

        // if (ciclePrint == 100)
        //     window.clear();
        // draw(&window);
        // window.display();
        // if (cicleNumber == 2000)
        if (peopleCells.size() == 0)
            return 0;
        //Sleep(TIMECICLE);
    }

    return 0;
}