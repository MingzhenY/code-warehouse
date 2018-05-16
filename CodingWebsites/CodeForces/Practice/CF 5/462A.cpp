#include <iostream>
#include <cstdio>
using namespace std;
char a[100][101];
int n; 
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
bool check(int i,int j){
	int t=1;
	for(int k=0;k<4;k++){
		int nx=i+dx[k],ny=j+dy[k];
		if(nx>=0&&nx<n&&ny>=0&&ny<n){
			t+=a[nx][ny]=='o';
		}
	}
	return t&1;
}
int main(void)
{
	freopen("462A.txt","r",stdin); 
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++) scanf("%s",a[i]);
		int t=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				t+=check(i,j);
			}
		}
		if(t==n*n) printf("YES\n");
		else printf("NO\n");
	}
return 0;
}














