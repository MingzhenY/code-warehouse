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

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root) return NULL;
        if(root->val <= p->val) return inorderSuccessor(root->right,p);
        else{
            TreeNode X = inorderSuccessor(root->left,p);
            return X ? X : root;
        }
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
