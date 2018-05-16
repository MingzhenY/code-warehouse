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
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int N = nums.size();
        vector<string> ANS;
        if(!N) return ANS;
        int Start, Prev;
        Start = Prev = nums[0];
        for(int i = 1 ; i <= N ; ++i){
            if(i == N || nums[i] != ++Prev){
                char line[32];
                int R = Prev - 1 + (i == N);
                if(Start == R)
                    sprintf(line,"%d",Start);
                else
                    sprintf(line,"%d->%d",Start,R);
                ANS.push_back(line);
                Start = Prev = nums[i];
            }
        }
        return ANS;
    }
    void Test(){
        vector<int> nums = {0,2,3,4,6,8,9};
        vector<string> VS = summaryRanges(nums);
        for(auto str:VS){
            cout<<str<<endl;
        }
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
