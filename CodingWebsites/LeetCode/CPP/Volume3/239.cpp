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
#include <stack>
#include <set>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ret;
        list<pair<int,int>> L;
        
        for(int i = 0 ; i < n ; ++i){
            while(!L.empty() && L.back().second <= nums[i])
                L.pop_back();
            if(i >= k - 1){
                ret.push_back(nums[i]);
                list<pair<int,int>>::reverse_iterator p = L.rbegin();
                while(p != L.rend()){
                    if(i - p->first < k){
                        ret[i - k + 1] = p->second;
                    }
                    else break;
                    ++p;
                }
            }
            L.push_back(make_pair(i,nums[i]));
        }
        return ret;
    }
    void Show(int i,list<pair<int,int>> L){
        printf("%d:",i);
        for(auto x:L){
            printf("(%d,%d)",x.first,x.second);
        }
        printf("\n");
    }
    void Test(){
        vector<int> nums = {1,3,-1,-3,5,3,6,7};
        vector<int> ret = maxSlidingWindow(nums,3);
        for(auto x:ret){
            cout<<x<<" ";
        }
        cout<<endl;
    }
};



int main(){
    Solution S;
    S.Test();
	return 0;
}
