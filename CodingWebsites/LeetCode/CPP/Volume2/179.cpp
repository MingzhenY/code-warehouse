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
using namespace std;


class Solution {
public:
    static bool cmp(const string &A,const string &B){
        return A > B;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for(auto x:nums){
            char temp[32];
            sprintf(temp,"%d",x);
            strs.push_back(temp);
        }
        sort(strs.begin(),strs.end(),cmp);
        string ret = "";
        for(auto str:strs){
            ret += str;
        }
        return ret;
    }
    void Test(){
        vector<int> nums = {3,30,34,5,9};
        cout<<largestNumber(nums)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
