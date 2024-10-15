#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_LENGTH 26
#define WORD_LENGTH 10

// Function to display the alphabet
void displayAlphabet(bool alphabet[ALPHABET_LENGTH]) {
    printf("Alphabet: ");
    for (int i = 0; i < ALPHABET_LENGTH; i++) {
        if (alphabet[i])
            printf("%c ", 'a' + i);
    }
    printf("\n");
}

int main() {
    char word[WORD_LENGTH] = "apple";
    char guess[WORD_LENGTH];
    bool alphabet[ALPHABET_LENGTH];

    // Initialize alphabet to true
    for (int i = 0; i < ALPHABET_LENGTH; i++) {
        alphabet[i] = true;
    }

    // Display the alphabet
    displayAlphabet(alphabet);

    while (true) {
        printf("Guess the word: ");
        scanf("%s", guess);

        bool correctGuess = (strcmp(guess, word) == 0);

        if (correctGuess) {
            printf("You guessed it right!\n");
            break;
        } else {
            printf("Try again!\n");
            // Update the alphabet based on the incorrect guess
            bool presentInWord[ALPHABET_LENGTH] = {false};
            for (int j = 0; j < strlen(guess); j++) {
                if (strchr(word, guess[j]) != NULL)
                    presentInWord[guess[j] - 'a'] = true;
                else
                    alphabet[guess[j] - 'a'] = false;
            }
            for (int k = 0; k < ALPHABET_LENGTH; k++) {
                if (presentInWord[k])
                    alphabet[k] = true;
            }
            // Display the updated alphabet
            displayAlphabet(alphabet);
            // Clear input buffer
            while (getchar() != '\n');
        }
    }

    return 0;
}

