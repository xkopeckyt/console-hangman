# Console Hangman

A classic word-guessing game implemented in C. Guess the hidden word one letter at a time before running out of attempts.

## Description

Hangman is a word puzzle game where you try to guess a randomly selected word by suggesting letters. You have 10 attempts - each wrong guess costs you one attempt. The game ends when you either guess the word or run out of attempts.

## Requirements

- C compiler (C11 or later)
- CMake (2.8.10 or higher)
- Dictionary file: `data/words_alpha.txt` (one word per line)

## Building

```bash
mkdir build
cd build
cmake ..
make
./console_hangman
```

## How to Play

1. The game displays underscores representing letters in the hidden word
2. Enter a single letter when prompted
3. Correct guesses reveal letter positions
4. Wrong guesses reduce your remaining attempts
5. Win by completing the word, or lose when attempts run out

Example:
```
_ _ _ _ _
¯ ¯ ¯ ¯ ¯

You have 10 guesses left.
*==========================*
Guess:
```

## Project Structure

```
console_hangman/
├── main.c              # Entry point and word selection
├── game.c / game.h     # Game logic and state management
├── ascii.c / ascii.h   # Display formatting
├── CMakeLists.txt      # Build configuration
└── data/
    └── words_alpha.txt # Dictionary file (required)
```

## Configuration

You can modify these values in the source code:
- `MAX_WORD_SIZE` in main.c - Maximum word length (default: 256)
- `PATH` in main.c - Dictionary file location
- Starting guesses in `game_init()` - Initial attempts (default: 10)

## Planned Features

- Language selection with multiple dictionary support
- Difficulty levels (easy/medium/hard)
- Multiplayer mode (player vs. player)

## Notes

This is a work in progress. The dictionary file path is relative to the executable location, so you may need to adjust it depending on where you run the program.

## Credits

The word dictionary (`data/words_alpha.txt`) is sourced from [dwyl/english-words](https://github.com/dwyl/english-words/blob/master/words_alpha.txt) on GitHub.
