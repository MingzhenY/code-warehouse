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
    int findKthLargest(vector<int>& nums, int k) {
        //use the idea of quick sort
        return FKL(nums,0,nums.size() - 1,k);
    }
    int FKL(vector<int> &nums,int L,int R,int k){
        //nums[L..R] find kth
        int l = L , r = R, V = nums[L], S = 0;
        while(l < r){
            if(S){
                //put values smaller than V into R
                while(l < r && nums[l] >= V) ++l;
                nums[r] = nums[l];
            }
            else{
                //put values larger than V into L
                while(r > l && nums[r] <= V) --r;
                nums[l] = nums[r];
            }
            S = ~S;
        }
        nums[l] = V;
        //now, there are three parts: [L,l) l=r (r,R]
        if(k <= l - L)
            return FKL(nums,L,l-1,k);
        else if(k == l - L + 1)
            return nums[l];
        else
            return FKL(nums,r+1,R,k - (l - L + 1));
    }
    void Test(){
        vector<int> nums = {3,2,1,5,6,4};
        cout<<findKthLargest(nums,6)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
