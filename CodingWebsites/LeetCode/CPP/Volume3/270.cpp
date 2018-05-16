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
    int closestValue(TreeNode* root, double target) {
        if(!root) return 0;
        TreeNode *L,*R;
        L = FindL(root,target);
        R = FindR(root,target);
        if(!L || !R){
            return L ? L->val : R->val;
        }
        else{
            return target - L->val < R->val - target ? L->val : R->val;
        }
    }
    TreeNode* FindL(TreeNode *root, double target){
        //Find target's predecessor
        if(!root) return NULL;
        if(target <= root->val - 1e-6)
            return FindL(root->left,target);
        else{
            TreeNode *V = FindL(root->right,target);
            return V ? V : root;
        }
    }
    TreeNode* FindR(TreeNode *root, double target){
        //Find target's successor
        if(!root) return NULL;
        if(target >= root->val + 1e-6)
            return FindR(root->right,target);
        else{
            TreeNode *V = FindR(root->left,target);
            return V ? V : root;
        }
    }
    void Test(){
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
