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
Using segment tree
*/
class Solution {
    //Rank
    int Rn;
    vector<int> Rank;
    void setRank(vector<int>& nums){
        int N = nums.size();
        Rank = vector<int>(nums);
        sort(Rank.begin(),Rank.end());
        Rn = 1;
        for(int i = 1 ; i < N ; ++i){
            if(Rank[i] != Rank[i-1]){
                Rank[Rn++] = Rank[i];
            }
        }
        Rank.resize(Rn);
    }
    int getRank(int Val){
        int L = 0, R = Rn;//[L,R)
        while(L + 1 < R){
            int M = (L + R) >> 1;
            if(Rank[M] <= Val)
                L = M;
            else
                R = M;
        }
        return L + 1;
    }
    //Segment Tree
    vector<int> ST;
    void BuildST(){
        ST = vector<int>(4*Rn,0);
    }
    void Update(int L,int V,int l,int r,int rt){
        if(l == r){
            ST[rt] += V;
            return;
        }
        int m = (l + r) >> 1;
        if(L <= m)
            Update(L,V,l,m,rt<<1);
        else
            Update(L,V,m+1,r,rt<<1|1);
        ST[rt] = ST[rt<<1] + ST[rt<<1|1];
    }
    //find k-th value
    int FindK(int K,int l,int r,int rt){
        if(l==r){
            return l - 1;
        }
        int m = (l + r) >> 1;
        if(ST[rt<<1] >= K)
            return FindK(K,l,m,rt<<1);
        else
            return FindK(K-ST[rt<<1],m+1,r,rt<<1|1);
    }
    double FindMedian(){
        int N = ST[1];
        if(N & 1){
            return Rank[FindK((N+1)/2,1,Rn,1)];
        }
        else{
            return (Rank[FindK(N/2,1,Rn,1)]*1.0+Rank[FindK(N/2+1,1,Rn,1)]*1.0)/2.0;
        }
    }
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return {};
        vector<double> Medians;
        setRank(nums);
        BuildST();
        for(int i = 0 ; i < k ; ++i)
            Update(getRank(nums[i]),1,1,Rn,1);
        Medians.push_back(FindMedian());
        for(int j = k ; j < nums.size() ; ++j){
            Update(getRank(nums[j-k]),-1,1,Rn,1);
            Update(getRank(nums[j]),1,1,Rn,1);
            Medians.push_back(FindMedian());
        }
        return Medians;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
