
#ifndef CONSOLE_HANGMAN_GAME_H
#define CONSOLE_HANGMAN_GAME_H

#include <stdint.h>
#include <stdlib.h>

struct game {
    char* word;
    char* guessed;
    size_t length;
    int remaining_guesses;
};

int play(char* word, size_t length);

#endif //CONSOLE_HANGMAN_GAME_H
