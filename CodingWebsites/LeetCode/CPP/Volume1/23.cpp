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
private:
    //Stack Part
    struct A{
        int val,id;
        A(){}
        A(int val,int id):val(val),id(id){}
        bool operator < (const A &B)const{
            return val < B.val;
        }
    };
    int SN;//Stack Size
    vector<A> Stack;//minimum stack
    void SiftUp(int i){
        while(i > 1 && Stack[i] < Stack[i / 2]){
            A t = Stack[i];
            Stack[i] = Stack[i / 2];
            Stack[i / 2] = t;
            i >>= 1;
        }
    }
    void SiftDown(int i){
        while(2 * i <= SN){
            i = 2 * i;
            if(i + 1 <= SN && Stack[i + 1] < Stack[i]) ++i;
            if(Stack[i / 2].val > Stack[i].val){
                A t = Stack[i / 2];
                Stack[i / 2] = Stack[i];
                Stack[i] = t;
            }
            else break;
        }
    }
    void S_Init(int n){
        SN = 0;
        Stack.resize(n + 1);
    }
    void S_Insert(A val){
        Stack[++SN] = val;
        SiftUp(SN);
    }
    A S_DeleteMin(){
        A Min = Stack[1];
        Stack[1] = Stack[SN--];
        SiftDown(1);
        return Min;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int N = lists.size();
        vector<ListNode *> P(N,0);
        S_Init(N);
        for(int i = 0 ; i < N ; ++i){
            P[i] = lists[i];
            if(P[i]){
                S_Insert(A(P[i]->val,i));
            }
        }
        
        ListNode * head = NULL, *last = NULL;
        while(SN > 0){
            A temp = S_DeleteMin();
            ListNode * p = lists[temp.id];
            lists[temp.id] = lists[temp.id]->next;
            push_back(head,last,p);
            if(lists[temp.id]) {
                S_Insert(A(lists[temp.id]->val,temp.id));
            }
        }
        return head;
    }
    void push_back(ListNode *&head,ListNode *&last,ListNode * val){
        if(head){
            last->next = val;
            last = val;
        }
        else{
            head = last = val;
            val->next = NULL;
        }
    }
    void Test(){
        
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
