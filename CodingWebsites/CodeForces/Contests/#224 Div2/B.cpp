#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define  inf  0x3fffffff
using namespace std;
int max(int a,int b) {return a>b?a:b;}
int min(int a,int b) {return a<b?a:b;}
int zdgys(unsigned int a,unsigned int b){while(a){if(a<b){a=a^b;b=a^b;a=a^b;}  a=a%b;}return (int)b;}
int zxgbs(int a,int b){return (a*b)/zdgys(a,b);}
long long a,b,w,x,c;                //���ȣ������Ҫ�ܽ�һ������������һ��һ������
                                  //��Σ�Ҫ�ö��ַ����ң��ȱ������е� t ���졣ǰ���� t-n ��������ʵ����t-n�Ƿǵݼ��ģ����϶��ֲ��ҵ�Ҫ�� 
						    


long long T(long long);
int main(void)
{
     cin>>a>>b>>w>>x>>c;
	
	if(a>=c) {cout<<0<<endl;return 0;}
	long long t=2000000000000000000;
	long long A=c-a,B=4000000000000000000;//���ҽ��� 
	while(t)
		{
	     if(T(t)>c-a) {B=t;t=(A+B)/2;}
		if(T(t)==c-a) {while(T(t-1)==T(t)) t--;
					cout<<t<<endl;
					return 0;
					}
		if(T(t)<c-a) {A=t;t=(A+B)/2;}
		}
return 0;
}
//��⣺t-ceil(tx/w)>=c-a;
 long long T(long long t)
 {long long n;
		if((t*x-b)%w==0) n=(t*x-b)/w;
		else n=(t*x-b)/w+1;
 return t-n;
 }

