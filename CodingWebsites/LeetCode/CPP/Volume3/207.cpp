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
    struct Node{
        list<int> L;
        int in;
        Node():in(0){}
    };
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<Node> V(numCourses);
        for(auto x:prerequisites){
            V[x.second].L.push_back(x.first);
            V[x.first].in++;
        }
        queue<int> Q;
        for(int i = 0 ; i < V.size() ; i++){
            if(0 == V[i].in){
                Q.push(i);
            }
        }
        int Left = numCourses;
        while(!Q.empty()){
            int k = Q.front();Q.pop();
            --Left;
            for(auto to : V[k].L){
                if(0 == --V[to].in){
                    Q.push(to);
                }
            }
        }
        return !Left;
    }
    void Test(){
        vector<pair<int, int>>  prerequisites = {{1,0}};
        cout<<canFinish(2,prerequisites)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
