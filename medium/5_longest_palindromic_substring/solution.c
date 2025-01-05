#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s)
{
    int longestlength= 0, longestLeft;
    int currentlength, left, right;

    for(int i=0; i<strlen(s); i++)
    {
        currentlength= 1;
        left= i-1;
        right= i+1;

        while(left >= 0 && right < strlen(s) && s[left] == s[right])
        {
            left--;
            right++;
            currentlength+= 2;
        }
        if(currentlength > longestlength)
        {
            longestlength= currentlength;
            longestLeft= left+1;
        }

        if(s[i] == s[i+1])
        {
            currentlength= 2;
            left= i-1;
            right= i+2;
        }
        else
        {
            continue;
        }
        while(left >= 0 && right < strlen(s) && s[left] == s[right])
        {
            left--;
            right++;
            currentlength+= 2;
        }
        if(currentlength > longestlength)
        {
            longestlength= currentlength;
            longestLeft= left+1;
        }
    }

    // When is only a character in string
    if(longestlength == 1)
    {
        longestLeft= 0;
    }

    char* output = malloc((longestlength + 1) * sizeof(char));

    for (int i= 0; i<longestlength; i++)
    {
        output[i]= s[longestLeft];
        longestLeft++;
    }

    if(longestlength == 1)
        output[0]= s[0];

    output[longestlength]= '\0';

    return output;
}

int main()
{
    char s[]= "2abbacabbaz";

    char *output= longestPalindrome(s);

    if(output != NULL)
    {
        printf("%s\n", longestPalindrome(s));
        free(output);
    }

    return 0;
}
