#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <list>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };
 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode*,int> M;
        map<RandomListNode*,int> N;
        map<int,RandomListNode*> RN;
        M[NULL] = 0; N[NULL] = 0;
        int MID = 1, NID = 1;
        
        map<RandomListNode*,int> rid;
        
        RandomListNode *temp = head;
        RandomListNode *Head=NULL,*Last=NULL;
        //Set up label and next
        while(temp){
            GetID(M,MID,temp);
            Push_back(Head,Last,temp->label);
            GetID(N,NID,Last);
            RN[N[Last]] = Last;
            temp = temp->next;
        }
        //Set up random
        temp = head;
        RandomListNode *temp2 = Head;
        while(temp){
            temp2->random = RN[M[temp->random]];
            temp = temp->next;
            temp2 = temp2->next;
        }
        return Head;
    }
    void Push_back(RandomListNode *&Head,RandomListNode *&Last,int label){
        RandomListNode *t = new RandomListNode(label);
        if(Head){
            Last->next = t;
            Last = t;
        }
        else{
            Head = Last = t;
        }
    }
    int GetID(map<RandomListNode*,int> &M,int &ID, RandomListNode *node){
        if(M.count(node))
            return M[node];
        else
            return M[node] = ID++;
    }
    void Test(){
        RandomListNode A(1),B(2),C(3);
        A.next = &B;
        B.next = &C;
        A.random = NULL;
        B.random = &A;
        C.random = &B;
        
        RandomListNode *t = copyRandomList(&A);
        RandomListNode *temp = t;
        while(temp){
            printf("%d(%d,%d)\n",temp->label,
                   temp->next?temp->next->label:-1,
                   temp->random?temp->random->label:-1);
            temp = temp->next;
        }
        
        
        
        while(t){
            RandomListNode *temp = t;
            t = t->next;
            delete temp;
        }
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
