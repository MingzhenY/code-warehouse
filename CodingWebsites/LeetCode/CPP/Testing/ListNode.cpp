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

void LN_PushBack(ListNode *&Head, ListNode *&Last, ListNode *t);


int main(){
    
	return 0;
}
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
