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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x = 0) : val(x), next(NULL) {}
};

void LN_Show(ListNode *Head){
    while(Head){
        printf("%d ",Head->val);
        Head = Head->next;
    }
    printf("\n");
}
class Solution {
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
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *LHead, *LTail, *RHead, *RTail;
        LHead = LTail = NULL;
        RHead = RTail = NULL;
        int Odd = true;
        for(ListNode *t = head ; t ;){
            ListNode *oldt = t;
            t = t->next;
            if(Odd)
                LN_PushBack(LHead,LTail,oldt);
            else 
                LN_PushBack(RHead,RTail,oldt);
            Odd = !Odd;
        }
        if(LTail) 
            LTail->next = RHead;
        return LHead;
    }
    void Test(){
        ListNode L[10], *Head = NULL, *Tail = NULL;
        for(int i = 0 ; i < 10 ; ++i) {
            L[i].val = i + 1;
            LN_PushBack(Head,Tail,&L[i]);
        }
        ListNode *ANS = oddEvenList(Head);
        LN_Show(ANS);
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
