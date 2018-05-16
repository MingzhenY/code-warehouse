#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define maxn 100
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<i<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
class bign//   注意，减法是加过绝对值的。
{
public:
int len,s[maxn];
bign(){
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
     while(!x.s[x.len-1]) x.len--;
     return x;
     }
bign operator *=(const bign&b) 
   {
   	*this =(*this)*b;
   	return *this;
   }
bign operator /=(const bign&b) 
   {
   	if(b==2){
   		//OUT3(s[0]+48,s[1]+48,s[2]+48);
   		int p=0;
   		for(int i=len-1;i>=0;i--){
   			if(i){
   				int t=p;
   				p=5*(s[i]&1);
   				s[i]=s[i]/2+t;
   			}
   			else{
   				s[i]=s[i]/2+p;
   			}
   		}
   		while(!s[len-1]) len--;
   		return *this;
   	}
   	bign L,R;
   	L="1";R="1";//OUT2(L.len,R.len);
   	while(R*b<=*this) R*=10;
   	while(L <=R){
   		
   		
   		bign M=(L+R);M/=2;
   		//printf("L=");L.show();
   		//printf("R=");R.show();
   		//printf("M=");M.show();
   		//getchar();
   		if(M*b==*this) return *this=M;
   		if(M*b>=*this) R=M-1;
   		else L=M+1;
   	}
   	return *this=L;
   }
void show(){
	for(int i=0;i<len;i++){
		cout<<s[len-i-1];
	}
	cout<<endl;
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


bign C(int a,int b);
int main(void)
{freopen("1009.txt","r",stdin); 	
	int N,K;
	cin>>N>>K;
	bign ANS;ANS="0";
	for(int a=0;a<N;a++){
		bign _ANS=C(N-a,a);
		for(int i=0;i<N-a;i++){
			_ANS*=K-1;
		}
		ANS+=_ANS;
	}
 	cout<<ANS<<endl;
return 0;
}
bign C(int a,int b){
	bign temp="0";
	if(b>a||b<0) return temp;
	if(2*b<a) b=a-b;
	temp="1";
	if(b==a) return temp;
	bign ANS="1";
	for(int i=b+1;i<=a;i++){
		ANS*=i;
	}
	for(int i=2;i<=a-b;i++){
		ANS/=i;
	}
	return ANS;
}







