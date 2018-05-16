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
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode * BuildFromVector(vector<int> &V,int L = 0, int R = -1){
        if(-1 == R){
            R = V.size() - 1;
        }
        int M = (L + R) >> 1;
        //     M
        //   /   \
        //[L,M) (M,R]
        TreeNode *ret = new TreeNode(V[M]);
        if(L < M) ret->left = BuildFromVector(V,L,M-1);
        if(M < R) ret->right = BuildFromVector(V,M+1,R);
        return ret;
    }
    void ShowTree(TreeNode *root,int dent = 0){
        if(!root) return;
        ShowTree(root->left,dent + 1);
        for(int i = 0 ; i < dent ; i++)
            printf("  ");
        printf("%d\n",root->val);
        ShowTree(root->right,dent + 1);
    }
    void DeleteTree(TreeNode *root){
        if(!root) return;
        DeleteTree(root->left);
        DeleteTree(root->right);
        delete root;
    }
    // Encodes a tree to a single string.
    string ToString(TreeNode* root) {
        if(!root) return "[null]";
        queue<TreeNode*> Q;
        Q.push(root);
        string str;
        int P = 0, E = 1, LastNonEmpty = 1;
        //P for current position pointer
        //E for end of list pointer
        while(++P <= LastNonEmpty){
            TreeNode *t = Q.front();Q.pop();
            str = str + (1 == P ? "[" : ",") + (t ? to_string(t->val) : "null");
            if(t){
                Q.push(t->left);
                ++E;
                if(t->left) LastNonEmpty = E;
                
                Q.push(t->right);
                ++E;
                if(t->right) LastNonEmpty = E;
            }
        }
        return str + "]";
    }
    
    // Decodes your encoded data to tree.
    TreeNode* FromString(string data) {
        int L, R = 0, len = data.length();
        TreeNode *root = NULL;
        queue<TreeNode*> Q;
        TreeNode *P = NULL;
        bool PLeft;
        while(1){
            L = ++R;
            while(R < len && (data[R] != ',' && data[R] != ']')) ++R;
            if(L == R || R == len) break;
            //[L,R) is now our value
            int Num = 0, Sign = 1;
            for(int i = L ; i < R ; ++i) {
                if(i == L && data[i] == '-'){
                    Sign = -1;
                    continue;
                }
                if(1 == Sign) Num = Num * 10 + data[i] - '0';
                else Num = Num * 10 - (data[i] - '0');
            }
            //Num in string
            TreeNode *temp;
            if(R == L + 4 && Num == 69560){
                //this means 'null' in string
                temp = NULL;
            }
            else {
                temp = new TreeNode(Num);
                Q.push(temp);
            }
            
            if(P){
                if(PLeft){
                    P->left = temp;
                    PLeft = false;
                }
                else{
                    P->right = temp;
                    P = Q.front();
                    Q.pop();
                    PLeft = true;
                }
            }
            else{
                root = temp;
                P = Q.front();
                Q.pop();
                PLeft = true;
            }
        }
        return root;
    }
    void Test(){
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
