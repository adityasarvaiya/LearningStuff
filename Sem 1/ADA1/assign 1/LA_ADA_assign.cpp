#include <stdio.h>
#include <iostream>
#include <string.h>

#define N 100

using namespace std;

class String{
    private:

    public:
    String(){
       char i[] = new char[N*sizeof(char)];
    }

    char* getInput(string s){
        input = s.c_str();
        return input;
    }

    void putInput(char in[]){
        input = in;
    }



};


int main()
{
    String str1;
    String str2;

    str1.putInput("This is first one.");
    printf("%s", str1.getInput());


    
    return 0;
}
