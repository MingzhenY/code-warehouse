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

class MedianFinder {
    /*
     Use Size-Balanced Tree to enable dynamic rank finding
     */
    struct Node{
        int S,V;
        Node *L,*R;
    };
    Node *root,*nil;
    void LeftRotate(Node *&root){
        if(root->R == nil) return;
        Node *T = root->R;
        root->R = T->L;
        T->L = root;
        T->S = root->S;
        root->S = root->L->S + root->R->S + 1;
        root = T;
    }
    void RightRotate(Node *&root){
        if(root->L == nil) return;
        Node *T = root->L;
        root->L = T->R;
        T->R = root;
        T->S = root->S;
        root->S = root->L->S + root->R->S + 1;
        root = T;
    }
    void Maintain(Node *&root){
        if(root->L->L > root->R){
            RightRotate(root);
            Maintain(root->R);
            Maintain(root);
        }
        else if(root->R->R > root->L){
            LeftRotate(root);
            Maintain(root->L);
            Maintain(root);
        }
        else if(root->L->R > root->R){
            LeftRotate(root->L);
            RightRotate(root);
            Maintain(root->R);
            Maintain(root->L);
            Maintain(root);
        }
        else if(root->R->L > root->L){
            RightRotate(root->R);
            LeftRotate(root);
            Maintain(root->L);
            Maintain(root->R);
            Maintain(root);
        }
    }
    void Insert(Node *&root,int V){
        if(root == nil){
            root = new Node;
            root->S = 1;
            root->V = V;
            root->L = nil;
            root->R = nil;
        }
        else{
            ++root->S;
            if(V <= root->V) Insert(root->L,V);
            else Insert(root->R,V);
        }
        Maintain(root);
    }
    Node * Find(Node *&root,int K){
        if(root == nil) return nil;
        if(K <= root->L->S) return Find(root->L,K);
        if(K == root->L->S + 1) return root;
        return Find(root->R,K - 1 - root->L->S);
    }
public:
    /** initialize your data structure here. */
    MedianFinder() {
        nil = new Node;
        nil->S = 0;
        nil->V = 0;
        nil->L = nil;
        nil->R = nil;
        root = nil;
    }
    
    void addNum(int num) {
        Insert(root,num);
    }
    
    double findMedian() {
        int N = root->S;
        if(N & 1){
            return Find(root,(N+1)/2)->V;
        }
        else{
            double L = Find(root,N/2)->V, R = Find(root,N/2+1)->V;
            return (L + R) / 2.0;
        }
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
