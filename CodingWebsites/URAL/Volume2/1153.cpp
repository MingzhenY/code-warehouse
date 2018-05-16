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
    int a[300];
    int len;
    Int(){*this=0ll;}  
    Int(long long k){*this=k;}
    Int(string k){*this=k;}
    void operator =(long long k){  
        if(!k){len=1;a[0]=0;return;}  
        len=0; 
        while(k) a[len++]=k%10000,k/=10000; 
    }
    void operator =(string k){
        len=(k.length()+3)/4;int n=k.length();
        int Off=((4-(n%4))%4);
        for(int i=0;i<len;++i) {
        	a[len-i-1]=0;
        	for(int j=max((i<<2)-Off,0);j<(i<<2)-Off+4;++j){
        		a[len-i-1]*=10;
        		a[len-i-1]+=k[j]-'0';
        	}
        }
    }
    Int operator +(Int B){  
        Int C;C.len=len>B.len?len:B.len;  
        for(int i=len;i<C.len;i++) a[i]=0;  
        for(int i=B.len;i<C.len;i++)B.a[i]=0;  
        int d=0;
        for(int i=0;i<C.len;i++){  
            C.a[i]=a[i]+B.a[i]+d;  
            d=C.a[i]/10000;  
            C.a[i]%=10000;
        }  
        if(d) C.a[C.len++]=d;  
        return C;  
    }  
    Int operator -(Int B){
        Int C;C.len=len;  
        for(int i=B.len;i<C.len;i++) B.a[i]=0;  
        int d=0;
        for(int i=0;i<C.len;i++){  
            C.a[i]=a[i]-B.a[i]-d;  
            d=0;  
            while(C.a[i]<0) d++,C.a[i]+=10000;  
        }  
        while(C.len>1&&!C.a[C.len-1]) C.len--;  
        return C;  
    }  
    bool operator<(const Int &B)const{  
    	if(len < B.len) return true;  
        if(len > B.len) return false;  
        for(int i=len-1;i>=0;i--){  
        	if(a[i] < B.a[i]) return true; 
            if(a[i] > B.a[i]) return false;  
        }  
        return false;  
    }
    bool operator<=(const Int &B)const{  
    	if(len < B.len) return true;  
        if(len > B.len) return false;  
        for(int i=len-1;i>=0;i--){  
        	if(a[i] < B.a[i]) return true; 
            if(a[i] > B.a[i]) return false;  
        }  
        return true;  
    }
    bool operator==(Int B){
    	if(len!=B.len) return false;
    	for(int i=len-1;i>=0;i--){  
        	if(a[i] != B.a[i]) return false; 
        }  
        return true;  
    }
    Int operator*(Int N){
    	return Mul(N);
    }
    Int operator<<(int k)const{
    	Int C;
		C.len=len+k;
    	for(int i=len-1;i>=0;--i) C.a[i+k]=a[i];
    	for(int i=0;i<k;++i) C.a[i]=0;
    	return C;
    }
    Int operator>>(int k)const{
    	if(len <= k) return Int(0);
    	Int C;
    	C.len=len-k;
    	for(int i=0;i<C.len;++i) C.a[i]=a[i+k];
    	return C;
    }
    static Int abs(Int &A,Int &B){
    	return A < B? B - A : A - B; 
    }
    Int Mul(Int &B){
    	Int C;C.len=len+B.len;
    	for(int i=0;i<C.len;i++){C.a[i]=0;} 
    	for(int i=0;i<len;i++){
    		for(int j=0;j<B.len;j++){
    			int I=i+j;
    			C.a[I]+=a[i]*B.a[j]; 
    			if(C.a[I]>=10000){
    				C.a[I+1]+=C.a[I]/10000;
    				C.a[I]%=10000;I++;
    			}
    		}
    	}
    	while(C.len>1&&!C.a[C.len-1]) C.len--;
    	return C;
    }
    Int div2(){
    	Int C=*this;
    	C.a[0]/=2;
    	for(int i=1;i<C.len;++i){
    		if(C.a[i]&1) C.a[i-1]+=5000;
    		C.a[i]>>=1;
    	}
    	while(C.len>1&&!C.a[C.len-1]) C.len--;
    	return C;
    }
    void show(){
    	printf("%d",a[len-1]);
        for(int i=len-2;i>=0;i--) printf("%04d",a[i]);
        printf(" ");
    }
    void showLn(){
    	printf("%d",a[len-1]);
        for(int i=len-2;i>=0;i--) printf("%04d",a[i]);
        printf("\n");
    }
};
string str;
int main(void)
{freopen("1153.txt","r",stdin); 
	while(cin>>str){
		Int X(str);X=X*Int(2);
		Int L=1,R=1;
		while(R <= X) R=R*Int(2);
		while((L+Int(1))< R){
			Int M=(L+R).div2();
			if(M*M <= X) L=M;
			else R=M;
		}
		L.showLn();
	}
return 0;
}








