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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int Diff = 0;
        //First pass, find Different in length
        ListNode *t1 = headA, *t2 = headB;
        while(t1 && t2) {
            t1 = t1->next;
            t2 = t2->next;
        }
        while(t1){
            t1 = t1->next;
            Diff++;
        }
        while(t2){
            t2 = t2->next;
            Diff--;
        }
        //Second Pass, find intersection
        t1 = headA;
        t2 = headB;
        while(Diff > 0){
            t1 = t1->next;
            Diff--;
        }
        while(Diff < 0){
            t2 = t2->next;
            Diff++;
        }
        while(t1 && t2){
            if(t1 == t2) return t1;
            t1 = t1->next;
            t2 = t2->next;
        }
        return NULL;
    }
    void Test(){
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
