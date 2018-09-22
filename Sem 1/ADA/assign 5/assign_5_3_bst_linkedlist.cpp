#include <iostream>
#include <stdio.h>

using namespace std;

// ques is about finding given 2 trees are mirror similar or not.
// I have take binary search tree not a normal tree for the example but checkmirror() method will work for any type of tree.

struct node {
    struct node *left;
    int value;
    struct node *right;
};

struct node * getNode() 
{
    struct node *tmp = (struct node *) malloc(sizeof(struct node));
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}

void insert(struct node **nod, int value) 
{
    if (*nod == NULL) {
        struct node *curr = getNode();
        curr->value = value;
        *nod = curr;
    } else if (value < (*nod)->value) {
        insert(&((*nod)->left), value);
    } else {
        insert(&(*nod)->right, value);
    }
}

bool search(struct node *nod, int value)
{
    if (nod == NULL) return false;
    if (nod->value == value) return true;
    if (value < nod->value) {
        return search(nod->left, value);
    } else {
        return search(nod->right, value);
    }
}

void printinorder(struct node *nod)
{
    if (nod != NULL) {
        printinorder(nod->left);
        printf("%d ", nod->value);
        printinorder(nod->right);
    }
}

void printpreorder(struct node *nod)
{
    if (nod != NULL) {
        printf("%d ", nod->value);
        printpreorder(nod->left);
        printpreorder(nod->right);
    }
}

void printpostorder(struct node *nod)
{
    if (nod != NULL) {
        printpostorder(nod->left);
        printpostorder(nod->right);
        printf("%d ", nod->value);
    }
}

bool checkmirror(struct node *root1, struct node *root2) 
{  
    if ((root1 == NULL && root2 == NULL)) {
        return true;
    } else if ((root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL)) {
        return false;
    } else {
        return (checkmirror(root1->left, root2->right) && checkmirror(root1->right, root2->left));
    }
}

int main(int argc, char const *argv[])
{
    struct node *root = NULL;
    int iter, val, i;
    printf("Enter the num of nodes you want to enter in 1st tree.: \n");
    scanf("%d",&iter);
    printf("Now enter all nodes:\n");
    for (i = 0; i < iter; i++) {
        scanf("%d", &val);
        insert(&root, val);
    }

    // insert(&root, 50);
    // insert(&root, 60);
    // insert(&root, 40);
    // insert(&root, 55);
    // insert(&root, 70);

    
    // if (search(root, 32)) {
    //     printf("Found\n");
    // } else {
    //     printf("NOT Found\n");
    // }

    printf("Inorder : ");
    printinorder(root);
    printf("\n");
    printf("Preorder : ");
    printpreorder(root);
    printf("\n");
    printf("Postorder : ");
    printpostorder(root);
    printf("\n");
    printf("\n");

    struct node *root2 = NULL;
    printf("Enter the num of nodes you want to enter in 2nd tree.: \n");
    scanf("%d",&iter);
    printf("Now enter all nodes:\n");
    for (i = 0; i < iter; i++) {
        scanf("%d", &val);
        insert(&root2, val);
    }

    // insert(&root2, 50);
    // insert(&root2, 40);
    // insert(&root2, 30);
    // insert(&root2, 45);
    // insert(&root2, 55);

    printf("Inorder : ");
    printinorder(root2);
    printf("\n");
    printf("Preorder : ");
    printpreorder(root2);
    printf("\n");
    printf("Postorder : ");
    printpostorder(root2);
    printf("\n");
    printf("\n");

    if (checkmirror(root, root2)) {
        printf("Are Mirror\n");
    } else {
        printf("Are NOT Mirror\n");
    }

    return 0;
}
