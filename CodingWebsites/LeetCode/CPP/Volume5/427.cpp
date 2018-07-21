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


// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
    
public:
    Node* construct(vector<vector<int>>& grid,int N = -1,int X = -1,int Y = -1) {
        if(N == -1){
            N = grid.size();
            X = Y = 0;
        }
        if(N == 1)
            return new Node(grid[X][Y],true,NULL,NULL,NULL,NULL);
        Node *p = new Node();
        int HalfN = N >> 1;
        p->topLeft = construct(grid,HalfN,X,Y);
        p->topRight = construct(grid,HalfN,X,Y + HalfN);
        p->bottomLeft = construct(grid,HalfN,X + HalfN, Y);
        p->bottomRight = construct(grid,HalfN,X + HalfN, Y + HalfN);
        
        int PureCount = 0, Sum = 0;
        vector<Node*> V = {p->topLeft,p->topRight,p->bottomLeft,p->bottomRight};
        for(auto x : V){
            if(x->isLeaf){
                PureCount++;
                Sum += x->val;
            }
        }
        if(PureCount == 4 && (Sum == 0 || Sum == 4)){
            //if this is pure
            for(auto x : V)
                delete x;
            p->topLeft = NULL;
            p->topRight = NULL;
            p->bottomLeft = NULL;
            p->bottomRight = NULL;
            p->isLeaf = true;
            p->val = Sum == 4;
        }
        else{
            //if this is not pure
            p->isLeaf = false;
        }
        return p;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
