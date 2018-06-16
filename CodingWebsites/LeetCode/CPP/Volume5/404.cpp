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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
        if(!root) return 0;
        if(root->left || root->right)
            return sumOfLeftLeaves(root->left,true) +
                    sumOfLeftLeaves(root->right,false);
        else
            return isLeft ? root->val : 0;
    }
    void Test(){
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
