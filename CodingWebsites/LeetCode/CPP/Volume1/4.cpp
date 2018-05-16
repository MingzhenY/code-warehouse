#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
class Solution {
private:
    vector<int> V;
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1,N2,N,NL;
        N1 = nums1.size();
        N2 = nums2.size();
        N = N1 + N2;
        NL = N >> 1;
        if(N1 < N2) return findMedianSortedArrays(nums2,nums1);
        
        if(N <= 1) {
            if(N == 0) return 0.0;
            else if(N == 1) return nums1[0];
            else {
                //Should not get here
                return -123.4567;
            }
        }
        
        //now N1 >= N2
        //index i means nums1[0..i) plus nums2[0..NL-i) is the Left group
        int L = (N1 - N2) >> 1, R = NL;//[L,R]
        while(L < R){
            int M = (L + R) >> 1;
            if(M < N1 && NL - M > 0 && nums1[M] < nums2[NL - M - 1]){
                //Move up
                L = M + 1;
                continue;
            }
            if(M > 0 && NL - M < N2 && nums1[M - 1] > nums2[NL - M]){
                //Move Down
                R = M;
                continue;
            }
            //No need to move, done
            L = M;
            break;
        }
        //now i = L is the line
        double LMax = 0.0,RMin = 0.0;
        LMax =
        L == 0 ? nums2[NL - L - 1]:
        NL - L == 0 ? nums1[L - 1]:
        max(nums1[L - 1],nums2[NL - L - 1]);
        RMin =
        L == N1 ? nums2[NL - L]:
        NL - L == N2 ? nums1[L]:
        min(nums1[L],nums2[NL - L]);
        
        return N & 1 ? RMin : (LMax + RMin) / 2.0;
    }
    vector<int> Getnums1(){
        //int A[] = {1,5,9,13,17,21,25};
        int A[] = {2,4};
        vector<int> VA(A,A+sizeof(A) / sizeof(A[0]));
        return VA;
    }
    vector<int> Getnums2(){
        //int A[] = {2,5,8,11,14,17,20,23,26};
        int A[] = {};
        vector<int> VA(A,A+sizeof(A) / sizeof(A[0]));
        return VA;
    }
    void Test(){
        vector<int> A = Getnums1();
        vector<int> B = Getnums2();
        cout<<findMedianSortedArrays(A,B)<<endl;
    }
};

/*
class Solution {//Binary Search  log(log(m*n))
private:
    int N1,N2,N,MaxNum,MinNum;
    vector<int> *Nums1;
    vector<int> *Nums2;
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        N1 = nums1.size();
        N2 = nums2.size();
        N = N1 + N2;
        Nums1 = &nums1;
        Nums2 = &nums2;
        MaxNum = MinNum = nums1.size()?nums1[0]:nums2.size()?nums2[0]:0;
        for(int i = 0 ; i < N1 ; ++i){
            if(nums1[i] > MaxNum) MaxNum = nums1[i];
            if(nums1[i] < MinNum) MinNum = nums1[i];
        }
        for(int i = 0 ; i < N2 ; ++i){
            if(nums2[i] > MaxNum) MaxNum = nums2[i];
            if(nums2[i] < MinNum) MinNum = nums2[i];
        }
        
        double ANS = 0.0;
        if(N & 1){
            ANS = AtRank(N / 2);
        }
        else{
            ANS = (AtRank(N / 2) + AtRank(N / 2 - 1))/2.0;
        }
        return ANS;
    }
    int GetRank(int v){//get v's rank is v is inserted into the numbers
        
    }
    int AtRank(int k){//Get the k-th number
        if(k < 0 || k >= N) {printf("Error in Rank\n");return 0};
        
    }
};*/

int main(){
    Solution S;
    S.Test();
	return 0;
}
