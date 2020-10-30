#pragma once
#include <stdlib.h>
#include <time.h>
#include <iostream>

const float ALPHA = 20; //porcentagem zumbi
const float GAMMA = 40; //porcentagem zumbi->pessoa
const float PESGAMMA = (1 - (GAMMA/100)); //porcentagem pessoa->zumbi

const int WALL = -1;
const int CLEAR = 0;
const int PEOPLE = 1;
const int INFECTED = 2;

const int TMATRIX = 200;
const int TIMECICLE = 10;
const int TCELL = 5;

const int TPEOPLE = 5000;
const int TINFECTED = (int)(TPEOPLE * (ALPHA / 100));
const int TWALL = 40;

const int WALLCELLS = 8;
