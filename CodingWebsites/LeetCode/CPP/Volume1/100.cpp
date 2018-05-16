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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p || !q) return p == q;
        return
            isSameTree(p->left,q->left) &&
            isSameTree(p->right,q->right) &&
            p->val == q->val;
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
        vector<int> VA(A,A+sizeof(A)/sizeof(A[0]));
        vector<int> VB(VA);
        VB[5] = 999;
        
        TreeNode *rootA,*rootB;
        buildTree(rootA,VA,0,VA.size()-1);
        buildTree(rootB,VB,0,VB.size()-1);
        cout<<isSameTree(rootA,rootB)<<endl;
        clearTree(rootA);
        clearTree(rootB);
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
