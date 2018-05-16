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
int N;
int ALL;
struct Block{
	int cell[20][20];
	Block R(int i){
		Block C=*this;
		for(int j=0;j<i;j++) C=C.rotate();
		return C;
	}
	Block rotate(){
		Block C;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				C.cell[i][j]=cell[j][N-i-1];
			}
		}
		return C;
	}
	void show(){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				printf("%d",cell[i][j]);
				if(j==N-1) printf("\n");
				else printf(" ");
			}
		}
	}
	void read(){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				scanf("%d",&cell[i][j]);
				ALL+=cell[i][j];
			}
		}
	} 
}B[6];

struct Cube{
	char cell[20][20][20];
	Cube(){
		memset(cell,-1,sizeof(cell));
	}
	void reset(){
		memset(cell,-1,sizeof(cell));
	}
	bool cross(Block B,int Dir,int Num){
		int T=1;//假设无矛盾		
		//判断有无矛盾 
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				for(int k=0;k<B.cell[i][j];k++){
					switch(Dir){
						case 0:if(~cell[k][i][j]) T=0;break;
						case 1:if(~cell[N-1-k][N-1-i][j]) T=0;break;
						case 2:if(~cell[j][N-1-k][N-1-i]) T=0;break;
						case 3:if(~cell[N-1-i][j][N-1-k]) T=0;break;
						case 4:if(~cell[N-1-i][k][j]) T=0;break;
						case 5:if(~cell[N-1-j][i][k]) T=0;break;
					}
				}
			}
		} 
		if(T){//如果无矛盾，将这个Block加入。 
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					for(int k=0;k<B.cell[i][j];k++){
						switch(Dir){
						case 0:cell[k][i][j]=Num;break;
						case 1:cell[N-1-k][N-1-i][j]=Num;break;
						case 2:cell[j][N-1-k][N-1-i]=Num;break;
						case 3:cell[N-1-i][j][N-1-k]=Num;break;
						case 4:cell[N-1-i][k][j]=Num;break;
						case 5:cell[N-1-j][i][k]=Num;break;
						}
					}
				}
			} 
		}
		return T;
	}
	void show(){
		for(int k=0;k<N;k++){
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					printf("%d",cell[k][i][j]+1);
					if(j==N-1) printf("\n");
					else printf(" ");
				}
			}
		}
	}
}ANS;
int Found;
bool F(vector<int> V){
	Block TB[6];int T1=0,T2=0,T3=0;Cube C;
	vector<int> V1,V2,V3;
	for(int i=0;i<(1<<4);i++){//i的前两位，后两位分别表示旋转次数。 
		for(int j=0;j<6;j++){
			int t=j%2;
			int times=(i>>(2*t))&3;
			TB[j]=B[V[j]].R(times);//旋转 
		}
		C.reset();
		if(C.cross(TB[0],0,V[0])&&C.cross(TB[1],1,V[1])) T1++,V1.push_back(i);
		C.reset();
		if(C.cross(TB[2],2,V[2])&&C.cross(TB[3],3,V[3])) T2++,V2.push_back(i);
		C.reset();
		if(C.cross(TB[4],4,V[4])&&C.cross(TB[5],5,V[5])) T3++,V3.push_back(i);
	}
	if(!(T1&&T2&&T3)) return 0;
	//T1表示 将0，1两个方块任意旋转后可以拼在一起的次数，旋转方法存在V1中
	//T2,T3依次类推。 
	
	for(int i=0;i<V1.size();i++){//0，1可以拼在一起的每种情况 
		TB[0]=B[V[0]].R(V1[i]&3);
		TB[1]=B[V[1]].R((V1[i]>>2)&3);
		for(int j=0;j<V2.size();j++){//2，3可以拼在一起的每种情况 
			int Count=0;
			TB[2]=B[V[2]].R(V2[j]&3);
			TB[3]=B[V[3]].R((V2[j]>>2)&3);
			C.reset();
			Count+=C.cross(TB[0],0,V[0]);
			Count+=C.cross(TB[1],1,V[1]);
			Count+=C.cross(TB[2],2,V[2]);
			if(Count<3) continue;
			Count+=C.cross(TB[3],3,V[3]);
			if(Count==4){//如果0，1，2，3可以拼在一起，继续搜索4，5可以拼在一起的每种情况 
				for(int k=0;k<V3.size();k++){
					Count=4;Cube tempC=C;
					TB[4]=B[V[4]].R(V3[k]&3);
					TB[5]=B[V[5]].R((V3[k]>>2)&3);
					Count+=tempC.cross(TB[4],4,V[4]);
					if(Count<5) continue;
					Count+=tempC.cross(TB[5],5,V[5]);
					if(Count==6){//如果都可以拼在一起，成功找到答案 
						ANS=tempC;return 1;
						
					}
				}
			}
		}
	}
	return 0;
}
void DFS(vector<int>V,int k,int depth){
	if(k==(1<<6)-1){
		//此时 V 为所有的组合。 
		if(F(V)) Found=1;
		return;
	}
	for(int i=0;i<6;i++){
		if((k>>i)&1) continue;
		vector<int> V_=V;V_.push_back(i); 
		DFS(V_,k|(1<<i),depth+1);
		if(Found) return;
		if(depth==2) break;
	}
}

int main(void)
{freopen("1802.txt","r",stdin); 
	while(cin>>N){
		Found=0;ALL=0;
		//读取数据 
		For(i,6) B[i].read();
		//计算 
		vector<int> V;V.push_back(0);
		if(ALL==N*N*N) DFS(V,1,1);
		//输出 
		if(Found) {
			cout<<"Yes"<<endl;
			ANS.show();
		}
		else cout<<"No"<<endl;
	}
return 0;
}








