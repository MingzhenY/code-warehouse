#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int A[2000001];

int main(){
    freopen("P1202.txt","r",stdin);
    int n,a;
    scanf("%d",&n);
    n = n<<1|1;
    
    for(int i = 0 ; i < n ; ++i) scanf("%d",&A[i]);
    sort(A,A+n);
    for(int i = 0 ; i < n ; i += 2){
        if(A[i]!=A[i+1]){
            printf("%d\n",A[i]);
            break;
        }
    }
    
    return 0;
}


