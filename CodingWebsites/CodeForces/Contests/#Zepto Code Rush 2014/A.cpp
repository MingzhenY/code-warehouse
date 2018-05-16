#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n,x;//2000
int t,h,m;
struct A{
	int h,m;
	void init(int a,int b){
		h=a,m=b;
	}
	bool operator <(const A&B)const{
		return h<B.h;
	}
};
A a[2000];int Na;
A b[2000];int Nb;
 
int main(void)
{
	freopen("A.txt","r",stdin); 
	cin>>n>>x;Na=Nb=0;int X=x;
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&t,&h,&m);
		if(t) a[Na++].init(h,m);
		else b[Nb++].init(h,m);
	}
	sort(a,a+Na);sort(b,b+Nb);
	//for(int i=0;i<Na;i++) printf("%d %d\n",a[i].m,a[i].h);
	//for(int i=0;i<Nb;i++) printf("\t%d %d\n",b[i].m,b[i].h);
	
	int Pa=0,Pb=0;
	int  ANS1=0;
	while(1){
		if(Pa==Pb){//ÄÃA
			if(x>=a[Pa].h&&Pa<Na) x+=a[Pa++].m,ANS1++; 
			else break;
		}
		else{
			if(x>=b[Pb].h&&Pb<Nb) x+=b[Pb++].m,ANS1++;
			else break;
		}
	}
	int ANS2=0;Pa=Pb=0;x=X;
	while(1){
		if(Pa==Pb){//ÄÃB
			if(x>=b[Pb].h&&Pb<Nb) x+=b[Pb++].m,ANS2++; 
			else break;
		}
		else{
			if(x>=a[Pa].h&&Pa<Na) x+=a[Pa++].m,ANS2++;
			else break;
		}
	}
	
	int ANS=max(ANS1,ANS2);
	
	printf("%d\n",ANS);
	
	
	
	
	

		
return 0;
}














