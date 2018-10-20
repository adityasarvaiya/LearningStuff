#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    int parent;
};

int countSets(struct node set[], int n) 
{   
    int i, count = 0;
    for (i = 0; i < n; i++) {
        if (set[i].parent == i) {
            count++;
        }
    }
    
    return count;
}

void printdetails(struct node set[], int i) 
{
    int Num = countSets(set, i);
    printf("Nub of sets : %d\n", Num);
    int k;
    for (k = 0; k < i; k++) {
        printf("%d  %d\n", set[k].data, set[k].parent);
    }
    printf("\n");
}

int findset(struct node set[], int data, int n) 
{
    int i;
    for (i = 0; i < n; i++) {
        if (set[i].data == data) {
            int tmp = i;
            while (set[tmp].parent != tmp) {
                tmp = set[tmp].parent;
            }

            int par = tmp;
            while (set[tmp].parent != tmp) {
                tmp = set[tmp].parent;
                set[tmp].parent = par;
            }
            return tmp;
        }
    } 
}

void setUnion(struct node set[], int n, int d1, int d2) 
{
    int par1 = findset(set, d1, n);
    int par2 = findset(set, d2, n);

    set[par2].parent = par1;
    par2 = findset(set, d2, n);
}


int main(int argc, char const *argv[])
{
    int n=5,i;
    struct node set[n];

    int input[] = {10,20,30,40,50};
        
    for (i = 0; i < n; i++) {
        set[i].parent = i;
        set[i].data = input[i];
    }

    int setname = findset(set, 30, n-1);
    printdetails(set, n);    

    setUnion(set, n, 20, 30);
    printdetails(set, n);

    setUnion(set, n, 30, 50);
    printdetails(set, n); 


    return 0;
}
