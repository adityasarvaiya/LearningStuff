#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *parent;
    struct node *left;
    int data;
    struct node *right;
    int count;
};

struct node* makenode(int data) 
{
    struct node *curr = (struct node*) malloc(sizeof(struct node));
    curr->parent = NULL;
    curr->left = NULL;
    curr->data = data;
    curr->right = NULL;
    curr->count = 1;

    return curr;
}

void insert(struct node **root, int data)
{
    struct node *curr = makenode(data);

    if ((*root) == NULL) {
        (*root) = curr;
    } else if ((*root)->data == data) {
        ((*root)->count)++;
    } else {
        curr->parent = (*root);
        
        if (data < ((*root)->data)) {
            if ((*root)->left == NULL) {
                (*root)->left = curr;
            } else {
                insert(&((*root)->left), data);
            }
        } else {
            if ((*root)->right == NULL ) {
                (*root)->right = curr;
            } else {
                insert(&((*root)->right), data);
            }
        }
    }
}

void printall(struct node *root)
{
    int len = root->count;
    int i;

    for (i = 0; i < len; i++) {
        printf("%d ", root->data);
    }
}

void printinord(struct node *root)
{
    if (root != NULL) {
        printinord(root->left);
        printall(root);
        //printf("%d ", root->data);
        printinord(root->right);
    }
}

void printpreord(struct node *root) 
{
    if (root != NULL) {
        printall(root);
        //printf("%d ", root->data);
        printpreord(root->left);
        printpreord(root->right);
    }
}

void printpostord(struct node *root)
{
    if (root != NULL) {
        printpostord(root->left);
        printpostord(root->right);
        printall(root);
        //printf("%d ", root->data);
    }
}

void printdetails(struct node *root) 
{
    printf("\n");
    
    printf("Inorder : ");
    printinord(root);
    printf("\n");
    
    printf("Preorder : ");
    printpreord(root);
    printf("\n");

    printf("Postorder : ");
    printpostord(root);
    printf("\n");
}


void rightrotate(struct node **root) 
{
    if ((*root) != NULL) {
        struct node * rootleft = (*root)->left;
        struct node * rootleftright = (*root)->left->right;

        (*root)->left = rootleftright;
        rootleft->right = *root;
        (*root) = rootleft;
    }
}

void leftrotate(struct node **root) 
{
    if ((*root) != NULL) {
        struct node * rootright = (*root)->right;
        struct node * rootrightleft = (*root)->right->left;

        (*root)->right = rootrightleft;
        rootright->left = *root;
        (*root) = rootright;
    }
}

struct node * search(struct node **root, int finddata) 
{
    if ((*root)==NULL || (*root)->data == finddata) {
        return (*root);
    } else if (finddata < (*root)->data) {
        (*root)->left = search(&((*root)->left), finddata);
        rightrotate(root);
        return (*root);
    } else {
        (*root)->right = search(&((*root)->right), finddata);
        leftrotate(root);
        return (*root);
    }
}

int main()
{
    struct node *root = NULL;
    
    int a[] = {15,20,24,10,13,7,30,36,25};
    // int a[] = {15,20,24,10,13,7,30};
    // int a[] = {24,20,15};
    int len = sizeof(a)/sizeof(a[0]);
    int i;

    for (i = 0; i < len ; i++){
        insert(&root, a[i]);
    }
    
    printdetails(root);

    root = search(&root, 24);
    printdetails(root);

    root = search(&root, 13);
    printdetails(root);

    root = search(&root, 36);
    printdetails(root);
}
