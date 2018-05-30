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

class SBT{
    /*
    Size Balanced Tree
    */
    int N,IP,Root;
    vector<int> S,L,R,K;
    //zig = left rotate
    void zig(int &x){int t=R[x];R[x]=L[t];L[t]=x;S[t]=S[x];S[x]=S[L[x]]+S[R[x]]+1;x=t;}
    //zag = right rotate 
    void zag(int &x){int t=L[x];L[x]=R[t];R[t]=x;S[t]=S[x];S[x]=S[L[x]]+S[R[x]]+1;x=t;}
    //level = balance tree
    void level(int &x,bool flag){
        if(flag){
            if(S[L[L[x]]]>S[R[x]]) zag(x);
            else if(S[R[L[x]]]>S[R[x]]) zig(L[x]),zag(x);
            else return;
        }
        else{
            if(S[R[R[x]]]>S[L[x]]) zig(x);
            else if(S[L[R[x]]]>S[L[x]]) zag(R[x]),zig(x);
            else return;
        }
        level(L[x],true);level(R[x],false);
        level(x,true);level(x,false);
    }
    void _Insert(int &rt,int v){
        if(!rt) {rt=++IP;L[rt]=R[rt]=0;S[rt]=1;K[rt]=v;return;}
        v<=K[rt]?_Insert(L[rt],v):_Insert(R[rt],v);
        ++S[rt];level(rt,v<=K[rt]);
    }
    int _Rank(int &rt,int v){
        if(!rt) return 1;
        return v<=K[rt]?_Rank(L[rt],v):1+S[L[rt]]+_Rank(R[rt],v);
    }
public:
    SBT(int Size){
        N = Size;
        S = vector<int>(N+1);//Size
        L = vector<int>(N+1);//Left child
        R = vector<int>(N+1);//Right child
        K = vector<int>(N+1);//key
        S[0] = L[0] = R[0] = 0;
        IP = Root = 0;
    }
    void Insert(int v){_Insert(Root,v);}
    int Rank(int v){return _Rank(Root,v);}
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int N = nums.size();
        SBT sbt = SBT(N);
        vector<int> ret(N);
        for(int i = N - 1 ; i >= 0 ; --i){
            //get the number of valeus to the right of i
            //that is smaller than i
            ret[i] = sbt.Rank(nums[i]) - 1;
            //add i into sbt structure
            sbt.Insert(nums[i]);
        }
        return ret;
    }
    void Test(){
        vector<int> nums = {5,2,6,1};
        vector<int> ans = countSmaller(nums);
        for(auto x:ans){
            printf("%d ",x);
        }
        printf("\n");
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
