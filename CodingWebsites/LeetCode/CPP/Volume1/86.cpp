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
    ListNode(){}
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *Head = NULL, *Last = NULL;
        while(head && head->val < x){
            ListNode *temp = head;
            head = head->next;
            Add(Head,Last,temp);
        }
        if(head){
            ListNode *pre = head;
            ListNode *p = head->next;
            while(p){
                if(p->val < x){
                    ListNode *temp = p;
                    p = p->next;
                    pre->next = p;
                    Add(Head,Last,temp);
                }
                else{
                    pre = p;
                    p = p->next;
                }
            }
        }
        if(Head) Last->next = head;
        else Head = Last = head;
        return Head;
    }
    void Add(ListNode *&head,ListNode *&last, ListNode *elem){
        elem->next = NULL;
        if(head){
            last->next = elem;
            last = last->next;
        }
        else{
            head = last = elem;
        }
    }
    void Test(){
        int V[6] = {1,4,3,2,5,2};
        ListNode A[6];
        for(int i = 0 ; i < 6 ; ++i){
            A[i].val = V[i];
            A[i].next = i + 1 < 6 ? &A[i + 1] : NULL;
        }
        ListNode *head = partition(&A[0],3);
        while(head){
            printf("%d ",head->val);
            head = head->next;
        }
        printf("\n");
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
