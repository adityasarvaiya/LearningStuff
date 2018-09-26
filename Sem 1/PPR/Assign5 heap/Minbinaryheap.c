#include <stdio.h>

struct node {
    int data;
    int empty;
};

void printheap (struct node *heap, int pos) 
{   
    int i;
    for (i = 0; i <= pos; i++) {
        printf("%d  ", heap[i].data);
    }   

    printf("\n");
}

void swap (int *a, int *b) 
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(struct node *heap, int pos) 
{
    if (pos > 0) {
        int parent = (pos - 1) / 2;

        if (heap[parent].data > heap[pos].data) {
            swap(&heap[parent].data, &heap[pos].data);
            heapify(heap, parent);
        }
    }
}

void insert(struct node *heap, int *pos, int data) 
{
    heap[(++(*pos))].data = data;
    heap[*pos].empty = 0;
    heapify(heap, *pos); 

}

void reheapify(struct node *heap, int iter, int pos) 
{
    if (iter <= pos) {
        int left = (2 * iter) + 1;
        int right = left + 1;

        int min;
        
        if (heap[left].empty) {
            return;
        } else if (heap[right].empty || heap[left].data < heap[right].data ) {
            min = left;
        } else {
            min = right;
        }

        if (heap[iter].data > heap[min].data) {
            swap(&heap[iter].data, &heap[min].data);
            reheapify(heap, min, pos);
        }
    }
}

int pop(struct node *heap, int *pos)
{
    swap(&heap[*pos].data, &heap[0].data);
    int tmp = heap[*pos].data;
    heap[*pos].empty = 1;
    (*pos)--;
    
    if (*pos != -1) {
        reheapify(heap, 0, *pos);
    }
}

int main () 
{
    struct node heap[100];
    int i;

    for (i = 0; i < 100; i++) {
        heap[i].empty = 1;
    }

    int pos = -1;
    insert(heap, &pos, 50);
    printheap(heap, pos);

    insert(heap, &pos, 20);
    printheap(heap, pos);

    insert(heap, &pos, 1);
    printheap(heap, pos);

    insert(heap, &pos, 85);
    printheap(heap, pos);

    insert(heap, &pos, 40);
    printheap(heap, pos);

    pop(heap, &pos);
    printheap(heap, pos);

    pop(heap, &pos);
    printheap(heap, pos);

    pop(heap, &pos);
    printheap(heap, pos);
}