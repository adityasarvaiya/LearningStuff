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

void TreeFromInoPost() 
{
	int ino[] = {3, 5, 6, 7, 8, 9, 10, 15, 20, 40, 43};
    int psto[] = {3, 6, 5, 7, 9, 8, 15, 43, 40, 20, 10};

    struct node *root = NULL;

    int i,j;
    int len = sizeof(ino)/sizeof(ino[0]);
    for (i = (len - 1); i >= 0; i--) {
        for (j = 0; j < len; j++) {
            if (psto[i] == ino[j]) {
                //printf("i : %d --- j : %d \n", i,j);
                insert(&root, psto[i]);
                break;
            }
        }
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

}


int searchNodeIno(int a[], int find, int start, int end) 
{
    int i;
    int flag = 0;
    for (i = start; i <= end; i++) {
        if (a[i] == find) {
            flag = 1;
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

struct node *maketree(int *ino, int *psto, int start, int end, int len){
    struct node *root = (struct node *) malloc(sizeof(struct node));

    int last = -1;
    int i,j;

    for (i = start; i <= end; i++) {
        for (j = 0 ; j < len; j++) {
            if (ino[i] == psto[j]) {
                if (j > last) {
                    last = j;
                }
                break;
            }
        }
    }

    int inoIndex = searchNodeIno(ino, psto[last], start, end);
    root->data = ino[inoIndex];

    if (inoIndex != start && inoIndex != end) {
        root->left = maketree(ino, psto, start, (inoIndex-1), len);
        root->right = maketree(ino, psto, (inoIndex+1), end, len);
    } else if ((inoIndex-1) == start) {
        root->left = createNode(ino[start]);
        root->right = maketree(ino, psto, (inoIndex+1), end, len);
    } else if ((inoIndex+1) == end) {
        root->left = maketree(ino, psto, start, (inoIndex-1), len);
        root->right = createNode(ino[end]);
    }
        
    return root;
}

struct node * createTree(int *ino, int *psto, int start, int end, int *last, int len) 
{
    struct node *newNode = createNode(psto[*last]);
    (*last)--;

    if (start > end) {
        return NULL;
    } else if (start == end) {
        return newNode;
    } else {
        int pos = searchNodeIno(ino, psto[*last], 0, len);
        newNode->right = createTree(ino, psto, (pos+1), end, last, len);
        newNode->left = createTree(ino, psto, start, (pos-1), last, len);
        return newNode;
    }
}

int main() 
{
	TreeFromInoPost(); 
    int ino[] = {3, 5, 6, 7, 8, 9, 10, 15, 20, 40, 43};
    int psto[] = {3, 6, 5, 7, 9, 8, 15, 43, 40, 20, 10};

	// int ino[] = {3, 5, 6, 7, 8, 9, 10, 15, 20, 40, 43};
    // int psto[] = {3, 6, 5, 7, 9, 8, 15, 43, 40, 20, 10};
    int len = sizeof(psto)/sizeof(psto[0]);
    
    int last = len - 1;
    // struct node * r = maketree(ino, psto, 0, len-1, len);
    struct node * r = createTree(ino, psto, 0, len-1, &last, len-1);
    
    printf("Preorder : ");
    printpreorder(r);
    printf("\n");

    printf("Inorder : ");
    printinorder(r);
    printf("\n");

    printf("Postorder : ");
    printpostorder(r);
    printf("\n");

}
