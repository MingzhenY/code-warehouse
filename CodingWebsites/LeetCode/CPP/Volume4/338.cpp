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
    int count(int x){
        x = ((x & 0xaaaaaaaa) >> 1) + (x & 0x55555555);
        x = ((x & 0xcccccccc) >> 2) + (x & 0x33333333);
        x = ((x & 0xf0f0f0f0) >> 4) + (x & 0x0f0f0f0f);
        x = ((x & 0xff00ff00) >> 8) + (x & 0x00ff00ff);
        x = ((x & 0xffff0000) >> 16) + (x & 0x0000ffff);
        return x;
    }
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        for(int i = 0 ; i <= num ; ++i)
            ret.push_back(count(i));
        return ret;
    }
    void Test(){
        vector<int> ANS = countBits(5);
        for(auto x:ANS){
            printf("%d ",x);
        }
        printf("\n");
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
