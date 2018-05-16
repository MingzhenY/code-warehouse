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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums,0,nums.size() - 1);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums,int L,int R) {
        if(L > R) return NULL;
        if(L == R) return new TreeNode(nums[L]);
        int M = (L + R) >> 1;
        TreeNode *head = new TreeNode(nums[M]);
        head->left = sortedArrayToBST(nums,L,M - 1);
        head->right = sortedArrayToBST(nums,M + 1, R);
        return head;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
