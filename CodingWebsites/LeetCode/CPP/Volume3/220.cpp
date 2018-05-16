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
#define LL long long
private:
    //Need a data structure that supports the following operation
    //1. Add number
    //2. Delete number
    //3. Find the minimum differences between numbers
    //To do this, use two maps
    map<LL,int> MC;//Count each number
    map<LL,int> MI;//Count each interval
    void Add(int V){
        //If number already inside
        //No need to update MI
        if(MC.count(V)){
            if(++MC[V] == 2){
                ++MI[0];
            }
            return;
        }
        ++MC[V];
        map<LL,int>::iterator L,R;
        int T = 0;
        L = R = MC.find(V);
        if(L != MC.begin()){
            ++MI[V - (--L)->first];
            ++T;
        }
        if(++R != MC.end()){
            ++MI[R->first - V];
            ++T;
        }
        if(2 == T){
            LL X = R->first - L->first;
            if(1 == MI[X]) MI.erase(X);
            else --MI[X];
        }
    }
    void Remove(int V){
        if(MC[V] > 1){
            if(--MC[V] == 1){
                if(MI[0] == 1) MI.erase(0);
                else --MI[0];
            }
            return;
        }
        map<LL,int>::iterator L,R;
        int T = 0;
        L = R = MC.find(V);
        if(L != MC.begin()){
            LL VL = V - (--L)->first;
            if(MI[VL] == 1) MI.erase(VL);
            else MI[VL]--;
            ++T;
        }
        if(++R != MC.end()){
            LL VR = R->first - V;
            if(MI[VR] == 1) MI.erase(VR);
            else MI[VR]--;
            ++T;
        }
        if(T == 2){
            LL VLR = R->first - L->first;
            MI[VLR]++;
        }
        MC.erase(V);
    }
    LL getMinDist(){
        if(MI.empty()) return -1;
        return MI.begin()->first;
    }
    void Show(){
        cout<<"MC:";
        for(auto x:MC){
            cout<<"("<<x.first<<","<<x.second<<")";
        }
        cout<<endl;
        cout<<"MI:";
        for(auto x:MI){
            cout<<"("<<x.first<<","<<x.second<<")";
        }
        cout<<endl;
    }
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int N = nums.size();
        MC.clear();
        MI.clear();
        for(int i = 0 ; i < N ; i++){
            if(i > k)
                Remove(nums[i - k - 1]);
            Add(nums[i]);
            LL D = getMinDist();
            printf("D[%d]=%d\n",i,D);
            if(D != -1 && D <= t)
                return true;
        }
        return false;
    }
    void Test(){
        vector<int> nums = {-1,2147483647};
        cout<<containsNearbyAlmostDuplicate(nums,1,2147483647)<<"\n";
        cout<<containsNearbyAlmostDuplicate(nums,1,-1)<<endl;
        return;
        Add(1);
        Show();
        Add(3);
        Show();
        Add(1);
        Show();
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
