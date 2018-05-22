#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int T,SD,SZ,ND,NZ;
char str[100007];

int main(){
    freopen("P1098.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%s",str);
        ND=NZ=SD=SZ=0;
        vector<int> D,Z;
        for(int i=0;str[i];++i){
            switch(str[i]){
                case 'd': SD = 1 ; break;
                case 'o': SD = SD == 1 ? 2 : 0 ; break;
                case 'n': SD = SD == 2 || SD == 6 ? SD + 1 : 0 ; break;
                case 'g': SD = SD == 3 || SD == 7 ? SD + 1 : 0 ; break ;
                case 'f': SD = SD == 4 ? 5 : 0 ; break;
                case 'a': SD = SD == 5 ? 6 : 0 ; break;
                case 'x': SD = SD == 8 ? 9 : 0 ; break;
                case 'u': SD = SD == 9 ? 10 : 0 ; break;
                default:  SD = 0 ;
            }
            if(SD==10) D.push_back(i);
            switch(str[i]){
                case 'z': SZ = 1 ; break;
                case 'a': SZ = SZ == 1 ? 2 : 0 ; break;
                case 'p': SZ = SZ == 2 ? 3 : 0 ; break;
                default:  SZ = 0 ;
            }
            if(SZ==3) Z.push_back(i);
        }
        
        for(int i=0,j;i<D.size();i=j){
            j=i+1;
            while(D[j]==D[j-1]+10) ++j;
            ND=max(ND,j-i);
        }
        for(int i=0,j;i<Z.size();i=j){
            j=i+1;
            while(Z[j]==Z[j-1]+3) ++j;
            NZ=max(NZ,j-i);
        }
        printf("%s!\n",ND>=NZ?"dongfangxu":"zap");
    }
    
    return 0;
}


