
/*
��ʽ�⣺�����������
һ������B��Ϊ��ʱ��ǰһ��������㣬��B=0����������Сֵ�� 
������������N֮ǰ�ﵽ�㣨D<N������һ���������㣬�����������B����Сֵ
�Ҿ��û��и�������������������д���AC�ˡ�  

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





