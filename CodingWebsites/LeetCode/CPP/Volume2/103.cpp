#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > AnsVec;
        if(!root) return AnsVec;
        list<TreeNode *> Level;
        Level.push_back(root);
        bool LeftToRight = true;
        while(1){
            list<TreeNode *> nextLevel;
            vector<int> LevelAns;
            for(auto x: Level){
                if(x->left) nextLevel.push_back(x->left);
                if(x->right) nextLevel.push_back(x->right);
            }
            if(LeftToRight){
                for(auto x:Level){
                    LevelAns.push_back(x->val);
                }
            }
            else{
                for(list<TreeNode *>::reverse_iterator it = Level.rbegin();
                    it != Level.rend(); it++){
                    LevelAns.push_back((*it)->val);
                }
            }
            LeftToRight = !LeftToRight;
            AnsVec.push_back(LevelAns);
            if(nextLevel.empty()) break;
            else swap(Level,nextLevel);
        }
        return AnsVec;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
