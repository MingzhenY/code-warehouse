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
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
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
        
    }
};
/*

    What if the given array is already sorted? How would you optimize your algorithm?
        remove the sort functions in first two lines
    What if nums1's size is small compared to nums2's size? Which algorithm is better?
    What if elements of nums2 are stored on disk, and the memory is limited such that 
        you cannot load all elements into the memory at once?
        create a binary search tree from nums1, then for each num in nums2, search in
        that tree.
*/

int main(){
    Solution S;
    S.Test();
	return 0;
}
