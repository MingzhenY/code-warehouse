#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <list>
#include <cmath>
#include <set>
#include <queue>
using namespace std;
/*Solution 1: insert into set and then go through set one time
    O(n * log(n))
 
 */
class Solution1 {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        set<int> S;
        for(int i = 0 ; i < n ; i++){
            S.insert(nums[i]);
        }
        int cnt = 0;
        int MaxGap = 0;
        int Prev = 0;
        for(auto x:S){
            if(cnt++){
                int Gap = x - Prev;
                if(Gap > MaxGap) MaxGap = Gap;
            }
            Prev = x;
        }
        return MaxGap;
    }
    void Test(){
        vector<int> V = {1,3,5,9,6};
        cout<<maximumGap(V)<<endl;
    }
};
/* Solution 2:
 bucket sort: 16 buckets, sort by 4 bit at a time
 O(9 * n)
 */
class Solution2 {
public:
    int maximumGap(vector<int>& nums) {
        list<int> L[16];
        list<int> NL[16];
        
        //After each pass, all numners are in L, and NL is empty
        int Mask = 15;
        //First Pass, sort first 4 bit
        for(int i = 0 ; i < nums.size() ; i++){
            L[nums[i] & Mask].push_back(nums[i]);
        }
        
        //Next 7 pass
        int RightShift = 0;
        for(int k = 0 ; k < 7 ; k++){
            Mask <<= 4;
            RightShift += 4;
            for(int i = 0 ; i < 16 ; i++){
                swap(L[i],NL[i]);
            }
            for(int i = 0 ; i < 16 ; i++){
                for(auto x : NL[i]){
                    L[(x&Mask)>>RightShift].push_back(x);
                }
                NL[i].clear();
            }
        }
        int Prev = -1;
        int MaxDiff = 0;
        //Final pass, read through all the numbers
        for(int i = 0 ; i < 16 ; i++){
            for(auto x : L[i]){
                if(Prev >= 0){
                    int Diff = x - Prev;
                    if(Diff > MaxDiff){
                        MaxDiff = Diff;
                    }
                }
                Prev = x;
            }
        }
        return MaxDiff;
    }
    void Test(){
        vector<int> V = {1,3,5,9,6};
        cout<<maximumGap(V)<<endl;
    }
};

/* Solution 3:
 The minimum gap is (MaxV - MinV)/(N - 1)
 So if each bucket has a value range less than the above value,
 only max and min is needed in each bucket(values in the same
 bucket cannot have a gap larger than the value range).
 
 In this case, go through nums once, and virtually fill the buckets,
 that is, only record Max and Min in each bucket.
 And then go through the buckets in order, to calculate gaps between
 buckets.
 */
class Solution3 {
public:
    int maximumGap(vector<int>& nums) {
        
        
        
        return 0;
    }
    void Test(){
        vector<int> V = {1,3,5,9,6};
        cout<<maximumGap(V)<<endl;
    }
};
int main(){
    Solution2 S;
    S.Test();
	return 0;
}
