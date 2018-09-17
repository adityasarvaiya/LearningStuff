#include <stdio.h>

int totalSum (int dim, int matrix[dim][dim], int pos) 
{   
    int i;
    int j;
    int sum;

    if (pos == 0) {
        sum = matrix[pos][pos + 1] + matrix[pos + 1][pos] + matrix[pos + 1][pos +1] ;
    } else if (pos == (dim - 1)) {
        sum = matrix[pos][pos - 1] + matrix[pos - 1][pos] + matrix[pos - 1][pos - 1];
    } else {
        sum =  matrix[pos][pos + 1] + matrix[pos + 1][pos] + matrix[pos + 1][pos +1] + 
        matrix[pos][pos - 1] + matrix[pos - 1][pos] + matrix[pos - 1][pos - 1] + 
        matrix[pos - 1][pos + 1] + matrix[pos + 1][pos - 1];
    }

    return sum;
}

int main()
{
    int dim;
    scanf("%d", &dim);

    int matrix[dim][dim];
    int i;
    int j;
    int sum;
    int max_sum;

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    j = 1;

    for (i = 0; i < dim; i++) {
        sum = totalSum(dim, matrix, i);
        printf("%d: %d\n", matrix[i][i], sum);
        if (sum > max_sum) {
            j = i+1;
            max_sum = sum;
        }
    }

    printf("index: %d", j);

    return 0;
}