#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x = 0) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        stack<bool> First;
        vector<int> V;
        if(!root) return V;
        S.push(root);
        First.push(true);
        while(!S.empty()){
            TreeNode *cnt = S.top();
            bool isFirst = First.top();
            
            S.pop();
            First.pop();
            
            if(isFirst){
                
                S.push(cnt);
                First.push(false);
                
                if(cnt->left){
                    S.push(cnt->left);
                    First.push(true);
                    continue;
                }
            }
            else{
                V.push_back(cnt->val);
                
                if(cnt->right){
                    S.push(cnt->right);
                    First.push(true);
                }
            }
            
        }
        //printf("\n");
        return V;
    }
    void ShowTree(TreeNode *root){
        show(root);
        printf("\n");
    }
    void show(TreeNode *root){
        if(!root) return;
        show(root->left);
        printf("%d ",root->val);
        show(root->right);
    }
    void Test(){
        TreeNode TN[8];
        int A[8] = {9,3,7,6,2,4,5,1};
        TreeNode *B[8][2] = {
            {&TN[1],&TN[3]},
            {NULL,&TN[2]},
            {NULL,NULL},
            {&TN[4],&TN[5]},
            {NULL,NULL},
            {&TN[6],&TN[7]},
            {NULL,NULL},
            {NULL,NULL}
        };
        for(int i = 0 ; i < 8 ; ++i){
            TN[i].val = A[i];
            TN[i].left = B[i][0];
            TN[i].right = B[i][1];
        }
        TreeNode *root = &TN[0];
        vector<int> ANS = inorderTraversal(root);
        for(auto x:ANS){
            printf("%d ",x);
        }
        printf("\n");
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
