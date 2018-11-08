#include <stdio.h>
#include <stdlib.h>

#define MINDIG 2
#define MAXKEYS 3
//MINDIG*2-1
#define MAXPTRS 4
//MINDIG*2 

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

void insert(struct node **root, int data, int goToLeaf);
void split(struct node **root, struct node **curr, struct node **par);

void printinorder(struct node *root, int *c) 
{
    if (root != NULL) {
        (*c) += 1;
        int i;
        for (i = 0; i < root->count; i++) {
            printinorder(root->ptr[i], c);
            printf("%d ", root->key[i]);
        }

        printinorder(root->ptr[root->count], c);
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
            printf("1(%d) ", root->ptr[i]->key[0]);
        }

        printf(" %d\n", root->key[i]);
    }

    if (root->ptr[root->count] == NULL) {
        printf("0 \n\n");
    } else {
        printf("1(%d) \n\n", root->ptr[root->count]->key[0]);
    }
}

void findParent(struct node *root, struct node **par, int key) 
{
    if (root != NULL) {
        int i;
        int flag = -1;

        for (i = 0; i < root->count; i++) {
            if (root->key[i] == key) {
                flag = i;
                break;
            }
        }

        if (flag == -1) {
            *par = root;
            findParent(root->ptr[newSearchIndex(root, key)], par, key);
        }
    }
}



int main(int argc, char const *argv[])
{
    struct node *root = NULL;

    // int in[] = {10, 15, 20, 12, 26, 18, 29};
    int in[] = {5, 3, 21, 9, 1, 13, 2, 7, 10, 12, 4, 8};
    int nodeCount = 0;
    int i;
    int n = 12;
    // int n = sizeof(in) / sizeof(in[0]);
    for (i = 0; i < n; i++) {
        printf("key:%d\n", in[i]);
        insert(&root, in[i], 1);
        printf("key:%d  r.count: %d\n", in[i], root->count);
        printnode(root);
        printf("Inorder : ");
        printinorder(root, &nodeCount);
        printf("\n");
    }

    printf("RootNode : \n");
    printf("RootNode.count : %d\n", root->count);
    printnode(root);

    nodeCount = 0;
    printf("Inorder :");
    printinorder(root, &nodeCount);
    printf("\nNodes: %d\n", nodeCount);

    return 0;
}

void split(struct node **root, struct node **curr, struct node **par) 
{
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    int i, tmp = -1;
    int mid = MINDIG;

    //shift all pointers to new node
    for (i = mid+1; i <= MAXPTRS; i++) {
        ++tmp;
        newNode->ptr[tmp] = (*curr)->ptr[i];
        (*curr)->ptr[i] = NULL;
    }

    tmp = -1;
    //shift keys to new node
    for (i = mid+1; i <= MAXKEYS; i++) {
        ++tmp;
        newNode->key[tmp] = (*curr)->key[i];
        // (*curr)->key[i] = -1;
    }

    (*curr)->count = MINDIG;
    newNode->count = tmp + 1;

    // insert into a parent node
    int data = (*curr)->key[MINDIG];
    printf("Data to be shifted to par : %d\n", data);
    insert(par, (*curr)->key[MINDIG], 0);

    findParent((*root), par, (*curr)->key[0]);

    int tmp1 = newSearchIndex((*par), data);
    printf("Index of newNode: %d of key: %d\n", tmp1, (*curr)->key[MINDIG]);
    (*par)->ptr[tmp1-1] = (*curr);
    (*par)->ptr[tmp1] = newNode;

    printf("key: %d\n", (*curr)->key[MINDIG]);
    printf("NewNode : \n");
    printf("NewNode.count : %d\n", newNode->count);
    printnode(newNode);
    
    printf("oldNode : \n");
    printf("oldNode.count : %d\n", (*curr)->count);
    printnode((*curr));

    printf("parNode : \n");
    printf("parNode.count : %d\n", (*par)->count);
    printnode((*par));

    *root = *par;
    if ((*par)->count > MAXKEYS) {
        struct node *newPar = NULL;
        findParent((*root), &newPar, (*par)->key[0]);
        split(root, par, &newPar);
    }
    
}

void insert(struct node **root, int data, int goToLeaf) 
{
    if ((*root) == NULL) {
        struct node *curr = createNode(data);
        *root = curr;
    } else {
        struct node *par = NULL;
        struct node *curr = *root;

        if (goToLeaf == 1) {
            //go to leaf node
            while (curr->ptr[0] != NULL) {
                par = curr;
                curr = curr->ptr[newSearchIndex(curr, data)];
            }    
        } else {
            findParent(*root, &par, (*root)->key[0]);
        }
        
        insertInNode(&curr, data);
        printf("Inserted node for key : %d \n", data);
        printf("Inserted.count : %d\n", curr->count);
        printnode(curr);


        if (curr->count > MAXKEYS) {
            split(root, &curr, &par);
        }
    }
}