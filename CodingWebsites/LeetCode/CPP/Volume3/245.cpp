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
using namespace std;

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        list<int> L1,L2;
        for(int i = 0; i < words.size() ; ++i){
            if(words[i] == word1) L1.push_back(i);
            if(words[i] == word2) L2.push_back(i);
        }
        int MinDis = words.size();
        if(word1 != word2){
            list<int>::iterator p1 = L1.begin(), p2 = L2.begin();
            while(p1 != L1.end() && p2 != L2.end()){
                int Dis = *p1 > *p2 ? *p1 - *p2++ : *p2 - *p1++;
                MinDis = min(MinDis, Dis);
            }
        }
        else{
            int Prev = -1;
            for(auto x:L1){
                if(~Prev){
                    MinDis = min(MinDis,x - Prev);
                }
                Prev = x;
            }
        }
        return MinDis;
    }
    void Test(){
        
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
