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

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        list<int> L1,L2;
        for(int i = 0; i < words.size() ; ++i){
            if(words[i] == word1) L1.push_back(i);
            if(words[i] == word2) L2.push_back(i);
        }
        list<int>::iterator p1 = L1.begin(), p2 = L2.begin();
        int MinDis = words.size();
        while(p1 != L1.end() && p2 != L2.end()){
            MinDis = min(MinDis,*p1 > *p2 ? *p1 - *p2 : *p2 - *p1);
            if(*p1 > *p2){
                ++p2;
            }
            else{
                ++p1;
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
