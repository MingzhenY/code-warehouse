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
    list<TreeNode *> S;
    vector<string> V;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        V = {};
        F(root);
        return V;
    }
    void F(TreeNode *root){
        if(!root) return;
        if(root->left || root->right){
            if(root->left){
                S.push_back(root);
                F(root->left);
                S.pop_back();
            }
            if(root->right){
                S.push_back(root);
                F(root->right);
                S.pop_back();
            }
        }
        else{
            string str;
            for(auto x:S){
                str += to_string(x->val) + "->";
            }
            str += to_string(root->val);
            V.push_back(str);
        }
    }
    void Test(){
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
