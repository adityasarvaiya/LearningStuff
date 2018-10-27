#include <stdio.h>
#include <stdlib.h>

#define MINDIG 3
#define MAXKEYS MINDIG*2-1
#define MAXPTRS MINDIG*2 


struct node {
    int count;
    int key[MAXKEYS];
    struct node * (ptr[MAXPTRS]);
};

struct node * createNode(int data)
{
    struct node *curr = (struct node *) malloc(sizeof(struct node));
    curr->count = 1;
    curr->key[0] = data;
    int i;
    for (i = 0; i < (MINDIG*2); i++) {
        curr->ptr[i] = NULL;
    }
    
    return curr;
}

void printinorder(struct node *root) 
{
    if (root != NULL) {
        int i;
        for (i = 0; i < root->count; i++) {
            printinorder(root->ptr[i]);
            printf("%d ", root->key[i]);
        }

        printinorder(root->ptr[root->count]);
    }
}

void insertInNode(struct node **root, int data) 
{
    int i = 0,j, n = (*root)->count;
    printf("n : %d\n", n);

    for (i = n-1; i >= 0; i--) {
        if ((*root)->key[i] > data) {
            (*root)->key[i+1] = (*root)->key[i];
            (*root)->ptr[i+2] = (*root)->ptr[i+1];
        } else {
            break;
        }
    }
    
    (*root)->key[i+1] = data;
    (*root)->ptr[i+2] = NULL;
    (*root)->count = (*root)->count + 1;
}

void insert(struct node **root, int data) 
{
    if ((*root) == NULL) {
        struct node *curr = createNode(data);
        *root = curr;
    } else if ((*root)->count < (MINDIG*2 - 1)) {
        insertInNode(root, data);
    }
}

int main(int argc, char const *argv[])
{
    struct node *root = NULL;

    int in[] = {10, 15, 20, 12, 26, 18, 29};
    int i;
    // int n = 4;
    int n = sizeof(in) / sizeof(in[0]);
    for (i = 0; i < n; i++) {
        insert(&root, in[i]);
    }
    
    printinorder(root);

    return 0;
}
