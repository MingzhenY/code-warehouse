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
using namespace std;


class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ANS;
        int n = nums.size();
        if(n == 0){
            char line[128];
            if(lower == upper){
                sprintf(line,"%d",upper);
            }
            else {
                sprintf(line,"%d->%d",lower,upper);
            }
            ANS.push_back(line);
            return ANS;
        }
        int nextExpect = lower;
        for(int i = 0 ; i < nums.size() ; i++){
            if(i && nums[i] == nums[i-1]) continue;
            if(nums[i] == nextExpect){
                nextExpect++;
            }
            else if(nums[i] > nextExpect){
                char line[128];
                if(nums[i] == nextExpect + 1){
                    sprintf(line,"%d",nextExpect);
                }else{
                    sprintf(line,"%d->%d",nextExpect,nums[i]-1);
                }
                ANS.push_back(line);
                nextExpect = nums[i] + 1;
            }
            else {
                //Duplicate Values, ignore
            }
        }
        if(nums[n-1] < upper){
            char line[128];
            if(upper == nums[n-1] + 1){
                sprintf(line,"%d",upper);
            }
            else{
                sprintf(line,"%d->%d",nums[n-1]+1,upper);
            }
            ANS.push_back(line);
        }
        return ANS;
    }
    void Test(){
        int A[]={-2147483648,-2147483648,0,2147483647,2147483647};
        vector<int> V(A,A+sizeof(A)/sizeof(A[0]));
        for(auto x:findMissingRanges(V,-2147483648,2147483647)){
            cout<<x<<endl;
        }
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
