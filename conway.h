 //Charlene Crystal Namuyige 
//Conway's Game of Life
#ifndef CONWAY_H
#define CONWAY_H
#define ALIVE "X"
#define DEAD "."
#include <ncurses.h>
#include <stdio.h>
#include <vector>

using namespace std;
void initialGrid(vector<vector<int>> &grid);
void printGrid(vector<vector<int> > & grid);
void playmode(int , int); 
#endif
