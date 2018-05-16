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

class NumArray1 {
    /*
     Binary Indexed Tree
     */
    vector<int> sum,vals;
public:
    NumArray1(vector<int> nums) {
        sum = vector<int>(nums.size() + 1, 0);
        vals = nums;
        for(int i = 0 ; i < nums.size() ; ++i){
            for(int x = i + 1 ; x < sum.size() ; x += x & -x)
                sum[x] += vals[i];
        }
    }
    int query(int x){
        int A = 0;
        for(; x ; x -= x & -x)
            A += sum[x];
        return A;
    }
    void update(int i, int val) {
        for(int x = i + 1 ; x < sum.size() ; x += x & -x){
            sum[x] += val - vals[i];
        }
        vals[i] = val;
    }
    
    int sumRange(int i, int j) {
        return query(j+1) - query(i);
    }
};

class NumArray2 {
    /*
     non-recursive segment tree
     */
    int N;
    vector<int> sum;
    void Build(vector<int> &nums){
        int n = nums.size();
        N = 1;
        while(N < n + 2) N *= 2;
        sum = vector<int>(N * 2, 0);
        for(int i = N + 1, j = 0 ; j < n ; ++i, ++j){
            sum[i] = nums[j];
        }
        for(int i = N - 1 ; i > 0 ; --i){
            sum[i] = sum[i * 2] + sum[i * 2 + 1];
        }
    }
    void Update(int X,int V){
        sum[X += N] = V;
        while(X /= 2){
            sum[X] = sum[X * 2] + sum[X * 2 + 1];
        }
    }
    int Query(int L,int R){
        int ANS = 0;
        for(int s = N + L - 1 , t = N + R + 1 ; s ^ t ^ 1 ; s /= 2, t /= 2){
            if(s % 2 == 0) ANS += sum[s ^ 1];
            if(t % 2 == 1) ANS += sum[t ^ 1];
        }
        return ANS;
    }
public:
    NumArray2(vector<int> nums) {
        Build(nums);
    }
    void update(int i, int val) {
        Update(i + 1,val);
    }
    
    int sumRange(int i, int j) {
        return Query(i + 1,j + 1);
    }
};


class NumArray3 {
    /*
     non-recursive segment tree from 'solution'
     */
    int N;
    vector<int> sum;
    void Build(vector<int> &nums){
        N = nums.size();
        sum = vector<int>(N * 2, 0);
        for(int i = N, j = 0 ; j < N ; ++i, ++j){
            sum[i] = nums[j];
        }
        for(int i = N - 1 ; i > 0 ; --i){
            sum[i] = sum[i * 2] + sum[i * 2 + 1];
        }
    }
    void Update(int X,int V){
        sum[X += N] = V;
        while(X /= 2){
            sum[X] = sum[X * 2] + sum[X * 2 + 1];
        }
    }
    int Query(int L,int R){
        int A = 0;
        for(int s = L + N, t = R + N; s <= t ; s /= 2, t /= 2){
            if(  s & 1) A += sum[s++];
            if(~ t & 1) A += sum[t--];
        }
        return A;
    }
public:
    NumArray3(vector<int> nums) {
        Build(nums);
    }
    void update(int i, int val) {
        Update(i,val);
    }
    
    int sumRange(int i, int j) {
        return Query(i,j);
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
class Solution {
public:
    void Test(){
        vector<int> V = {1,2,3,4,5,6,7,8,9,10};
        int n = V.size();
        NumArray2 NA2(V);
        NumArray3 NA3(V);
        for(int i = 0 ; i < n ; ++i){
            for(int j = i ; j < n ; ++j){
                int S2 = NA2.sumRange(i,j);
                int S3 = NA3.sumRange(i,j);
                if(S2 != S3){
                    i = j = n;
                    printf("%3d - %3d \n",S2,S3);
                }
            }
        }
        for(int i = 0 ; i < n ; ++i){
            int X = rand() % 20;
            NA2.update(i,V[i] + X);
            NA3.update(i,V[i] + X);
        }
        for(int i = 0 ; i < n ; ++i){
            for(int j = i ; j < n ; ++j){
                int S2 = NA2.sumRange(i,j);
                int S3 = NA3.sumRange(i,j);
                if(S2 != S3){
                    i = j = n;
                    printf("%3d - %3d \n",S2,S3);
                }
            }
        }
    }
};
int main(){
    Solution S;
    S.Test();
	return 0;
}
