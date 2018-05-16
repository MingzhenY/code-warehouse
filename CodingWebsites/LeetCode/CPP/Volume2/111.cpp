#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        return root ? minDepthLeaf(root) : 0;
    }
    int minDepthLeaf(TreeNode *root){
        //return depth to a leaf node
        //or -1 if no leaf is found
        if(!root) return -1;
        if(!root->left && !root->right){
            //Found leaf
            return 1;
        }
        int L = minDepthLeaf(root->left);
        int R = minDepthLeaf(root->right);
        return ~L && ~R ? min(L,R) + 1
                        : ~L ? L + 1
                             : ~R ? R + 1
                                  : -1;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
