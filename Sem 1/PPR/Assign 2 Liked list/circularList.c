#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};


void printList(struct node ** head){
    printf("List is as follows\n");
    
    struct node * tmp = *head;
    int flag = 1;

    while (tmp != NULL ) {
        
        if (flag == 0 && tmp == *head) {
            break;
        }

        if (tmp == *head) {
            flag--;
        }

        printf("%d   ", tmp->data);
        tmp = tmp->next;
    }

    printf("\n");
}

void addfirst(struct node ** head, int info){
    struct node * tmp = (struct node *) malloc(sizeof(struct node));
    tmp->data = info;

    if (*head == NULL) {
        tmp->next = tmp;
        *head = tmp;
    }else {
        struct node * last = NULL;
        last = *head;

        while (last->next != *head){
            last = last->next;
        }
        
        tmp->next = *head;
        *head = tmp;
        last->next = *head;
    }
    
}

void addEnd(struct node ** head, int info) {
    struct node * tmp = (struct node *) malloc(sizeof(struct node));
    tmp->data = info;
    tmp->next = NULL;

    if (*head == NULL) {
        *head = tmp;
    }else {
        struct node * p = *head;
        while (p->next != NULL) {
            p = p->next;
        }

        p->next = tmp;
    }
}

void addAfter(struct node ** head, int posData, int info){
    struct node * tmp = (struct node *) malloc(sizeof(struct node));
    tmp->data = info;

    struct node * p = *head;
    int flag = 0;
    while (p->data != posData) {

        if (p->next == NULL) {
            printf("No element found with data : %d\n", posData);
            flag = 1;
            break;
        }else{
            p = p->next;
        }
    }
    
    if (flag == 0) {
        tmp->next = p->next;
        p->next = tmp;
    }

}

void addBefore(struct node ** head, int posData, int info){
    struct node * tmp = (struct node *) malloc(sizeof(struct node));
    tmp->data = info;

    struct node * p = *head;
    if (*head == NULL) {
        printf("Sorry List is empty\n");
    }else{
        if ((*head)->data == posData) {
            addfirst(head,info);
        }else{
            int flag = 0;
            while (p->next->data != posData) {    
                p = p->next;
                if (p == NULL) {
                    printf("No element found with data : %d\n", posData);
                    flag = 1;
                    break;
                }
            }

            if (flag == 0) {
                tmp->next = p->next;
                p->next = tmp;
            }
        }
    }
}

void deleteFirst(struct node ** head){
    struct node * tmp;
    tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

void deleteLast(struct node ** head) {
    struct node * tmp1 = NULL;
    struct node * tmp2 = NULL;
    tmp1 = *head;
    tmp2 = NULL;
    if (tmp1 == NULL) {
        printf("Sorry List is already Empty.\n");
        return;
    } 

    while (tmp1->next != NULL) {
        tmp2 = tmp1;
        tmp1 = tmp1->next;
    }

    tmp2->next = NULL;
    free(tmp1);
}

void delete(struct node ** head, int inData){
    struct node * tmp = NULL;
    struct node * tmp1 = NULL;
    tmp = *head;

    if (*head == NULL) {
        printf("List is Empty");
        return;
    } else if ((*head)->data == inData) {
        *head = (*head)->next;
        free(tmp);
    } else {
        
        while (tmp != NULL && tmp->data != inData ) {
            tmp1 = tmp;
            tmp = tmp->next;
        }
        
        if (tmp == NULL){
            printf("Sorry %d element not found.\n", inData);
        } else {
            tmp1->next = tmp->next;
            free(tmp);
        }
    }
}

int findEvenPosSum(struct node ** head){
    struct node * tmp = *head;
    int sum = 0;
    int flag = 1;

    while (tmp != NULL) {
        
        if (flag == 0 && (tmp == *head || tmp->next == *head)) {
            break;
        }
        
        if (tmp == *head) {
            flag--;
            tmp = tmp->next;

        } else {
            tmp = tmp->next;
            if (tmp->next == *head) {
                break;
            }
            tmp = tmp->next;
        }

        sum += tmp->data;
        
    }

    return sum;

}

void AllNelements(struct node ** head, int g){
    struct node * tmp = NULL;
    tmp = *head;
    int flag = 1;

    while (tmp != *head || flag == 1) {
        if (tmp == *head) {
            flag = 0;
        }

        printf("%d   ",tmp->data);
        
        int i;
        for (i = 0; i < g; i ++) {
            tmp = tmp->next;
        }
    }
}

int main()
{               
    struct node * head = NULL;

    addfirst(&head, 22);
    addfirst(&head, 20);
    addfirst(&head, 19);
    addfirst(&head, 17);
    addfirst(&head, 18);
    addfirst(&head, 15);
    addfirst(&head, 12);

    printList(&head);

    // int sum = findEvenPosSum(&head);
    // printf("Sum is : %d", sum);

    AllNelements(&head,3);

    return 0;
}
