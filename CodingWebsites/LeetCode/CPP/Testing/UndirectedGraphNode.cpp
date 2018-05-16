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
#define DEBUG
/*
 Notes From Leetcode.com:
 OJ's undirected graph serialization:
 
 Nodes are labeled uniquely.
 We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
 
 As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 
 The graph has a total of three nodes, and therefore contains three parts as separated by #.
 
 First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 Second node is labeled as 1. Connect node 1 to node 2.
 Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 
 Visually, the graph looks like the following:
 
    1
   / \
  /   \
 0 --- 2
      / \
      \_/

 */

/*
 The following codes make testing of UndirectedGraphNode much easier.
 In this code, we assume labels could be any number, not necessarily starting from 0.
 The UGN_Build() doesn't require the input labels to be sorted.
 */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
    ~UndirectedGraphNode(){
#ifdef DEBUG
        printf("Node %d Deleted\n",label);
#endif
    }
};
/*
 UGN_Map():
 Create a map from labels to UGNs.
 Most functions here works on this map instead of a node from the graph.
 */
map<int,UndirectedGraphNode*> *UGN_Map(UndirectedGraphNode *node){
    map<int,UndirectedGraphNode*> *M = new map<int,UndirectedGraphNode*>();
    map<int,bool> InQ;
    queue<UndirectedGraphNode*> Q;
    Q.push(node);
    InQ[node->label] = true;
    while(!Q.empty()){
        UndirectedGraphNode *cnt = Q.front();Q.pop();
        (*M)[cnt->label] = cnt;
        for(auto x : cnt->neighbors){
            if(!InQ.count(x->label)){
                InQ[x->label] = true;
                Q.push(x);
            }
        }
    }
    return M;
}
/*
 UGN_Build():
 Build an undirected graph from a string described above
 
 Input(s):
 graph: A string representing the undirected graph
 
 Output(s):
 A node in undirected graph
 */
UndirectedGraphNode * UGN_Build(string graph){
    
    
    
    return NULL;
}
/*
 UGN_ToString():
 Generate the string representation of an undirected graph
 
 Input(s):
 M: a map from labels to UGNs.
 
 Output(s):
 A string representing the undirected graph with ascending label
 */
string UGN_ToString(map<int,UndirectedGraphNode*> *M){
    
    return "Not Implemented Yet";
}
/*
 UGN_Clear():
 Delete graph and clean up space
 
 Input(s):
 M: a map from labels to UGNs.
 
 Output(s):
 
 */
void UGN_Clear(map<int,UndirectedGraphNode*> *&M){
    //1.Delete all nodes in M
    for(auto x : (*M)){
        delete x.second;
    }
    //2.Delete the map itself
    delete M;
    M = NULL;
}

int main(){
    
	return 0;
}
