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
#include <map>
#include <set>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        if(head->next){
            ListNode *p = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;
            return p;
        }
        else return head;
    }
};
int main(){
    Solution S;
    S.Test();
	return 0;
}
