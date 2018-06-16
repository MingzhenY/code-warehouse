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
    map<LL,int> Stones;
    vector<set<int>> From;
public:
    bool canCross(vector<int>& stones) {
        int N = stones.size();
        for(int i = 0 ; i < N ; ++i)
            Stones[stones[i]] = i;
        From.resize(N);
        if(stones[1] == stones[0] + 1) From[1].insert(0);
        for(int i = 1 ; i < N ; ++i){
            for(auto x : From[i]){
                LL step = stones[i] - stones[x];
                for(LL next = stones[i] + step - 1; next <= stones[i] + step + 1 ; ++next){
                    if(next > stones[i] && Stones.count(next)){
                        int I = Stones[next];
                        From[I].insert(i);
                        printf("%d -> %d (%d->%d)\n",stones[i],int(next),i,I);
                    }
                }
            }
        }
        return !From[N - 1].empty();
    }
    void Test(){
        //vector<int> stones1 = {0,1,3,5,6,8,12,17};
        vector<int> stones2 = {0,1,2,3,4,8,9,11};
        //printf("%d\n",canCross(stones1));
        printf("%d\n",canCross(stones2));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
