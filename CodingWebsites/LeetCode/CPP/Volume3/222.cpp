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
private:
    int getH(TreeNode *root){
        int H = 0;
        while(root){
            ++H;
            root = root->left;
        }
        return H;
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int LH = getH(root->left), RH = getH(root->right);
        if(LH == RH){
            return (1 << LH) + countNodes(root->right);
        }
        else{
            return countNodes(root->left) + (1 << RH);
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
