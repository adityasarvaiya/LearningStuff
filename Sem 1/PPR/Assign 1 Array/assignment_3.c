#include <stdio.h>

void transpose(int *m, int *n, int matrix[*m][*n])
{
    int transposed_matrix[*n][*m];
    int i;
    int j;

    for (i = 0; i < *m; i++) {
        for (j = 0; j < *n; j++) {
            transposed_matrix[j][i] = matrix[i][j];
        }
    }

    for (i = 0; i < *n; i++) {
        for (j = 0; j < *m; j++) {
            printf("%d   ", transposed_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    int m;
    int n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    int i;
    int j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int transposed_matrix[n][m];
    transpose(&m, &n, matrix);

     
}