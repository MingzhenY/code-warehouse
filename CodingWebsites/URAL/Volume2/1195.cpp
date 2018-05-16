#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define C(x) (a[x]==3-player)
#define T(a,b,c) (C(a)&&C(b)&&C(c)) 
using namespace std;
int F(char *a,int k,char player){
	//Lose
	if(T(0,1,2)||T(3,4,5)||T(6,7,8)||T(0,3,6)||
		T(1,4,7)||T(2,5,8)||T(0,4,8)||T(2,4,6)) return -1;//Lose
	if(k==9) return 0;//Tie
	int A=3;
	for(int i=0;i<9;++i){
		if(a[i]==3){
			a[i]=player;
			int D=F(a,k+1,3-player);
			A=min(A,D);
			a[i]=3;
		}
	}
	//printf("%c%c%c\n%c%c%c\n%c%c%c\n",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8]);
	//printf("A=%d\n",-A);
	return -A;
}
char a[3][4];
char str[10];
int main(void)
{freopen("1195.txt","r",stdin); 
	
		scanf("%s%s%s",a[0],a[1],a[2]);
		strcpy(str,a[0]);strcat(str,a[1]);strcat(str,a[2]);
		for(int i=0;i<9;++i){
			switch(str[i]){
				case 'X':str[i]=1;break;
				case 'O':str[i]=2;break;
				default:str[i]=3;break;
			}
		}
		int D=F(str,6,(char)1);
		
		if(~D){
			if(D) printf("Crosses win\n");
			else printf("Draw\n");
		}
		else printf("Ouths win\n");
	
return 0;
}








