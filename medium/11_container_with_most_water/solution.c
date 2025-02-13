#include <stdio.h>
#include <stdbool.h>

/* Formula which calculates the size of water container */
#define CALCULATE_WATER_SIZE(left, right, low)((right-left) * low)

int maxArea(int* height, int heightSize)
{
    int max_water_container= 0;
    int aux;

    /* Use two pointers, left which starts from 0, right which starts from heightSize-1 */
    int l= 0, r= heightSize-1;
    /* Assign first size of water container based on the startup value of pointers */
    max_water_container= CALCULATE_WATER_SIZE(l, r, (height[l] <= height[r] ? height[l] : height[r]));

    /* Check after overflows and if pointers don't carry the same value, which means that the array got parsed. */
    while((l+1 < heightSize) && (r-1 > 0) && (l != r))
    {
        /* if left pointer is greater than right, decrease right */
        if(height[l] > height[r])
            r-=1;
        /* if left is lower than right, increse left */
        else if(height[l] < height[r])
            l++;
        /* If are equal check the successor */
        else
        {
            if(height[l+1] >= height[r-1])
                l++;
            else
                r-=1;
        }

        /* Calculate the size and compare it after with the max hold */
        aux= CALCULATE_WATER_SIZE(l, r, (height[l] <= height[r] ? height[l] : height[r]));
        if(max_water_container < aux)
        {
            max_water_container= aux;
        }
    }

    return max_water_container;
}

int main()
{
    int height[]= {1,8,6,2,5,4,8,3,7};

    printf("%d\n", maxArea(height, (sizeof(height)/sizeof(int))));

    return 0;
}
