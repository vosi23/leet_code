#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(int x)
{
    // length of maximum number which fits in int type is 12 including the sign and end character met in strings
    char s[12];
    int index= 0;
    int size= 0;

    /* Negative numbers will result to false always  */
    if(x < 0)
        return false;

    /* If the format contains one single digit then will return always true */
    if(x<10)
        return true;

    /* Convert the int to string, with a reversed int can appear overflow issues */
    while(x)
    {
        s[index]= (char)((x%10)+48);
        x/=10;
        index++;
    }
    s[index]= '\0';

    size= index;
    index--;
    /* Comparing the characters */
    for(int i=0; i<size/2; i++)
    {
        if(s[i] != s[index])
            return false;
        index--;
    }

    return true;
}

int main()
{
    int x= 1001;

    bool res= isPalindrome(x);

    printf("%d\n", res);

    return 0;
}
