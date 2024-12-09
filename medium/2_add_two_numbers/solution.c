#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* result= (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tail= result;
    result->val= 0;
    result->next= NULL;

    int val1, val2, sum, carry=0;
    bool firstTime= true;

    while((l1!=NULL) || (l2!=NULL))
    {
        val1=0; val2=0; sum=0;

        if(l1!=NULL)
        {
            val1= l1->val;
            l1= l1->next;
        }
        if(l2!=NULL)
        {
            val2= l2->val;
            l2= l2->next;
        }

        sum= val1 + val2;
        if(carry > 0)
        {
            sum+= carry;
            /* carry can be maximum 1 */
            carry--;
        }
        if(sum > 9)
        {
            sum= sum-10;
            carry++;
        }

        tail->next= (struct ListNode*)malloc(sizeof(struct ListNode));
        tail= tail->next;
        tail->val= sum;
        tail->next= NULL;
    }

    /* If the sum of the first 2 digits from each number are greater than 10 */
    /* Is needed to create another node where to store the carry value */
    if(carry!=0)
    {
        tail->next= (struct ListNode*)malloc(sizeof(struct ListNode));
        tail= tail->next;
        tail->val= carry;
        tail->next= NULL;
    }

    /* Exclude the dummy node */
    result= result->next;

    return result;
}

int main()
{
    struct ListNode* l1= (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l2= (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* result= (struct ListNode*)malloc(sizeof(struct ListNode));

    /* Init l1 & l2 with the data from first example */
    l1->next= (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->next= (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->val= 2;
    l1->next->val= 4;
    l1->next->next->val= 3;
    l1->next->next->next= NULL;

    l2->next= (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->next= (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->val= 5;
    l2->next->val= 6;
    l2->next->next->val= 4;
    l2->next->next->next= NULL;


    // Call function 
    result= addTwoNumbers(l1, l2);

    while(result != NULL)
    {
        printf("%d ", result->val);
        result= result->next;
    }

    printf("\n");

    return 0;
}
