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

void LN_Show(ListNode *Head){
    while(Head){
        printf("%d ",Head->val);
        Head = Head->next;
    }
    printf("\n");
}


int main(){
    
	return 0;
}

