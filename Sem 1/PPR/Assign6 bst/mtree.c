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
        printf("%d, ", root->data);  
        printpreorder(root->left);
        printpreorder(root->right);
    }
}

void printinorder(struct node *root) 
{   
    if (root != NULL) {
        printinorder(root->left);
        printf("%d, ", root->data);
        printinorder(root->right);
    }
}

void printpostorder(struct node *root) 
{
    if (root != NULL) {
        printpostorder(root->left);
        printpostorder(root->right);
        printf("%d, ", root->data);
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

struct node * BSTFromInoPost(int *ino, int *psto, int len) 
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
    return root;
}


int searchInArray(int *a, int find, int start, int len) 
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
                int pos = searchInArray(ino, tmp, 0, len);
                newNode->right = createTree(ino, psto, (pos+1), end, last, len);
                newNode->left = createTree(ino, psto, start, (pos-1), last, len);
                return newNode;
            }
        }
    } else {
        return NULL;
    }   
}

struct node * TreeFromInoPosto(int *ino, int *psto, int len) 
{
    int last1 = (len - 1);
    // struct node * r = maketree(ino, psto, 0, len-1, len);
    struct node * root = createTree(ino, psto, 0, len-1, &last1, len);
    
    return root;
}

struct node *makeMirror(struct node *root)
{
    if (root == NULL) {
        return NULL;
    } else {
        int data = root->data;
        struct node *curr = createNode(data);
        curr->left = makeMirror(root->right);
        curr->right = makeMirror(root->left);
        return curr;
    }
}

void printArray(int a[], int len)
{
    int i;
    for (i = 0; i <= len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void printAllPaths(struct node *root, int path[], int pos)
{
    if (root != NULL) {
        path[++pos] = root->data;

        if (root->left == NULL && root->right == NULL) {
            printArray(path, pos);
            return;
        } 
        
        if (root->left != NULL) {
            printAllPaths(root->left, path, (pos));
        }

        if (root->right != NULL) {
            printAllPaths(root->right, path, (pos));
        }
    }
}

void AllAtKdis(struct node *root, int curr_k, int k)
{
    if (curr_k == k) {
        printf("%d ", root->data);
    } else if (curr_k < k) {
        if (root->left != NULL) {
            AllAtKdis(root->left, curr_k+1, k);
        }

        if (root->right != NULL) {
            AllAtKdis(root->right, curr_k+1, k);
        }
    }
}

int deleteterminal(struct node *root) 
{
    if (root->left == NULL && root->right == NULL) {
        return 1;
    } 
    
    if (root->left != NULL) {
        if(deleteterminal(root->left)) {
            struct node *tmp = root->left;
            root->left = NULL;
            free(tmp);
        }
    } 
    
    if (root->right != NULL) {
        if(deleteterminal(root->right)) {
            struct node *tmp = root->right;
            root->right = NULL;
            free(tmp);
        }
    }

    return 0;
}

int main() 
{
	
    // int ino[] = {3, 15, 1, 10, 16, 9, 49};
    // int psto[] = {3, 1, 15, 16, 49, 9, 10};
    
    //int pre[] = {10, 8, 7, 5, 3, 6, 9, 20, 15, 40}
    int ino[] = {3, 5, 6, 7, 8, 9, 10, 15, 20, 40};
    int psto[] = {3, 6, 5, 7, 9, 8, 15, 40, 20, 10};

	// int ino[] = {3, 5, 6, 7, 8, 9, 10, 15, 20, 40, 43};
    // int psto[] = {3, 6, 5, 7, 9, 8, 15, 43, 40, 20, 10};

    int len = sizeof(psto)/sizeof(psto[0]);
    
    // struct node *root = BSTFromInoPost(ino, psto, len); 
    // PrintAllDetails(root);
   
    printf("\n");
    struct node * root1 = TreeFromInoPosto(ino, psto, len);
    PrintAllDetails(root1);

    int path[100];
    printf("All Paths : \n");
    printAllPaths(root1, path, -1);

    // printf("Mirror : \n");
    // struct node *mirror = makeMirror(root);
    // PrintAllDetails(mirror);

    // printf("\nAll at K distances : \n");
    // AllAtKdis(root1, 0, 4);
    // printf("\n");

    printf("\nDelete all Terminals:  \n");
    int z = deleteterminal(root1);
    PrintAllDetails(root1);
    printf("\n");
}
