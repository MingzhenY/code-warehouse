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
    int rob(TreeNode *root, bool include_root){
        if(!root) return 0;
        if(include_root){
            return root->val + rob(root->left,false) + rob(root->right,false);
        }
        else{
            return rob(root->left) + rob(root->right);
        }
    }
public:
    int rob(TreeNode* root) {
        int A = rob(root, true);
        int B = rob(root, false);
        return A > B ? A : B;
    }
    void Test(){
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
