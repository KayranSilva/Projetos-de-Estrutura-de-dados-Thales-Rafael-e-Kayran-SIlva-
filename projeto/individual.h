#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "config.h"
#include "maze.h"

typedef struct {
    char moves[MAX_MOVES];
    int fitness;
} Individual;

void calculate_fitness(Individual *ind);
void display_individual_path(Individual *ind);

#endif