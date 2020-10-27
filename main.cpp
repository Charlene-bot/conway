#include "conway.h"
int main()
{
  initscr();
  keypad(stdscr, true); 
  
  vector<vector<int>> grid; 

  initialGrid(grid); 
  printGrid(grid); 


//  int startx = 0;
 // int starty = 0;

/*  int ch = getch(); 
  while(!(ch == 113))
    playmode(startx, starty); 
*/
  refresh(); 
  getch(); 
  endwin();
  return 0;
}
