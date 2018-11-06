#include <stdio.h>
#include <stdlib.h>

#define MINDIG 3
#define MAXKEYS MINDIG*2-1
#define MAXPTRS MINDIG*2 


struct node {
    int count;
    int key[MAXKEYS+1];
    struct node * (ptr[MAXPTRS+1]);
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
    // printf("n : %d\n", n);

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

    return n;
}


void printnode(struct node *root) 
{
    int i;
    for (i = 0; i < root->count; i++) {
        if (root->ptr[i] == NULL) {
            printf("0 ");
        } else {
            printf("1 ");
        }

        printf(" %d\n", root->key[i]);
    }

    if (root->ptr[MAXPTRS-1] == NULL) {
        printf("0 \n\n");
    } else {
        printf("1 \n\n");
    }
}

void insert(struct node **root, int data) 
{
    if ((*root) == NULL) {
        struct node *curr = createNode(data);
        *root = curr;
    } else {
        struct node *par = NULL;
        struct node *curr = *root;

        while (curr->ptr[0] != NULL) {
            par = curr;
            
            curr = curr->ptr[newSearchIndex(curr, data)];
        }    

        if (curr->count < (MINDIG*2 - 1)) {
            insertInNode(&curr, data);
        } else {
            insertInNode(&curr, data);
            struct node *newNode = (struct node *) malloc(sizeof(struct node));
            int i, tmp = -1;
            int mid = MINDIG;

            //shift all pointers to new node
            for (i = mid; i <= MAXPTRS; i++) {
                ++tmp;
                newNode->ptr[tmp] = curr->ptr[i];
                curr->ptr[i] = NULL;
            }

            tmp = -1;
            //shift keys to new node
            for (i = mid+1; i <= MAXKEYS; i++) {
                ++tmp;
                newNode->key[tmp] = curr->key[i];
                curr->key[i] = -1;
            }

            curr->count = MINDIG;
            newNode->count = tmp + 1;

            // insert into a parent node
            insert(&par, curr->key[MINDIG]);
            int tmp1 = newSearchIndex(par, curr->key[MINDIG]);
            printf("tmp1 : %d\n", tmp1);
            par->ptr[tmp1-1] = curr;
            par->ptr[tmp1] = newNode;

            printf("key: %d\n", curr->key[MINDIG]);
            printf("oldNode : \n");
            printf("oldNode.count : %d\n", curr->count);
            printnode(curr);
            
            printf("oldNode : \n");
            printf("oldNode.count : %d\n", curr->count);
            printnode(curr);

            printf("parNode : \n");
            printf("parNode.count : %d\n", par->count);
            printnode(par);

            *root = par;
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
        printf("r.count : %d\n", root->count);
        printnode(root);
    }
    
    printf("Inorder : ");
    printinorder(root);

    return 0;
}
