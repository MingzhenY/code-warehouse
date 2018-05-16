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
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(!n) return;
        k %= n;
        if(!k) return;
        // k * C = 0 (mod n)
        //There are G cicles with C elements each
        int G = gcd(k,n);
        int C = n / G;
        
        for(int i = 0 ; i < G ; i++){
            int j = i;
            int V = nums[j];
            for(int t = 0 ; t < C ; t++){
                int nextj = (j + k) % n;
                int nV = nums[nextj];
                nums[nextj] = V;
                V = nV;
                j = nextj;
            }
        }
    }
    int gcd(int x,int y){
        while(y){
            int t = x % y;
            x = y;
            y = t;
        }
        return x;
    }
    void Test(){
        vector<int> V = {1,2,3,4,5,6};
        rotate(V,4);
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
