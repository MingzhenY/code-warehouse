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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *tempHead = NULL,*tempLast = NULL;
        ListNode *Head = NULL,*Last = NULL;
        while(head){
            bool Rev = splitK(head,tempHead = NULL,tempLast = NULL,k);
            printf("Rev = %d\n",Rev);
            if(Rev) reverse(tempHead,tempLast);
            if(Head){
                Last->next = tempHead;
                Last = tempLast;
            }
            else{
                Head = tempHead;
                Last = tempLast;
            }
        }
        return Head;
    }
    bool splitK(ListNode *&From,ListNode *&Head,ListNode *&Last,int k){
        //Move first K elements
        int MoveCount = 0;
        for(int i = 0 ; i < k ; ++i){
            if(From){
                ++MoveCount;
                ListNode *temp = From;
                From = From->next;
                AddBack(Head,Last,temp);
            }
            else break;
        }
        return MoveCount == k;
    }
    void reverse(ListNode *&Head,ListNode *&Last){
        //Reverse 'From'
        ListNode *newHead = NULL, *newLast = NULL;
        while(Head){
            ListNode *temp = Head;
            Head = Head->next;
            AddFront(newHead,newLast,temp);
        }
        Head = newHead;
        Last = newLast;
    }
    void AddBack(ListNode *&Head,ListNode *&Last,ListNode *elem){
        if(Head){
            Last->next = elem;
            elem->next = NULL;
            Last = elem;
        }
        else{
            Head = Last = elem;
            elem->next = NULL;
        }
    }
    void AddFront(ListNode *&Head,ListNode *&Last,ListNode *elem){
        if(Head){
            elem->next = Head;
            Head = elem;
        }
        else{
            Head = Last = elem;
            elem->next = NULL;
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
        for(int i = 2 ; i <= 9 ; ++i) push_back(L1,i);
        ListNode *list = reverseKGroup(L1,4);
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
