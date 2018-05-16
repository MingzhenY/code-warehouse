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
    ListNode(){}
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *Head = NULL,*Last = NULL,*Right = NULL;
        ListNode *temp = head;
        int N = ListLen(head), n = 0;
        while(temp){
            n++;
            ListNode *t = temp;
            temp = temp->next;
            if(n <= N / 2){
                push_back(Head,Last,t);
            }
            else{
                push_front(Right,t);
            }
        }
        ListNode *AH = NULL,*AL = NULL;
        while(1){
            if(Head){
                ListNode *t = Head;
                Head = Head->next;
                push_back(AH,AL,t);
            }
            if(Right){
                ListNode *t = Right;
                Right = Right->next;
                push_back(AH,AL,t);
            }
            if(!Head && !Right) break;
        }
    }
    int ListLen(ListNode* head){
        int Count = 0;
        while(head){
            Count++;
            head = head->next;
        }
        return Count;
    }
    void push_back(ListNode *&head,ListNode *&last,ListNode *t){
        t->next = NULL;
        if(head){
            last->next = t;
            last = t;
        }
        else{
            head = last = t;
        }
    }
    void push_front(ListNode *&head,ListNode *t){
        t->next = head;
        head = t;
    }
    void Test(){
        ListNode D[10];
        for(int i = 0 ; i < 10 ; ++i){
            D[i].val = i+1;
            D[i].next = i + 1 < 10 ? &D[i+1] : NULL;
        }
        reorderList(&D[0]);
        ListNode *temp = &D[0];
        while(temp){
            printf("%d - ",temp->val);
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
