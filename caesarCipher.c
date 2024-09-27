#include <stdio.h>
#include <stdlib.h>

// Encrypts the sentence using a Caesar cipher with a given delay
char* cipher(char* sentence, int delay);

int main() {
    char frase[50];        // Buffer to store the input sentence
    int spostamento, i = 0; // spostamento is the shift amount (delay)
    
    // Getting the sentence to encrypt from the user
    printf("Insert the sentence to encrypt: \n");
    fgets(frase, 50, stdin);    // Reads up to 50 characters
    fflush(stdin);              // Clears the input buffer
    system("cls");              // Clears the console screen

    // Getting the shift value (delay) from the user
    printf("Insert the delay to encrypt the sentence: \n");
    scanf("%d", &spostamento);      // Reads the delay value

    cipher(frase, spostamento);     // Encrypts the sentence using the Caesar cipher
    puts(frase);                    // Prints the encrypted sentence

    return 0;
}

// Function to apply a Caesar cipher to the sentence
char* cipher(char* sentence, int delay) {
    int i = 0;

    // Iterating through each character in the sentence
    while(sentence[i] != '\0') {

        // Shifting uppercase letters ('A' to 'Z')
        if(sentence[i] >= 65 && sentence[i] <= 90) {
            sentence[i] = (((sentence[i] - 65 + delay) % 26 + 26) % 26) + 65;
        
        // Shifting lowercase letters ('a' to 'z')
        } else if(sentence[i] >= 97 && sentence[i] <= 122) {
            sentence[i] = (((sentence[i] - 97 + delay) % 26 + 26) % 26) + 97;
        }

        i++;            // Move to the next character
    }

    return sentence;    // Return the modified (encrypted) sentence
}
