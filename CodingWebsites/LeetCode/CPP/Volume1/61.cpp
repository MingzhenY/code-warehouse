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
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int N = getN(head);
        if(!N) return head;
        k %= N;
        if(!k) return head;
        ListNode *L,*R;
        R = head;
        for(int i = 0 ; i < k ; ++i) R = R->next;
        L = head;
        while(R->next){
            L = L->next;
            R = R->next;
        }
        ListNode *newHead = L->next;
        L->next = NULL;
        R->next = head;
        return newHead;
    }
    int getN(ListNode *head){
        int ANS = 0;
        while(head){
            ++ANS;
            head = head->next;
        }
        return ANS;
    }
    void AddNode(ListNode *&head,ListNode *&last,int v){
        if(head){
            last->next = new ListNode(v);
            last = last->next;
        }
        else{
            head = last = new ListNode(v);
        }
    }
    void Test(){
        ListNode *head = NULL, *last = NULL;
        int A[] = {1,2,3,4,5,6,7,8,9};
        int N = sizeof(A) / sizeof(A[0]);
        for(int i = 0 ; i < N ; ++i) AddNode(head,last,A[i]);
        ListNode *H = rotateRight(head,10);
        while(H){
            printf("%d ",H->val);
            H = H->next;
        }
        printf("\n");
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
