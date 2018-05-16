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

struct TreeLinkNode {
int val;
TreeLinkNode *left, *right, *next;
TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        //Should calculate this level by level, not inorder
        if(!root) return;
        for(TreeLinkNode *Current = root; Current ; Current = Current->next){
            //lchild -> rchild
            if(Current->left && Current->right){
                Current->left->next = Current->right;
            }
            //rightmost -> (root(->next)^n->leftmost)
            TreeLinkNode *rightmost;
            rightmost = Current->right ? Current->right :
                        Current->left ? Current->left :
                        NULL;
            if(rightmost){
                TreeLinkNode *p = Current->next;
                while(p){
                    if(p->left){
                        rightmost->next = p->left;
                        break;
                    }
                    if(p->right){
                        rightmost->next = p->right;
                        break;
                    }
                    p = p->next;
                }
            }
        }
        //Down to the next level
        for(TreeLinkNode *leftmost = root; leftmost ; leftmost = leftmost->next){
            if(leftmost->left){
                connect(leftmost->left);
                break;
            }
            if(leftmost->right){
                connect(leftmost->right);
                break;
            }
        }
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
