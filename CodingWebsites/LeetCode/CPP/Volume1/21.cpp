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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL , *last = NULL;
        ListNode *Chosen;
        
        while(l1 && l2){
            if(l1->val <= l2->val){
                Chosen = l1;
                l1 = l1->next;
            }
            else{
                Chosen = l2;
                l2 = l2->next;
            }
            AddNode(head,last,Chosen);
        }
        while(l1){
            Chosen = l1;
            l1 = l1->next;
            AddNode(head,last,Chosen);
        }
        while(l2){
            Chosen = l2;
            l2 = l2->next;
            AddNode(head,last,Chosen);
        }
        
        return head;
    }
    void AddNode(ListNode * &head,ListNode * &last,ListNode *elem){
        elem -> next = NULL;
        
        if(head == NULL){
            head = last = elem;
        }
        else{
            last -> next = elem;
            last = elem;
        }
    }
    void push_back(ListNode* &head, int n){
        if(head == NULL){
            head = new ListNode(n);
        }
        else{
            ListNode *p = head;
            while(p->next){
                p = p->next;
            }
            p->next = new ListNode(n);
        }
    }
    void Test(){
        ListNode *L1 = new ListNode(1);
        ListNode *L2 = new ListNode(1);
        for(int i = 2 ; i <= 10 ; ++i) push_back(L1,i * i / 2 + 1);
        for(int i = 2 ; i <= 10 ; ++i) push_back(L2,i * i - i + 1);
        ListNode *list = mergeTwoLists(L1,L2);
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
