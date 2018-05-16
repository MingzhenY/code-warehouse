#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <list>
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        list<int> path;
        findPathSum(root,ret,path,sum);
        return ret;
    }
    void findPathSum(TreeNode* root,vector<vector<int>> & ret,list<int> &path,int sum){
        //if (root == NULL) -> do nothing
        if(!root) return;
        //Modify data
        path.push_back(root->val);
        sum -= root->val;
        //if (isLeaf && sum == root->val) -> found a valid path
        if(!root->left && !root->right){
            //Found a leaf, record answer
            if(!sum){
                vector<int> V;
                for(auto x:path){
                    V.push_back(x);
                }
                ret.push_back(V);
            }
        }
        else{
            findPathSum(root->left,ret,path,sum);
            findPathSum(root->right,ret,path,sum);
        }
        //clean up data
        path.pop_back();
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
