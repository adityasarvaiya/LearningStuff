#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[4] = {10,20,30,40};
    int *p = a;

    printf("*++p : %d",*++p);
    return 0;
}
