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
using namespace std;

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        //Step One: lchild -> rchild
        connect1(root);
        //Step Two: rchild -> (next->lchild)
        connect2(root);
    }
    void connect1(TreeLinkNode *root){
        if(!root) return;
        if(root->left && root->right){
            root->left->next = root->right;
        }
        connect1(root->left);
        connect1(root->right);
    }
    void connect2(TreeLinkNode *root){
        if(!root) return;
        if(root->right && root->next && root->next->left){
            root->right->next = root->next->left;
        }
        connect2(root->left);
        connect2(root->right);
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
