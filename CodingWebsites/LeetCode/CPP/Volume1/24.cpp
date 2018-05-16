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
    ListNode* swapPairs(ListNode* head) {
        ListNode * Head = NULL, *Last = NULL;
        ListNode *A, *B;
        while(head){
            A = head;
            if(A){
                B = head = head->next;
                if(B){
                    head = head->next;
                    AddNode(Head,Last,B);
                    AddNode(Head,Last,A);
                }
                else{
                    AddNode(Head,Last,A);
                }
            }
        }
        return Head;
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
        for(int i = 2 ; i <= 5 ; ++i) push_back(L1,i);
        ListNode *list = swapPairs(L1);
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
