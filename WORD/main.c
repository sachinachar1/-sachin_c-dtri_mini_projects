#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define WORD_SIZE 5
#define MAX_ATTEMPTS 6


void get_guess(char guess[]);
void evaluate_guess(const char guess[], const char secret[], char result[]);
int check_win(const char result[]);

int main(void) {
    const char secret_word[WORD_SIZE + 1] = "apple";
    char guess[WORD_SIZE + 1];
    char result[WORD_SIZE + 1];
    int attempts = 0;
    int win = 0;

    printf("Welcome to Wordle!\n");

    while (attempts < MAX_ATTEMPTS && !win) {
        printf("Attempt %d of %d: ", attempts + 1, MAX_ATTEMPTS);
        get_guess(guess);

        evaluate_guess(guess, secret_word, result);
        printf("Result: %s\n", result);

        win = check_win(result);

        attempts++;
    }

    if (win) {
        printf("Congratulations! You guessed the word.\n");
    } else {
        printf("Sorry, you've run out of attempts. The word was: %s\n", secret_word);
    }

    return 0;
}


void get_guess(char guess[]) {
    int valid = 0;

    while (!valid) {
        fgets(guess, WORD_SIZE + 2, stdin);
        if (strlen(guess) == WORD_SIZE + 1 && guess[WORD_SIZE] == '\n') {
            guess[WORD_SIZE] = '\0';
            valid = 1;
            for (int i = 0; i < WORD_SIZE; i++) {
                if (!isalpha(guess[i])) {
                    valid = 0;
                    printf("Invalid input. Please enter a %d-letter word: ", WORD_SIZE);
                    break;
                }
                guess[i] = tolower(guess[i]);
            }
        } else {
            printf("Invalid input. Please enter a %d-letter word: ", WORD_SIZE);
            while (getchar() != '\n');
        }
    }
}


void evaluate_guess(const char guess[], const char secret[], char result[]) {
    int secret_used[WORD_SIZE] = {0};


    for (int i = 0; i < WORD_SIZE; i++) {
        if (guess[i] == secret[i]) {
            result[i] = 'C';
            secret_used[i] = 1;
        } else {
            result[i] = '_';
        }
    }


    for (int i = 0; i < WORD_SIZE; i++) {
        if (result[i] != 'C') {
            for (int j = 0; j < WORD_SIZE; j++) {
                if (guess[i] == secret[j] && !secret_used[j]) {
                    result[i] = 'P';
                    secret_used[j] = 1;
                    break;
                }
            }
            if (result[i] == '_') {
                result[i] = 'A';
            }
        }
    }
    result[WORD_SIZE] = '\0';
}


int check_win(const char result[]) {
    for (int i = 0; i < WORD_SIZE; i++) {
        if (result[i] != 'C') {
            return 0;
        }
    }
    return 1;
}
