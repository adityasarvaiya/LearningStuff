#include<stdio.h>
#include<stdlib.h>

struct chain {
    int value;
    struct chain *next;
};

struct hash {
    int key;
    struct chain *next;
};

void display(struct hash hashtable[], int size)
{
    int i;
    printf("\n\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ->  ", i);
        if (hashtable[i].next != NULL){            
            struct chain *curr = hashtable[i].next;
            while (curr != NULL) {
                printf("%d\t", curr->value);
                curr = curr->next;
            }
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int size, i;
    printf("Enter size: \n");
    scanf("%d", &size);

    struct hash hashtable[size];    

    for (i = 0; i < size; i++) {
        hashtable[i].next = NULL;
    }

    for (i = 0; i < size; i++) 
    {
        int value, index;
        scanf("%d", &value);
        index = value % size;

        struct chain *curr = (struct chain*) malloc(sizeof(struct chain));
        curr->value = value; 
        curr->next = NULL;

        if (hashtable[index].next == NULL) {
            hashtable[index].next = curr;
        } else {
            struct chain *tmp = hashtable[index].next;
            while (tmp->next != NULL) {
                tmp = tmp->next;
            }
            tmp->next = curr;
        }
    }    

    display(hashtable, size);

    return 0;
}

