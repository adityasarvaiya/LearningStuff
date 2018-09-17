#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};


void printList(struct node ** head){
    printf("List is as follows\n");
    
    struct node * tmp = *head;
    while (tmp != NULL) {
        printf("%d   ", tmp->data);
        tmp = tmp->next;
    }

    printf("\n");
}

void addfirst(struct node ** head, int info){
    struct node * tmp = (struct node *) malloc(sizeof(struct node));
    tmp->data = info;
    if (*head == NULL) {
        tmp->next = NULL;
    }else {
        tmp->next = *head;
    }

    // tmp->next = *head;
    *head = tmp;
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


void insertionsort(struct node ** head) 
{
    struct node * curr = *head;
    struct node * tmp = *head;

    while (curr != NULL){
        
        tmp = *head;

        while (tmp != curr) {
            
            if (tmp->data > curr->data) {
                int t = tmp->data;
                tmp->data = curr->data;
                curr->data = t;
            }

            tmp = tmp->next;
        }       
        
        curr = curr->next;
    }
}

void reverseList(struct node ** head) {
    struct node * prev = NULL;
    struct node * curr = *head;
    struct node * next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    *head = prev;
}

void reverseListGroup(struct node ** head, int g) {
    int flag = 2;

    struct node * prev = NULL;
    struct node * curr = *head;
    struct node * next = NULL;
    struct node * prevtail = NULL;
    struct node * currtail = NULL;

    while (curr != NULL && curr->next != NULL) {
        int i;
        prev = NULL;
        next = NULL; 

        for (i = 0; i < g; i++) {
            
            if(i==0){
                currtail = curr;
            }

            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;

            if (curr == NULL) {
                break;
            }
        }

        flag--;

        if (currtail == *head) {
            *head = prev;
        }

        if (flag == 0) {
            prevtail->next = prev;
            flag = 1;
        }

        prevtail = currtail;
    }

}

void deleteDuplicate(struct node ** head){
    struct node * curr = *head;
    struct node * prev = NULL;
    struct node * iter = NULL;
    struct node * next = NULL;

    while (curr != NULL) {
        int data = curr->data;
        int flag = 0;
        iter = *head;
        while (iter != curr) {
            if (iter->data == data) {
                prev->next = curr->next;
                flag =1;
                break;
            }

            iter = iter->next;
        }
   
        if (flag == 1) {
            free(curr);
            curr = prev;
        }
        
        prev = curr;
        curr = curr->next;
    }
}

void pairSwap(struct node ** head){
    struct node * curr = *head;
    struct node * tmp = NULL;
    struct node * prev = NULL;

    while (curr != NULL) {
        if (curr->next != NULL) {
            
            tmp = curr->next->next;
            if (prev != NULL) {
                prev->next = curr->next;
            }else{
                *head = curr->next;
            }
            curr->next->next = curr;
            curr->next = tmp;

            prev = curr;
            curr = curr->next;
        }
    }
}

int findMiddle(struct node ** head) {
    struct node * slow = NULL;
    struct node * fast = NULL;

    slow = *head;
    fast = *head;

    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
        if (fast->next == NULL ) {
            break;
        }
        fast = fast->next;
    }

    return slow->data;
}


// struct node * reverse (struct node ** head) 
// {   
//     struct node *tmp; 
//     if (*head != NULL && (*head)->next != NULL) {
//         tmp = reverse((*head)->next);
//         (*head)->next->next = *head;
//     } else {
//         return *head;
//     }

//     return tmp;
// }


int main()
{               
    struct node * head = NULL;

    // addfirst(&head, 40);
    // addfirst(&head, 70);
    // addfirst(&head, 20);
    // addfirst(&head, 50);
    // addEnd(&head, 15);
    // addEnd(&head, 1);
    // addEnd(&head, -1);
    // addEnd(&head, 0);
    // addEnd(&head, 10);
    // addEnd(&head, 99);
    // addEnd(&head, 69);

    // printList(&head);
    // addAfter(&head, 50, 55);
    // addAfter(&head, 60, 65);
    // addAfter(&head, 40, 45);
    // addAfter(&head, 100,11);

    // printList(&head);
    
    // addBefore(&head, 40, 33);
    // addBefore(&head, 55, 53);
    // addBefore(&head, 65, 63);

    // printList(&head);

    // printf("After deletion\n");
    // deleteFirst(&head);
    // deleteFirst(&head);

    // printList(&head);

    // printf("After last deletion\n");

    // deleteLast(&head);
    // deleteLast(&head);

    // printList(&head);
    
    // printf("After particular deletion\n");
    // delete(&head, 45);
    // delete(&head, 30);
    // delete(&head, 60);
    // delete(&head, 55);
    // delete(&head, 100);
    

    // printList(&head);
    // delete(&head, 59);
    
    addfirst(&head, 3);
    addfirst(&head, 5);
    addfirst(&head, 18);
    addfirst(&head, 6);
    addfirst(&head, 20);
    addfirst(&head, 15);
    addfirst(&head, 18);
    addfirst(&head, 20);
    addfirst(&head, 21);

    printList(&head);
   
    
    // insertionsort(&head);
    // printList(&head);

    // reverseList(&head);
    // printList(&head);

    // printf("Reverse by group\n");
    // reverseListGroup(&head,4);
    // printList(&head);

    // deleteDuplicate(&head);
    // printList(&head);

    // printf("After Swapping \n");
    // // pairSwap(&head);
    // // printList(&head); //NOT WORIKING FOR ODD INPUTS

    
    // int mid = findMiddle(&head);
    // printf("\nMid is : %d\n", mid);


    return 0;
}
