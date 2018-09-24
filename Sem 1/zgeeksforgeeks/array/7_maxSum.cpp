#include <bits/stdc++.h>
#include<array>

using namespace std;

int main(int argc, char const *argv[])
{
    array<int, 10> a= {1, 20, 2, 10};
    int i;
    
    cout << (end(a) - begin(a)) << endl;
    cout << a.front() << endl;
    cout << a.size() << endl;


    return 0;
}
