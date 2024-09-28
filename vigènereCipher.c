#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* cipher(char* Sentence, char* Key);        //Encrypts the given sentence using the Vigenère cipher with the provided key
char* fullKey(char* Key, char* Sentence);       //Expands the key to match the length of the sentence by repeating characters
void removeAllNewlines(char* str);              //Removes all newline characters from the input string

int main() {
    char* sentence;               // Stores the user-input sentence
    char* key;                    // Stores the user-input encryption key
    char* encryptedSentence;       // Stores the encrypted sentence result

    // Allocating memory for the sentence and getting user input
    sentence = malloc(50 * sizeof(char));
    printf("Insert the sentence to encrypt: \n");
    fgets(sentence, 50, stdin);
    sentence = realloc(sentence, strlen(sentence) * sizeof(char));      // Reallocates based on actual input length
    removeAllNewlines(sentence);                                        // Removes newlines from the sentence

    // Allocating memory for the key and getting user input
    key = malloc((strlen(sentence) + 1) * sizeof(char));
    printf("Insert the word to use for encryption: \n");
    fgets(key, strlen(sentence) + 1, stdin);  
    removeAllNewlines(key);                                             // Removes newlines from the key
    key = fullKey(key, sentence);                                       // Extends the key to match the sentence length

    encryptedSentence = cipher(sentence, key);                          // Encrypts the sentence using the cipher
    printf("The encrypted sentence is:\n");
    puts(encryptedSentence);                                            // Outputs the encrypted sentence

    free(key);
    free(encryptedSentence);
    free(sentence);

    return 0;
}

// Expands the key by repeating it to match the length of the sentence
char* fullKey(char* Key, char* Sentence) {
    int sentenceLength = strlen(Sentence);
    int keyLength = strlen(Key);
    char* full_key = malloc(sentenceLength + 1);                        // Allocating memory for the expanded key

    // Cyclically repeats the key
    for (int i = 0; i < sentenceLength; i++) {
        full_key[i] = Key[i % keyLength];                               // Repeats the key characters
    }
    full_key[sentenceLength] = '\0';                                    // Null-terminates the expanded key

    return full_key;
}

// Removes all newline characters from the input string
void removeAllNewlines(char* str) {
    char* src = str;
    char* dest = str;

    // Copies characters while skipping newlines
    while (*src) {
        if (*src != '\n') {
            *dest++ = *src;
        }
        src++;
    }
    *dest = '\0';                                                       // Null-terminates the modified string
}

// Encrypts the sentence using the Vigenère cipher with the provided key
char* cipher(char* Sentence, char* Key) {
    int length = strlen(Sentence);
    char* encrypted = malloc(length + 1);                               // Allocating memory for the encrypted sentence
    
    // Encrypt each character
    for (int i = 0; i < length; i++) {
        if (Sentence[i] >= 65 && Sentence[i] <= 90) {  
            encrypted[i] = (((Sentence[i] - 65 + (Key[i] - 65)) % 26) + 65);  // Uppercase letters
        } else if (Sentence[i] >= 97 && Sentence[i] <= 122) {  
            encrypted[i] = (((Sentence[i] - 97 + (Key[i] - 97)) % 26) + 97);  // Lowercase letters
        } else {
            encrypted[i] = Sentence[i];                                         // Non-alphabetic characters are copied unchanged
        }
    }
    encrypted[length] = '\0';                                                   // Null-terminates the encrypted string
    return encrypted;
}
