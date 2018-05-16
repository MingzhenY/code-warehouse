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
const int maxn=100;
class bign//   注意，减法是加过绝对值的。
{

public:
int len,s[maxn];
bign()
    {
    len=1;memset(s,0,sizeof(s));    
    } 
    
bign operator=(const char* num) 
    {
    len=strlen(num);
    for(int i=0;i<len;i++) s[i]=num[len-i-1]-'0';
    for(int j=len-1;;j--) 
       {
       	if(s[j]==0) len--;
       	else break;
       }
	return *this;
    }
    
bign operator=(long long  num)
    {
    char s[maxn];
    sprintf(s,"%lld",num);
    *this=s;
    return *this;
    }
bign(long long num){*this=num;}
bign(const char *num){*this=num;}
string str() const
    {
    string res="";
    for(int i=0;i<len;i++) res=(char)(s[i]+'0')+res;
    if(res=="") res="0";
    return res;
    }

bign operator +(const bign&b) const
    {
    bign c;
    c.len=0;
    for(int i=0,g=0;g||i<max(len,b.len);i++)
       {
	   int x=g;
	   if(i<len) x+=s[i];
	    if(i<b.len) x+=b.s[i];
	    c.s[c.len++]=x%10;
	    g=x/10;
	   } 
	return c;
    } 

bign operator +=(const bign&b) 
   {
   	*this =*this+b;
   	return *this;
   }



bign operator -(const bign&b)const
    {bign A,a,x;
    if(*this>b) {A=*this;a=b;} else {a=*this;A=b;}
     x.len=A.len;
    for(int i=0,g=0;i<max(len,b.len);i++)
       {x.s[i]=g;
        if(A.s[i]>a.s[i]) {x.s[i]=x.s[i]+A.s[i];if(i<a.len) x.s[i]=x.s[i]-a.s[i];g=0;}
        else {if(A.s[i]==a.s[i]) {x.s[i]=0;g=0;continue;}
        	  x.s[i]=x.s[i]+A.s[i]-a.s[i]+10;g=-1;
             }
       }
    return x;
   }

bign operator -=(const bign&b) 
   {
   	*this =*this-b;
   	return *this;
   }
   
 
 bign operator *(const bign&b) const
     {
     bign x;
     
     for(int i=0;i<len;i++)
        {
        for(int j=0;j<b.len;j++)
           {bign k;
           	k+=s[i]*b.s[j];
           	for(int m=0;m<i+j;m++) k=k+k+k+k+k+k+k+k+k+k;
           	x+=k;
           }
        }
       
     return x;
     }
bign operator *=(const bign&b) 
   {
   	*this =(*this)*b;
   	return *this;
   }       

bool operator >(const bign&b)const
   {
	if(len>b.len) return 1;
	if(len<b.len) return 0; 
	for(int i=len-1;i>=0;i--)
	   {
	   	if(s[i]>b.s[i])  return 1;
	   	if(s[i]<b.s[i])  return 0;	   	
	   }
	return 0;
   }     

bool operator >=(const bign&b) const
    {
    if(b>*this) return 0;
    else return 1;
    }

bool operator <(const bign&b) const
    {
    if(*this>=b) return 0;
    else return 1;
    }

bool operator <=(const bign&b) const
    {
    if(*this>b) return 0;
    else return 1;
    }

bool operator ==(const bign&b) const
    {
    if(*this>b||*this<b) return 0;
    else return 1;
    }

bool operator !=(const bign&b) const
    {
    if(*this==b) return 0;
    else return 1;
    }    
};

istream& operator >>(istream &in,bign&x)
{
string s;
in>>s;
x=s.c_str();
return in;
}

ostream& operator <<(ostream &out,const bign& x)
{
out<<x.str();
return out;
}
bign dp[51][501];
int N,S; 
int main(void)
{freopen("1036.txt","r",stdin); 
	while(cin>>N>>S){
		if(S&1) {
			cout<<0<<endl;
			continue;
		}
		S/=2;
		for(int i=0;i<51;i++){
			for(int j=0;j<501;j++){
				dp[i][j]="0";
			}
		}
		dp[0][0]=1;
		for(int i=1;i<=N;i++){//i:当前位数 
			for(int j=0;j<=500;j++){//j:当前数字和 
				for(int k=0;k<10;k++){//k:当前数字 
					if(j-k>=0) dp[i][j]+=dp[i-1][j-k];
				} 
			}
		}
		bign ANS=dp[N][S]*dp[N][S];
		cout<<ANS<<endl;
	}
return 0;
}








