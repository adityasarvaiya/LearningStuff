#include <iostream>

using namespace std;

// ques is about finding given 2 trees are mirror similar or not.
// I have take binary search tree not a normal tree for the example but checkmirror() method will work for any type of tree.

struct node {
    int data;
    int empty;
};

void insert(struct node ar[],int pos, int data)
{
    if (ar[pos].empty) {
        ar[pos].data = data;
        ar[pos].empty = 0;
    } else {
        if (data < ar[pos].data) { pos = (2 * pos) + 1;}  
        else if (data > ar[pos].data) { pos = (2 * pos) + 2;};

        insert(ar, pos, data);
    }
}

bool search(struct node ar[], int pos, int data)
{
    if (ar[pos].empty) return false;
    if (ar[pos].data == data) return true;
    if (data < ar[pos].data) return search(ar, (2*pos + 1), data);
    if (data > ar[pos].data) return search(ar, (2*pos + 2), data);
}

void printinorder(struct node ar[], int pos)
{
    if (!ar[pos].empty) {
        printinorder(ar, 2*pos + 1);
        printf("%d ", ar[pos].data);
        printinorder(ar, 2*pos + 2);
    }
}

void printpreorder(struct node ar[], int pos)
{
    if (!ar[pos].empty) {
        printf("%d ", ar[pos].data);
        printpreorder(ar, 2*pos + 1);
        printpreorder(ar, 2*pos + 2);
    }
}

void printpostorder(struct node ar[], int pos)
{
    if (!ar[pos].empty) {
        printpostorder(ar, 2*pos + 1);
        printpostorder(ar, 2*pos + 2);
        printf("%d ", ar[pos].data);
    }
}


int main(int argc, char const *argv[])
{
    struct node ar[100];
    int i;

    for (i = 0; i < 100; i++) {
        ar[i].empty = 1;
    }

    insert(&ar[0], 0, 25);
    insert(&ar[0], 0, 10);
    insert(&ar[0], 0, 9);
    insert(&ar[0], 0, 30);
    insert(&ar[0], 0, 28);
    insert(&ar[0], 0, 45);
    insert(&ar[0], 0, 15);

    if (search(&ar[0], 0, 55)) {
        printf("Found\n");
    } else {
        printf("NOT Found\n");
    }

    printinorder(ar,0);
    printf("\n");
    printpreorder(ar,0);
    printf("\n");
    printpostorder(ar,0);
    printf("\n");

    return 0;
}
