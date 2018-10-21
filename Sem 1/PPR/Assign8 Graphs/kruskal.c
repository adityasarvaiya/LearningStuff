#include <stdio.h>
#include <stdlib.h>

struct node {
    int par;
    int data;
};

void printdetails(struct node *set, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%d  %d\n", set[i].data, set[i].par);
    }

    printf("\n");
}

struct node* makeset(struct node ** set, int n, int input[]) 
{
    int i;
    *set = (struct node *) malloc(n * sizeof(struct node));

    for (i = 0; i < n; i++) {
        (*set)[i].data = input[i];
        (*set)[i].par = i;
    }

    return *set;
}

int findset(struct node *set, int n, int data)  
{
    int i;
    for (i = 0; i < n; i++) {
        if (set[i].data == data) {
            int tmp = i;

            while (set[tmp].par != tmp) {
                tmp = set[tmp].par;
            }
            
            int par = tmp;
            tmp = i;

            while (set[tmp].par != tmp) {
                tmp = set[tmp].par;
                set[tmp].par = par;
            }

            return par;
        }

    }  
}

void setunion(struct node *set, int n, int d1, int d2) 
{   
    int par1 = findset(set, n, d1);
    int par2 = findset(set, n, d2);

    set[par2].par = par1;
    par2 = findset(set, n, d2);

}


int main ()
{   
    int n = 5;
    
    int input[] = {10,20,30,40,50};
    printf("1\n");
    struct node *set;
    set = makeset(&set, n, input);
    printf("2\n");
    
    printdetails(set, n); 
    printf("3\n");

    int setname = findset(set, n, 30);
    printf("4\n");
    
    printf("%d\n", setname);
    printdetails(set, n);    

    setunion(set, n, 20, 30);
    printf("5\n");
    
    printdetails(set, n);

    setunion(set, n, 30, 50);
    printdetails(set, n); 

}