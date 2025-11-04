#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#define DEBUG
#define MAX_WORD_SIZE 256

const char *PATH = "../data/words_alpha.txt";

unsigned long get_random_long(){
    unsigned long index = (unsigned long)rand() << 30;
    index |= (unsigned long)rand() << 15;
    index |= (unsigned long)rand();

    return index;
}

size_t choose_word(char* word){
    FILE* fptr = fopen(PATH, "rb");
    if(fptr == NULL){
        return 0;
    }
    if(fseek(fptr, 0L, SEEK_END) != 0){
        fclose(fptr);
        return 0;
    }
    long size = ftell(fptr);
    if(size <= 0){
        fclose(fptr);
        return 0;
    }
    rewind(fptr);

    unsigned long index = get_random_long() % (unsigned long) size;

    if(fseek(fptr, (long)index, SEEK_SET) != 0){
        fclose(fptr);
        return 0;
    }

    long pos = ftell(fptr);
    long start_pos = 0;
    while (pos > 0) {
        fseek(fptr, --pos, SEEK_SET);
        int ch = fgetc(fptr);
        if (ch == '\n') {
            start_pos = pos + 1;
            break;
        }
    }
    fseek(fptr, start_pos, SEEK_SET);

    char* ptr = fgets(word, MAX_WORD_SIZE, fptr);
    fclose(fptr);
    if(ptr == NULL){
        return 0;
    }
    word[strlen(word) - 2] = '\0'; // trim newline at the end
    return strlen(word);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    char* word = calloc(sizeof(char), MAX_WORD_SIZE);
    if(word == NULL){
        perror("Memory allocation error!\n");
        return 1;
    }
    size_t length;
    if((length = choose_word(word)) == 0){
        free(word);
        perror("Error when selecting a word!\n");
        return 1;
    }

    #ifdef DEBUG
        printf("\nSELECTED WORD: %s, LENGTH: %ld\n\n", word, length);
    #endif
    play(word, length);
    return 0;
}
