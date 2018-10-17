#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    int parent;
};


int findset(int data) 
{
    
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

    int set = findset(30);

    return 0;
}
