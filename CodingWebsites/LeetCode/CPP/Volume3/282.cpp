#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <list>
#include <cmath>
#include <map>
#include <set>
#include <stack>
using namespace std;

class ZigzagIterator {
    bool Valid;
    int Value;
    struct ListNode{
        vector<int>::iterator p,e;
        ListNode *next;
        ListNode(){}
        ListNode(vector<int> &v):p(v.begin()),e(v.end()),next(NULL){}
    };
    ListNode *head,*last;
    void AddNode(vector<int> &v){
        ListNode *temp = new ListNode(v);
        if(head){
            last->next = temp;
            temp->next = head;
            last = temp;
        }
        else{
            head = last = temp;
            head->next = last;
            last->next = head;
        }
    }
    void Remove(ListNode *p){
        if(!head) return;
        ListNode *t = head, *pt = last;
        while(t != p){
            t = t->next;
            pt = pt->next;
            if(t == head) return;
        }
        pt->next = t->next;
        if(t == head) last->next = head = head->next;
        if(t == last) last = pt;
        if(head == last) head = last = NULL;
        delete t;
    }
    ListNode *p;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        head = last = NULL;
        //Add as many none-empty vectors as needed here
        if(!v1.empty()) AddNode(v1);
        if(!v2.empty()) AddNode(v2);
        p = head;
        if(p){
            Valid = true;
            Value = *(p->p);
            ++(p->p);
            p = p->next;
        }
        else Valid = false;
    }
    int next() {
        int V = Value;
        //Advance
        while(1){
            if(p->p == p->e){
                //current vector is used up, move on
                if(head == last){
                    Valid = false;
                    Remove(p);
                    break;
                }
                else{
                    ListNode *temp = p;
                    p = p->next;
                    Remove(temp);
                }
            }
            else{
                Valid = true;
                Value = *(p->p);
                ++(p->p);
                p = p->next;
                break;
            }
        }
        return V;
    }
    
    bool hasNext() {
        return Valid;
    }
};

int main(){
    //Solution S;
    //S.Test();
	return 0;
}
