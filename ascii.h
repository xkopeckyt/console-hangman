
#ifndef CONSOLE_HANGMAN_ASCII_H
#define CONSOLE_HANGMAN_ASCII_H
#include "game.h"

/*static const char* template = "------------------------------\n"
                       "|                            |\n"
                       "|                            |\n"
                       "|                            |\n"
                       "|                            |\n"
                       "|                            |\n"
                       "|                            |\n"
                       "|                            |\n"
                       "|                            |\n"
                       "|                            |\n"
                       "|                            |\n"
                       "|                            |\n"
                       "|                            |\n"
                       "|                            |\n"
                       "------------------------------\n";*/

void print_round(struct game* game);
void print_guessed_letters(struct game* game);
static const char* splitter = "*==========================*";


#endif //CONSOLE_HANGMAN_ASCII_H
