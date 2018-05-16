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
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        int LC,RC,LFR;
        LC = longestConsecutive(root->left);
        RC = longestConsecutive(root->right);
        LFR = longestFromRoot(root);
        return max(LFR,max(LC,RC));
    }
    int longestFromRoot(TreeNode *root){
        if(!root) return 0;
        int LANS,RANS;
        LANS = root->left && root->left->val == root->val + 1 ? longestFromRoot(root->left) + 1 : 0;
        RANS = root->right && root->right->val == root->val + 1 ? longestFromRoot(root->right) + 1 : 0;
        return max(1,max(LANS,RANS));
    }
    void Test(){
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
