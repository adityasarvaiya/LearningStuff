#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
};

void setNull(struct node *tmp, struct node *parent)
{
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->parent = parent;
}

void insert(struct node **root, int ip)
{
    if (!(*root)) {
        *root = (struct node *) malloc(sizeof(struct node));
        setNull(*root, NULL);
        (*root)->data = ip;
    } else if (ip < (*root)->data) {
        if (!((*root)->left)) {
            struct node *left = (struct node *) malloc(sizeof(struct node));
            setNull(left, *root);
            left->data = ip;
            (*root)->left = left;
        } else {
            insert(&((*root)->left), ip);
        }
    } else {
        if (!((*root)->right)) {
            struct node *right = (struct node *) malloc(sizeof(struct node));
            setNull(right, *root);
            right->data = ip;
            (*root)->right = right;
        } else {
            insert(&((*root)->right), ip);
        }
    }
}

void search(struct node *root, int ip)
{
    if (root == NULL) {
        printf("N -- %d\n", ip);
    } else if (ip == root->data) {
        printf("Y -- %d\n", root->data);
    } else if(ip < root->data) {
        search(root->left, ip);
    } else {
        search(root->right, ip);
    }
}

void printpreorder(struct node *root) 
{   
    if (root != NULL) {
        printf("%d_", root->data);  
        printpreorder(root->left);
        printpreorder(root->right);
    }
}

void printinorder(struct node *root) 
{   
    if (root != NULL) {
        printinorder(root->left);
        printf("%d_", root->data);
        printinorder(root->right);
    }
}

void printpostorder(struct node *root) 
{
    if (root != NULL) {
        printpostorder(root->left);
        printpostorder(root->right);
        printf("%d_", root->data);
    }
}

void totalLeafNodes(struct node *root, int *totalleaves, int *sum)
{
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            printf("--%d--  ", root->data);
            (*sum) += root->data;
            (*totalleaves)++;
            return;
        }

        totalLeafNodes(root->left, totalleaves, sum);
        totalLeafNodes(root->right, totalleaves, sum);
    }
}



int main() 
{
    struct node *root = NULL;    
    
    int n,i,ip;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        scanf("%d", &ip);
        insert(&root, ip);
    }
    
    printf("Preorder : ");
    printpreorder(root);
    printf("\n");

    printf("Inorder : ");
    printinorder(root);
    printf("\n");

    printf("Postorder : ");
    printpostorder(root);
    printf("\n");
    
    int totleafnodes  = 0;
    int sum = 0;
    totalLeafNodes(root, &totleafnodes, &sum);
    printf("Total Leaf nodes : %d\n", totleafnodes);
    printf("Total Sum of Leaf nodes : %d\n", sum);

    //printf("How many elements you want to search ? \n");
    //scanf("%d", &n);
    //for (i = 0; i < n; i++) {
    //    scanf("%d", &ip);
    //    search(root, ip);
    //}
}
