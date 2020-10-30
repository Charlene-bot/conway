#include "conway.h"



int main()
{
  initscr();
  clear(); 
  noecho(); 
  cbreak(); 
  nodelay(stdscr, true); 
  keypad(stdscr, true); 
  
  vector<vector<int>> grid; 
   
  initialGrid(grid); 
  printGrid(grid); 

//  int key = getch(); 
//  while(key != 'Q')
  playmode(grid); 
//  printGrid(grid); 
  refresh(); 
  getch(); 
  endwin();
  return 0;
}
