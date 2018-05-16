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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ANS;
        rsv(root,ANS);
        return ANS;
    }
    void rsv(TreeNode *root,vector<int> &ANS,int Depth = 0){
        if(!root) return;
        if(ANS.size() == Depth){
            ANS.push_back(root->val);
        }
        rsv(root->right,ANS,Depth+1);
        rsv(root->left,ANS,Depth+1);
        
    }
    void Test(){
        vector<int> V = {1,2,3,4,5,6,7,8};
        vector<int> V2 = {9,10,11,12};
        TreeNode *T = BuildFromVector(V);
        T->left->left->left = BuildFromVector(V2);
        ShowTree(T);
        vector<int> RSV = rightSideView(T);
        for(auto x:RSV){
            cout<<x<<" ";
        }
        cout<<endl;
        DeleteTree(T);
    }
    TreeNode * BuildFromVector(vector<int> &V,int L = 0, int R = -1){
        if(-1 == R){
            R = V.size() - 1;
        }
        int M = (L + R) >> 1;
        //     M
        //   /   \
        //[L,M) (M,R]
        TreeNode *ret = new TreeNode(V[M]);
        if(L < M) ret->left = BuildFromVector(V,L,M-1);
        if(M < R) ret->right = BuildFromVector(V,M+1,R);
        return ret;
    }
    void ShowTree(TreeNode *root,int dent = 0){
        if(!root) return;
        ShowTree(root->left,dent + 1);
        for(int i = 0 ; i < dent ; i++)
            printf("  ");
        printf("%d\n",root->val);
        ShowTree(root->right,dent + 1);
    }
    void DeleteTree(TreeNode *root){
        if(!root) return;
        DeleteTree(root->left);
        DeleteTree(root->right);
        delete root;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
