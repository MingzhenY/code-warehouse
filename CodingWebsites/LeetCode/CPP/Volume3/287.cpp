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
/*
 Find duplicate without modifying nums (values ranges from [1,n) )
 O(1) space, less than O(n^2)
 */
class Solution1 {
    /*
     Binary Search for the duplicated value
     split the value range in two parts, one of the parts must contain
     the duplicated number
     O(nlogn) time, O(1) space
     */
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int L = 1 , R = n ;//[L,R)
        while(L + 1 < R){
            int M = L + (R - L) / 2;
            int C = 0;
            for(auto x:nums) C += x < M;
            //[1,M) = C
            //[M,R) = n - C
            if(C >= M) R = M;
            else L = M;
        }
        return L;
    }
    void Test(){
        vector<int> nums = {1,2,3,4,5,6,7,8,9,3};
        cout<<findDuplicate(nums)<<endl;
    }
};
class Solution {
    /*
     A clever solution from leetcode. O(n) time, O(1) space
     assume nums has n + 1 numbers
     view nums[0..n] as linked list where i -> nums[i]
     since nums[0..n] ranges from [1,n], the linked list goes on forever.
     Which means it has cycles and it will reach cycles if you start with any number
     ranged from 1 to n. In each cycle that you eventually reached, their values are
     a permutation of their positions. So the entry point of any cycle indicates
     duplicate number.
     
     So use three pointers to determin the entry of the cycle that is reached from 0.
     */
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        //Slow/Fast Pointer
        int P,Slow,Fast;
        bool FirstMeet = false;
        Slow = Fast = 0;
        while(1){
            Fast = nums[nums[Fast]];
            Slow = nums[Slow];
            if(FirstMeet){
                P = nums[P];
                if(P == Slow) return P;
            }
            if(Fast == Slow && !FirstMeet) {
                FirstMeet = true;
                P = 0;
            }
        }
    }
    void Test(){
        vector<int> nums = {1,2,3,4,5,6,7,8,9,3};
        cout<<findDuplicate(nums)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
