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
struct Int{  
    char a[3000];  
    int len;  
    Int(int k){*this=k;}  
    Int(){*this=0;}  
    void operator =(int k){  
        if(!k){len=1;a[0]=0;return;}  
        len=0;  
        while(k) a[len++]=k%10,k/=10;  
    }  
    void operator =(string k){  
        len=k.length();  
        for(int i=0;i<len;i++) {  
            a[i]=k[len-i-1]-48;  
        }  
    }  
    Int operator +(Int &B){  
        Int C;C.len=len>B.len?len:B.len;  
        for(int i=len;i<C.len;i++) a[i]=0;  
        for(int i=B.len;i<C.len;i++)B.a[i]=0;  
        int d=0;  
        for(int i=0;i<C.len;i++){  
            C.a[i]=a[i]+B.a[i]+d;  
            d=C.a[i]/10;  
            C.a[i]%=10;  
        }  
        if(d) C.a[C.len++]=d;  
        return C;  
    }  
    Int operator +=(Int B){  
        *this=*this+B;  
        return *this;  
    }  
    Int operator -(Int &B){  
        Int C;C.len=len;  
        for(int i=B.len;i<C.len;i++)B.a[i]=0;  
        int d=0;  
        for(int i=0;i<C.len;i++){  
            C.a[i]=a[i]-B.a[i]-d;  
            d=0;  
            while(C.a[i]<0) d++,C.a[i]+=10;  
        }  
        while(C.len>0&&!C.a[C.len-1]) C.len--;  
        if(C.len==0) C=0;  
        return C;  
    }  
    bool operator>=(Int B){  
        if(len>B.len) return 1;  
        if(len<B.len) return 0;  
        for(int i=len-1;i>=0;i--){  
            if(a[i]>B.a[i]) return 1;  
            if(a[i]<B.a[i]) return 0;  
        }  
        return 1;  
    }
    void left(int k){
    	for(int i=len-1;i>=0;i--) a[k+i]=a[i];
		for(int i=0;i<k;i++) a[i]=0;
		len+=k;  
    }
    Int operator*(Int B){
    	Int C;C.len=len+B.len;
    	for(int i=0;i<C.len;i++){C.a[i]=0;} 
    	for(int i=0;i<len;i++){
    		for(int j=0;j<B.len;j++){
    			int I=i+j;
    			C.a[I]+=a[i]*B.a[j]; 
    			while(C.a[I]>9){
    				C.a[I+1]+=C.a[I]/10;
    				C.a[I]%=10;I++;
    			}
    		}
    	}
    	while(C.len>0&&!C.a[C.len-1]) C.len--;
    	return C;
    }
    void operator++(){
    	a[0]+=1;
    	for(int i=0;i<len;i++){
    		if(a[i]<10) break;
    		a[i+1]+=a[i]/10;
    		a[i]%=10;
    	}
    	if(a[len]) len++; 
    }
    void operator--(){
    	a[0]-=1;
    	for(int i=0;i<len;i++){
    		if(a[i]>=0) break;
    		a[i+1]--;
    		a[i]+=10;
    	}
    	if(!a[len-1]) len--; 
    }
    void show(){  
        for(int i=len-1;i>=0;i--) printf("%d",a[i]);
    }  
};  
int N; 
Int F[1001];
int main(void)
{freopen("1366.txt","r",stdin); 
	F[1]=0;F[2]=1;
	for(int i=3;i<=1000;i++){
		Int K=i;
		F[i]=K*F[i-1];
		K=1;
		if(i&1) F[i]=F[i]-K;
		else F[i]=F[i]+K;
	} 
	while(cin>>N){
		F[N].show();cout<<endl;
		//OUT1(F[N].len);
	}
return 0;
}








