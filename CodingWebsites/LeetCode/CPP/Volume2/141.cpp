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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *P1 = head,*P2 = head;
        while(1){
            P2 = P2->next;
            if(!P2) return false;
            if(P2 == P1) return true;
            P2 = P2->next;
            if(!P2) return false;
            if(P2 == P1) return true;
            P1 = P1->next;
        }
        return true;
    }
    void Test(){
        ListNode A(1),B(2),C(3),D(4),E(5);
        A.next = &B;
        B.next = &C;
        C.next = &D;
        D.next = &E;
        E.next = &B;
        cout<<hasCycle(&A)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
