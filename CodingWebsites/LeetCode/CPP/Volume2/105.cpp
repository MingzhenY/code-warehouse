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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder,0,preorder.size(),inorder,0,inorder.size());
    }
    void buildTree(vector<int>& preorder,int Lpre,int Rpre, vector<int>& inorder,int Lin,int Rin){
        if(Lpre == Rpre || Lin == Rin) return NULL;
        int CurV = preorder[Lpre];//Current Value
        int I = 0;
        for(int i = Lin ; i < Rin ; ++i){
            if(inorder[i] == CurV){
                I = i;
                break;
            }
        }
        // preorder = Lpre + [Lpre + 1, Lpre + I - Lin + 1) [Lpre + I - Lin + 1, Rpre)
        // inorder = [Lin, I) + I + [I + 1, Rin)
        TreeNode *head = new TreeNode(CurV);
        head->left = buildTree(preorder, Lpre + 1, Lpre + I - Lin + 1,
                               inorder, Lin, I);
        head->right = buildTree(preorder, Lpre + I - Lin + 1, Rpre,
                                inorder, I + 1 , Rin);
        return head;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
