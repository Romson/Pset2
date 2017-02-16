/* Program that prompts the user to insert their name which will be displayed in uppercase intials */

// Enter libraries
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main()
{
    // Insert name
    string name = GetString();
    
    // String length for name
    int namelength = strlen(name);
    
    // Print first initial using the 0th array character for name
    printf("%c", toupper(name[0]));
    
    // Loop to see if there are other strings after the first string (name) and i will represent namelength
    for ( int i = 0; i < namelength; i++ )
        {
            // If there is a space found the next uppercase is displayed for the following name
            if ( name[i] == ' ' )
            {
                printf("%c", toupper(name[i + 1]));
            }
        } printf("\n");
        
    return 0;
}