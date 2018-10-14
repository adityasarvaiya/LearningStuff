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

struct node *rightrotate(struct node **root)
{
    struct node *tmp = ((*root)->left)->right;
    ((*root)->left)->right = (*root);
    struct node *newroot = (*root)->left;
    (*root)->left = tmp;
    (*root) = newroot;

    return (*root);
}

struct node * leftrotate(struct node **root)
{   
    struct node *tmp = ((*root)->right)->left;
    ((*root)->right)->left = (*root);
    struct node *newroot = (*root)->right;
    (*root)->right = tmp;
    (*root) = newroot;

    return (*root);
}

void llrotate(struct node **root) 
{   
    printf("LL Rotation \n");
    *root = rightrotate(root);
}

void rrrotate(struct node **root)
{   
    printf("RR Rotation \n");
    *root = leftrotate(root);
}

void lrrotate(struct node **root)
{
    printf("LR Rotation \n");
    (*root)->left = rightrotate(&((*root)->left));
    *root = leftrotate(root);
}

void rlrotate(struct node **root)
{
    printf("RL Rotation \n");
    (*root)->right = leftrotate(&((*root)->right));
    (*root) = rightrotate(root);
}

int max(int a, int b) 
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int findheight(struct node *root, int h)
{
    int leftheight=0, rightheight=0;

    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;    
    }

    if (root->left != NULL) {
        leftheight = findheight(root->left, (h+1));        
    }

    if (root->right != NULL) {
        rightheight = findheight(root->right, (h+1));
    }

    return (1 + max(leftheight, rightheight));
} 

void balance(struct node **root) 
{
    if ((*root) != NULL) {
        //balance(&((*root)->left));
        //balance(&((*root)->right));
   
        printf("1 \n");
        int lheight = 0, rheight = 0;
        
        if ((*root)->left != NULL) {
            lheight = findheight((*root)->left, 0);
        }
        
        if ((*root)->right != NULL)
        {
            rheight = findheight((*root)->right, 0);
        }

        int diff = lheight - rheight;
        printf("Node : %d\n", (*root)->data);
        printf("Lhei : %d  Rhei : %d \n", lheight, rheight);
        printf("Diff is : %d\n", diff);

        if (diff >= 2) {
            printf("2 \n");
            int llheight = 0;
            
            if ((*root)->left->left != NULL) {
                llheight = findheight(((*root)->left)->left, 0);
            }

            int lrheight = 0; 
            
            if ((*root)->left->right) { 
                lrheight = findheight(((*root)->left)->right, 0);
            }
            
            if ((llheight - lrheight) > 0) {
                printf("3 \n");
                lrrotate(root);
            } else {
                printf("4 \n");
                llrotate(root);
            }         
         
            printdetails(*root);
            balance(root);
        } 
        
        if (diff <= -2) {
            printf("5 \n");
            //printdetails(*root);
            int rlheight = 0, rrheight = 0;
            
            if ((*root)->right->left != NULL) 
            {   
                printf("a\n");
                rlheight = findheight(((*root)->right)->left, 0);
            }
            
            if ( (*root)->right->right != NULL) 
            {
                printf("b\n");
                rrheight = findheight(((*root)->right)->right, 0);
            }

            if ((rlheight - rrheight) > 0) {
                printf("6 \n");
                rlrotate(root);
            } else {
                printf("7 \n");
                rrrotate(root);
            }       

            printdetails(*root);
            balance(root);
        } 
    }
}



int main()
{
    struct node *root = NULL;
    
    int a[] = {15,20,24,10,13,7,30,36,25};
    int len = sizeof(a)/sizeof(a[0]);
    int i;

    for (i = 0; i < len ; i++){
        insert(&root, a[i]);
        printf("Input : %d\n", a[i]);
        printf("height : %d\n", findheight(root, 0));
        balance(&root);
        printdetails(root);
    }
    
    printdetails(root);
    //rightrotate(&root);
    //printdetails(root);

    printf("height : %d", findheight(root, 0));

    printf("\n");
    balance(&root);
    printdetails(root);

}
