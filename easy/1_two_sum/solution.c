#include <stdio.h>
#include <stdlib.h>


int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize= 2;
    int* result= (int*)malloc(*returnSize * sizeof(int));

    result[0]= 0;
    result[1]= 0;

    for(int i=1; i<numsSize; i++)
    {
        if((nums[result[0]] + nums[i]) == target)
        {
            result[1] = i;
            break;
        }

        if((i+1 == numsSize) && (result[1] == 0))
        {
            result[0]= result[0] + 1;
            i= result[0];
        }
    }

    return result;
}


int main()
{
    const int target= 9;
    int nums[]= {2, 7, 11, 15};
    int returnSize= 2;
    int* result;

    const int nums_size= sizeof(nums) / sizeof(nums[0]);

    result= twoSum(nums, nums_size, target, &returnSize);

    printf("%d %d\n", result[0], result[1]);

    free(result);

    return 0;
}
