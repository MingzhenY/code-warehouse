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

class Trie {
    struct Node{
        int Passing;
        int End;
        Node *p[26];
        Node(){
            Passing = End = 0;
            memset(p,0,sizeof(p));
        }
    };
    Node *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *t = root;
        int n = word.length();
        for(int i = 0 ; i < n ; i++){
            if(!t->p[word[i] - 'a']){
                t->p[word[i] - 'a'] = new Node();
            }
            t->Passing++;
            t = t->p[word[i] - 'a'];
        }
        t->End++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *t = root;
        int n = word.length();
        for(int i = 0 ; i < n ; i++){
            if(!t->p[word[i] - 'a']){
                return false;
            }
            t = t->p[word[i] - 'a'];
        }
        return t->End > 0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *t = root;
        int n = prefix.length();
        for(int i = 0 ; i < n ; i++){
            if(!t->p[prefix[i] - 'a']){
                return false;
            }
            t = t->p[prefix[i] - 'a'];
        }
        return t->Passing > 0 || t->End > 0;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
