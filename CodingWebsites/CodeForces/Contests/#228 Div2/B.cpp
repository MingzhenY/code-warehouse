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
#include <fstream>
#define  inf  0x3fffffff
using namespace std;
int max(int a,int b) {return a>b?a:b;}
int min(int a,int b) {return a<b?a:b;}
int zdgys(unsigned int a,unsigned int b){while(a){if(a<b){a=a^b;b=a^b;a=a^b;}  a=a%b;}return (int)b;}
int zxgbs(int a,int b){return (a*b)/zdgys(a,b);}
int N,i,j;char board[100][100];int n_th;
int is_sharp(int,int);
bool is_cross(int,int);
int dx[5]={-1,0,0,0,1};
int dy[5]={0,-1,0,1,0};
int Dfs(int);
//ifstream fin("B.txt"); 
int main(void)
{cin>>N; int count=0;

for(i=0;i<N;i++) {for(j=0;j<N;j++) {cin>>board[i][j];if(board[i][j]=='#') count++;  }}
//cout<<is_cross(1,1); 
if(count%5!=0) {cout<<"NO";return 0;}
if(count==0) {cout<<"YES";return 0;}
n_th=count/5;

//cout<<n_th<<"   "<<n_now<<endl;
if(Dfs(0)==-1) {cout<<"YES";return 0;}
else {cout<<"NO";return 0;}

return 0;
}
int is_sharp(int x,int y)
{
if(x<0||x>=N) return 0;
if(y<0||y>=N) return 0;
if(board[x][y]=='#') return 1;
return 0;
}
bool is_cross(int x,int y)
{int Count=0;
for(int i=0;i<5;i++) {int nx=x+dx[i],ny=y+dy[i];
if(nx<0||nx>=N) return 0;
if(ny<0||ny>=N) return 0;
	if(is_sharp(nx,ny)==1) Count++;
	}
if(Count==5) return 1;
else return 0;
}
int Dfs(int k)
{
if(k==n_th) return -1;
for(int i=1;i<N-1;i++) for(int j=1;j<N-1;j++) if(is_cross(i,j))
{
for(int i1=0;i1<5;i1++) {int nx=i+dx[i1],ny=j+dy[i1];board[nx][ny]='#'+1;}
int D=Dfs(k+1);if(D==-1) return -1;
for(int i1=0;i1<5;i1++) {int nx=i+dx[i1],ny=j+dy[i1];board[nx][ny]='#';}
}
return 0;
}
