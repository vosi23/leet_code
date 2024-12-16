#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int const nums3Size= nums1Size + nums2Size;
    int nums3[nums3Size];
    int n1=0, n2=0;

    int medianIndex;
    double median;

    for(int i=0; i<nums3Size; i++)
    {
        /* n1 reached the end of array nums1 */
        if(n1 == nums1Size)
        {
            /* Add the remain elements from nums2 array */
            nums3[i]= nums2[n2];
            n2++;
            /* Obsolete to go forward */
            continue;
        }

        /* n2 reached the end of array nums 2 */
        if(n2 == nums2Size)
        {
            /* Add the remain elements from nums1 array */
            nums3[i]= nums1[n1];
            n1++;

            /* Obsolete to go forward */
            continue;
        }

        /* Elements of nums1 and nums2 arrays comparison */
        if(nums1[n1] <= nums2[n2])
        {
            nums3[i]= nums1[n1];
            n1++;
        }
        else
        {
            nums3[i]= nums2[n2];
            n2++;
        }
    }

    /* Calculate the median index of nums3 */
    medianIndex= nums3Size / 2;

    if((nums3Size % 2) == 0)
        /* If nums3 array length is even then the median must be composed with the both elements from the middle */
        median= nums3Size > 1 ? ((double) (nums3[medianIndex-1] + nums3[medianIndex]) / (double) 2) : (double)nums3[0];
    else
        /* If nums3 array length is odd then is needed only a element from the middle, because it's only 1 */
        median= nums3Size > 1 ? ((double) nums3[medianIndex]) : (double) nums3[0];

    return median;
}

int main()
{
    int nums1[]= {1, 3};
    int nums2[]= {2};

    double res;

    res= findMedianSortedArrays(nums1, sizeof(nums1)/sizeof(nums1[0]), nums2, sizeof(nums2)/sizeof(nums2[0]));

    printf("%f\n", res);

    return 0;
}
