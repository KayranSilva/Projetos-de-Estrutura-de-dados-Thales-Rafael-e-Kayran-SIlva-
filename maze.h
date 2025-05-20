#ifndef MAZE_H
#define MAZE_H

#include "config.h"

extern char maze[ROWS][COLS];
extern int start_x, start_y;
extern int exit_x, exit_y;

void printMaze();
void find_positions();

#endif