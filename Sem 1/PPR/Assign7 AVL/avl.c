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

int max(int a, int b) 
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int findheight (struct node * root) 
{
    if (root == NULL) {
        return 0;
    } else { 

        int h = 1;
        if (root->left != NULL || root->right != NULL) {
            h += max(findheight(root->left), findheight(root->right));
        }

        return h;
    }
}

void rightrotate(struct node **root) 
{
    struct node * rootleft = (*root)->left;
    struct node * rootleftright = (*root)->left->right;

    (*root)->left = rootleftright;
    rootleft->right = *root;
    (*root) = rootleft;
}

void leftrotate(struct node **root) 
{
    struct node * rootright = (*root)->right;
    struct node * rootrightleft = (*root)->right->left;

    (*root)->right = rootrightleft;
    rootright->left = *root;
    (*root) = rootright;
}

void llrotation(struct node **root)
{
    rightrotate(root);
}

void rrrotation(struct node **root)
{
    leftrotate(root);
}

void lrrotation(struct node **root)
{
    leftrotate(&((*root)->left));
    rightrotate(root);
}

void rlrotation(struct node **root)
{
    rightrotate(&((*root)->right));
    leftrotate(root);
}

void balance(struct node **root) 
{   

    if ((*root) != NULL) {

        // printf("1\n");
        balance(&((*root)->left));
        balance(&((*root)->right));
        // printf("2\n");

        int h1 = findheight((*root)->left);
        int h2 = findheight((*root)->right);
        // printf("3\n");

        // printf("root : %d  diff : %d  %d  %d\n", (*root)->data, (h1-h2), h1, h2);

        if ((h1 - h2) > 1) {
            //Left side 
            int ll = findheight((*root)->left->left);
            int lr = findheight((*root)->left->right);
            // printf("4\n");

            if ((ll-lr) > 0) {
                // printf("5\n");
                llrotation(root);
            } else {
                // printf("6\n");
                lrrotation(root);
            }
        }

        if ((h1 - h2) < -1) {
            //Left side 
            int rl = findheight((*root)->right->left);
            int rr = findheight((*root)->right->right);
            // printf("7\n");

            if ((rl-rr) > 0) {
                // printf("8\n");
                rlrotation(root);
            } else {
                // printf("9\n");
                rrrotation(root);
            }
        }

    } 

    // printf("\n");
}

void delete(struct node **root) 
{
    struct node *delete = *root;
    struct node *parent = *root;

    if ((*root)->left != NULL) {
        struct node *pred = (*root)->left;
      
        if (pred->right == NULL) {
            pred->right = (*root)->right;
            *root = pred;
        } else {
            struct node *lefttree = pred;
            while (pred->right != NULL) {
                parent = pred;
                pred = pred->right;
            }

            parent->right = NULL;
            pred->left = lefttree;
            pred->right = (*root)->right;
            (*root) = pred;
        }

    } else if ((*root)->right != NULL) {
        struct node *succ = (*root)->right;
        
        if (succ->left == NULL) {
            succ->left = (*root)->left;
            *root = succ;
        } else {
            struct node *righttree = succ;
        
            while (succ->left != NULL) {
                parent = succ;
                succ = succ->left;
            }

            parent->left = NULL;
            succ->left = (*root)->left;
            succ->right = righttree;
            *root = succ;
        }
    } else {
        *root = NULL;
    }
    
    free(delete);
}

void search(struct node **root, int finddata) 
{
    if ((*root)==NULL) {
        printf("Input data is not available. please try again.\n");
    } else {
        if ((*root)->data == finddata) {
            printf("%d Found\n", finddata);
            delete(root);
        } else if (finddata < (*root)->data) {
            search(&((*root)->left), finddata);
        } else {
            search(&((*root)->right), finddata);
        }
    }
}


int main()
{
    struct node *root = NULL;
    
    // int a[] = {15,20,24,10,13,7,30,36,25};
    int a[] = {15,20,24,10,13,7,30};
    // int a[] = {24,20,15};
    int len = sizeof(a)/sizeof(a[0]);
    int i;

    for (i = 0; i < len ; i++){
        insert(&root, a[i]);
        // printf("Input : %d\n", a[i]);
        // printf("height : %d\n", findheight(root));
        balance(&root);
        // printdetails(root);
    }
    
    printdetails(root);
    search(&root, 24);
    printdetails(root);
    //rightrotate(&root);
    //printdetails(root);

}
