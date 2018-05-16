#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *Head = NULL, *Last = NULL;
        int d = 0;
        while(l1 || l2 || d){
            int val1 = l1?l1->val:0;
            int val2 = l2?l2->val:0;
            int sum = val1+val2+d;
            //Add sum to List
            if(Last){
                Last->next = new ListNode(sum % 10);
                Last = Last->next;
            }
            else{
                Head = Last = new ListNode(sum % 10);
            }
            d = sum/10;
            l1 = l1?l1->next:NULL;
            l2 = l2?l2->next:NULL;
        }
        return Head;
    }
    void push_front(ListNode **L,ListNode *e){
        if(!e) return;
        e->next = *L;
        *L = e;
    }
    ListNode *GetL1(){
        ListNode *L1 = NULL;
        push_front(&L1,new ListNode(3));
        push_front(&L1,new ListNode(4));
        push_front(&L1,new ListNode(2));
        return L1;
    }
    ListNode *GetL2(){
        ListNode *L2 = NULL;
        push_front(&L2,new ListNode(4));
        push_front(&L2,new ListNode(6));
        push_front(&L2,new ListNode(5));
        return L2;
    }
    void Show(ListNode *L){
        while(L){
            cout<<(L->val)<<endl;
            L = L->next;
        }
    }
};

int main(){
    Solution S;
    S.Show(S.addTwoNumbers(S.GetL1(),S.GetL2()));
	return 0;
}
