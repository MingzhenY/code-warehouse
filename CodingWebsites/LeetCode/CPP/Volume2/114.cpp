#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <list>
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
    void flatten(TreeNode* root) {
        vector<TreeNode*> PO;
        PreOrder(PO,root);
        int N = PO.size();
        if(N <= 1) return;
        for(int L = 0, R = 1 ; L < N ; ++L, ++R){
            PO[L]->left = NULL;
            PO[L]->right = R < N ? PO[R] : NULL;
        }
    }
    void PreOrder(vector<TreeNode*> &PO, TreeNode *root){
        if(!root) return;
        PO.push_back(root);
        PreOrder(PO,root->left);
        PreOrder(PO,root->right);
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
