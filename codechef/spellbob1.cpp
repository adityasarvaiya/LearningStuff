#include <iostream>
#include <stdio.h>
#include <set>
#include<bits/stdc++.h>

using namespace std;

int findbob(string st1, string st2, int j, int b, int o){
    if(j<3){
        if((st1[j] != 'b' && st2[j] != 'b') && (st1[j] != 'o' && st2[j] != 'o')){
            return 0;
        
        }else if((st1[j] != 'o' && st2[j] != 'o')){
            return findbob(st1,st2,++j,++b,o);
        
        }else if((st1[j] != 'b' && st2[j] != 'b')){
            return findbob(st1,st2,++j,b,++o);
        
        }else{
            int tm1=j,tm2=b;
            int f = findbob(st1,st2,++j,++b,o);
            if (f==0){
                f = findbob(st1,st2,++tm1,tm2,++o);
                // if(f==0){
                //     cout<<"no"<<endl;
                // }
            }
            return f;
        }
    }else{
        if(o==1 && b==2){
            //cout<<"yes"<<endl;
            return 1;
        }else{
            return 0;
        }
    }

}

int main (){
    int n;
    cin >> n;
    n %= 20000;

    for(int i=0; i<n; i++){
        string st1,st2;
        cin >> st1 >> st2;

        // transform(st1.begin(), st1.end(), st1.begin(), ::tolower);
        // transform(st2.begin(), st2.end(), st2.begin(), ::tolower);

        
        int b=0;
        int o=0;

        int f = findbob(st1,st2,0,b,o);
        if(f==0){
            cout<<"no"<<endl;
        }else{
            cout<<"yes"<<endl;
        }
    }

}