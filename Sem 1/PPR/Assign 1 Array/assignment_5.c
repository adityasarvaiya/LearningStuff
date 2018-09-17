#include <stdio.h>

#define MAX_SIZE 100

int main() 
{
    int n;
    int i;
    scanf("%d", &n);

    char employee_names[n][MAX_SIZE];
    char sorted_names[n][MAX_SIZE];

    for (i = 0; i < n; i++) {
        scanf("%s", &employee_names[i]);
    }



    for (i = 0; i < n; i++) {
        printf("%s\n", employee_names[i]);
    }
}