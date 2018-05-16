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
#include <stack>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class BSTIterator {
    struct Node{
        TreeNode *p;
        int State;//0 Left 1 Self 2 Right 3
        Node(TreeNode *p = NULL,int State = 0):State(State),p(p){};
    };
    stack<Node> S;
    TreeNode *Next;
public:
    BSTIterator(TreeNode *root) {
        if(!root){
            Next = NULL;
            return;
        }
        Next = root;
        while(Next){
            S.push(Node(Next,Next->left ? 1 : 2));
            Next = Next->left;
        }
        Next = S.top().p;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return Next != NULL;
    }
    
    /** @return the next smallest number */
    int next() {
        if(Next == NULL) return 0;
        TreeNode *Ret = Next;
        //Advance Next if possible
        while(!S.empty()){
            Node T = S.top(); S.pop();
            //printf("(%d,%d)\n",T.p->val,T.State);
            //State: 0 Left 1 Self 2 Right 3
            if(T.State == 0){
                T.State = 1;
                if(T.p->left){
                    S.push(T);
                    S.push(Node(T.p->left,0));
                    continue;
                }
            }
            if(T.State == 1){
                T.State = 2;
                S.push(T);
                Next = T.p;
                break;
            }
            if(T.State == 2){
                T.State = 3;
                if(T.p->right){
                    S.push(T);
                    S.push(Node(T.p->right,0));
                    continue;
                }
            }
            if(S.empty()){
                Next = 0;
            }
        }
        //Return
        return Ret->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

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
    void Test(){
        vector<int> V = {1,2,3,4,5,6,7,8,9,10,11};
        TreeNode *T = BuildFromVector(V);
        ShowTree(T);
        BSTIterator BI(T);
        while(BI.hasNext())
            cout<<BI.next()<<" ";
        cout<<endl;
        DeleteTree(T);
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
