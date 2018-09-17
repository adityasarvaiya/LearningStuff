#include <stdio.h>

struct hash {
    int flag;
    int value;
};

void display(struct hash *hashtable, int size)
{
    int i;
    for (i = 0; i < size; i++) {
        if (hashtable[i].flag == 1) {
            printf("%d\t", hashtable[i].value);
        } else {
            printf(" \t");
        }
        
    }

    printf("\n");
}

int findLinearHashValue(int value, int size, int i)
{
    return (value + i) % size;
}

int findQuadraticHashValue(int value, int size, int i)
{
    return (value + i + i*i) % size;
}

int main(int argc, char const *argv[])
{
    int size,i;
    scanf("%d", &size);
    struct hash hashtable[size];

    for (i = 0; i < size; i++) {
        hashtable[i].flag = 0; 
    }

    int value;
    for (i = 0; i < size; i++) {
        scanf("%d", &value);
        int tmp1 = 0;
        int index = findQuadraticHashValue(value, size, tmp1);

        while (hashtable[index].flag == 1) {
            tmp1++;
            index = findQuadraticHashValue(value, size, tmp1);
        }

        if (hashtable[index].flag == 1) {
            printf("Error : No more space in Hashtable.\n");
        } else {
            hashtable[index].value = value;
            hashtable[index].flag = 1; 
        }


        // if (hashtable[index].flag == 0) {
        //     hashtable[index].value = value;
        //     hashtable[index].flag = 1;
        // } else {
        //     int tmp = index;
        //     while (hashtable[tmp].flag == 1) {
        //         tmp = (tmp + 1) % size;
        //         if (tmp == index) {
        //             printf("NO More space in hashtable");
        //             break;
        //         }
        //     }

        //     if (hashtable[tmp].flag == 1) {
        //         printf("Error : No more space in Hashtable.\n");
        //     } else {
        //         hashtable[tmp].value = value;
        //         hashtable[tmp].flag = 1; 
        //     }
        // }

        printf("%d) \t", i);
        display(hashtable, size);
    }

    display(hashtable, size);

    return 0;
}

