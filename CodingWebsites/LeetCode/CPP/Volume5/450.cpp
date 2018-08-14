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
public:
    //if the deleted node has left child
    //use the rightmost leaf of the left child as new root
    TreeNode* deleteNode(TreeNode* root, int key) {
        DelNode(root,key);
        return root;
    }
    
    void DelNode(TreeNode * &root, int key){
        if(!root) return;
        if(root->val == key){
            //start deleting
            if(root->left){
                TreeNode *newroot = deleteMax(root->left);
                if(newroot)
                    root->val = newroot->val;
            }
            else{
                root = root->right;
            }
        }
        else{
            if(key < root->val)
                DelNode(root->left,key);
            else
                DelNode(root->right,key);
        }
    }
    
    
    //delete and return the rightmost leaf
    TreeNode* deleteMax(TreeNode* &root){
        if(!root) return NULL;
        if(root->right){
            return deleteMax(root->right);
        }
        else{
            TreeNode *ret = root;
            root = root->left;
            return ret;
        }
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
