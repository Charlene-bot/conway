Charlene Crystal Namuyige 
Homework 2 -- CS300
October 2020 
Bart Massey 


This assignment is a terminal-based adventure game using ncurses. It is an iimplementation of Conway's Game of Life. 

My code starts my initializing the terminal and has two basic modes: play and paused, which are toggled by hitting the p button. The program begins in paused mode. Each character position represents one cell which can either be dead or alive. Alive cells are represented by X while dead cells are blank.

In paused mode, the user can move the cursor with arrow keys, toggle the state of the cell underneath the cursor by hitting x, take a single step forward in time by hitting n. In play mode, the game of life updates by 1 step every 0.5 seconds. The user cannot move the cursor or edit cells in this mode.
At ant time, the user can cleanly exit the program by pressing q.
