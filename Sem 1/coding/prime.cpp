#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,i;
    cin >> n;    

    for (i = 0; i < n; i++) {
        int s,e,j;
        cin >> s; 
        cin >> e;
        cout << "s: " << s << "e: " << e << endl;
        int size = e-s;
        int prime[size];
        for (j = 0; j < size; j++) {
            prime[j] = 1;
        }

        for (j = s; j <= ((e-s)/2); j++) {

            int m = ;
            while (j * m <= e) {
                int in = (j * m) - s;
                cout << "in : " << in  << endl;
                prime[in] = 0;
                ++m;
            }
        }

        for (j = 0; j < size; j++) {
            if (prime[j] == 1) {
                cout << j + s << endl;
            }
        }

    }

    return 0;
}
