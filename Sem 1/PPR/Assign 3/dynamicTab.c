#include <stdio.h>
#include <stdlib.h>

void checkRealloc(int *a, int *cap, int *size) 
{
    if (*size == *cap) {
        *size += 1; 
        *cap *= 2;
        a = (int *) realloc(a, sizeof(int)* (*cap));
    } else if (*cap >= (*size*4)) {
        *cap /= 2;
        a = realloc(a,sizeof(int) * (*cap));
    }
}

void insertDynamic(int *a, int data, int *cap, int *size)
{   
    checkRealloc(a, cap, size);
    *size += 1; 
    a[*size-1] = data;

}

void printArray (int * a, int size)
{ 
    int i;
    for (i = 0; i < size; i++) 
    {
        printf("%d  ", *(a+i));
    }

}

void pop_back(int *a, int *cap, int *size, int n)
{
    (*size) -= n;
    checkRealloc(a, cap, size);
}

void deleteIndex(int *a, int *cap, int *size, int index) 
{
    int i;
    for (i = index; i < ((*size) -1); i++) 
    {
        a[i] = a[i+1];
    }
    (*size) -= 1;
    checkRealloc(a,cap,size);
}

void first_Value_delete(int *a, int *cap, int *size, int value)
{
    int i;
    int flag = 0;
    for (i = 0; i < *size; i++) 
    {  
        if (a[i] == value && flag == 0) {
            flag = 1;
        }

        if (flag == 1 && i < ((*size)-1)) {
            a[i] = a[i+1];
        }
    }

    (*size) -= 1;
    checkRealloc(a,cap,size);
}

void All_Value_delete(int *a, int *cap, int *size, int value)
{
    int i;
    int j = 0;

    for (i = 0; i < *size; i++) 
    {  
        if (a[i] != value ) {
            a[j] = a[i];
            j++;
        }
    }

    (*size) = j;
    checkRealloc(a,cap,size);
}

int main()
{
    int n;
    scanf("%d", &n);

    int size = 0;
    int cap = 1;
    int *a = (int *) malloc((sizeof(int)*cap));

    int i;
    int data;
    for (i = 0; i < n; i++) 
    {   
        scanf("%d", &data);
        // data = i;
        if (size == cap) {
            size += 1; 
            cap *= 2;
            a = (int *) realloc(a, sizeof(int)* (cap));
        } else {
            size += 1; 
        }

        a[size-1] = data;

        printf("capacity = %d; size = %d; elements = ", cap, size);
        printArray(a,size);
        printf("\n");
    }

    printf("delete nodes: ");
    int dn;
    scanf("%d", &dn);
    pop_back(a, &cap, &size, dn);
    printf("capacity = %d; size = %d; elements = ", cap, size);
    printArray(a,size);


    printf("delete node with index: ");
    int index;
    scanf("%d", &index);
    deleteIndex(a, &cap, &size, index);
    printf("capacity = %d; size = %d; elements = ", cap, size);
    printArray(a,size);


    printf("delete first node with value: ");
    int value;
    scanf("%d", &value);
    first_Value_delete(a, &cap, &size, value);
    printf("capacity = %d; size = %d; elements = ", cap, size);
    printArray(a,size);


    printf("delete all node with value: ");
    int value1;
    scanf("%d", &value1);
    All_Value_delete(a, &cap, &size, value1);
    printf("capacity = %d; size = %d; elements = ", cap, size);
    printArray(a,size);


    return 0;
}
