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
#include <queue>
using namespace std;

struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
 };

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        map<int,UndirectedGraphNode *> M;
        map<int,bool> Vis;
        queue<UndirectedGraphNode *> Q;
        Q.push(node);
        Vis[node->label] = true;
        while(!Q.empty()){
            UndirectedGraphNode *cnt = Q.front();Q.pop();
            UndirectedGraphNode *T = MGetNode(M,cnt->label);
            for(auto x:cnt->neighbors){
                T->neighbors.push_back(MGetNode(M,x->label));
                if(!Vis[x->label]){
                    Vis[x->label] = true;
                    Q.push(x);
                }
            }
        }
        return MGetNode(M,node->label);
    }
    UndirectedGraphNode * MGetNode(map<int,UndirectedGraphNode *> &M,int label){
        if(M.count(label)) return M[label];
        else {
            M[label] = new UndirectedGraphNode(label);
            return M[label];
        }
    }
    void Test(){
        UndirectedGraphNode *node = new UndirectedGraphNode(0);
        node->neighbors.push_back(node);
        node->neighbors.push_back(node);
        UndirectedGraphNode *temp = cloneGraph(node);
        printf("label = %d, neighbors.size()=%lu\n",temp->label,temp->neighbors.size());
        
        delete temp;
        delete node;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
