#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cipher(char* Sentence);

int main() {
    char* sentence= malloc(50 * sizeof(char));       // Allocating memory for the sentence
    char* encryptedSentence;                    // stores the encrypted sentence result

    printf("Insert the sentence to encrypt: \n");
    fgets(sentence, 50, stdin);
    sentence[strcspn(sentence, "\n")] = '\0';                               // Remove newline
    encryptedSentence = cipher(sentence);
    puts(encryptedSentence);                                                // Encrypt the sentence

    return 0;
}

char* cipher(char* Sentence) {
    int i = 0;
    char* encrypted = malloc(strlen(Sentence) + 1);
    
    while (Sentence[i] != '\0') {
        if (Sentence[i] >= 65 && Sentence[i] <= 90) {
            encrypted[i] = ((Sentence[i] - 65 + 13) % 26) + 65;  // Encrypt uppercase
        } else if (Sentence[i] >= 97 && Sentence[i] <= 122) { 
            encrypted[i] = ((Sentence[i] - 97 + 13) % 26) + 97;  // Encrypt lowercase
        } else {
            encrypted[i] = Sentence[i];                         // Non-alphabetic characters remain unchanged
        }
        i++;
    }
    encrypted[i] = '\0';                                        // Null-terminate the encrypted string

    return encrypted;
}
