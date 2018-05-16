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

class WordDictionary {
    struct Node{
        int End;
        int MaxLen;//distance from the longest end of word
        int MinLen;//distance from the shortest end of word
        Node *p[26];
        Node(){
            MaxLen = End = 0;
            MinLen = INT_MAX;
            memset(p,0,sizeof(p));
        }
    };
    Node *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *p = root;
        int n = word.length();
        for(int i = 0 ; i < n ; i++){
            if(!p->p[word[i]-'a']){
                p->p[word[i]-'a'] = new Node;
            }
            p->MaxLen = max(p->MaxLen, n - i);
            p->MinLen = min(p->MinLen, n - i);
            p = p->p[word[i]-'a'];
        }
        p->End++;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(root, word, 0, word.length());
    }
    bool search(Node *p, string &word, int pos, int n){
        if(!p) return false;
        if(pos == n){
            return p->End > 0;
        }
        if(p->MaxLen + pos < n || p->MinLen + pos > n)
            return false;
        if(word[pos] == '.'){
            for(int i = 0 ; i < 26 ; i++){
                if(search(p->p[i],word,pos+1,n)) return true;
            }
            return false;
        }
        else
            return search(p->p[word[pos]-'a'],word,pos+1,n);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

class Solution{
public:
    void Test(){
        
    }
};
int main(){
    Solution S;
    S.Test();
	return 0;
}
