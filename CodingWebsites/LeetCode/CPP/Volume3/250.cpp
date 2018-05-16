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
    struct A{
        bool unival;
        bool empty;
        int value;
        A(bool u = true,bool e = false,int v = 0):unival(u),empty(e),value(v){}
        A operator +(const A &B)const{
            A C;
            if(empty) return B;
            if(B.empty) return *this;
            return A(unival && B.unival && value == B.value,false,value);
        }
    };
public:
    int countUnivalSubtrees(TreeNode* root) {
        int ret = 0;
        F(root,ret);
        return ret;
    }
    A F(TreeNode *root,int &ret){
        if(!root){
            return A(true,true);
        }
        A L = F(root->left,ret);
        A R = F(root->right,ret);
        A C = L + R;
        ret += C.unival = C.unival && (C.empty || C.value == root->val);
        C.empty = false;
        C.value = root->val;
        return C;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
