#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int findfirst(char str[], int j, int hash[], char in) {
    int i,f = 0;

    if (hash[in - 'a'] == 1) {
        hash[in - 'a'] = 2;
    } else if (hash[in - 'a'] == 0) {
        hash[in - 'a'] = 1;
        f = 1;
    }

    for (i = 0; i < j; i++) {
        //printf("\n str[i] : %c \n", str[i]);
        if (hash[str[i] - 'a'] == 1) {
            return i;
        }
    }    
    
    if (f == 1) {
        return j;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int i,j,n;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        int len,tmp;
        scanf("%d", &len);
        char str[len];
        int hash[26];
        
        for ( tmp = 0; tmp < 26; tmp ++) {
            hash[tmp] = 0;
        }

        for (j = 0; j < len; j++) {
            char in;
            scanf("%c", &in);
            if (in == ' ' || in == '\n') {
                j--;
                continue;
            }

            //printf("in : %c\n", in);
            str[j] = in;
        
            int out = findfirst(str, j, hash, in);
            if (out == -1) {
                printf("-1 ");
            } else {
                printf("%c ", str[out]);   
            }

        }
        
    }

    return 0;
}
