#include "genetic.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

void initialize_population(Individual *pop) {
    for(int i = 0; i < POP_SIZE; i++) {
        for(int j = 0; j < MAX_MOVES; j++) {
            int r = rand() % 4;
            char moves[] = {'C', 'B', 'E', 'D'};
            pop[i].moves[j] = moves[r];
        }
        calculate_fitness(&pop[i]);
    }
}

Individual tournament_selection(Individual *pop) {
    Individual best;
    best.fitness = -1;
    
    for(int i = 0; i < TOURNAMENT_SIZE; i++) {
        int idx = rand() % POP_SIZE;
        if(pop[idx].fitness > best.fitness) {
            best = pop[idx];
        }
    }
    return best;
}

void crossover(Individual parent1, Individual parent2, Individual *child) {
    int point = rand() % MAX_MOVES;
    for(int i = 0; i < point; i++) {
        child->moves[i] = parent1.moves[i];
    }
    for(int i = point; i < MAX_MOVES; i++) {
        child->moves[i] = parent2.moves[i];
    }
}

void mutate(Individual *ind) {
    for(int i = 0; i < MAX_MOVES; i++) {
        if((double)rand()/RAND_MAX < MUTATION_RATE) {
            int r = rand() % 4;
            char moves[] = {'C', 'B', 'E', 'D'};
            ind->moves[i] = moves[r];
        }
    }
}

void new_generation(Individual *pop) {
    Individual new_pop[POP_SIZE];
    
    int best_idx = 0;
    for(int i = 1; i < POP_SIZE; i++) {
        if(pop[i].fitness > pop[best_idx].fitness) {
            best_idx = i;
        }
    }
    new_pop[0] = pop[best_idx];

    for(int i = 1; i < POP_SIZE; i++) {
        Individual parent1 = tournament_selection(pop);
        Individual parent2 = tournament_selection(pop);
        Individual child;
        
        crossover(parent1, parent2, &child);
        mutate(&child);
        calculate_fitness(&child);
        
        new_pop[i] = child;
    }

    memcpy(pop, new_pop, sizeof(new_pop));
}