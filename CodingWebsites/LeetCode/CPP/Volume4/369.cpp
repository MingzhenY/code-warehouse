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
    ListNode * reverseList(ListNode *head){
        ListNode *H = NULL, *p = head;
        while(p){
            ListNode *next = p->next;
            p->next = H;
            H = p;
            p = next;
        }
        return H;
    }
public:
    ListNode* plusOne(ListNode* head) {
        ListNode *H = reverseList(head);
        ListNode *p = H;
        int D = 1;
        while(p){
            p->val += D;
            D = p->val / 10;
            p->val %= 10;
            p = p->next;
        }
        head = reverseList(H);
        if(D){
            ListNode *p = new ListNode(D);
            p->next = head;
            return p;
        }
        else
            return head;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
