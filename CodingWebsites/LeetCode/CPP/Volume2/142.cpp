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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode *L1,*L2,*H = NULL;
        L1 = L2 = head;
        int Meet = 0;
        while(1){
            L1 = L1->next;
            L2 = L2->next;
            if(!L2) return NULL;
            L2 = L2->next;
            if(!L2) return NULL;
            if(L1 == L2) Meet++;
            if(Meet) H = H ? H->next : head;
            if(H == L1) return H;
            
        }
        return NULL;
    }
    void Test(){
        ListNode A(1),B(2),C(3),D(4),E(5);
        A.next = &B;
        B.next = &C;
        C.next = &D;
        D.next = &E;
        E.next = &B;
        ListNode *t = detectCycle(&A);
        if(t)
            cout<<t->val<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
