#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cipher(char* Sentence, int Delay);

int main() {
    char* sentence = malloc(50 * sizeof(char) + 1);       // Allocate memory for the input sentence
    char* encryptedSentence;                              // Do not allocate here; let cipher allocate it.
    int delay;

    printf("Insert the sentence to encrypt: \n");
    fgets(sentence, 50, stdin);
    sentence[strcspn(sentence, "\n")] = '\0';             // Remove newline character from input

    printf("Insert the delay to apply(integer): \n");
    scanf("%d", &delay);

    encryptedSentence = cipher(sentence, delay);          // Call the cipher function to encrypt the sentence
    puts(encryptedSentence);                              // Display the encrypted sentence

    free(sentence);
    free(encryptedSentence);  
                                
    return 0;
}

char* cipher(char* Sentence, int Delay) {
    int length = strlen(Sentence);                        // Get the length of the input sentence
    char* encrypted = malloc(length + 1);                 // Allocate memory for the encrypted string

    if (encrypted == NULL) {                              // Check if malloc was successful
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < length; i++) {
        if (Sentence[i] >= 65 && Sentence[i] <= 90) {   // Encrypt uppercase letters
            encrypted[i] = ((Sentence[i] - 65 + Delay) % 26) + 65;
        } else if (Sentence[i] >= 97 && Sentence[i] <= 122) { // Encrypt lowercase letters
            encrypted[i] = ((Sentence[i] - 97 + Delay) % 26) + 97;
        } else {
            encrypted[i] = Sentence[i];                   // Non-alphabetic characters remain unchanged
        }
    }

    encrypted[length] = '\0';                             // Null-terminate the encrypted string
    return encrypted;
}
