#ifndef GENETIC_H
#define GENETIC_H

#include "individual.h"
#include "config.h"

void initialize_population(Individual *pop);
Individual tournament_selection(Individual *pop);
void crossover(Individual parent1, Individual parent2, Individual *child);
void mutate(Individual *ind);
void new_generation(Individual *pop);

#endif