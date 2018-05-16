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
const int maxn=10000;
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

 bign operator *(const bign&b) const
     {
     bign x;
     
     for(int i=0;i<len;i++)
        {
        for(int j=0;j<b.len;j++)
           {bign k;
           	k+=s[i]*b.s[j];
           	k.left(i+j);
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

void left(int k){
		for(int i=len+k;i>=k;i--){
			s[i]=s[i-k];
		}
		for(int i=0;i<k;i++) s[i]=0;
		len+=k;
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

int main(void)
{freopen("1206.txt","r",stdin); 
	int N;
	while(cin>>N){
		bign ANS=36;
		for(int i=1;i<N;i++){
			ANS*=55;
		}
		cout<<ANS<<endl;
	}
return 0;
}








