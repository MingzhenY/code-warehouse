#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <list>
#include <cmath>
#include <map>
#include <set>
#include <stack>
using namespace std;

class Solution {
#define LL long long
    LL F[30];
    LL SumF[30];
    char rotate180[10];
    //0,1,2,3 ,4 ,5 ,6, ,7  ,8  ,9   ,10
    //1,3,4,12,20,60,100,300,500,1500,2500
public:
    Solution(){
        F[0] = 1;//""
        F[1] = 3;//"0","1","8"
        SumF[0] = 1;
        SumF[1] = 4;
        LL S[2] = {1,3};
        for(int i = 2 ; i < 30 ; ++i){
            /*
            F[i] = F[i - 2] * 4 + // "1/8/6/9" + x + "1/8/9/6"
            F[i - 4] * 4 + //"10/80/60/90" + x + "01/08/09/06"
            F[i - 6] * 4 + ...//"100/..." + x + "001/..."
            */
            F[i] = S[i & 1] << 2;
            S[i & 1] += F[i];
            SumF[i] = SumF[i - 1] + F[i];
            //printf("F[%d]=%lld\n",i,F[i]);
        }
        //Note: F[27] > INT_MAX
        for(int i = 0 ; i < 10 ; ++i){
            int V;
            switch(i){
                case 0:
                case 1:
                case 8:
                    V = i;
                    break;
                case 6:
                case 9:
                    V = 15 - i;
                    break;
                default:
                    V = -'0';
            }
            rotate180[i] = V + '0';
        }
    }
    int strobogrammaticInRange(string low, string high) {
        LL High = CountBelow(high,0,(high.length() - 1) / 2,high.length());
        LL Low = CountBelow(low,0,(low.length() - 1) / 2,low.length());
        printf("%lld - %lld + %d = %lld\n",High,Low,
               isStrobogrammatic(high),High - Low + isStrobogrammatic(high));
        return low.length() < high.length() || (low.length() == high.length() && low <= high) ? High - Low + isStrobogrammatic(high) : 0;
        return  CountBelow(high,0,(high.length() - 1) / 2,high.length()) -
                CountBelow(low,0,(low.length() - 1) / 2,low.length()) +
                isStrobogrammatic(high);
    }
    LL CountBelow(string &str,int i,int n,int orglen){
        //Count number range [0, str) when i = 0
        int A = str[i] - '0', B = orglen - i + 1;
        if(i > n){
            //passed the center line
            //there is still one possibility
            //for example 9696 should be counted when str is 9697
            //and shouldn't be counted when str is 9695 or 9696
            //this can only be down here
            string rev = str.substr(0,n+1);
            bool Valid = true;
            for(int k = orglen / 2 - 1 ; k >= 0 ; --k) {
                if(rotate180[str[k] - '0'])
                    rev += rotate180[str[k] - '0'];
                else{
                    Valid = false;
                    break;
                }
            }
            printf("%s\n",rev.c_str());
            return orglen > 1 && Valid && rev < str;
        }
        //Part One:count in range [str[0..i-1] , str[0..i-1] + A * 10^B)
        int CountDigit = ((i || orglen == 1) && (A > 0)) + (A > 1) + (A > 8) +
        (orglen & 1 ? 0 : (A > 6));
        LL ANS = CountDigit;//this is the first number
        for(int k = i + 1 ; k < orglen / 2 ; ++k){
            ANS *= 5;//Add 0,1,6,8,9
        }
        if((orglen & 1) && i < n){
            ANS *= 3;//Add 0,1,8 (this is the middle)
        }
        //for(int t = 0 ; t < i ; ++t) printf("  ");printf("D1 = %lld\n",ANS);
        
        //Part Two: Only consider later letters if current one can be rotated
        if(rotate180[str[i] - '0']) ANS += CountBelow(str,i+1,n,orglen);
        
        //for(int t = 0 ; t < i ; ++t) printf("  ");printf("D2 = %lld\n",ANS);
        
        //Part Three: for number 12345, calculate all Strobogrammatic numbers
        //that has 4 digits or less
        if(!i && orglen > 1){
            ANS += SumF[orglen - 1] - 1;
        }
        //for(int t = 0 ; t < i ; ++t) printf("  ");printf("D3 = %lld\n",ANS);
        return ANS;
    }
    bool isStrobogrammatic(string num) {
        long long L = 0, R = 0;
        int n = num.size();
        for(int i = 0 , p137 = 1; i < n ; ++i, p137 *= 137){
            L = L + p137 * num[i];
            R = R + p137 * rotate180[num[n - i - 1] - '0'];
        }
        return L == R;
    }
    void Test(){
        cout<<strobogrammaticInRange("0","2100000000")<<endl;
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
