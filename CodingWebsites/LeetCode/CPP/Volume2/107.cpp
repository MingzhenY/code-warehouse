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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ANS;
        if(!root) return ANS;
        list<TreeNode*> List;
        List.push_back(root);
        while(!List.empty()){
            list<TreeNode*> newList;
            vector<int> tempVec;
            for(auto x: List){
                tempVec.push_back(x->val);
                if(x->left) newList.push_back(x->left);
                if(x->right) newList.push_back(x->right);
            }
            ANS.push_back(ttempVec);
            swap(List,newList);
        }
        int N = ANS.size()  / 2;
        for(int i = 0 ; i < N ; ++i){
            swap(ANS[i],ANS[N-i-1]);
        }
        return ANS;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
