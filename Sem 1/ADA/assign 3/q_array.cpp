#include <iostream>
#define MAX_SIZE 100

using namespace std;

template <typename T>
class queue{
    private:
        T a[MAX_SIZE];
        int r = -1;
        int f = -1;

    public:
        int isEmpty() {
            if (f == -1) {
                return 1;
            } else {
                return 0;
            }
        }

        void push(T data) { 
            r = (r + 1) % MAX_SIZE; 
            a[r] = data;

            if (f == -1) {
                f++;
            }
        }

        T pop () {
            if (!isEmpty()){
                T tmp = a[f];
                f = (f + 1) % MAX_SIZE;

                if (f = (r + 1) % MAX_SIZE){
                    f = -1;
                    r = -1;
                }
                return tmp;

            }else{
                cout << "Sorry queue is Empty.";
                exit(0);
            }
        }

        T top () {
            return a[f];
        }
};

int main() {
    queue<int> q;

    q.push(12);
    q.push(22);
    q.push(32);
    q.push(42);

    while ( ! q.isEmpty() ) {
        cout << q.pop() << "  ";
    }

    
}