#include <stdio.h>

struct node {
    int data;
    int empty;
};

void printheap (struct node *heap, int pos) 
{
    for (int i = 0; i <= pos; i++) {
        printf("%d  ", heap[i].data);
    }

    printf("\n");
}

void heapify(struct node *heap, int pos) 
{
    if (pos > 0) {
        int parent = (pos-1) / 2;
        int left = pos % 2;
        int right = (left + 1) % 2;

        if (heap[parent].data < heap[pos].data) {
            int tmp = heap[parent].data;
            heap[parent].data = heap[pos].data;
            heap[pos].data = tmp;
            heapify(heap, parent);
        }
    } 
}


void reheapify(struct node *heap, int currpos, int pos) 
{
    
    int left = (currpos*2) + 1;
    int right = (currpos*2) + 2;
    int big;

    if (heap[left].empty) {
        return;
    } else if ((heap[left].data > heap[right].data) || heap[right].empty) {
        big = left;
    } else {
        big = right;
    }

    if (heap[big].data > heap[currpos].data) {
        int tmp = heap[big].data;
        heap[big].data = heap[currpos].data;
        heap[currpos].data = tmp;
        reheapify(heap, big, pos);
    }
}


void insert (struct node *heap, int data, int *pos) 
{
    (*pos)++;
    heap[*pos].data = data;
    heap[*pos].empty = 0;
    heapify(heap, *pos);
}



int pop (struct node *heap, int *pos) 
{
    int tmp;
    if (!heap[0].empty) {
        tmp = heap[0].data;
        heap[0].data = heap[*pos].data;
        heap[*pos].data = tmp;

        printf("\n");
        printheap(heap, *pos);

        heap[*pos].empty = 1;
        (*pos)--;

        reheapify(heap, 0, *pos);
    }

    return tmp;
}

int main(int argc, char const *argv[])
{
    struct node heap[100];

    for (int i = 0; i < 100; i++) {
        heap[i].empty = 1;
    }

    int pos = -1;
    insert(heap, 1, &pos);
    printheap(heap, pos);

    insert(heap, 20, &pos);
    printheap(heap, pos);

    insert(heap, 15, &pos);
    printheap(heap, pos);

    insert(heap, 25, &pos);
    printheap(heap, pos);

    insert(heap, 10, &pos);
    printheap(heap, pos);

    insert(heap, 22, &pos);
    printheap(heap, pos);

    insert(heap, 60, &pos);
    printheap(heap, pos);
     
    int out;
    out = pop(heap, &pos);
    printf("largest value : %d  -> ", out);    
    printheap(heap, pos);

    out = pop(heap, &pos);
    printf("largest value : %d  -> ", out);    
    printheap(heap, pos);

    out = pop(heap, &pos);
    printf("largest value : %d  -> ", out);    
    printheap(heap, pos);

    return 0;
}
