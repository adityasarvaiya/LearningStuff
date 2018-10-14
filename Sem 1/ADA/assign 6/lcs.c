#include<string.h> 
#include<stdio.h>
#include<string.h>

int maxof(int a, int b) 
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

void printmatrix(int l1, int l2 ,int matrix[l1][l2]) 
{
    int i,j;
    for (i = 0; i <= l1; i++) {
        for (j = 0; j <= l2; j++) {
            //cout << matrix[i][j] << "  ";
            printf("%d ", matrix[i][j]);
        }
        // cout << endl;
        printf("\n");
    }
}

int main()
{
    char s1[] = "abcdaf";
    char s2[] = "acbcf";

    int len1 = strlen(s1) + 1;
    int len2 = strlen(s2) + 1;

    // cout << "hello"<< endl;
    // cout << "l1 : " << len1 << "  l2 : " << len2;

    int matrix[len1][len2];

    int i,j;
    for (i = 0; i < len1; i++) {
        matrix[i][0] = 0;
    }
    
    for (j = 0; j < len2; j++) {
        matrix[0][j] = 0;
    }

    printmatrix(len1, len2, matrix);    

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {

            if (s1[i] ==  s2[j]) {
                matrix[i][j] = matrix[i-1][j-1] + 1;
            } else {
                matrix[i][j] = maxof(matrix[i-1][j], matrix[i][j-1]);
            }
        }
    }

    printmatrix(len1, len2, matrix);

    return 0;
}