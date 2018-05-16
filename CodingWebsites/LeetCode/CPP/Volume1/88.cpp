#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> A(m);
        for(int i = 0 ; i < m ; ++i) A[i] = nums1[i];
        int I = 0, L1 = 0 , L2 = 0;
        while(L1 < m && L2 < n){
            if(A[L1] < nums2[L2]){
                nums1[I++] = A[L1++];
            }
            else{
                nums1[I++] = nums2[L2++];
            }
        }
        while(L1 < m){
            nums1[I++] = A[L1++];
        }
        while(L2 < n){
            nums1[I++] = nums2[L2++];
        }
    }
    void Test(){
        int A[10] = {1,3,5,7,9,0,0,0,0,0};
        int B[5] = {2,4,6,8,10};
        vector<int> nums1(A,A+sizeof(A)/sizeof(A[0]));
        vector<int> nums2(B,B+sizeof(B)/sizeof(B[0]));
        merge(nums1,5,nums2,5);
        for(auto x : nums1){
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
