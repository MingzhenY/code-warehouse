
/*
公式题：分两种情况，
一：若在B点为零时，前一个点大于零，则B=0成立，是最小值。 
二：若可以在N之前达到零（D<N）且下一个数大于零，则这种情况下B是最小值
我觉得还有更多的情况，但是这两个写完就AC了。  

*/
#include <iostream>
#include <cstdio>
#include <cmath>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
int N;double A;
int main(void)
{
	freopen("1066.txt","r",stdin);
	while(cin>>N>>A){
		double D=ceil((1+sqrt(1+4*A))/2);
		double a=(D*D+D+A-2)/(1-D);
		double HN=N*N+N*a+N+A-a-2;
		if(D<=N){
			printf("%.2f\n",HN);
			continue;
		}
		a=(N*N+N+A-2)/(1-N);
		HN=N*N+N*a+N+A-a-2;
		if(HN>=2*N+a){
			printf("%.2f\n",HN);
			continue;
		}
	}
return 0;
}





