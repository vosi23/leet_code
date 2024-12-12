
#include <stdio.h>

/*

Please find the two biggest values from a array.

The solution must be provided in a function, function which must return a int value which must contain the both found values. (max1 and max2)

After the function call print the results in the console as max1= n, max2=n, where n is the first and second biggest values from the a array.

*/

int maxTwoInArr(int vector[], int numElements)
{
    int max1= 0, max2= 0;
    int res;

    for(int i= 0; i<= numElements; i++)
    {
        if(max1 < vector[i])
        {
            max2 = max1;         
            max1 = vector[i];
        }
        else if(max2 < vector[i])
            max2 = vector[i];
    }

    res = (max1) | (max2 << 8);
    return res;
}

int main()
{
    int a[] = {35, 5, 9, 17, 27, 13, 12, 3, 5, 89 };
    const int sizeA= sizeof(a)/sizeof(a[0]);

    int res= maxTwoInArr(a, sizeA);

    printf("max1= %d, max2= %d\n", (res & 0xFF), ((res >> 8) & 0xFF));

    return 0;
}
