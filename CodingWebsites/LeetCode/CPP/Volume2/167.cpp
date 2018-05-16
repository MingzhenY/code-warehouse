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
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L = 0 , R = numbers.size()-1;
        while(L < R){
            if(numbers[L] + numbers[R] == target)
                return vector<int> {L+1,R+1};
            if(numbers[L] + numbers[R] > target){
                R--;
            }
            else{
                L++;
            }
        }
        return vector<int> {-1,-1};
    }
    void Test(){
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
