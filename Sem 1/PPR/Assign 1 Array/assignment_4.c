#include <stdio.h>

void find_row_unique (int dim, int pos, int matrix[dim][dim], int row_unique[dim][dim+1]) 
{
    int i;
    int j;
    int k;
    int flag;
    k = 0;
    flag = 0;

    //row_unique[pos][0] = 0;
    
    for (i = 0; i < dim; i++) {
        for (j = 0; j <= k; j++) {
            if (row_unique[pos][j] == matrix[pos][i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            k++;
            row_unique[pos][k] = matrix[pos][i];
        }

        if (i == (dim - 1)) {
            row_unique[pos][0] = k;
        }
    }
}

int main()
{
    int dim;
    scanf("%d", &dim);

    int matrix[dim][dim];
    int i;
    int j;
    int k;
    int row_unique[dim][dim+1];
    // int col_unique[dim][dim+1];
    // int matrix_unique[dim * dim];

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < dim; i++) {
        find_row_unique(dim, i, matrix, row_unique);
    }

    printf("Along rows: \n");
    for (i = 0; i < dim; i++) {
        k = row_unique[i][0];
        for (j = 1; j <= k; j++) {
            printf("%d   ", row_unique[i][j]);
        }
        printf("\n");
    }

    return 0;
}