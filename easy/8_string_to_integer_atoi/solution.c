#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_INT (int)(pow(2, 31) -1)
#define MIN_INT (int)(pow(-2, 31))

int myAtoi(char* s)
{
    int s_length= strlen(s);
    int output= 0;
    int digit= 0;
    bool first_integer_found= false;
    bool positive_number= true;

    /* Constraints check 1 */
    if((s_length <=0) || (s_length >= 200))
        return 0;

    for(int i=0; i<s_length; i++)
    {
        /* Constraints check 2 */
        if((s[i] > 57) || (s[i] == '/') || (s[i] == '.') || s[i] == ',')
            return output;

        if((s[i] == ' ') && (first_integer_found == false))
            continue;

        if((s[i] == '-') && (first_integer_found == false))
        {
            positive_number= false;
            first_integer_found= true;
            continue;
        }

        if((s[i] == '+') && (first_integer_found == false))
        {
            first_integer_found= true;
            continue;
        }

        if(((s[i] == '-') || (s[i] == '+')) && (first_integer_found == true))
            return output;

        /* Spaces between number chars are not permitted */
        if((s[i] < 48) && (first_integer_found == true))
            return output;

        if(s[i] >= 48 && s[i] <= 57)
        {
            first_integer_found= true;

            digit= (int)(s[i]-48);
            digit= positive_number == false ? (digit * -1) : (digit * 1);
            // overflow detection
            if((output > MAX_INT/10) || ((output == MAX_INT/10) && (digit > (MAX_INT % 10))))
                // return rounded value of the MAX int
                return MAX_INT;
            // underflow detection
            if((output < MIN_INT/10) || ((output == MIN_INT/10) && (digit < (MIN_INT % 10))))
                // return the rounded value of the MIN int
                return MIN_INT;

            output= output*10 + digit;
        }
    }

    return output;
}

int main()
{
    char s[]= " -042";

    int res= myAtoi(s);

    printf("%d\n", res);

    return 0;
}
