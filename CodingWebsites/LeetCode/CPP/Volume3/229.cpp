#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <list>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <ctime>
using namespace std;

class Solution1 {
    /* Method 1: use probability
     
     */
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(!n) return {};
        srand(time(NULL));
        map<int,int> M;
        int K = min(1000,n * 3);
        for(int i = 0 ; i < K ; ++i){
            ++M[nums[rand()%n]];
        }
        if(n < 1000){
            for(int i = 0 ; i < n ; ++i){
                ++M[nums[i]];
            }
        }
        vector<int> V;
        for(auto x:M){
            if(x.second > K / 4){
                V.push_back(x.first);
            }
        }
        M.clear();
        for(int i = 0 ; i < V.size() ; ++i){
            M[V[i]] = 0;
        }
        
        for(int i = 0 ; i < n ; ++i){
            if(M.count(nums[i])){
                ++M[nums[i]];
            }
        }
        vector<int> ret;
        for(auto x:M){
            if(x.second > n/3){
                ret.push_back(x.first);
            }
        }
        return ret;
    }
    void Test(){
        vector<int> nums = {8,8,7,7,7};
        vector<int> ret = majorityElement(nums);
        for(auto x:ret){
            cout<<x<<" ";
        }
        cout<<endl;
    }
};

class Solution {
    /* Method 2:
     note that, there are at most two values to output(say A and B)
     the are both more than n/3, so the number of random numbers are smaller than
     the number of A and the number of B. So, record two number and if a new number occurs,
     decrease the number count of the recorded number
     This can ensure that the output number is in the recorded number.
     but the number recorded might not be the answer(in the case where only one number appears
     more than n/3 times). So we should go through nums again to count the recorded numbers.
     */
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int A,CA,B,CB;
        CA = CB = 0;
        for(int i = 0 ; i < n ; ++i){
            int &x = nums[i];
            if(CA && x == A) ++CA;
            else if(CB && x == B) ++CB;
            else if(!CA) A = x, ++CA;
            else if(!CB) B = x, ++CB;
            else --CA, --CB;
        }
        vector<int> ret;
        CA = CB = 0;
        for(int i = 0 ; i < n ; ++i){
            CA += nums[i] == A;
            CB += nums[i] == B;
        }
        if(CA > n / 3) ret.push_back(A);
        if(CB > n / 3 && B != A) ret.push_back(B);
        return ret;
    }
    void Test(){
        vector<int> nums = {2,2};
        vector<int> ret = majorityElement(nums);
        for(auto x:ret){
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
