#include "game.h"
#include "ascii.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool guessed_before(uint32_t guessed, char input){
    int shift = (int) (input - 97);
    uint32_t bit = 1;
    return (guessed & (bit << shift));
}

char guess_input (struct game* game){
    while(true){
        printf("Guess:\n");
        fflush(stdout);
        char input;
        if((scanf(" %1c", &input) != 1)) return 0;
        input = (char)tolower(input);
        if(input < 97 || input > 122){
            printf("Please input a valid character!\n");
            char next;
            while ((next = (char)getchar()) != '\n' && next != EOF);
            continue;
        }

        if(guessed_before(game->guessed_letters, input)) {
            printf("You have already guessed this letter.\n");
            continue;
        }

        return input;
    }
}

void update_guessed_letters(struct game* game, char guess){
    int shift = (int) (guess - 97);
    uint32_t bit = 1;
    game->guessed_letters |= (bit << shift);
}

bool process_guess(struct game* game, char guess){
    bool correct = false;
    for(size_t i = 0; i < game->length; i++){
        if(game->word[i] == guess){
            correct = true;
            game->guessed[i] = guess;
        }
    }
    update_guessed_letters(game, guess);
    return correct;
}

bool solved(struct game* game){

    return strcmp(game->word, game->guessed) == 0;
}

void destroy_game(struct game* game){
    if(game == NULL){
        return;
    }
    free(game->word);
    free(game->guessed);
    free(game);
}

struct game* game_init(char* word, size_t length){
    struct game* game = malloc(sizeof(struct game));
    if(game == NULL){
        free(word);
        return NULL;
    }
    char* guessed = malloc(length + 1);
    if(guessed == NULL){
        free(word);
        free(game);
        return NULL;
    }
    int i = 0;
    for(; i < length; i++){
        guessed[i] = ' ';
    }
    guessed[i] = '\0';

    game->length = length;
    game->word = word;
    game->guessed = guessed;
    game->remaining_guesses = 10;
    game->guessed_letters = 0;

    return game;
}

int play(char* word, size_t length){
    struct game* game = game_init(word, length);
    print_round(game);

    while(game->remaining_guesses > 0){
        char guess = guess_input(game);
        if(guess == 0) {
            destroy_game(game);
            return -1;
        }

        bool retval = process_guess(game, guess);
        if(!retval) game->remaining_guesses--;
        print_round(game);
        if(retval && solved(game)) break;
    }

    if(game->remaining_guesses > 0){
        printf("\nYOU WON!\n"
               "The word was: %s\n", game->word);
    } else{
        printf("\nYOU LOST!\n"
               "The word was: %s\n", game->word);
    }

    destroy_game(game);
    return 0;
}
