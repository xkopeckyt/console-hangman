#include "ascii.h"
#include <ctype.h>
#include <stdio.h>

void print_guesses(struct game* game) {
    char* guessed = game->guessed;
    printf("\n");
    for(size_t i = 0; i < game->length; i++){
        printf("%c ", toupper(guessed[i]));
    }
    printf("\n");
    for(size_t i = 0; i < game->length; i++){
        printf("¯ ");
    }
    printf("\n");
}