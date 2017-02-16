/* Program that encrypts the entered input using the Vigenere cipher */

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Enter arguments argc and argv to accept command line input.
int main(int argc, string argv[])
{
    // Display correct usage if argc != 2, thus if no key is given.
    if ( argc != 2 )
    {
        printf("Usage: devigenere <keyword>\n");
        return 1;
    }
    
    // Declare variables.
    string key = argv[1];
    int keyword = strlen(key);
    
    for ( int i = 0, n = keyword; i < n; i++ )
    {
        // Display message if key !isalpha.
        if ( !isalpha(key[i]) )
        {
            printf("Keyword must be only A-Z and a-z\n");
            return 1;
        }
    }
    
    // Declare variables and get user input for ciphertext.
    string plainText = GetString();
    int n = strlen(plainText);
    
    // Loop for string length declared in integer i, while j will be used for the keyword index count.
    for ( int i = 0, j = 0; i < n; i++ )
    {
        // Declare integer m and enter modulo to reuse string stored in argv[1].
        int m = toupper( key[j % keyword] ) - 65;
        
        if ( !isalpha( plainText[i] ))
        {
            printf("%c", plainText[i]);
        }
        else
        {
            // Enter if statement for how uppercase input, given in ciphertext, is calculated and displayed.
            if ( isupper( plainText[i] ))
            {
                // Character 'h' used to display output for uppercase calculation.
                // Integer j increments as long as the for statement is true.
                char h = (( plainText[i] - 65 + m ) % 26 + 65);
                printf("%c", h);
                j++;
            }
            // Enter if statement for how lowercase input, given in ciphertext, is calculated and displayed.
            if ( islower( plainText[i] ))
            {
                // Character 'h' used to display output for lowercase calculation.
                // Integer j increments as long as the for statement is true.
                char h = (( plainText[i] - 97 + m ) % 26 + 97);
                printf("%c", h);
                j++;
            }
        }
    } printf("\n"); // New line after encrypted ciphertext is displayed.
    
    // Return 0 to explicitly signify success.
    // This concludes the Vigenere cipher for pset 2.
    return 0;
}