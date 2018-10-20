#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    int parent;
};


int findset(struct node set[], int data, int index) 
{
    if (index > -1) {
        if (set[i].parent == i) {
            return i;
        } else {
            int tmp = findset(set, data, index-1);
            set[i].parent = tmp;
            return tmp;
        }
    }
}


int main(int argc, char const *argv[])
{
    int n=5,i;
    struct node set[n];

    int input = {10,20,30,40,50};
        
    for (i = 0; i < n; i++) {
        set[i].parent = i;
        set[i].data = input[i];
    }

    int set = findset(set, 30, n-1);
    printf("Set of 30 is : %d\n", set);

    return 0;
}
