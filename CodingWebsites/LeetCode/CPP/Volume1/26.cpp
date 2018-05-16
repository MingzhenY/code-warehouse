#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() > 0){
            int ID = 1;
            for(int i = 1 ; i < nums.size() ; ++i){
                if(nums[i] != nums[i - 1]){
                    nums[ID++] = nums[i];
                }
            }
            nums.resize(ID);
            return ID;
        }
        else return 0;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
