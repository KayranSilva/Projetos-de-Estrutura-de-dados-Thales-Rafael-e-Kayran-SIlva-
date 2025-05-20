#include "maze.h"
#include <stdio.h>

char maze[ROWS][COLS] = {
    "##########",
    "#S       #",
    "# #### ###",
    "# #      #",
    "# # ## ###",
    "#   #   E#",
    "##########"
};

int start_x, start_y;
int exit_x, exit_y;

void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void find_positions() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(maze[i][j] == 'S') {
                start_x = i;
                start_y = j;
            }
            if(maze[i][j] == 'E') {
                exit_x = i;
                exit_y = j;
            }
        }
    }
}