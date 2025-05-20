#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"
#include "maze.h"
#include "individual.h"
#include "genetic.h"

int main() {
    srand(time(NULL));
    find_positions();


    Individual population[POP_SIZE];
    initialize_population(population);

    int generation = 0;
    while(generation++ < MAX_GENERATIONS) {
        int best_fitness = -1;
        Individual best;
        for(int i = 0; i < POP_SIZE; i++) {
            if(population[i].fitness > best_fitness) {
                best_fitness = population[i].fitness;
                best = population[i];
            }
        }

<<<<<<< HEAD
        printf("Geracao %d - Melhor fitness: %d\n", generation, best_fitness);
        display_individual_path(&best);

        if(best_fitness >= 1000) {
            printf("\nSolucao encontrada!\n");
=======
        printf("Geraçao %d - Melhor fitness: %d\n", generation, best_fitness);
        display_individual_path(&best);

        if(best_fitness >= 1000) {
            printf("\nSoluçao encontrada!\n");
>>>>>>> fe07b40658ac0c79b6157209503a262a0571c329
            printf("Movimentos: ");
            for(int i = 0; i < MAX_MOVES; i++) {
                printf("%c ", best.moves[i]);
            }
            break;
        }

        new_generation(population);
    }

    return 0;
}
