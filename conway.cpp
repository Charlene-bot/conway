#include "conway.h"

void initialGrid(vector<vector<int>> &gridOne) 
{
    //looping through and initializing 2d vector to 0
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
    nodelay(stdscr, false); 
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
            case 'n':
            case 'N':
                newworld(gridOne);  

                break; 
            case 'p':
            case 'P':
                key = play(gridOne); 
                break; 

            default:
                break;
        }

        printGrid(gridOne);  
        move(curry, currx); 
        refresh(); 
        if(key == 'Q' || key == 'q')
            break; 
    } 
    printGrid(gridOne);
}

int play(vector<vector<int>> & grid)
{
    nodelay(stdscr, true); 
    int ch; 
    while(1)
    {
        newworld(grid); 
        auto refresh_time = chrono::milliseconds(500); 
        this_thread::sleep_for(refresh_time); 
        printGrid(grid); 
        ch = getch(); 
        if(ch == 'p' || ch == 'q' || ch == 'P' || ch == 'Q')
            break; 
    }  
    return ch; 

}


void newworld(vector<vector<int>> &grid)
{
    vector<vector<int>> future; 
    //looping through the cells 
    for(int l = 0; l < COLS; l++)
    {
        vector<int> num; 

        for(int m = 0; m < LINES; m++)
        {
            int aliveNeighbors = 0; 
            if(l == 0 || l == COLS -1 || m == 0 || m == LINES - 1)
                num.push_back(0); 
            else
            {
                //looping through surrounding neighbors
                for(int i = -1; i < 2 ; i++)
                {
                    for(int j = -1; j < 2; j++)
                    {
                        aliveNeighbors = aliveNeighbors + grid[l + i][m + j];     
                        //original cell needs to be subtracted out 
                    }

                }
                aliveNeighbors -= grid[l][m]; 
                //Implementing the Rules of the Game of life 
                if((grid[l][m] == 1) && (aliveNeighbors < 2))
                    num.push_back(0);
                else if((grid[l][m] == 1) && (aliveNeighbors > 3))
                    num.push_back(0); 
                else if((grid[l][m] == 0) && (aliveNeighbors == 3))
                    num.push_back(1);
                else 
                    num.push_back(grid[l][m]); 
            }
        }
        //fill in new 2D 
        future.push_back(num); 
    }
    //update og 
    grid = future; 
}   


