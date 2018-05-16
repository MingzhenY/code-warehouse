#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x = 0) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int Max,Min,Empty;
        return isValidBST(root,Max,Min,Empty);
    }
    bool isValidBST(TreeNode *root,int &Max,int &Min,int &Empty){
        if(!root) {
            Empty = true;
            return true;
        }
        int LValid,LMax,LMin,LEmpty;
        LValid = isValidBST(root->left,LMax,LMin,LEmpty);
        int RValid,RMax,RMin,REmpty;
        RValid = isValidBST(root->right,RMax,RMin,REmpty);
        Max = REmpty ? root->val : RMax;
        Min = LEmpty ? root->val : LMin;
        Empty = false;
        return  (LEmpty || (LValid && LMax < root->val)) &&
                (REmpty || (RValid && RMin > root->val));
    }
    void Test(){
        TreeNode TN[3];
        TN[0].val = 2;
        TN[1].val = 1;
        TN[2].val = 3;
        TN[0].left = &TN[1];
        TN[0].right = &TN[2];
        cout<<isValidBST(&TN[0])<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
