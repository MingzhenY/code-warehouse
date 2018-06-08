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
        int val;
        int count;
        A(int val = 0,int count = 0):val(val),count(count){}
        bool operator <(const A &B)const{
            return count > B.count || 
                (count == B.count && val > B.val);
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> M,N;
        //O(n * log(k))
        for(auto x : nums){
            M[x]++;
        }
        
        //O(k * log(k))
        int X = M.size();
        vector<A> C;
        for(auto x:M){
            C.push_back(A(x.first,x.second));
        }
        sort(C.begin(),C.end());
        
        //O(k)
        vector<int> ret;
        for(int i = 0 ; i < k ; ++i)
            ret.push_back(C[i].val);
        return ret;
    }
    void Test(){
        vector<int> nums = {1,1,1,2,2,3};
        vector<int> ans = topKFrequent(nums,2);
        for(auto x:ans){
            printf("%d\n",x);
        }
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
