#include <stdio.h>
#include <iostream>

using namespace std;

int bob(string st){
    int b=0,o=0;

    for(int j=0;j<3;j++){
        if(st[j]=='b'){
            b++;
        }else if(st[j]=='o'){
            o++;
        }

    }

    if (b>=2 && o>=1){
        return 1;
    } else {
        return 0;
    }
}

int checkbob(string st1, string st2, int i, int f){
    if(i<3){
        if(bob(st1)){ 
            return 1;
        }else if(bob(st2)){
            return 1;
        }else if(f==1){
            char ch = st1[i];
            st1[i]=st2[i];
            st2[i]=ch;
            return checkbob(st1,st2,i++,0); 
        }else{
            i++;
            return checkbob(st1,st2,i,1);
        }
    }else{
        return 0;
    }
    
}

int main(){

    int n;
	cin>>n;
	string st1,st2,st3;
	
    int b=2,o=1;
    int flag;

	for (int i=0;i<n;i++){
        cin>>st1;
		cin>>st2;
        //cout<<  "st1[0] is"<< st1[0];
        string st[6];

        flag = checkbob(st1,st2,0,1);

		if(flag==1){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
        b=0;
        o=0;
        
	}

    

    return 0;
}