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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int N;
    ListNode *H;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        H = head;
        ListNode *t = head;
        N = 0;
        while(t){
            ++N;
            t = t->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int n = 1 + rand() % N;
        ListNode *t = H;
        while(t){
            if(!--n)
                return t->val;
            t = t->next;
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

int main(){
    Solution S;
    S.Test();
	return 0;
}
