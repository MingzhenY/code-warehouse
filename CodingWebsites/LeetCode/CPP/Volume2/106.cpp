#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder,0,inorder.size(),
                         postorder,0,postorder.size());
    }
    TreeNode* buildTree(vector<int>& inorder, int Lin, int Rin,
                        vector<int>& postorder, int Lpost, int Rpost) {
        if(Lin == Rin || Lpost == Rpost) return NULL;
        int CurV = postorder[Rpost - 1];
        int I;
        for(int i = Lin ; i < Rin ; ++i) {
            if(inorder[i] == CurV){
                I = i;
                break;
            }
        }
        //inorder = [Lin, I) + I + [I + 1 , Rin)
        //postorder = [Lpost, Lpost + I - Lin) + [Lpost + I - Lin, Rpost - 1) + Rpost
        TreeNode * head = new TreeNode(CurV);
        head->left = buildTree(inorder, Lin, I,
                               postorder, Lpost, Lpost + I - Lin);
        head->right = buildTree(inorder, I + 1, Rin,
                                postorder, Lpost + I - Lin, Rpost - 1);
        return head;
    }
};
int main(){
    Solution S;
    S.Test();
	return 0;
}
