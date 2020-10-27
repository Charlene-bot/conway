#include "conway.h"

void initialGrid(vector<vector<int>> &gridOne)
{
    vector<int> num; 
    for(int i = 0; i < COLS; i++)
    {
      for(int j = 0; j < LINES; j++)
      {
        num.push_back(0);
        gridOne.push_back(num); 
      }
    }
}

void printGrid(vector<vector<int>> &gridOne)
//void printGrid(std::vector <int> const &gridOne)
{
  for(int i = 0; i < COLS; i++)
  {
    for(int j= 0; j < LINES; j++)
      {
        if(gridOne[i][j]== 1)
        {
            mvprintw(j, i, ALIVE); 
            refresh(); 
        }
        else
        {
            mvprintw(j, i, DEAD); 
            refresh();
        }
      }
  }

}
void playmode(int startx, int starty)
{
  //Paused mode toggling with the arrow keys

  int key = getch();
  while(key != 113)
  {
    switch(key)
    {
      case KEY_UP:
        move(starty-1, startx);
        refresh();
      break;
      case KEY_DOWN:
        //mvprintw(starty + 1, startx,  alive);
        refresh();
      break;
      case KEY_LEFT:
       // mvprintw(starty, startx - 1, alive);
        refresh();
      break;
      case KEY_RIGHT:
        //mvprintw(starty, startx + 1, alive);
        refresh();
      break;
      default:
         printw("Wrong input"); 
        break;
      }
    }
}

