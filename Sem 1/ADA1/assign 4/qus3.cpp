#include <stdio.h>
#include <iostream>

using namespace std;

struct node {
    int data;
    struct node *next;
};

class priorityQ {

    private:
        int priority;
        struct node *head = NULL;

    public:
        priorityQ(int prio = 0){
            priority = prio;
        }

        struct node * createNode ()
        {
            struct node *tmp = (struct node *) malloc(sizeof(struct node));

            return tmp; 
        }

        void printQ() 
        {
            struct node * curr = head;

            while (curr) {
                printf("%d  ", curr->data);
                curr = curr->next;
            }
            printf("\n");
        }

        void pqinsert (int data)
        {
            struct node * curr = createNode();
            curr->data = data;

            if (head == NULL) {
                head = curr;
            } else {
                struct node *tmp = head;
                struct node *prev = NULL;

                while (tmp != NULL) {
                    
                    if (priority == 0) {
                        if (data > tmp->data) {
                            if (prev == NULL){
                                curr->next = tmp;
                                head = curr;    
                            } else {
                                prev->next = curr;
                                curr->next = tmp;
                            }

                            break;
                        } else if (tmp->next == NULL) {
                            tmp->next = curr;
                            curr->next = NULL;
                        }
                    } else {
                        if (data < tmp->data) {
                            if (prev == NULL){
                                curr->next = tmp;
                                head = curr;    
                            } else {
                                prev->next = curr;
                                curr->next = tmp;
                            }

                            break;
                        } else if (tmp->next == NULL) {
                            tmp->next = curr;
                            curr->next = NULL;
                        }
                    }
                    
                    prev = tmp;
                    tmp = tmp->next;
                } 
            }
        }


        int minpop()
        {
            int returnData;
            struct node *tmp = NULL;
            struct node *prev = NULL;
            
            if(head->next == NULL){
                tmp = head;
                head = NULL;
                returnData = tmp->data;
                free(tmp);
            } else if (priority == 0) {
            
                tmp = head;
                prev = head;

                while (tmp->next != NULL) {
                    prev = tmp;
                    tmp = tmp->next;
                }
                returnData = tmp->data;
                prev->next = NULL;
                free(tmp);
            } else {
                returnData = head->data;
                tmp = head;
                head = head->next;
                free(tmp);
            }

            

            return returnData;
        }

        int maxpop()
        {
            int returnData;
            struct node *tmp = NULL;
            struct node *prev = NULL;
            
            if(head->next == NULL){
                tmp = head;
                head = NULL;
                returnData = tmp->data;
                free(tmp);
            } else if (priority != 0) {
            
                tmp = head;
                prev = head;

                while (tmp->next != NULL) {
                    prev = tmp;
                    tmp = tmp->next;
                }
                returnData = tmp->data;
                prev->next = NULL;
                free(tmp);
            } else {
                returnData = head->data;
                tmp = head;
                head = head->next;
                free(tmp);
            }

            return returnData;
        }
        
};

int main()
{
    // pass q(0) OR q for descending order : High value = High Priority  
    // pass q(1)      for Ascending  order : Low value  = High Priority  
    priorityQ q(1);
    q.pqinsert(10);
    q.pqinsert(40);
    q.pqinsert(30);
    q.pqinsert(60);
    q.pqinsert(20);

    q.printQ();

    printf("max : %d  ::  min : %d\n", q.maxpop(), q.minpop());
    return 0;
}
