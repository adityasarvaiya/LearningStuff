#include <iostream>

using namespace std;

struct node{
    struct node *left;
    int data;
    int c;
    int left_nodes;
    struct node *right;
};

struct node * createnode(int data, int left_nodes)
{
    struct node *root = (struct node*) malloc(sizeof(struct node));
    root->left = NULL;
    root->right = NULL;
    root->data = data;
    root->c = left_nodes;
    root->left_nodes = left_nodes;
    
    return root;
}

void insert(struct node **root, int data, int left_nodes) 
{
    if ((*root) == NULL) {
        *root = createnode(data, left_nodes);
    } else if (data != (*root)->data) {
        if (data < (*root)->data) {
            insert(&((*root)->left), data, (*root)->left_nodes);
            (*root)->left_nodes += 1;
        } else {
            insert(&((*root)->right), data, (*root)->left_nodes + 1);
        }
    }
}

void prnt_inorder(struct node *root)
{
    if (root != NULL) {
        prnt_inorder(root->left);
        cout << root->data << "  " << root->c << "  " << root->left_nodes << endl;
        prnt_inorder(root->right);
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {10, 0, 6, 5, 4, 7, 1, 3, 2};
    // int a[] = {12, 10, 11};
    // int a[] = {10, 9, 8, 7, 6, 5, 4, 3};
    int n = sizeof(a) / sizeof(a[0]);
    int i;
    struct node *root = NULL;

    for (i = n-1; i >= 0; --i) {
        insert(&root, a[i], 0);
    }

    prnt_inorder(root);


    return 0;
}
