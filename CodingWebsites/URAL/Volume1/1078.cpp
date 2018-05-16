#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
struct S{
	int x,y;//起止坐标 
	int max;//小于它的有多少个 
	int path;
	bool isin(const S&B){
		return x>B.x&&y<B.y;
	}
	
}s[500];
vector<int> List[500];

int N; 
int DFS(int i){
	if(~s[i].max) return s[i].max;
	int ANS=-1;
	if(List[i].size()<1) return 0;
	For(j,List[i].size()) {
		int t=DFS(List[i][j]);
		if(ANS<t) ANS=t,s[i].path=List[i][j];
	}
	return s[i].max=ANS+1; 
}
int ANSI;
int F(int i){
	if(~s[i].path) F(s[i].path);
	printf("%d",i+1);
	if(i==ANSI) printf("\n");
	else printf(" ");
}
int main(void)
{freopen("1078.txt","r",stdin); 
	cin>>N;
	For(i,N) {
		scanf("%d%d",&s[i].x,&s[i].y);
		s[i].max=-1;s[i].path=-1;
		for(int j=0;j<i;j++){
			if(s[i].isin(s[j])) List[j].push_back(i);
			if(s[j].isin(s[i])) List[i].push_back(j);
		}
	}
	For(i,N) {
		DFS(i);
		//OUT2(i,s[i].max);
	}
	int ANS=-1;ANSI=0;
	For(i,N){
		if(~ANS) {
			if(ANS<s[i].max) ANS=s[i].max,ANSI=i;
		}
		else ANS=s[i].max,ANSI=i;
	}
	if(~ANS){
		cout<<ANS+1<<endl;
		F(ANSI);
		cout<<endl;
	}
	else{
		cout<<"1\n1\n"<<endl;
	}
	
	
return 0;
}








