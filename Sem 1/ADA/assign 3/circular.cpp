#include <iostream>

using namespace std;

template <typename T>
class queue {

    private: 
        int front;
        int rare;
        int MAX_SIZE;
        T * q;

    public:
        queue(int size){
            MAX_SIZE = size;
            front = -1;
            rare = -1;
            q = new T[MAX_SIZE];
        }

    public:

        int printq () {
            int tmp = front;
            // cout << endl;
            if (this->empty()) {
                cout << "Queue is Empty." << endl;
            } else if (front == rare) {
                cout << q[front] << endl;
            } else {
                while (1) {   
                    cout << q[tmp] << "    ";
                    
                    if (tmp == rare) {
                        break;
                    } else {
                        tmp = (tmp + 1) % MAX_SIZE;
                    }
                }
            }

            cout << endl << endl;

        }

        int empty () {  
            if (front == -1) {
                return 1;
            } else {
                return 0;
            } 
        }

        void insert (T data) {
            if (this->empty()) {
                front = 0;
                rare = 0;
                q[rare] = data; 
            } else {
                if ( front == ((rare + 1) % MAX_SIZE) ) {
                    cout << "Sorry Queue is Full." << endl;
                } else {
                    rare = (rare + 1) % MAX_SIZE;
                    q[rare] = data;
                }
            }
        }

        T removeq () {
            T tmp;
            if (this->empty()) {
                cout << "Sorry Queue is empty." << endl;
            } else {
                tmp = q[front];
                front = (front + 1) % MAX_SIZE;
            }
            return tmp;
        }

};

template <typename X>
static void remvtest (queue <X> *pq, X * px, bool * pund) 
{
    if (pq->empty()) {
        *pund = true;
    } else {
        *pund = false;
        *px = pq->removeq(); 
    }
}



int main(int argc, char const *argv[])
{   
    queue <int> q(5);
    
    cout << "Adding 10 20 60 30 90 99 : " << endl;

    q.insert(10);
    q.insert(20);
    q.insert(60);
    q.insert(30);
    q.insert(90);
    q.insert(99);

    q.printq();

    cout << endl <<"Remove 4 Elements : ";
    cout << endl << q.removeq();
    cout << endl << q.removeq();
    cout << endl << q.removeq();
    cout << endl << q.removeq();
    cout << endl;
 
    cout << endl <<"After remove : " << endl;
    q.printq();

    cout << "Adding 15 25 : " << endl;

    q.insert(15);
    q.insert(25);
    q.printq();

    int px; 
    bool pund = true;
    queue <int> p(5);

    cout << endl <<"Adding to p : 70 75" << endl;
    p.insert(70);
    p.insert(75);
    p.printq();

    cout << endl << "remvtest(&p, &px, &pund) : " << endl;
    remvtest(&p, &px, &pund);

    cout << "removed item (px)  : " << px << " success flag (pund) : "  << pund << endl;
    return 0;
}
