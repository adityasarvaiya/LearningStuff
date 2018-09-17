#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include<stdlib.h>

#define MAX_SIZE 100

using namespace std;

template <typename T>
class stack {

    private: 
        T a[MAX_SIZE];
        int head;
    
    public:
        stack(){
            head = -1;
        }

        int isEmpty(){
            if (head == -1) {
                return 1;
            } else {
                return 0;
            }
        }
        
        void push(T data){
            ++head;
            a[head] = data;
        }

        T pop(){

            if (this->isEmpty()) {
                cout << "Sorry Stack is empty.";
                exit(0);
            } else {
                T data = a[head];
                --head;
                return data;
            }
            
        }

        T peek(){
            return a[head];
        }

        

};

vector<string> tokenizers(string input)
{
    int i = 0;
    vector<string> tokens;
    
    while (input[i] != '\0'){
        
        int beg = i;

        if (input[i] == '-' && i == 0) {
            beg = i;
            ++i;
            while (input[i] > 47 && input[i] < 58) {
                i++;
            }
            tokens.push_back(input.substr(beg, i));

        }else if (input[i] == '-' && input[i-1] == '('){
            beg = i;
            ++i;
            while (input[i] != ')') { 
                ++i; 
            }

            tokens.push_back(input.substr(beg, i-beg));

        }else if ((input[i] < 48 && input[i] != '\0') || input[i] == 94) {
            // char c = input[i];
            // // cout << "opp is " << input[i] << endl;
            // // cout << "c is " << c << endl;
            // string s = to_string(c);
            tokens.push_back(input.substr(i,1));
            ++i;

        }else {
            if (input[i] != '\0') {
                beg = i;
                i++;

                while (input[i] > 47 && input[i] < 58) {
                    i++;
                }

                tokens.push_back(input.substr(beg, i-beg));
            }
        }
    }

    return tokens;
}


void printVec(vector<string> vec) {
    vector<string>::iterator it;
    
    for (it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " " << endl;
    }
}

void infixToPostfix(vector<string> vec, vector<string> output){
    map <char, int> prec;
    prec.insert(pair <char, int> ('^',1));
    prec.insert(pair <char, int> ('*',2));
    prec.insert(pair <char, int> ('\\',3));
    prec.insert(pair <char, int> ('+',4));
    prec.insert(pair <char, int> ('-',5));

    stack<string> st;
    int j = 0;

    vector<string>::iterator itr;
    cout << "Inside the infix pos    : " ;
    // string output[100];

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i]  << "  ";  
        
        // if (strlen(vec[i]) > 1) {
        //     output[j++] = vec[i];
        // }else if (vec[i] == '(' || vec[i] == '^') {
        //     st.push(vec[i]);
        // }else if(vec[i] == ')') {
        //     while (st.peek() != '(') {
        //         String tmp = st.pop();
        //         output[j++] = tmp;
        //     }
        //     st.pop();
        // }else{
            // switch(vec[i])
            // {
            //     case '*':
            //         if ( st.peek() == '+' || (st.peek() == '-' || st.isEmpty()) ) {
            //             st.push(vec[i]);
            //         }else {
            //             while (!( st.peek() == '+' || (st.peek() == '-' || st.isEmpty()))) {
            //                 string tmp = st.pop();
            //                 output[j++] = tmp;
            //             }
            //             st.push(vec[i]);
            //         }
            //     case '/':
            //         if ( st.peek() == '+' || (st.peek() == '-' || st.isEmpty()) ) {
            //             st.push(vec[i]);
            //         }else {
            //             while (!( st.peek() == '+' || (st.peek() == '-' || st.isEmpty()))) {
            //                 string tmp = st.pop();
            //                 output[j++] = tmp;
            //             }
            //             st.push(vec[i]);
            //         }
            //     case '+':
            //         if ( st.peek() == '(' || st.isEmpty() ) {
            //             st.push(vec[i]);
            //         }else {
            //             while (!(st.peek() == '(' || st.isEmpty()) ) {
            //                 string tmp = st.pop();
            //                 output[j++] = tmp;
            //             }
            //             st.push(vec[i]);
            //         }

            //     case '-':
            //         if ( st.peek() == '(' || st.isEmpty() ) {
            //             st.push(vec[i]);
            //         }else {
            //             string tmp1 = st.peek();
            //             string tmp2 = "(";
            //             while (!( strcmp(tmp1, tmp2) == 0 || st.isEmpty()) ) {
            //                 string tmp = st.pop();
            //                 output[j++] = tmp;
            //             }
            //             st.push(vec[i]);
            //         }
            // }
        // }
    }

}

void convert(vector<string> vec, char converted[]){
    int ch = 65;
    for (int i = 0; i < vec.size(); i++) {
        if ( vec[i].size() > 1) {
            converted[i] = ch++; 
        }else if(isdigit(vec[i][0])){
            converted[i] = ch++;
        }else{
            // cout << "vec is : " << vec[i] << endl;
            converted[i] = vec[i][0];
        }
    }

    for (int i = 0; i < vec.size(); i++){
        cout << converted[i] << "  ";
    }
}

int main() 
{
    stack<string> st;
    string input;
    vector<string> postfix;
    vector<string> vec;
    vector<string> output;

    // st.push("10");
    // st.push("20");
    // st.push("30");
    // st.push("40");

    // cout << "Peek : " << st.peek() << endl;
    // cout << "Pop  : " << st.pop()  << endl;
    // cout << "Peek : " << st.peek() << endl;
    // cout << "Pop  : " << st.pop()  << endl;

    // cout << "Enter the expression : " << endl;
    // getline(cin,input);
    input = "-10+130*(-55)/11";
    cout << "Input is : " << input << endl;

    vec = tokenizers(input);
    printVec(vec);

    char converted[100];
    convert(vec, converted);

    cout << "output ::" << endl;
    infixToPostfix(vec, output);
    printVec(output);


}