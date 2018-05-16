#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define  inf  0x3fffffff
using namespace std;
int max(int a,int b) {return a>b?a:b;}
int min(int a,int b) {return a<b?a:b;}
int zdgys(unsigned int a,unsigned int b){while(a){if(a<b){a=a^b;b=a^b;a=a^b;}  a=a%b;}return (int)b;} 
int zxgbs(int a,int b){return (a*b)/zdgys(a,b);}
const int maxn=1000000;
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
//char a[1000000];
//char b[1000000];
bool is_seven(int);

int main(void)
{/*int na=0,nb=0;
scanf("%s",a);
for(int i=0;i<1000000;i++) if(a[i]=='1'||a[i]=='6'||a[i]=='8'||a[i]=='9'||a[i]=='0') {na++;a[i]-=48;b[i]=a[i]} else break;
nb=na;*/ 
bign a,b;
cin>>a;b=a;

while(b.len>2)  b=b/10-2*b.s[b.len-1];
if(b%7==0) cout<<b;





return 0;
}


