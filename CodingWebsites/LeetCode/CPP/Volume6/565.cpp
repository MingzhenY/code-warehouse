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
#include <unordered_map>
#include <set>
#include <stack>
using namespace std;

//Bug#1: Endless Loop bug in FindLoop().
//Bug#2: Logic Error in FindLoop().
//Solved the problem where A[i] <- [0,N-1](can have duplicate values).
//which is harder than where A[0..N-1] is a permutation of [0..N-1].

class Solution {
    #define NEXT(i) nums[i]
    void FindLoop(vector<int>& nums, 
                  unordered_map<int,int> &Visit,
                  unordered_map<int,int> &Loop,
                  int start, int step){
        if(Visit.count(start)){
            //Found loop, record
            if(Visit[start] != -1)
                Loop[start] = step - Visit[start];
        }
        else{
            Visit[start] = step;
            FindLoop(nums,Visit,Loop,NEXT(start),step+1);
            Visit[start] = -1;
        }
    }
    void MarkLoop(vector<int>& nums,vector<int>& LongestPath,int start,int length){
        if(LongestPath[start] == -1){
            LongestPath[start] = length;
            MarkLoop(nums,LongestPath,NEXT(start),length);
        }
        else
            return;
    }
    void UpdateRest(vector<int>& nums,vector<int>& LongestPath,int start){
        if(LongestPath[start] != -1)
            return;
        UpdateRest(nums,LongestPath,NEXT(start));
        LongestPath[start] = 1 + LongestPath[NEXT(start)];
    }
public:
    int arrayNesting(vector<int>& nums) {
        //1.Construct a graph where i -> nums[i]
        //See #define NEXT(i) nums[i]
        
        //2.Find Loops [(member,Length)]
        unordered_map<int,int> Visit;//Stores(index,step)
        unordered_map<int,int> Loop;//Stores(member,length)
        for(int start = 0 ; start < nums.size() ; ++start){
            if(!Visit.count(start))
                FindLoop(nums,Visit,Loop,start,0);
        }
        Visit.clear();
        
        vector<int> LongestPath(nums.size(),-1);
        //3.Mark Loops
        for(auto p : Loop){
            //printf("Loop(%d,%d)\n",p.first,p.second);
            MarkLoop(nums,LongestPath,p.first,p.second);
        }
        
        //4.1 record loop values
        set<int> NotLoop;
        for(int start = 0 ; start < nums.size() ; ++start)
            if(LongestPath[start] == -1)
                NotLoop.insert(start);
        //4.2 Update the rest
        for(int start = 0 ; start < nums.size() ; ++start){
            UpdateRest(nums,LongestPath,start);
        }
        //4.3 All non-loop values will be -1.
        for(auto start : NotLoop)
            LongestPath[start]--;
        
        //5.Find LongestPath
        int MaxPath = 0;
        for(auto pathlength : LongestPath){
            if(pathlength > MaxPath)
                MaxPath = pathlength;
        }
        return MaxPath;
    }
    void Test(){
        vector<int> nums={1,6,5,4,2,3,4,0,3};//ANS = 7
        //vector<int> nums={5,4,0,3,1,6,2};//ANS = 4
        cout<<arrayNesting(nums)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
