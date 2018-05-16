#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int val = 0 , ListNode *next = NULL):val(val),next(next){}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // head->...->PL->L->...->R->PR->...
        //                [reverse]
        
        //Step One: Split the list
        int M = m , N = n - m + 2;
        ListNode *Left = head, *PLeft = NULL;
        while(--M > 0 && Left) {
            PLeft = Left;
            Left = Left->next;
        }
        ListNode *Right = PLeft, *PRight = Left;
        while(--N > 0 && PRight) {
            Right = PRight;
            PRight = PRight->next;
        }
        //M and N should all be zero here
        if(M || N) return NULL;
        
        //Step Two: Reverse [L,R]
        Right->next = NULL;
        Reverse(Left,Right);
        //Step Three: Reconstruct the list
        ListNode *Head = NULL;
        
        if(PLeft){
            Head = head;
            PLeft->next = Left;
        }
        else{
            Head = Left;
        }
        
        if(PRight){
            Right->next = PRight;
        }
        return Head;
    }
    void Reverse(ListNode *&head, ListNode *&last){
        ListNode *Head = NULL, *Last = head;
        while(head){
            ListNode *temp = head;
            head = head->next;
            temp->next = Head;
            Head = temp;
        }
        head = Head;
        last = Last;
    }
    void PushBack(ListNode *&head,ListNode *&last,ListNode *elem){
        if(!elem) return;
        elem->next = NULL;
        if(head) last->next = elem, last = elem;
        else head = last = elem;
    }
    void ShowList(ListNode *head){
        while(head){
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }
    void Test(){
        int A[] = {1,2,3,4,5,6,7,8,9,10};
        ListNode LN[10];
        for(int i = 0 ; i < 10 ; ++i){
            if(i + 1 < 10){
                //if not the last
                LN[i] = ListNode(A[i],&LN[i + 1]);
            }
            else{//last
                LN[i] = ListNode(A[i]);
            }
        }
        ShowList(&LN[0]);
        ListNode *L = reverseBetween(&LN[0],1,10);
        ShowList(L);
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
