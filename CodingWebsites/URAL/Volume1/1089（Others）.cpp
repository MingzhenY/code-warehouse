#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<cmath>  
#include<algorithm>  
using namespace std;  
char doc[3005][15];  
bool check(char a[],char b[])  
{  
    int len=strlen(a),len1=strlen(b),count=0;  
    if(len!=len1)return false;  
    for(int i=0;i<len;i++)  
    {  
        if(a[i]!=b[i])count++;  
    }  
    if(count==1)return true;  
    else return false;  
}  
  
  
int main()  
{  
  freopen("1089.txt","r",stdin);  
    int i,j;  
    int total=0;  
    char s[15]; //��Ϊ�ļ���ĵ��ʿ��ܳ���10�����ļ���ĵ���Ҳ���ݴ�������ģ���������Ҫ���Ĵ�Щ����С��WA��������   
    char ch;  
    int res=0,cnt;  
  
    while(~scanf("%s",s) && s[0]!='#')  
        strcpy(doc[total++],s);   
      
      
    getchar();  
    cnt=0;  
    memset(s,0,sizeof(s)); //�浥��   
    while(~scanf("%c",&ch))  
    {  
        if(!isalpha(ch))  
        {  
            bool flag=false;  
            for(i=0;i<total;i++)  
            {  
                if(check(s,doc[i]))  
                {  
                    res++;  
                    cout<<doc[i];  
                    flag=true;  
                    break;  
                }  
                  
            }  
            if(!flag)  
            {  
                cout<<s;  
            }  
            cout<<ch;  
            memset(s,0,sizeof(s));  
            cnt=0;  
        }  
        else  
        {  
            s[cnt++]=ch;  
        }   
    }  
    cout<<endl;  
    cout<<res<<endl;  
      
}  
