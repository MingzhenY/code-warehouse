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


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *Head = NULL;
        while(head){
            ListNode *t = head;
            head = head->next;
            InsertOrder(Head,t);
        }
        return Head;
    }
    void InsertOrder(ListNode *&Head, ListNode *t){
        if(!t) return;
        if(Head){
            if(t->val < Head->val){
                t->next = Head;
                Head = t;
            }
            else{
                ListNode *p = Head;
                while(p->next && p->next->val < t->val){
                    p = p->next;
                }
                t->next = p->next;
                p->next = t;
            }
        }
        else{
            t->next = NULL;
            Head = t;
        }
    }
    void Test(){
        
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
