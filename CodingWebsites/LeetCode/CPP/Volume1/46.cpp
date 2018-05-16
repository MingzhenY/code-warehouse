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
    vector<vector<int>> permute(vector<int>& nums) {
        int N = nums.size();
        vector<bool> Vis(N,0);
        vector<int> Stk(N,-1);
        int Top = 0;
        vector<vector<int>> ANS;
        //int MaxCount = 0;
        while(Top >= 0){
            //if(++MaxCount > 1000) break;
            //printf("Top = %d\n",Top);
            if(Top == N){
                //Record Anawer
                vector<int> temp;
                for(int i = 0 ; i < Top ; ++i)
                    temp.push_back(nums[Stk[i]]);
                ANS.push_back(temp);
                //move down
                --Top;
            }
            else{
                if(Stk[Top] >= 0){
                    //Remove Old
                    Vis[Stk[Top]] = false;
                }
                FindNext(Vis,Stk[Top]);
                if(Stk[Top] >= 0){
                    //Add new, move up
                    Vis[Stk[Top]] = true;
                    ++Top;
                }
                else{
                    //The number is finished, move down
                    Stk[Top--] = -1;
                }
            }
        }
        
        return ANS;
    }
    void FindNext(vector<bool>& Vis,int &I){
        int N = Vis.size();
        for(int i = I + 1; i < N ; ++i)
            if(!Vis[i]) {
                I = i;
                return;
            }
        I = -1;
    }
    void Test(){
        int A[] = {6,3,2,7,4,-1};
        vector<int> nums(A,A+sizeof(A)/sizeof(A[0]));
        vector<vector<int>> ans = permute(nums);
        for(auto line : ans){
            for(auto x:line) cout<<x<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
