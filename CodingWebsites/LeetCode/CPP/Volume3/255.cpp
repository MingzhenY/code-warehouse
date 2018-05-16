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
public:
    bool verifyPreorder(vector<int>& preorder) {
        int Max,Min;
        bool empty;
        return verify(preorder,0,preorder.size(),empty,Max,Min);
    }
    bool verify(vector<int> &preorder,int L,int R,bool &Empty, int &Max, int &Min){
        //[L , R)
        if(L >= R){
            Empty = true;
            return true;
        }
        if(L + 1 == R){
            Empty = false;
            Max = Min = preorder[L];
            return true;
        }
        int M = L;
        int V = preorder[L];
        while(M < R && preorder[M] <= V) ++M;
        //L - [L + 1 , M) [M , R)
        //printf("(%d,%d) = %d:[%d,%d) [%d,%d)\n",L,R,L,L+1,M,M,R);
        bool LEmpty, REmpty, LValid, RValid;
        int LMax,LMin,RMax,RMin;
        LValid = verify(preorder,L + 1,M,LEmpty,LMax,LMin);
        RValid = verify(preorder,M,R,REmpty,RMax,RMin);
        Empty = false;
        if(LEmpty){
            Max = max(V,RMax);
            Min = min(V,RMin);
        }
        else if(REmpty){
            Max = max(V,LMax);
            Min = min(V,LMin);
        }
        else{
            Max = max(V,max(LMax,RMax));
            Min = min(V,min(LMin,RMin));
        }
        return LValid && RValid && (LEmpty || LMax < V) && (REmpty || RMin > V);
    }
    void Test(){
        vector<int> nums = {10,5,3,7,19,12,11,15,20,23};
        nums = {2,4,1,3};
        cout<<verifyPreorder(nums)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
