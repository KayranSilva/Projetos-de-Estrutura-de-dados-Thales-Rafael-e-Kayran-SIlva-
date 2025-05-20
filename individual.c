#include "individual.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void calculate_fitness(Individual *ind) {
    int x = start_x, y = start_y;
    int collision = 0;

    for(int i = 0; i < MAX_MOVES; i++) {
        int new_x = x, new_y = y;
        switch(ind->moves[i]) {
            case 'C': new_x--; break;
            case 'B': new_x++; break;
            case 'E': new_y--; break;
            case 'D': new_y++; break;
        }

        if(new_x < 0 || new_x >= ROWS || new_y < 0 || new_y >= COLS || 
           maze[new_x][new_y] == '#') {
            collision += 1;
            break;
        }

        x = new_x;
        y = new_y;
        if(x == exit_x && y == exit_y) break;
    }

    int distance = abs(x - exit_x) + abs(y - exit_y);
    ind->fitness = 1000 - distance - (collision * 10);
}

void display_individual_path(Individual *ind) {
    char temp_maze[ROWS][COLS];
    memcpy(temp_maze, maze, sizeof(maze));

    int x = start_x, y = start_y;
    temp_maze[x][y] = 'S';

    for (int i = 0; i < MAX_MOVES; i++) {
        int new_x = x, new_y = y;
        switch(ind->moves[i]) {
            case 'C': new_x--; break;
            case 'B': new_x++; break;
            case 'E': new_y--; break;
            case 'D': new_y++; break;
        }

        if (new_x < 0 || new_x >= ROWS || new_y < 0 || new_y >= COLS || maze[new_x][new_y] == '#') {
            break;
        }

        x = new_x;
        y = new_y;

        if (temp_maze[x][y] != 'S' && temp_maze[x][y] != 'E') {
            temp_maze[x][y] = '.';
        }

        printf("\nPasso %d:\n", i+1);
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                printf("%c", temp_maze[r][c]);
            }
            printf("\n");
        }
        printf("\n");

        if (x == exit_x && y == exit_y) {
            printf("Saida enocntrada!\n");
            system("pause");
            break;
        }

        #ifdef _WIN32
            Sleep(500);
        #else
            usleep(500000);
        #endif
    }
}

