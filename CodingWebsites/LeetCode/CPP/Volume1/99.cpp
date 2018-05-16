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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        if(!root) return;
        bool LEmpty,REmpty;
        TreeNode *LMax,*LMin,*RMax,*RMin;
        findMinMax(root->left,LEmpty,LMax,LMin);
        findMinMax(root->right,REmpty,RMax,RMin);
        bool LeftValid = LEmpty || LMax->val < root->val;
        bool RightValid = REmpty || RMin->val > root->val;
        if(LeftValid && RightValid){
            //The switched values are on one subtree
            //can't tell which one
            recoverTree(root->left);
            recoverTree(root->right);
        }
        else if(LeftValid){
            swap(root->val,RMin->val);
        }
        else if(RightValid){
            swap(root->val,LMax->val);
        }
        else{
            swap(LMax->val,RMin->val);
        }
    }
    void findMinMax(TreeNode *root,bool &Empty,TreeNode *&Max,TreeNode *&Min){
        //This should work on a non-valid BST to solve the problem
        if(!root){
            Empty = true;
            return;
        }
        bool LEmpty,REmpty;
        TreeNode *LMax,*LMin,*RMax,*RMin;
        findMinMax(root->left,LEmpty,LMax,LMin);
        findMinMax(root->right,REmpty,RMax,RMin);
        Max = REmpty || root->val > RMax->val ? root : RMax;
        Max = LEmpty || Max->val > LMax->val ? Max : LMax;
        Min = LEmpty || root->val < LMin->val? root : LMin;
        Min = REmpty || Min->val < RMin->val ? Min : RMin;
        Empty = false;
    }
    void buildTree(TreeNode * &root,vector<int> &V,int L,int R){
        if(L == R){
            root = new TreeNode(V[L]);
            return;
        }
        int M = (L + R) >> 1;
        root = new TreeNode(V[M]);
        if(L < M) buildTree(root->left,V,L,M - 1);
        buildTree(root->right,V,M + 1,R);
    }
    void clearTree(TreeNode *&root){
        if(!root) return;
        clearTree(root->left);
        clearTree(root->right);
        delete root;
        root = NULL;
    }
    void showTree(TreeNode *root,int indent = 0){
        if(!root) return;
        for(int i = 0 ; i < indent ; ++i) printf("\t");
        printf("%d:\n",root->val);
        showTree(root->left,indent + 1);
        showTree(root->right,indent + 1);
    }
    void ShowTree(TreeNode *root){
        showTree(root);
        printf("\n");
    }
    void Test(){
        int A[] = {7,2,3,4,5,6,1,8,9,10,11,12};
        vector<int> V(A,A+sizeof(A)/sizeof(A[0]));
        TreeNode *root = NULL;
        buildTree(root,V,0,V.size() - 1);
        ShowTree(root);
        printf("----------------------------\n");
        recoverTree(root);
        ShowTree(root);
        
        clearTree(root);
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
