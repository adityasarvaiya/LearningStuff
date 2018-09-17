#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node * prev = NULL;
    int data;
    struct node * next = NULL;
};

void addfirst (struct node ** head, int info) {
    struct node * curr = (node *) malloc(sizeof(struct node));
    curr->data = info;

    if (*head == NULL) {
        
    } else {

    }
}

int main() {
    struct node * head = NULL;

    addfirst(&head, 10);
}