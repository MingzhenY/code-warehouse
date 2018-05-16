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

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> A;
        T(root,A);
        return A;
    }
    void T(TreeNode *root,vector<int> &A){
        if(!root) return;
        A.push_back(root->val);
        T(root->left,A);
        T(root->right,A);
    }
    void Test(){}
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
