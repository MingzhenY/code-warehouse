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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        return trim(root,L,R);
    }
    TreeNode* trim(TreeNode* &root, int L, int R) {
        if(!root) return NULL;
        if(root->val < L) return trim(root->right,L,R);
        if(root->val > R) return trim(root->left,L,R);
        root->left = trim(root->left,L,R);
        root->right = trim(root->right,L,R);
        return root;
    }
    bool LeftRotate(TreeNode *&root){
        if(!root || !root->right) return false;
        //printf("LeftRotate----------\n");ShowTree(root);
        TreeNode *right = root->right;
        root->right = right->left;
        right->left = root;
        root = right;
        return true;
    }
    bool RightRotate(TreeNode *&root){
        if(!root || !root->left) return false;
        //printf("RightRotate----------\n");ShowTree(root);
        TreeNode *left = root->left;
        root->left = left->right;
        left->right = root;
        root = left;
        return true;
    }
    void ShowTree(TreeNode *root,int indent = 0){
        if(!root) return;
        for(int i = 0 ; i < indent ; ++i) printf("  ");
        printf("|%d\n",root->val);
        ShowTree(root->left,indent + 1);
        ShowTree(root->right,indent + 1);
        
    }
    void setNode(TreeNode &P,TreeNode *A,TreeNode *B){
        P.left = A;
        P.right = B;
    }
    void Test(){
        int A[7] = {2,5,7,9,8,4,6};
        TreeNode TN[5];
        TN[4] = TreeNode(1);
        TN[3] = TreeNode(2);
        TN[2] = TreeNode(4);
        TN[1] = TreeNode(0);
        TN[0] = TreeNode(3);
        setNode(TN[0],&TN[1],&TN[2]);
        setNode(TN[1],NULL,&TN[3]);
        setNode(TN[3],&TN[4],NULL);
        ShowTree(&TN[0]);
        printf("--------------\n");
        ShowTree(trimBST(&TN[0],1,3));
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
