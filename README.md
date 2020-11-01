Charlene Crystal Namuyige 
Homework 2 -- CS300
October 2020 
Bart Massey 


This assignment is a terminal-based adventure game using ncurses. It is an implementation of Conway's Game of Life. 

My code starts my initializing the terminal and has two basic modes: play and paused, which are toggled by hitting the p button. The program begins in paused mode. Each character position represents one cell which can either be dead or alive. Alive cells are represented by X while dead cells are blank.
In paused mode, the user can move the cursor with arrow keys, toggle the state of the cell underneath the cursor by hitting x, take a single step forward in time by hitting n. In play mode, the game of life updates by 1 step every 0.5 seconds. The user cannot move the cursor or edit cells in this mode.
At any time, the user can cleanly exit the program by pressing q.



How to use this game

Arrows -- move up, down, right and left. 
P/p    -- to play/pause the game 
X/x    -- to add the character X at cursor. 
Q/q    -- to quit out of game
N/n    -- to move only one step in the game 

Compiling and running 
make 
make clean -- to clean up the directory


A couple of issues -- you have to press q/Q twice if you don't enter the play/pause mode otherwise a single Q will suffice

Cited work 
https://stackoverflow.com/questions/10164263/how-to-pass-two-dimensional-array-of-an-unknown-size-to-a-function
https://www.geeksforgeeks.org/program-for-conways-game-of-life/

