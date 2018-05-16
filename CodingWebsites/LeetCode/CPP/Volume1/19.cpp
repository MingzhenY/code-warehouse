#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *L = head;
        ListNode *PreL = NULL;
        ListNode *R = head;
        for(int i = 0 ; i < n ; ++i){
            if(R) R = R->next;
        }
        while(R){
            R = R->next;
            PreL = L;
            L = L->next;
        }
        //printf("PreL:%d L:%d\n",PreL?PreL->val:0,L->val);
        if(PreL == NULL) return L->next;
        else {
            PreL->next = L->next;
            return head;
        }
    }
    void push_back(ListNode* head, int n){
        ListNode *p = head;
        while(p->next){
            p = p->next;
        }
        p->next = new ListNode(n);
    }
    void Test(){
        ListNode *head = new ListNode(1);
        for(int i = 2 ; i <= 5 ; ++i) push_back(head,i);
        ListNode *list = removeNthFromEnd(head,5);
        while(list){
            printf("->%d",list->val);
            list = list->next;
        }
        printf("\n");
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
