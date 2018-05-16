#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <list>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;

class Solution {
    int p10[10];
public:
    int countDigitOne(int n) {
        if(n <= 0) return 0;
        char line[32];
        sprintf(line,"%d",n);
        int len = strlen(line);
        
        p10[0] = 1;
        for(int i = 1 ; i < 10 ; ++i) p10[i] = 10 * p10[i - 1];
        int ANS = 0, PreOnes = 0;
        for(int i = 0 ; i < len ; ++i){
            int A = line[i] -= '0', B = len - i - 1;
            ANS += (B ? A * B * p10[B - 1] : 0) + (PreOnes * A + (A > 1)) * p10[B];
            //ANS += countAB(A,B) + PreOnes * A * p10[B];
            PreOnes += line[i] == 1;
        }
        return ANS + PreOnes;
    }
    int countAB(int A,int B){
        //count the number of 1 range [0,A * 10^B)
        return B ? A * B * p10[B - 1] + (A > 1) * p10[B]
                 : A > 1;
    }
    void Test(){
        cout<<countDigitOne(20)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
