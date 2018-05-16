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
    TreeNode(){};
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        return FindGT(root,root->val);
    }
    int FindGT(TreeNode *root,int val){
        //Find the smallest value that is bigger than val, or -1
        if(!root) return -1;
        if(root->val > val) return root->val;
        int LANS = FindGT(root->left,val);
        int RANS = FindGT(root->right,val);
        if(~LANS){
            if(~RANS){
                return min(LANS,RANS);
            }
            else return LANS;
        }
        else return RANS;
    }
    void ShowTree(TreeNode *root,int indent = 0){
        if(!root) return;
        for(int i = 0 ; i < indent ; ++i) printf("  ");
        printf("-%d\n",root->val);
        ShowTree(root->left,indent + 1);
        ShowTree(root->right,indent + 1);
        
    }
    void setNode(TreeNode &P,TreeNode &A,TreeNode &B){
        P.val = min(A.val,B.val);
        P.left = &A;
        P.right = &B;
    }
    void Test(){
        int A[7] = {2,5,7,9,8,4,6};
        TreeNode TN[13];
        TN[5] = TreeNode(2);
        TN[6] = TreeNode(5);
        TN[11] = TreeNode(7);
        TN[12] = TreeNode(9);
        TN[8] = TreeNode(6);
        TN[9] = TreeNode(8);
        TN[10] = TreeNode(4);
        setNode(TN[2],TN[5],TN[6]);
        setNode(TN[7],TN[11],TN[12]);
        setNode(TN[3],TN[7],TN[8]);
        setNode(TN[4],TN[9],TN[10]);
        setNode(TN[1],TN[3],TN[4]);
        setNode(TN[0],TN[2],TN[1]);
        cout<<findSecondMinimumValue(&TN[0])<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
