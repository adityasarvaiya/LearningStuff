#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,j,i; 
    scanf("%d", &n);

    for (j = 0; j < n; j++) {
        string input;
        int count = 0;

        cin >> input;
        stack<char> mystack;

        for (i = 0; i < input.length(); i++) {
            if (input[i] == '(') {
                mystack.push('(');
            } else if (input[i] == ')') {
                if (!mystack.empty()) {
                    mystack.pop();
                    count += 2;
                }

            }
        }

        printf("%d\n", count);

    }
   


    return 0;
}
