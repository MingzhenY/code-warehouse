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
    int calculateSum(list<int> &L,int sum){
        int Sum = 0, ANS = 0;
        for(auto x : L){
            Sum += x;
            ANS += Sum == sum;
        }
        return ANS;
    }
    int myPathSum(list<int> &L, TreeNode* root, int sum){
        if(!root) return 0;
        L.push_front(root->val);
        int ANS = calculateSum(L,sum);
        ANS += myPathSum(L, root->left, sum);
        ANS += myPathSum(L, root->right, sum);
        L.pop_front();
        return ANS;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        list<int> L;
        return myPathSum(L,root,sum);
    }
    void Test(){}
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
