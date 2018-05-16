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
    int sumNumbers(TreeNode* root) {
        int Sum = 0;
        F(root,Sum,0);
        return Sum;
    }
    void F(TreeNode *root,int &Sum,int V){
        if(!root) return;
        V = V * 10 + root->val;
        if(root->left || root->right){
            F(root->left,Sum,V);
            F(root->right,Sum,V);
        }
        else{
            Sum += V;
        }
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
