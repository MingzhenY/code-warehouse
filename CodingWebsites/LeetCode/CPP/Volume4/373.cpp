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
    struct A{
        int I1,I2;
        int Sum;
        A(int I1,int I2,int Sum):I1(I1),I2(I2),Sum(Sum){}
        bool operator <(const A & B)const{
            return Sum > B.Sum;
        }
    };
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int N1 = nums1.size(), N2 = nums2.size();
        if(!N1 || !N2)
            return {};
        priority_queue<A> Q;
        Q.push(A(0,0,nums1[0]+nums2[0]));
        //Use set to avoid adding the same pair into queue multiple times
        set<pair<int,int>> S;
        vector<pair<int,int>> ret;
        while(!Q.empty() && ret.size() < k){
            A t = Q.top();
            Q.pop();
            ret.push_back(make_pair(nums1[t.I1],nums2[t.I2]));
            pair<int,int> P;
            P = make_pair(t.I1 + 1,t.I2);
            if(P.first < N1 && P.second < N2 && !S.count(P)){
                S.insert(P);
                Q.push(A(P.first,P.second,nums1[P.first]+nums2[P.second]));
            }
            P = make_pair(t.I1,t.I2 + 1);
            if(P.first < N1 && P.second < N2 && !S.count(P)){
                S.insert(P);
                Q.push(A(P.first,P.second,nums1[P.first]+nums2[P.second]));
            }
        }
        return ret;
    }
    void Test(){
        vector<int> nums1 = {1,7,11}, nums2 = {2,4,6};
        auto ans = kSmallestPairs(nums1,nums2,4);
        for(auto p : ans){
            printf("(%d,%d)\n",p.first,p.second);
        }
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
