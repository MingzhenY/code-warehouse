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
using namespace std;

struct calendar{
	int Days;//ÌìÊý
	int Mark;
	int D[7][14];
	calendar(){memset(D,0,sizeof(D));}
	void init(){
		memset(D,0,sizeof(D));
		Mark=0;
		Days=0;
	}
	void show(){
		
		int MY=13;int T=0;
		start:
		T=0;
		for(int i=0;i<7;i++){
			if(D[i][MY]<=Days&&D[i][MY]>0) T=1;
		}
		if(!T){
			MY--;goto start;
		}
		int MX=0;
		start2:
		T=0;
		for(int i=0;i<7;i++){
			if(D[i][MX]<=Days&&D[i][MX]>0) T=1;
		}
		if(!T){
			MX++;goto start2;
		}
		
		for(int i=1;i<=7;i++){
			switch(i){
				case 1:printf("mon");break;
				case 2:printf("tue");break;
				case 3:printf("wed");break;
				case 4:printf("thu");break;
				case 5:printf("fri");break;
				case 6:printf("sat");break;
				case 7:printf("sun");break;
			}
			for(int j=MX;j<=MY;j++) {
				if(D[i%7][j]<=Days&&D[i%7][j]>0) {
					if(D[i%7][j]==Mark){
						if(j!=MX) printf(" ");
						printf(" [%2d]",D[i%7][j]);
					}
					else{
						if(Mark+7!=D[i%7][j]&&j!=MX) printf(" ");
						printf("  %2d",D[i%7][j]);
					}
				}
				else if(j!=MY) {
					if(j!=MX)printf("     ");	
					else printf("    ");
				}
			}
			cout<<endl; 
		}	
	}
	
}C;
int year,month,day;
void F(int x,int y,int day){
	//C.show();
	//C.D[x][y]=day;
	y=7;
	//OUT3(x,y,day);
	for(int i=0;i<14;i++){
		C.D[x][i]=day-(y-i)*7;
		//OUT3(x,i,C.D[x][i]);
		if(x){
			for(int j=x+1;j<=7;j++) C.D[j%7][i]=C.D[x][i]+j-x;
			for(int j=x-1;j>=1;j--) C.D[j%7][i]=C.D[x][i]+j-x;	
		}
		else{
			for(int j=1;j<=7;j++){
				C.D[j%7][i]=C.D[x][i]+j-7;
			}
		}
	}
	//OUT3(x,y,C.D[x%7][y]);
	C.Mark=day;
	C.show();
}
int Week(int y,int m,int d)  {
	int ANS=6;
	for(int i=1600;i<y;i++){
		ANS+=365;
		if(i%100==0){
			if(i%400==0) ANS++;
		}
		else if(i%4==0) ANS++;
	}
    int R=0;
    if(y%100==0){
		if(y%400==0) R=1;
	}
	else if(y%4==0) R=1;
	for(int i=1;i<m;i++){
		switch(i){
			case 1:case 3:case 5:case 7:case 8:case 10:case 12:
				ANS+=31;break;
			case 2:ANS+=28+R;break;
			default:ANS+=30;break;
		}
	}
	ANS+=d-1;
	return ANS%7;
} 

int main(void)
{freopen("1201.txt","r",stdin); 
	while(cin>>day>>month>>year){
		int M=Week(year,month,day);
		C.init();
		//D[M][day/7]=day;
		
		switch(month){
			case 2:C.Days=28;break;
			case 1:case 3:case 5:case 7:
			case 8:case 10:case 12:
				C.Days=31;break;
			default:C.Days=30;break;
		}
		if(month==2){
			if(year%100==0){
				if(year%400==0) C.Days=29;
			}
			else if(year%4==0) C.Days=29;
		} 
		F(M,day/7,day);
		//cout<<endl;
	}
return 0;
}








