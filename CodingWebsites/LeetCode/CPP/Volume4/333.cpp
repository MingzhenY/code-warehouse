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
    int ANS;
    int isBST(TreeNode *root, int &Min, int &Max){
        if(!root) {
            return 0;
        }
        int X;
        int LMin,LMax,RMin,RMax;
        int Lx,Rx;
        Lx = isBST(root->left,LMin,LMax);
        Rx = isBST(root->right,RMin,RMax);
        
        Max = Min = root->val;
        X = 1;
        if(Lx > 0){
            if(LMin < Min) Min = LMin;
            if(LMax > Max) Max = LMax;
            X += Lx;
        }
        if(Rx > 0){
            if(RMin < Min) Min = RMin;
            if(RMax > Max) Max = RMax;
            X += Rx;
        }
        bool Left = Lx >= 0 && (!Lx || LMax < root->val);
        bool Right = Rx >= 0 && (!Rx || RMin > root->val);
        if(Left && Right && X > ANS)
            ANS = X;
        return Left && Right ? X : -1;
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
public:
    int largestBSTSubtree(TreeNode* root) {
        int Min,Max;
        ANS = 0;
        isBST(root,Min,Max);
        return ANS;
    }
    void Test(){
        vector<int> T = {1,2,7,4,5,6,7,8,9,10,11};
        TreeNode *root = BuildFromVector(T);
        ShowTree(root);
        printf("%d\n",largestBSTSubtree(root));
        
        DeleteTree(root);
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
