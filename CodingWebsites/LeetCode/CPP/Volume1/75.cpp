#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int N = nums.size();
        int L = 0 , R = N - 1;//[L,R]
        while(L + 1 < N && 0 == nums[L]) ++L;
        while(R > 0 && 2 == nums[R]) --R;
        
        for(int i = L ; i <= R ; ++i){
            if(nums[i] == 0){
                if(L != i){
                    int t = nums[L];
                    nums[L] = nums[i];
                    nums[i] = t;
                    ++L;
                    --i;
                }
            }
            else if (nums[i] == 2){
                if(R != i){
                    int t = nums[R];
                    nums[R] = nums[i];
                    nums[i] = t;
                    --R;
                    --i;
                }
            }
        }
    }
    void Test(){
        int A[] = {2,1,0};
        vector<int> V(A,A+sizeof(A)/sizeof(A[0]));
        sortColors(V);
        for(auto x:V){
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
