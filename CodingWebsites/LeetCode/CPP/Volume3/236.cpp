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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        list<bool> L,R, cnt;
        find(root,cnt,L,R,p,q);
        for(list<bool>::iterator iL = L.begin(), iR = R.begin();
            iL != L.end() && iR != R.end(); ++iL, ++iR){
            if(*iL == *iR){
                root = *iL ? root->left : root->right;
            }
            else break;
        }
        return root;
    }
    void find(TreeNode *root, list<bool> &cnt, list<bool> &L, list<bool> &R,TreeNode *p, TreeNode *q){
        if(!root) return;
        if(root == p) L = cnt;
        if(root == q) R = cnt;
        cnt.push_back(true);
        find(root->left,cnt,L,R,p,q);
        cnt.pop_back();
        cnt.push_back(false);
        find(root->right,cnt,L,R,p,q);
        cnt.pop_back();
        
    }
    void Test(){
        
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
