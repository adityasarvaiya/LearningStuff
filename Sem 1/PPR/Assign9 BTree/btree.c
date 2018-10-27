#include <stdio.h>
#include <stdlib.h>

#define MINDIG 3
#define MAXKEYS MINDIG*2-1
#define MAXPTRS MINDIG*2 


struct node {
    int count;
    int key[MAXKEYS];
    struct node * (ptr[MAXPTRS]);
    struct node *par;
};

struct node * createNode(int data)
{
    struct node *curr = (struct node *) malloc(sizeof(struct node));
    curr->count = 1;
    curr->key[0] = data;
    curr->par = NULL;
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
    int i = 0, j, n = (*root)->count;
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

int newSearchIndex(struct node *root, int data)
{
    int i = 0, n = root->count;
    for (i = 0; i < n; i++) {
        if (root->key[i] > data) {
            return i;
        }
    } 

    return (n + 1);
}


void insert(struct node **root, int data) 
{
    if ((*root) == NULL) {
        struct node *curr = createNode(data);
        *root = curr;
    } else {
        struct node *par = NULL;

        while ((*root)->ptr[0] != NULL) {
            par = (*root);
            (*root) = (*root)->ptr[newSearchIndex(*root, data)];
        }    

        if ((*root)->count < (MINDIG*2 - 1)) {
            insertInNode(root, data);
        } else {
            insertInNode(root, data);
            struct node *newNode = (struct node *) malloc(sizeof(struct node));
            int i, tmp = -1;
            int mid = MINDIG;
            //shift all pointers to new node
            for (i = mid; i < MAXPTRS; i++) {
                ++tmp;
                newNode->ptr[tmp] = (*root)->ptr[i];
                (*root)->ptr[i] = NULL;
            }
            
            tmp = -1;
            //shift keys to new node
            for (i = mid+1; i < MAXKEYS; i++) {
                ++tmp;
                newNode->key[tmp] = (*root)->key[i];
                (*root)->key[i] = -1;
            }

            (*root)->count = MINDIG;
            newNode->count = tmp + 1;

            // insert into a parent node
            insert(&par, (*root)->key[MINDIG]);
            if (par == NULL) {
                struct node *curr = createNode((*root)->key[MINDIG]);
                curr->ptr[0] = (*root);
                curr->ptr[1] = newNode;
                (*root) = curr;
            } else if () {

            }
        }

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
