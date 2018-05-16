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
int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={-1,-1,0,1,1,1,0,-1};
int N,M,x[100000],y[100000],done[100000];//connect[100000];
int is_Volcano(int,int);
int search(int,int,int);
int Search(void);
//void Connect(void);

int main(void)
{
cin>>N>>M;
int i,j;
for(i=0;i<M;i++) {scanf("%d%d",&x[i],&y[i]);done[i]=0;} //»ðÉ½ 

//system("pause");
//Connect();
if(Search()) cout<<-1;
else cout<<2*N-2;

return 0;
}


int search(int x1,int y1,int cur)
{
//cout<<"Begin of search:"<<x1<<" "<<y1<<endl;system("pause");
if(y1==1||x1==N) return 1;
int i,nx,ny,j,RE=0,_cur;done[cur]=1;

for(j=0;j<8;j++){ nx=x1+dx[j]; ny=y1+dy[j]; _cur=is_Volcano(nx,ny);
		if(_cur!=-1&&done[_cur]==0) RE+=search(nx,ny,_cur);
			}
done[cur]=0;
return RE;
}
int Search(void)
{//cout<<"Begin of Search:\n";system("pause");
int i,RE=0; 
for(i=0;i<M;i++) {
				if(x[i]==1&&done[i]==0) RE+=search(x[i],y[i],i);
				if(x[i]!=1&&y[i]==N&&done[i]==0) RE+=search(x[i],y[i],i);
				}
return RE;
} 
int is_Volcano(int x1,int y1)
{
int i;if(x1<1||x1>N||y1<1||y1>N) return -1;
for(i=0;i<M;i++) if(x1==x[i]&&y1==y[i]) return i;
return -1;
}
/*
void Connect(void)
{
int i,j,nx,ny,count;
for(i=0;i<M;i++){count=0;
			for(j=0;j<8;j++){ 
						nx=x[i]+dx[j]; ny=y[i]+dy[j];
						if(is_Volcano(nx,ny)!=-1) count++;
						}
			connect[i]=count;
			}
}*/
