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
    int getDepth(TreeNode *root){
        if(!root) return 0;
        int DL = getDepth(root->left);
        int DR = getDepth(root->right);
        return 1 + max(DL,DR);
    }
    int FL(vector<vector<int>> &ret,TreeNode* root){
        if(!root) return -1;
        int DL = FL(ret,root->left);
        int DR = FL(ret,root->right);
        int D = 1 + max(DL,DR);
        ret[D].push_back(root->val);
        return D;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        int Depth = getDepth(root);
        vector<vector<int>> ret(Depth);
        FL(ret,root);
        return ret;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
