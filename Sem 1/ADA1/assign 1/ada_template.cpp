#include<iostream>

#define MAX_SIZE 100
using namespace std;

template<typename T>
class mystack{
    private:
        int top=-1;
        T data[MAX_SIZE];

    public:
        T getData(){
            return data[top];
        }

        bool isEmpty(){
            if(top==-1){ return 1; }
            else { return 0; }
        }

        void push(T d){
            this->data[++top] = d;
        }

        T pop(){
            if(!this->isEmpty()){
                return data[top];
                top--;
            }else{
                cout << "Error";
                exit(1);
            }
        }

        T peak(){
            if(!this->isEmpty()){
                return data[top];
            }else{
                cout << "Error";
            }
        }

};

int main(){
    mystack<int> st;

    cout << st.isEmpty() << endl;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.peak();

    cout << st.getData() <<endl;
}