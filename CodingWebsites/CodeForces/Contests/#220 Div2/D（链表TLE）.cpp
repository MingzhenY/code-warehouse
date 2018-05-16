/*
	Name: D.cpp
	Author: Zearot
	Date: 24/12/13 07:25
	Description: 
*/
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

using namespace std;
int max(int a,int b) {return a>b?a:b;}
int min(int a,int b) {return a<b?a:b;}
int a[1000000];
int S[1000000];
int D[1000000][2];
int Last,First,Count=0,Cur=0;
int n,m,i,j,temp;

void add(int);
void remove(int);
void Move(int);



int main(void)
{
cin>>n>>m;
for(i=0;i<m;i++) {scanf("%d",&a[i]);}
for(i=0;i<n;i++) {scanf("%d",&temp);Move(temp);}

if(Cur==0) cout<<"Poor stack!";
else{int now=First;
	while(1)   {
			cout<<S[now];
			if(now==Last) break;
			now=D[now][1];
				   }
	}
return 0;
}

void add(int t)//Cur
{
if(Cur==0){
S[Count]=t;
D[Count][0]=-1;
D[Count][1]=-1;
First=Count;
Last=Count;
		}
else{
S[Count]=t;
D[Last][1]=Count;
D[Count][0]=Last;
D[Count][1]=-1;
Last=Count;
    }
Count++;Cur++;
}

void remove(int n)
{

if(n!=First) D[D[n][0]][1]=D[n][1];  else if(Cur>1) {First=D[n][1];D[First][0]=-1;}
if(n!=Last)  D[D[n][1]][0]=D[n][0];  else if(Cur>1) {Last=D[n][0];D[Last][1]=-1;}
Cur--;
}

void Move(int t)
{
if(t==1||t==0) add(t);
else{int now1=First,count1=1,count2=0;int _Cur=Cur;
for(int i=0;i<_Cur;i++){
		if(count2>=m) break;
		if(count1>=a[count2]) {remove(now1);count2++;}
		count1++;now1=D[now1][1];
                      }
    }

}


















