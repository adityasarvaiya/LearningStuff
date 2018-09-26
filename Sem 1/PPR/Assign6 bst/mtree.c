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
            //printf("--%d--  ", root->data);
            (*sum) += root->data;
            (*totalleaves)++;
            return;
        }

        totalLeafNodes(root->left, totalleaves, sum);
        totalLeafNodes(root->right, totalleaves, sum);
    }
}

void PrintAllDetails(struct node *r) 
{
    printf("\n");
    printf("Preorder : ");
    printpreorder(r);
    printf("\n");

    printf("Inorder : ");
    printinorder(r);
    printf("\n");

    printf("Postorder : ");
    printpostorder(r);
    printf("\n");

    int totleafnodes  = 0;
    int sum = 0;
    totalLeafNodes(r, &totleafnodes, &sum);
    printf("Total Leaf nodes : %d\n", totleafnodes);
    printf("Total Sum of Leaf nodes : %d\n", sum);
}

void BSTFromInoPost(int *ino, int *psto, int len) 
{
    struct node *root = NULL;

    int i,j;
    for (i = (len - 1); i >= 0; i--) {
        for (j = 0; j < len; j++) {
            if (psto[i] == ino[j]) {
                //printf("i : %d --- j : %d \n", i,j);
                insert(&root, psto[i]);
                break;
            }
        }
    }

 	PrintAllDetails(root);

}


int searchNodeIno(int *a, int find, int start, int len) 
{
    int i;
    for (i = start; i < len; i++) {
        if (a[i] == find) {
            return i;
        }
    }
}

struct node *createNode(int data) 
{
    struct node * tmp = (struct node *) malloc(sizeof(struct node));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

struct node * createTree(int *ino, int *psto, int start, int end, int *last, int len) 
{
    if (*last > -1) {

        if (start > end) {
            return NULL;
        } else {  
            
            int tmp = psto[*last];
            struct node *newNode = createNode(tmp);
            (*last)--;

            if (start == end) {
                return newNode;
            } else {
                int pos = searchNodeIno(ino, tmp, 0, len);
                newNode->right = createTree(ino, psto, (pos+1), end, last, len);
                newNode->left = createTree(ino, psto, start, (pos-1), last, len);
                return newNode;
            }
        }
    } else {
        return NULL;
    }   
}

void TreeFromInoPosto(int *ino, int *psto, int len) 
{
    int last1 = (len - 1);
    // struct node * r = maketree(ino, psto, 0, len-1, len);
    struct node * root = createTree(ino, psto, 0, len-1, &last1, len);
    
    PrintAllDetails(root);
}

int main() 
{
	
    // int ino[] = {3, 15, 1, 10, 16, 9, 49};
    // int psto[] = {3, 1, 15, 16, 49, 9, 10};
    
    int ino[] = {3, 5, 6, 7, 8, 9, 10, 15, 20, 40};
    int psto[] = {3, 6, 5, 7, 9, 8, 15, 40, 20, 10};

	// int ino[] = {3, 5, 6, 7, 8, 9, 10, 15, 20, 40, 43};
    // int psto[] = {3, 6, 5, 7, 9, 8, 15, 43, 40, 20, 10};

    int len = sizeof(psto)/sizeof(psto[0]);
    BSTFromInoPost(ino, psto, len); 
    TreeFromInoPosto(ino, psto, len);


}
