#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void change (int x , int y, string *str, int i, int j) {
    if ( (i >= 0 && j >= 0) && (i < x && j < y) ) {
        if (str[i][j] ==  'x') {
            str[i][j] = '0';
            change(x, y, str, i-1, j);
            change(x, y, str, i, j-1);
            change(x, y, str, i+1, j);
            change(x, y, str, i, j+1);
        }
    }
}

int main(int argc, char const *argv[])
{
    int x,y,i,j;
    cin >> x >> y;

    string str[x];

    for (i = 0; i < x; i++) {
        cin >> str[i];
    }

    int count = 0;
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            if (str[i][j] ==  'x') {
                change(x, y, str, i, j);
                j--;
                count++;
            }
        }
    }   

    cout << endl << "shapes : " << count << endl;

    return 0;
}
