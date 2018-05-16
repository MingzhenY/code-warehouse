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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int N = nums.size();
        
        //Step One: sort the numbers
        sort(nums.begin(),nums.end());
        
        //Step Two: Limit each number to 4 times
        if(nums.size() > 1){
            int ID = 0;
            int V = nums[0] + 1;
            int Times = 1;
            
            for(int i = 0 ; i < N ; ++i){
                if(nums[i] == V){
                    Times++;
                }
                else {
                    V = nums[i];
                    Times = 1;
                }
                if(Times <= 4){
                    nums[ID++] = nums[i];
                }
            }
            nums.resize(N = ID);
        }
        
        //Step Three: Search for the answers
        vector<vector<int>> Ans;
        for(int i = 0 ; i < N - 3 ; ++i){
            for(int j = i + 1 ; j < N - 2 ; ++j){
                //Select First Two Number nums[i] and nums[j]
                int SumFirst2 = nums[i] + nums[j];
                int SumLast2 = target - SumFirst2;
                //Find Last Two numbers
                int L = j + 1 , R = N - 1;//[L,R]
                while(L < R){
                    int CurSumLast2 = nums[L] + nums[R];
                    if(CurSumLast2 == SumLast2){
                        //Record
                        int D[4];
                        D[0] = nums[i];
                        D[1] = nums[j];
                        D[2] = nums[L];
                        D[3] = nums[R];
                        Ans.push_back(vector<int>(D,D+4));
                        //Move On
                        ++L, --R;
                    }
                    else if(CurSumLast2 < SumLast2){
                        ++L;
                    }
                    else if(CurSumLast2 > SumLast2) {
                        --R;
                    }
                }
            }
        }
        
        //Step Four: Remove Duplicates
        sort(Ans.begin(),Ans.end());
        if(Ans.size() > 1){
            int ID = 1;
            for(int i = 1 ; i < Ans.size() ; ++i){
                if(Ans[i][0] != Ans[i - 1][0] ||
                   Ans[i][1] != Ans[i - 1][1] ||
                   Ans[i][2] != Ans[i - 1][2] ||
                   Ans[i][3] != Ans[i - 1][3]){
                    Ans[ID++] = Ans[i];
                }
            }
            Ans.resize(ID);
        }
        return Ans;
    }
    void Test(){
        int S[] = {-3,-2,-1,0,0,1,2,3};
        vector<int> Sums(S,S+sizeof(S)/sizeof(S[0]));
        vector<vector<int> > V = fourSum(Sums,0);
        for(auto i:V){
            for(auto j:i){
                printf("%d ",j);
            }
            printf("\n");
        }
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
