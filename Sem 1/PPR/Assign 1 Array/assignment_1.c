#include <stdio.h>

int main()
{
    int dim;
    int i;
    int j;
    int x;
    int sum_of_inputs;
    sum_of_inputs = 0;

    scanf("%d" , &dim);
    int nub[dim][dim];

    for (i = 0; i < dim; i++) {
        scanf("%d" , &nub[i][i]);
        sum_of_inputs += nub[i][i];
    }

    i=0;

    while ( sum_of_inputs >= ((dim * dim) - dim) * i ) {
        i++;
    }

    x=i;

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            if (i != j) {
                nub[i][j] = x;
            }
            printf("%d   ",nub[i][j]);
        }
        printf("\n");
    }

    return 0;
}