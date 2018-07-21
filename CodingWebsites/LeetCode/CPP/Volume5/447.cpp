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
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int N = points.size();
        int ANS = 0;
        for(int i = 0 ; i < N ; ++i){
            //find Boomerangs with i in the middle
            map<int,int> M;
            for(int j = 0 ; j < N ; ++j){
                if(j == i) continue;
                int D = (points[i].first - points[j].first)*(points[i].first-points[j].first) + 
                        (points[i].second - points[j].second)*(points[i].second-points[j].second);
                M[D]++;
            }
            for(auto x : M){
                ANS += x.second * (x.second - 1);
            }
        }
        return ANS;
    }
    void Test(){
        vector<pair<int,int>> P = {{0,0},{1,0},{2,0}};
        cout<<numberOfBoomerangs(P)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
