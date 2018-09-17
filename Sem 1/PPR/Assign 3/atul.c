#include <stdio.h>
#include <stdlib.h>
void delete_by_index(int index, int *arr, int *size, int *capacity)
{
    int i = 0;
    while (i < ((*size) - (index + 1))){
        arr[index] = arr[index + 1];
        index++;
        i++;
    }
    *size -= 1;
    if ((*size) == (float)((*capacity) / 4)){
        (*capacity) = (*capacity) / 2;
        arr = (int *)realloc(arr, (*capacity) * sizeof(int));
    }
}
void delete_first_value(int val, int **arr, int *size, int *capacity)
{
    int i;
    int t;
    for (i = 0; i < ((*size) - 1); i++){
        if (*arr[i] == val){
            t = *arr[i];
            *arr[i] = *arr[i + 1];
            *arr[i + 1] = t;
        }
    }
    (*size)--;
    if (*size == (float)(*capacity / 4)){
        *capacity = *capacity / 2;
        *arr = (int *)realloc(*arr, *capacity * sizeof(int));
    }
}
void delete_all_value(int val, int **arr, int *size, int *capacity)
{
    int *arr2;
    arr2 = (int *) malloc (*capacity * sizeof(int));
    int i;
    int j;
    j = 0;
    for (i = 0; i < *size; i++){
        if (*arr[i] != val){
            arr2[j] = *arr[i];
            j++;
        }
    }
    *arr = arr2;
    *size -= (*size - j);
    if (*size == (float)(*capacity / 4)){
        *capacity = *capacity / 2;
        *arr = (int *)realloc(*arr, *capacity * sizeof(int));
    }
}
void display(int * list, int size, int capacity)
{
    int i;
    printf("%s %d", "size =", size);
    printf(" %s %d", "capacity =", capacity);
    printf(" %s ", "elements = ");
    for (i = 0; i < size; i++){
        printf("%d ", list[i]);
    }printf("\n\n");
}
int main()
{
    int i;
    int j;
    int * arr;
    int n;
    int size;
    int capacity;
    printf("%s\n" ,"enter the size of input");
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int));
    size = 0;
    capacity = 1;
    i = 0;
    while (i < n){


        printf("%s\n", "choose 1 for insert and 2 for delete" );
        scanf("%d", &j);
        if (j == 1){
            if (size == capacity){
                capacity = 2 * size;
                arr = (int *)realloc(arr, capacity * sizeof(int));
            }
            printf("%s\n", "give an input");
            scanf("%d", &arr[i]);
            size += 1;
            display(arr, size, capacity);
            i++;
        }
        else{
            size -= 1;
            i--;
            if (size == (float)(capacity / 4)){
                capacity = capacity / 2;
                arr = (int *)realloc(arr, capacity * sizeof(int));
            }
            display(arr, size, capacity);
        }
    }
    delete_by_index(3, arr, &size, &capacity);
    display(arr, size, capacity);
    // delete_first_value(5, &arr, &size, &capacity);
    // display(arr, size, capacity);
    // delete_all_value(7, &arr, &size, &capacity);
    // display(arr, size, capacity);
    return 0;
}