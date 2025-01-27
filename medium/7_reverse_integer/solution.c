#include <stdio.h>
#include <math.h>

#define MAX_VALUE_INT (int)(pow(2, 31)-1)
#define MIN_VALUE_INT (int)(pow(-2, 31))

int reverse(int x)
{
    int reversed= 0, digit;

    if(!(x>=MIN_VALUE_INT && x<=MAX_VALUE_INT))
        return 0;

    while(x!=0)
    {
        digit= x%10;

        /* Overflow detection */
        if(reversed > MAX_VALUE_INT/10 || ((reversed == MAX_VALUE_INT/10) && (digit > MAX_VALUE_INT % 10)))
            return 0;

        /* Underflow detection */
        if(reversed < MIN_VALUE_INT/10 || ((reversed == MIN_VALUE_INT/10) && (digit < MIN_VALUE_INT % 10)))
            return 0;

        reversed= digit + (reversed * 10);
        x= x/10;
    }

    return reversed;
}

int main()
{
    int number= 1534236469;

    int res= reverse(number);

    printf("%d\n", res);

    return 0;
}
