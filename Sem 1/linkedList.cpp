#include <iostream>

using namespace std;

typedef struct node{
    node * next;
    int data;
}head;

void printList(node * h){
    if(head->next != 0){
        cout << "   >>   " << h->data << endl;
        if(h->next != NULL){
            printList(h->next);
        }
    }else{
        cout << "Linked list is empty." << endl;
    }
}

int main(int argc, char const *argv[])
{
    node head;
    head.next = 0;
    head.data = NULL;
    int n=0;

    cout << "Enter the number of integers in the linked list."<<endl;
    cin >> n;

    node n1[n];

    for(int i = 0; i < n; i++){
        cout << "Enter number " << i << endl;
        if(head.next == NULL){
            cin >> n1[i].data;
            n1[i].next = NULL;
            head.next = &n1[i];  
        }else{
            cin >> n1[i].data;
            n1[i].next = NULL;
            n1[i-1].next = &n1[i];
        }
    }   

    int j = 0;
    printList(head.next);

    // int num1, num2;
    // cout << "Enter 2 numbers to be interchanged." << endl;
    // cin >> num1 >> num2;


    return 0;
}
