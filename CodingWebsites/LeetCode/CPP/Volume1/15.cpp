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
    vector<vector<int>> threeSum(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(),nums.end());
        if(nums.size() > 0){
            int ID = 1;
            int V = nums[0],Cnt = 1;
            for(int i = 1 ; i < N ; ++i){
                if(nums[i] == V){
                    if(++Cnt <= 3){
                        nums[ID++] = V;
                    }
                }
                else{
                    V = nums[i];
                    Cnt = 1;
                    nums[ID++] = V;
                }
            }
            nums.resize(ID);
            N = ID;
        }
        
        
        vector<vector<int>> ANS;
        int D[3];
        for(int i = 0 ; i < N ; ++i){
            for(int j = i + 1 ; j + 1 < N ; ++j){
                int Sum2 = nums[i] + nums[j];
                int I3 = BinarySearch(nums,j + 1,N,-Sum2);
                //printf("I3 = %d\n",I3);
                if(I3 >= 0){
                    D[0] = nums[i];
                    D[1] = nums[j];
                    D[2] = nums[I3];
                    ANS.push_back(vector<int>(D,D+3));
                }
            }
        }
        sort(ANS.begin(),ANS.end());
        
        if(ANS.size() >= 2){
            int RI = 1;
            for(int i = 1 ; i < ANS.size() ; ++i){
                if(ANS[i][0] != ANS[i - 1][0] ||
                   ANS[i][1] != ANS[i - 1][1] ||
                   ANS[i][2] != ANS[i - 1][2])
                    ANS[RI++] = ANS[i];
            }
            ANS.resize(RI);
        }
        return ANS;
    }
    int BinarySearch(vector<int>& nums,int i,int N,int v){//does v exist in range [i,N]
        if(v < nums[i]) return -1;
        int L = i , R = N, M;//[L,R) last <= v
        while(L + 1 < R){
            M = (L + R) >> 1;
            if(nums[M] <= v) L = M;
            else R = M;
        }
        //printf("nums[%d]=%d\n",L,nums[L]);
        return nums[L] == v ? L : -1;
    }
    void Test(){
        //int nums[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
        int nums[] = {-4,-5,-6,3,11,-13,3,14,1,-10,11,6,8,9,-6,-9,6,3,-15,-8,0,5,6,-8,14,-11,0,2,14,-15,14,-13,-5,-15,5,13,-13,-6,13,-4,-1,1,-13,14,-13,-12,-10,9,6,12,8,14,-5,-8,-9,-6,-4,-2,3,-5,-2,-6,-2,1,-5,-12,-1,-11,-11,-11,0,-4,-2,-5,-5,0,-2,-7,-14,-10,-10,10,-11,-8,-13,-13,1,-2,-7,11,8,6,-9,-9,14,1,-13,-9,-3,-9,-5,13,2,8,-7,13,-14,6,-9,-13,3,-12};
        vector<int> N(nums,nums + sizeof(nums) / sizeof(int));
        vector<vector<int>> ANS = threeSum(N);
        for(auto a : ANS){
            for(auto i:a){
                printf("%d ",i);
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
