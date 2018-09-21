#include <iostream>
#include <string> // for string functions
#include <cstring> // for string functions
#include <string.h>

using namespace std;

#define N 100

class String{

    private:
    char* data;


    public:
    String(int n){
        data = new char[n];
    }

    ~String(){
        delete [] data;
    }
0
    void putString(){
        string data1;
        cout << "Enter the string : "<<endl;
        getline(cin, data1);
        strcpy(data, data1.c_str()); 
    }

    char* getString(){
        return data;
    }

    char* concat(String str_obj){
        char* concatinated_string = new char[strlen(data) + strlen(str_obj.getString()) + 1];
        // ONE WAY OF COPING THE DATA
        // strcat(concatinated_string, data);
        // strcat(concatinated_string, str_obj.getString());


        // OTHER WAY OF COPING THE DATA
        int i = 0;
        int j = 0;

        while(data[i] != '\0'){
            concatinated_string[i] = data[i];
            i++;
        }

        while(str_obj.getString()[j] != '\0'){

            concatinated_string[i] = str_obj.getString()[j];
            j++;
            i++;
        }


        // Returning the output
        cout << " strlen : " << strlen(concatinated_string) << endl; 
        return concatinated_string; 
    }
};

int main(){

    int n;
    cout<< "Enter the len: "<<endl;
    cin>> n;
    cin.ignore();

    String s1(n);
    s1.putString();
    cout << s1.getString() << endl;

    String s2(n);
    s2.putString();
    cout << s2.getString() << endl;

    cout << s1.concat(s2);


    return 0;
}
