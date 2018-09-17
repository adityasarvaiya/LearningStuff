#include <stdio.h>

typedef struct node {
    char data;
    node *next;
};

node *createNode() 
{
    node *tmp = (node *) malloc(sizeof(node));
    return tmp;
}

void findNonRepeating(node ** head) 
{   
    node * curr = *head;
    node * nonRep = NULL;
    while (curr != NULL) {
        if (nonRep == NULL) {
            nonRep = curr;
        } else if (curr->data == nonRep->data) {
            printf()
        }

        curr = curr->next;
    }
}

int main () {
    int T;
    scanf("%d",&T);

    int i;
    int j;
    int n;
    for (i = 0; i < T; i++) {
        node * head = NULL;
        scanf("%d",&n);
        for (j = 0; j < n; j++) {
            char input;
            scanf("%d", &input);

            node *curr = createNode();
            curr->data = input;
            curr->next = NULL;

            if (head == NULL) {
                head = curr;
            } else {
                node *tmp = head;
                
                while (tmp->next != NULL) {
                    tmp = tmp->next;
                }

                tmp-next = curr;
            }

            findNonRepeating(&head);
        }
    }
}