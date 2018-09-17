#include <stdio.h>

int main(int argc, char const *argv[])
{
    char str[][100] = {"Aditya", "Sandeep", "Atul"};
    char *end = str[0] + sizeof(str)*sizeof(str)/sizeof(*str);
    int *p;

    printf("sizeof(str) is : %lu\n", sizeof(str));
    printf("sizeof(*str) is : %lu\n", sizeof(*str));
    printf("End is : %d\n", end);
    printf("End is : %s\n", end);
    printf("End add is : %u\n", &end);
    printf("Start is : %s", str);
    printf("Start add is : %u", str);
    
    
    return 0;
}
