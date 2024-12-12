#include <stdio.h>

/*

A fitness app routinely measures velocity during a bicycle ride. It stores the velocity and time data as a series of pairs {vi, ti} of length n where i is the index of each measurement.

Implement the calories_burned function to calculate the calories burned on the ride using the formula below:

calories burned= weight×i= 0∑n−2​((2.5×vi​−6)×(ti+1​−ti​))/3600

For example, calling:

int data[][2]=
{
{6, 0},
{4, 1800},
{0, 3600}
};
double calories= calories_burned(60, data, 3);

Should return 390.
*/

double calories_burned(int weight, int ride[][2], int n) 
{
    double total_calories = 0.0;
    int v_i = 0;
    int t_i = 0;
    int t_next = 0;
    double segment_calories = 0;

    for (int i = 0; i < n - 1; i++)
    {
        v_i = ride[i][0];
        t_i = ride[i][1];
        t_next = ride[i + 1][1];

        segment_calories = (2.5 * v_i - 6) * (t_next - t_i);
        
        total_calories += segment_calories;
    }

    return (weight * total_calories) / 3600.0;
}

int main()
{
    int data[][2] =
    {
        {6, 0},
        {4, 1800},
        {0, 3600}
    };
    double calories = calories_burned(60, data, 3);
    printf("%lf\n", calories);
}
