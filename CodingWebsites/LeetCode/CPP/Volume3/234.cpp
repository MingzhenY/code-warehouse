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
    bool isPalindrome(ListNode* head) {
        unsigned long long L = 0, R = 0, p137 = 1;
        for(ListNode *p = head; p ; p = p->next){
            L = L + p->val * p137;
            R = R * 137 + p->val;
            p137 *= 137;
        }
        return L == R;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
