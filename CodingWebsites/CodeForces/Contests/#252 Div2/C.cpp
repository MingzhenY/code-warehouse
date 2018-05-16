#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int m,n,k;
struct A{
	int x;int y;
};
A f(int n){
	A temp;
	int x=n/m+1,y=n%m+1;
	if((x&1)==0) y=m-y+1; 
	temp.x=x;temp.y=y;
	return temp;
}

int main(void)
{
	freopen("C.txt","r",stdin); 
	while(cin>>n>>m>>k){
		//for(int i=0;i<11;i++) OUT3(i,f(i).x,f(i).y);
		int cur=0;
		for(int i=0;i<k-1;i++){
			A temp1=f(cur++),temp2=f(cur++);
			printf("%d %d %d %d %d\n",2,temp1.x,temp1.y,temp2.x,temp2.y);
		}
		printf("%d ",n*m-(k-1)*2);
		for(;cur<n*m;cur++){
			A temp=f(cur);
			printf("%d %d ",temp.x,temp.y); 
		}
		printf("\n");
	}
return 0;
}














