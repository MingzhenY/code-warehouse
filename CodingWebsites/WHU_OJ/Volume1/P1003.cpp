#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;
struct Person{
    string name;
    int depth,age;
};

Person P[]={
    {string("Adam"),1,930},
    {string("Seth"),2,912},
    {string("Enosh"),3,905},
    {string("Kenan"),4,910},
    {string("Mahalalel"),5,895},
    {string("Jared"),6,962},
    {string("Enoch"),7,365},
    {string("Methuselah"),8,969},
    {string("Lamech"),9,777},
    {string("Noah"),10,0},
    {string("Shem"),11,0},
    {string("Ham"),11,0},
    {string("Japheth"),11,0}
};
map<string,int> Mage,Mdepth;


int main(){
    freopen("P1003.txt","r",stdin);
    for(int i=0;i<sizeof(P)/sizeof(Person);++i){
        Mage[P[i].name]=P[i].age;
        Mdepth[P[i].name]=P[i].depth;
    }
    string name1,name2;
    int age1,age2;
    int depth1,depth2;
    while(cin>>name1>>name2){
        age1=Mage[name1];
        age2=Mage[name2];
        depth1=Mdepth[name1];
        depth2=Mdepth[name2];
        
        printf("%s\n",depth1<depth2?"Yes":"No");
        if(age1 && age2){
            printf("%s\n",age1>age2?"Yes":"No");
        }else printf("No enough information\n");
    }
    
    
    return 0;
}


