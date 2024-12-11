#include <stdio.h>
#include <string.h>

#define NO_ASCII_CHARACTERS 128u



int lengthOfLongestSubstring(char* s)
{
    /* Create a lookup array to count each ascii character */
    int last_seen[NO_ASCII_CHARACTERS];

    /* local variables needed for algorithm */
    int start_i= 0, output= 0;
    int current_length;
    char current_char;

    /* Init the lookup array */
    for (int i = 0; i < NO_ASCII_CHARACTERS; i++)
        last_seen[i] = -1;

    for (int i= 0; s[i] != '\0'; i++)
    {
        /* Get the current char */
        current_char = s[i];

        /* If the same character was seen already and is bigger than start */
        /* Reset the start to 1 after the last seen position */
        if (last_seen[current_char] >= start_i)
        {
            start_i = last_seen[current_char] + 1;
        }

        /* Update the lookup table with the current index */
        last_seen[current_char] = i;

        /* Update the maximum length, if is the case */
        current_length= i - start_i + 1;
        if (current_length > output) {
            output= current_length;
        }
    }

    return output;
}

int main()
{
    char s[]= "abcabcbb";

    printf("%d\n", lengthOfLongestSubstring(s));

    return 0;
}
