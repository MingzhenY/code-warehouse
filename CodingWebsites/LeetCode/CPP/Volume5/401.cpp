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
    int countBit(int x){
        x = ((x & 0xaaaaaaaa) >> 1) + (x & 0x55555555);
        x = ((x & 0xcccccccc) >> 2) + (x & 0x33333333);
        x = ((x & 0xf0f0f0f0) >> 4) + (x & 0x0f0f0f0f);
        x = ((x & 0xff00ff00) >> 8) + (x & 0x00ff00ff);
        x = ((x & 0xffff0000) >> 16)+ (x & 0x0000ffff);
        return x;
    }
public:
    vector<string> readBinaryWatch(int num) {
        int A[10] = {1,2,4,8,16,32,64,128,256,512};
        int N = 1 << 10;
        vector<string> ret;
        for(int i = 0 ; i < N ; ++i){
            if(countBit(i) != num) continue;
            int H = 0,M = 0;
            for(int j = 0 ; j < 4 ; ++j){
                H = 2 * H + ((i & A[j]) != 0);
            }
            for(int j = 4 ; j < 10 ; ++j){
                M = 2 * M + ((i & A[j]) != 0);
            }
            if(H >= 0 && H <12 && M >= 0 && M < 60){
                char time[32];
                sprintf(time,"%d:%02d",H,M);
                ret.push_back(time);
            }
        }
        return ret;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
