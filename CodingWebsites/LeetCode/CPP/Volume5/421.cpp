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
    int HighBit(int x){
        for(int mask = 0x40000000, k = 30 ; mask ; mask >>= 1, --k)
            if(x & mask)
                return k;
        return 0;
    }
    int FindMax(vector<int>& nums, int L,int R){
        //find max in nums[L,R)
        int Max = nums[L];
        for(int i = L ; i < R ; ++i)
            Max = max(Max,nums[i]);
        return Max;
    }
    int SortByBit(vector<int>& nums, int L, int R, int k){
        //Sort nums[L,R) by the k-th bit, return the split index
        int mask = 1 << k;
        int IL = L, IR = R;//[L,R)
        while(true){
            while(IL < IR && (~nums[IL] & mask))
                ++IL;
            while(IL < IR && (nums[IR-1] & mask))
                --IR;
            if(IL >= IR)
                break;
            //now nums[IL] has bit 1, nums[IR-1] has bit 0
            swap(nums[IL],nums[IR-1]);
        }
        //nums[L,IL) has 0s in the k-th bit
        //nums[IL,R) has 1s in the k-th bit
        return IL;
    }
    void Show(string tag,vector<int> &nums,int L0,int R0,int L1,int R1){
        printf("%s : ",tag.c_str());
        for(int i = L0 ; i < R0 ; ++i)
            printf("%d ",nums[i]);
        printf("|| ");
        for(int i = L1 ; i < R1 ; ++i)
            printf("%d ",nums[i]);
        printf("\n");
    }
    int F01(vector<int> &nums,int L0,int R0,int L1,int R1,int k){
        //the k-th bit of [L0,R0) are 0s
        //the k-th bit of [L1,R1) are 1s
        //returns the max xor of (the lower (k+1) bits of numbers) in range [L0,R0) + [L1,R1)
        
        //End Function when k is 0
        if(k <= 0){
            return L0 < R0 && L1 < R1;
        }
        if(L0 == R0 || L1 == R1){
            //the k-th bit are all the same
            //This means the xor of any two numbers in this range
            //will have a 0 in the k-th bit
            //So we don't care about the k-th bit
            int L,R;
            if(L0 == R0) L = L1, R = R1;
            else L = L0, R = R0;
            
            //split by (k-1)-th bit and call F01 again.
            int M = SortByBit(nums,L,R,k - 1);
            return F01(nums,L,M,M,R,k - 1);
        }
        else{
            //There are 1s and 0s in k-th bit
            //So the max xor will have 1 in the k-th bit
            int M0 = SortByBit(nums,L0,R0,k-1);
            int M1 = SortByBit(nums,L1,R1,k-1);
            
            //Case 1 : k-th bit can be 1
            if( (L0 < M0 && M1 < R1) ||
                (M0 < R0 && L1 < M1)){
                //this is when current bit is 1
                int A = F01(nums,L0,M0,M1,R1,k-1);
                int B = F01(nums,L1,M1,M0,R0,k-1);
                if(false){
                    Show("A",nums,L0,M0,M1,R1);
                    Show("B",nums,L1,M1,M0,R0);
                    printf("A = %d, B = %d\n",A,B);
                }
                return (1 << k) | max(A,B);
            }
            //Case 2 : k-th bit must be 0
            if( (M0 == R0 && M1 == R1) ||
                (M0 == L0 && M1 == L1)){
                if(M0 == R0 && M1 == R1){
                    //0s : [L0,M0) + [L1,M1)
                    vector<int> V;
                    for(int i = L0 ; i < M0 ; ++i) V.push_back(nums[i]);
                    for(int i = L1 ; i < M1 ; ++i) V.push_back(nums[i]);
                    return (1 << k) | F01(V,0,V.size(),V.size(),V.size(),k);
                }
                else{
                    //1s : [M0,R0) + [M1,R1)
                    vector<int> V;
                    for(int i = M0 ; i < R0 ; ++i) V.push_back(nums[i]);
                    for(int i = M1 ; i < R1 ; ++i) V.push_back(nums[i]);
                    return (1 << k) | F01(V,0,0,0,V.size(),k);
                }
            }
            printf("ERROR in F01\n");
            return 0;
        }
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        int highBit = HighBit(FindMax(nums,0,nums.size()));
        //To fit the requirement of F01
        //all the numbers has (highBit + 1)-th bit as 0
        //So the left range is [0,nums.size())
        //the right range is [nums.size(),nums.size()) (which is the empty range)
        return F01(nums,0,nums.size(),nums.size(),nums.size(),highBit + 1);
    }
    void Test(){
        vector<int> nums = {3,10,5,25,2,8};
        //nums = vector<int>{5,25};
        printf("%d\n",findMaximumXOR(nums));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
