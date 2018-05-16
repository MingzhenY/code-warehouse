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
    ListNode* sortList(ListNode* head) {
        int n = 0;
        for(ListNode *temp = head; temp ; temp = temp->next) n++;
        return MergeSortList(head,n);
    }
    ListNode* MergeSortList(ListNode *head, int n){
        if(n <= 1) return head;
        //Partition list into L, R
        ListNode *L = head, *LL = head, *R;
        int Count = n >> 1;
        while(--Count)
            LL = LL->next;
        R = LL->next;
        LL->next = NULL;
        //Solve sub problem
        L = MergeSortList(L, n / 2);
        R = MergeSortList(R, n - n / 2);
        //Merge L,R
        ListNode *Head = NULL, *Last = NULL;
        while(L && R){
            ListNode *t;
            if(L->val < R->val){
                t = L;
                L = L->next;
            }
            else{
                t = R;
                R = R->next;
            }
            LN_PushBack(Head,Last,t);
        }
        while(L){
            ListNode *t = L;
            L = L->next;
            LN_PushBack(Head,Last,t);
        }
        while(R){
            ListNode *t = R;
            R = R->next;
            LN_PushBack(Head,Last,t);
        }
        return Head;
    }
    void LN_PushBack(ListNode *&Head, ListNode *&Last, ListNode *t){
        t->next = NULL;
        if(Head){
            Last->next = t;
            Last = t;
        }
        else{
            Head = Last = t;
        }
    }
    void Test(){
        int A[] = {1,9,2,8,3,7,4,6,5,10};
        int n = sizeof(A) / sizeof(A[0]);
        ListNode *Head = NULL;
        for(int i = 0 ; i < n ; ++i){
            ListNode *temp = new ListNode(A[i]);
            temp->next = Head;
            Head = temp;
        }
        Head = sortList(Head);
        for(int i = 0 ; i < n ; ++i){
            if(Head){
                ListNode *t = Head;
                Head = Head->next;
                printf("->%d",t->val);
                delete t;
            }
        }
        printf("\n");
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
