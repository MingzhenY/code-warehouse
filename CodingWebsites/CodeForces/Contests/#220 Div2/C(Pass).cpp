#include <cstdlib>
#include <iostream>

using namespace std;
int N,M,i,j,L=0,i1,j1;
bool is(int,int,int);
int Move(int,int);
char B[1000][1000];
int  D[1000][1000];
int main()
{       

cin>>N>>M;
int temp=0;
for(i=0;i<N;i++)  for(j=0;j<M;j++) {D[i][j]=-1;cin>>B[i][j];if(B[i][j]=='D') temp++;}

if(temp==0) {cout<<"Poor Dima!\n";}
else
{int t=0,MOV=0;
for(i=0;i<N;i++)  for(j=0;j<M;j++) 
   {if(L) break;
   if(B[i][j]=='D'&&D[i][j]==-1) {t=Move(i,j);MOV=MOV>t?MOV:t ;}
//   for(i1=0;i1<N;i1++)  for(j1=0;j1<M;j1++) {
 //  if(B[i][j]=='D'+1||B[i][j]=='I'+1||B[i][j]=='N'+1||B[i][j]=='A'+1)   B[i][j]--;
//   									}
   }
if(L||MOV==0) {
              if(L) cout<<"Poor Inna!\n";
              else if(MOV==0)  cout<<"Poor Dima!\n";
              }

else cout<<MOV; 
   
}
               
//    system("PAUSE");
    return 0;
}
bool is(int x,int y,int n)
{
if(x<0||x>=N) return 0;
if(y<0||y>=M) return 0;
if(B[x][y]==n||B[x][y]==n+1||B[x][y]==n+2) return 1;
else return 0;
}

int Move(int x,int y)
{int temp=0,count=0,MOV=0;// printf("\n   头测试：当前坐标（%d，%d）,当前值：%c",x,y,B[x][y]);system("PAUSE");

if(D[x][y]>=0) return D[x][y];


if(B[x][y]=='D'||B[x][y]=='D'+1)
{
if(B[x][y]=='D'+1) L=1; if(L) return 0;B[x][y]='D'+1;
if(is(x-1,y,'I')) {count=Move(x-1,y);if(L) return 0;D[x-1][y]=count; MOV=MOV>count?MOV:count;}  
if(is(x,y+1,'I')) {count=Move(x,y+1);if(L) return 0;D[x][y+1]=count; MOV=MOV>count?MOV:count;} 
if(is(x+1,y,'I')) {count=Move(x+1,y);if(L) return 0;D[x+1][y]=count; MOV=MOV>count?MOV:count;} 
if(is(x,y-1,'I')) {count=Move(x,y-1);if(L) return 0;D[x][y-1]=count; MOV=MOV>count?MOV:count;} 
 //printf("\n测试：当前坐标（%d，%d）,当前值：%c,MOV=%d",x,y,B[x][y],MOV);
B[x][y]='D'; 
return MOV;
}

temp=0;count=0;MOV=0;
if(B[x][y]=='I'||B[x][y]=='I'+1)
{
if(B[x][y]=='I'+1) L=1; if(L) return 0;B[x][y]='I'+1;
if(is(x-1,y,'M')) {count=Move(x-1,y);if(L) return 0;D[x-1][y]=count; MOV=MOV>count?MOV:count;}  
if(is(x,y+1,'M')) {count=Move(x,y+1);if(L) return 0;D[x][y+1]=count; MOV=MOV>count?MOV:count;} 
if(is(x+1,y,'M')) {count=Move(x+1,y);if(L) return 0;D[x+1][y]=count; MOV=MOV>count?MOV:count;} 
if(is(x,y-1,'M')) {count=Move(x,y-1);if(L) return 0;D[x][y-1]=count; MOV=MOV>count?MOV:count;} 
B[x][y]='I';//printf("\n测试：当前坐标（%d，%d）,当前值：%c,MOV=%d",x,y,B[x][y],MOV);
return MOV;
}

temp=0;count=0;MOV=0;
if(B[x][y]=='M'||B[x][y]=='M'+1)
{
if(B[x][y]=='M'+1) L=1; if(L) return 0;B[x][y]='M'+1;
if(is(x-1,y,'A')) {count=Move(x-1,y);if(L) return 0;D[x-1][y]=count; MOV=MOV>count?MOV:count;} 
if(is(x,y+1,'A')) {count=Move(x,y+1);if(L) return 0;D[x][y+1]=count; MOV=MOV>count?MOV:count;} 
if(is(x+1,y,'A')) {count=Move(x+1,y);if(L) return 0;D[x+1][y]=count; MOV=MOV>count?MOV:count;} 
if(is(x,y-1,'A')) {count=Move(x,y-1);if(L) return 0;D[x][y-1]=count; MOV=MOV>count?MOV:count;} 
B[x][y]='M';//printf("\n测试：当前坐标（%d，%d）,当前值：%c,MOV=%d",x,y,B[x][y],MOV);
return MOV;
}

temp=0;count=0;MOV=0;
if(B[x][y]=='A'||B[x][y]=='A'+1)
{
B[x][y]='A'+1;
if(is(x-1,y,'D')) {count=Move(x-1,y);if(L) return 0;D[x-1][y]=count; MOV=MOV>count?MOV:count;} 
if(is(x,y+1,'D')) {count=Move(x,y+1);if(L) return 0;D[x][y+1]=count; MOV=MOV>count?MOV:count;} 
if(is(x+1,y,'D')) {count=Move(x+1,y);if(L) return 0;D[x+1][y]=count; MOV=MOV>count?MOV:count;} 
if(is(x,y-1,'D')) {count=Move(x,y-1);if(L) return 0;D[x][y-1]=count; MOV=MOV>count?MOV:count;} 
B[x][y]='A'; //printf("\n测试：当前坐标（%d，%d）,当前值：%c,MOV=%d",x,y,B[x][y],MOV);
return MOV+1;
}
//printf("\n测试：当前坐标（%d，%d）,当前值：%c,MOV=%d",x,y,B[x][y],MOV);
return 0;
}
