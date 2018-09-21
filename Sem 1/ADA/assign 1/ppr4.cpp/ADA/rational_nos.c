#include<stdio.h>
#include<stdbool.h>

int gcd(int a, int b){
	return b==0?a:gcd(b, a%b);
}

typedef struct rn{
	int p, q;
	double real;
} rn;

rn reduced(rn x){
	struct rn a;
	int cgcd=gcd(x.p,x.q);
	a.p=x.p/cgcd;
	a.q=x.q/cgcd;
	return a;
}

bool equality(rn x, rn y){
	x = reduced(x);
	y = reduced(y);
	bool res=1;
	if(x.p!=y.p||x.q!=y.q) res=0;
	return res;
}

void inp(int p, int q, rn *a){
	a->p=p;
	a->q=q;
	a->real = (double)p/(double)q;
	return;
}

int main(){
	rn x, y;
	int p, q;
	//x.p=4; x.q=3;
	//y.p=8; y.q=7;
	/*inp(4, 3, &x);
	inp(8, 7, &y);*/
	printf("Enter rational numbers in the format: p q\n");
	printf("X: ");
	scanf("%d %d", &p, &q);
	if(q==0){
		printf("\nDivision y zero not possible!!\n");
		return 0;
	}
	inp(p, q, &x);
	printf("Y: ");
	scanf("%d %d", &p, &q);
	if(q==0){
		printf("\n\nDivision by zero not possible!\n");
		return 0;
	}
	inp(p, q, &y);	
	if(equality(x,y)) printf("X and Y are equal\n");
	else printf("X and Y are not equal\n");
	return 0;
}
