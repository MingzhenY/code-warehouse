#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define maxd 1000100000
using namespace std;
int StoI(string s){
	int ANS=0;int Sign=0;
	if(s[0]=='-') Sign=1;
	else ANS=s[0]-48;
	for(int i=1;i<s.length();++i) ANS*=10,ANS+=s[i]-48;
	if(Sign) return -ANS;
	else return ANS;
}
int a[100007],n,k;
bool mark[100007];
int main(void)
{
	freopen("518E.txt","r",stdin); 
	while(~scanf("%d%d",&n,&k)){
		memset(mark,0,sizeof(mark));
		for(int i=1;i<=n;++i){
			string str;cin>>str;
			if(str[0]=='?') mark[i]=1;
			else a[i]=StoI(str);
			//printf("a[%d]=%d\n",i,a[i]);
		}
		int ERR=0;
		for(int start=1;start<=k;++start){
			int t = 1 + (n-start)/k ;
			int LowerBound=-maxd,UpperBound;
			for(int i=start;i<=n;i+=k){
				if(!mark[i]){
					if(a[i]<=LowerBound){
						ERR=1;break;
					}
					else{
						LowerBound=a[i];continue;
					}
				}
				int L=i,R=i,cnt=1;
				while(R+k <=n && mark[R+k]) R+=k,++cnt;
				if(R+k <=n) UpperBound=a[R+k];
				else UpperBound=maxd;
				//��������[L,R]�е�'?',��Χ(LowerBound,UpperBound);
				//printf("�ҵ�����[%d,%d],��Χ��(%d,%d)\n",L,R,LowerBound,UpperBound); 
				if(UpperBound-LowerBound<=cnt) {
					ERR=1;break;
				}
				else{
					if(UpperBound <=cnt/2){
						for(int num=UpperBound-1,j=R;j>=L;j-=k,num--){
							a[j]=num;mark[j]=0;
						}
					}
					else if(LowerBound>=-(cnt/2)){
						for(int num=LowerBound+1,j=L;j<=R;j+=k,num++){
							a[j]=num;mark[j]=0;
						}
					}
					else if(UpperBound >cnt/2 && cnt/2-LowerBound>=cnt){
						//��UpperBound ��ʼ��ֵ 
						for(int num=cnt/2,j=R;j>=L;j-=k,num--){
							a[j]=num;mark[j]=0;
						}
					}
					else if(LowerBound <-(cnt/2)&&UpperBound+cnt/2>=cnt){
						//��LowerBound ��ʼ��ֵ 
						for(int num=-(cnt/2),j=L;j<=R;j+=k,num++){
							a[j]=num;mark[j]=0;
						}
					}else {
						ERR=2;break;
					}
				}
				
			}
			if(ERR) break;
		}
		if(ERR){
			//printf("ERR=%d  ",ERR);
			printf("Incorrect sequence\n");
			
		}
		else{
			for(int i=1;i<=n;++i){
				printf("%d",a[i]);
				if(i==n) printf("\n");
				else printf(" ");
			}
		}
	}

		
return 0;
}














