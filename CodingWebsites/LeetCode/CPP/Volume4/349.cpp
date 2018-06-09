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
    void Distinct(vector<int> &nums){
        if(!nums.size()) return;
        sort(nums.begin(),nums.end());
        int N = nums.size();
        int I = 1;
        for(int i = 1 ; i < N ; ++i){
            if(nums[i] != nums[i-1]){
                nums[I++] = nums[i];
            }
        }
        nums.resize(I);
    }
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        Distinct(nums1);
        Distinct(nums2); 
        int N1 = nums1.size(), I1 = 0;
        int N2 = nums2.size(), I2 = 0;
        vector<int> ret;
        while(I1 < N1 && I2 < N2){
            int V1 = nums1[I1];
            int V2 = nums2[I2];
            if(V1 == V2)
                ret.push_back(V1);
            I1 += V1 <= V2;
            I2 += V1 >= V2;
        }
        return ret;
    }
    void Test(){
        vector<int> A = {1,2,3,4}, B = {3,3,3,4,4,4,4,4,5};
        vector<int>result = intersection(A,B);
        for(auto x:result){
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
