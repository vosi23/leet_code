#include <stdio.h>

// TODO: add brief requirements

double calories_burned(int weight, int ride[][2], int n) 
{
    double total_calories = 0.0;
    int v_i = 0;
    int t_i = 0;
    int t_next = 0;
    double segment_calories = 0;

    for (int i = 0; i < n - 1; i++) {
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
    int data[][2] = {
        {6, 0},
        {4, 1800},
        {0, 3600}
    };
    double calories = calories_burned(60, data, 3);
    printf("%lf\n", calories);
}
