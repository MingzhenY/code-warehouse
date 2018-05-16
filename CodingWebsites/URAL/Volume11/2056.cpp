#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x1fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define eps 1e-9
int sgn(double x){return (x>eps)-(x<-eps);} 
using namespace std;
int main(void)
{freopen("2056.txt","r",stdin); 
	int n,A[10],N3,N4,N5;double Sum=0.0;
    while(cin>>n){
        N3=N4=N5=0;
        for(int i=0;i<n;++i) {
            cin>>A[i];
            if(A[i]==3) N3++;
            else if(A[i]==4) N4++;
            else N5++;
            Sum+=A[i];
        }
        Sum/=n;
        if(N3) cout<<"None"<<endl;
        else if(N5==n) cout<<"Named"<<endl;
        else if(sgn(Sum-4.5)>=0) cout<<"High"<<endl;
        else cout<<"Common"<<endl;
    }
return 0;
}








