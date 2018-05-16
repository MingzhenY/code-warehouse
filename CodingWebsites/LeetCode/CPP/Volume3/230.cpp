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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        TreeNode *p = ks(root,k,count);
        if(p) return p->val;
        else return 0;
    }
    TreeNode* ks(TreeNode *root, int k,int &count){
        if(!root) return NULL;
        int LC = 0, RC = 0;
        TreeNode *p = ks(root->left,k,LC);
        if(p) return p;
        if(k == LC + 1) return root;
        p = ks(root->right,k - LC - 1, RC);
        if(p) return p;
        count += LC + RC + 1;
        return NULL;
    }
    void Test(){
        TreeNode A(2),B(1);
        A.left = &B;
        cout<<kthSmallest(&A,1)<<endl;
        cout<<kthSmallest(&A,2)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
