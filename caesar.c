/* Program that encrypts the entered input using Caesar's cipher*/

// Enter libraries
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Convert input -key- to an integer
    string key = argv[1];
    
    // Display correct way of usage if more than one command-line argument is inserted.
    if ( argc != 2 )
    {
        printf("Usage: /home/cs50/pset2/caesar <key>\n");
        return 1;
    }
    
    // Asks for string and rotate string characters with inserted key value
    // and keep status of uppercase and non alpha input intact.
    // A modulo value of 26 for the letters a - z (97 - 122) and uppercase A - Z (65 - 90)
    // to keep a nice loop when a key value of higher than 26 is given.
    else
    {
        int m = atoi(key) % 26;
        string plainText = GetString();
        
        if ( plainText != NULL)
        {
            for ( int i = 0, n = strlen(plainText); i < n; i++ )
            {
                int j = 0;
                if  ( isalpha(plainText[i]) )
                {
                    // Ascii value 65 with modulo 26 for keeping uppercase input -though rotated- capitalized.
                    if ( isupper(plainText[i]) )
                    {
                        j = 65 + ( (plainText[i] - 65 + m ) % 26 );
                        printf("%c", j);
                    }
                    
                    // Ascii value 65 with modulo 26 for keeping lowercase input -though rotated- intact.
                    else
                    {
                        j = 97 + ( (plainText[i] - 97 + m ) % 26 );
                        printf("%c", j);
                    }
                }
                
                // If non-alpha input is given this else statement makes sure it remains the same.
                else
                {
                    printf("%c", plainText[i]);
                }
            }
        } printf("\n");
    }
    // Return 0 to explicitly signify success.
    // This concludes the Caesar cipher for pset2
    return 0;
}