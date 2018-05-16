#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        ListNode *PreL,*L,*Last;
        PreL = NULL;
        L = Last = head;
        while(1){
            if(Last){
                Last = Last->next;
            }
            else break;
            if(Last){
                Last = Last->next;
            }
            else break;
            PreL = L;
            L = L->next;
        }
        TreeNode *root = new TreeNode(L->val);
        if(PreL){
            PreL->next = NULL;
            root->left = sortedListToBST(head);
        }
        else
            root->left = NULL;
        root->right = sortedListToBST(L->next);
        return root;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
