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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(sum == root->val && !root->left && !root->right){
            return true;
        }
        return  hasPathSum(root->left,sum - root->val) ||
                hasPathSum(root->right,sum - root->val);
    }
    
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
