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
    void deleteNode(ListNode* node) {
        ListNode *pre = node;
        while(node->next){
            node->val = node->next->val;
            pre = node;
            node = node->next;
        }
        pre->next = NULL;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
