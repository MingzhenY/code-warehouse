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

char maze[500][500];
char te[500][500];int n,m,k,i,j;int mov=1;
int test(int,int);
void move(int,int);
int main(void)
{
scanf("%d %d %d",&n,&m,&k);//cout<<"\n"<<n<<" "<<m<<" "<<k;
for(i=0;i<n;i++) {for(j=0;j<m;j++) cin>>maze[i][j];}

//for(i=0;i<n;i++) { for(j=0;j<m;j++) {printf("%c",maze[i][j]);}  printf("\n");}
for(i=0;i<n;i++) for(j=0;j<m;j++) {te[i][j]=test(i,j);if(te[i][j]==3&&maze[i][j]=='.') move(i,j);}

for(i=0;i<n;i++) for(j=0;j<m;j++) if(te[i][j]<0&&te[i][j]>=-k) maze[i][j]='X';

//for(i=0;i<n;i++) { for(j=0;j<m;j++) {printf("%c",maze[i][j]);}  printf("\n");}
for(i=0;i<n;i++) { for(j=0;j<m;j++) {printf("%d ",te[i][j]);}  printf("\n");}
return 0;
}
int test(int i,int j)
{int count=4;
if(i>0&&maze[i-1][j]=='.') count--;
if(j>0&&maze[i][j-1]=='.') count--;
if(i<n-1&&maze[i+1][j]=='.') count--;
if(j<m-1&&maze[i][j+1]=='.') count--;
return count;


}
void move(int i,int j)
{te[i][j]=-mov;mov++;
if(i>0&&maze[i-1][j]=='.'&&te[i-1][j]>=0) move(i-1,j);
if(&j>0&&maze[i][j-1]=='.'&&te[i][j-1]>=0) move(i,j-1);
if(i<n-1&&maze[i+1][j]=='.'&&te[i+1][j]>=0) move(i+1,j);
if(j<m-1&&maze[i][j+1]=='.'&&te[i][j+1]>=0) move(i,j+1);
return;
}
