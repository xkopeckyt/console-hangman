#include "ascii.h"
#include <ctype.h>
#include <stdio.h>

void print_word_status(struct game* game){
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

void print_remaining(struct game* game){
    printf("You have %d guesses left.\n", game->remaining_guesses);
}

void print_guessed_letters(struct game* game){
    uint32_t guessed = game->guessed_letters;
    if(guessed == 0){
        return;
    }
    uint32_t bit = 1;
    printf("Already guessed: \n");
    for(int i = 0; i < 32; i++){
        if(guessed & bit){
            char c = i + 65;
            printf("%c ", c);
        }
        bit <<= 1;
    }
    printf("\n");
}

void print_round(struct game* game) {
    print_word_status(game);
    print_guessed_letters(game);
    print_remaining(game);
    printf("*==========================*\n");
}