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
#include <map>
#include <set>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *t = root;
        while(t && t->val != p->val){
            if((p->val <= t->val && t->val <= q->val) ||
               (p->val >= t->val && t->val >= q->val))
                return t;
            if(p->val < t->val)
                t = t->left;
            else t = t->right;
        }
        return t;
    }
    void Test(){}
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
