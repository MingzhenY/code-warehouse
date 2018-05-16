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
     ListNode(int x = 0) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *Head = NULL, *Last = NULL;
        while(head){
            ListNode *pHead = head, *pLast = head;
            while(pLast->next && pLast->next->val == pLast->val) pLast = pLast->next;
            //pHead->...->pLast
            head = pLast->next;
            
            if(Head){
                Last->next = pHead;
                Last = Last->next;
                Last->next = NULL;
            }
            else{
                Head = Last = pHead;
                Last->next = NULL;
            }
            
        }
        return Head;
    }
    void Test(){
        int A[6] = {1,4,4,4,7,8};
        ListNode LN[6];
        for(int i = 0 ; i < 6 ; ++i){
            LN[i].val = A[i];
            if(i < 5) LN[i].next = &LN[i + 1];
        }
        ListNode *Head = deleteDuplicates(&LN[0]);
        while(Head){
            printf("%d ",Head->val);
            Head = Head->next;
        }
        printf("\n");
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
