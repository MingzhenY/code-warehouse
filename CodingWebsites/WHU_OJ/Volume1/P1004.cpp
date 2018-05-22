#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#define eps 1e-9
using namespace std;
int dcmp(double d){return (d>-eps) - (d<eps);}

int main(){
    freopen("P1004.txt","r",stdin);
    map<string,double> M;
    M[string("centimeters")]=45.72;
    M[string("meters")]=0.4572;
    M[string("feet")]=1.5;
    M[string("inches")]=18;
    M[string("cubits")]=1;
    
    double a,b,c;
    string sa,sb,sc;
    while(cin>>a>>sa>>b>>sb>>c>>sc){
        a/=M[sa];
        b/=M[sb];
        c/=M[sc];
        if(!dcmp(a-6*b)) printf("Excellent\n\n");
        else if(!dcmp(a-b)) printf("Spin\n\n");
        else printf("Neither\n\n");
    }
    
    
    return 0;
}


