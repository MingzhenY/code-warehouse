#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0 ; i < nums.size() ; ++i){
            for(int j = 0 ; j < nums.size(); ++j){
                if(i==j) continue;
                if(nums[i]+nums[j] == target){
                    vector<int> V;
                    V.push_back(i);
                    V.push_back(j);
                    return V;
                }
            }
        }
        
        return vector<int>();
    }
};

int main(){
    Solution S;
    vector<int> V;
    V.push_back(3);
    V.push_back(2);
    V.push_back(4);
    
    //cout<<S.twoSum(V,6)<<endl;
    vector<int> ANS = S.twoSum(V,6);
    for(auto a:ANS){
        cout<<a<<endl;
    }

	return 0;
}
