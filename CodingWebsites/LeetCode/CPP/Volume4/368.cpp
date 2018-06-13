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
    vector<list<int>> to;
    map<int,vector<int>> M;
    vector<int> F(vector<int> &nums, int ID){
        if(M.count(ID))
            return M[ID];
        vector<int> ret;
        for(auto t : to[ID]){
            vector<int> D = F(nums,t);
            if(D.size() > ret.size())
                ret = D;
        }
        if(ID < nums.size())
            ret.push_back(nums[ID]);
        return M[ID] = ret;
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int N = nums.size();
        to = vector<list<int>>(N + 1);
        for(int i = 0 ; i < N ; ++i){
            for(int j = i + 1 ; j < N ; ++j){
                if(nums[i] % nums[j] == 0){
                    to[j].push_back(i);
                }
                if(nums[j] % nums[i] == 0){
                    to[i].push_back(j);
                }
            }
        }
        for(int i = 0 ; i < N ; ++i){
            to[N].push_back(i);
        }
        return F(nums,N);
    }
    void Test(){
        vector<int> nums = {1,2,4,8};
        vector<int> ans = largestDivisibleSubset(nums);
        for(auto x:ans){
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
