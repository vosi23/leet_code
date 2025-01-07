#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows)
{
    char* output = malloc((strlen(s)+1) * sizeof(char));

    /* Distance between "pylons" */
    const int increment= 2 * (numRows - 1);
    int output_index= 0;

    if (numRows == 1)
    {
        /* Copy the s to output array as it is */
        strcpy(output, s);
        return output;
    }

    for (int row= 0; row < numRows; row++)
        for (int i= row; i< strlen(s); i+= increment)
        {
            output[output_index]= s[i];
            output_index++;

            if ((row > 0) && (row < (numRows-1)) && ((i + increment - (2 * row)) < strlen(s)))
            {
                output[output_index]= s[i + increment - (2 * row)];
                output_index++;
            }
        }
    output[output_index]= '\0';

    return output;
}

int main()
{
    char s[]= "PAYPALISHIRING";
    char *result= convert(s, 3);

    if(result != NULL)
    {
        printf("%s\n", result);
        free(result);
    }

    return 0;
}
