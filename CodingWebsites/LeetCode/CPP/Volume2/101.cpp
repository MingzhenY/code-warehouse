#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;


 Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return IsSymmertic(root,root);
    }
    bool IsSymmertic(TreeNode *l,TreeNode *r){
        if(!l && !r) return true;
        if(!l || !r) return false;
        return
        l->val == r->val &&
        IsSymmertic(l->left,r->right) &&
        IsSymmertic(l->right,r->left);
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
