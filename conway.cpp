#include "conway.h"

void initialGrid(vector<vector<int>> &gridOne)
{
    for(int i = 0; i < COLS; i++)
    {
      vector<int> num; 
      for(int j = 0; j < LINES; j++)
        {
          num.push_back(0);
        }
          gridOne.push_back(num); 
    }
}
void printGrid(vector<vector<int>> &gridOne)
{
  for(int i = 0; i < COLS; i++)
  {
    for(int j= 0; j < LINES; j++)
      {
        if(gridOne[i][j]== 1)
        {
            mvprintw(j, i, ALIVE); 
        }
        else
        {
            mvprintw(j, i, DEAD); 
        }
      }
  }
}
void playmode(vector<vector<int>> & gridOne)
{
  int currx = 0; 
  int curry = 0;
  //Paused mode toggling with the arrow keys
  while(true)
  {
   int key = getch(); 
    switch(key)
    {
      case KEY_UP:
              if(curry > 0)
                curry--; 
               break;
      case KEY_DOWN:
              if(curry < LINES-1)
                curry++; 
               break; 
      case KEY_LEFT:
              if(currx > 0)
                currx--;
               break; 
      case KEY_RIGHT:
              if(currx < COLS -1)
                currx++; 
               break; 
      case 'X':
      case 'x':
               if(gridOne[currx][curry] == 0)
                   gridOne[currx][curry] = 1; 
               else 
                   gridOne[currx][curry] = 0; 
               break; 
       default:
//              printw("Wrong input"); 
              break;
      }
     
      printGrid(gridOne);  
      move(curry, currx); 
      refresh(); 
      if(key == 'Q')
        break; 
 } 
      printGrid(gridOne);
 }

