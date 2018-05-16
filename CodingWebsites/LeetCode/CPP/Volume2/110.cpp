#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
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
    bool isBalanced(TreeNode* root) {
        return isBalancedHeight(root) >= 0;
    }
    int isBalancedHeight(TreeNode *root){
        //if is balanced return height
        //else return -1
        if(!root) return 0;
        int L,R;
        L = isBalancedHeight(root->left);
        R = isBalancedHeight(root->right);
        if(~L && ~R && abs(L - R) <= 1)
            return max(L,R) + 1;
        else
            return -1;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
