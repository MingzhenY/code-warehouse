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

class WordDistance {
#define LL long long
    map<LL,list<int>> M;
    int N;
public:
    WordDistance(vector<string> words) {
        N = words.size();
        for(int i = 0 ; i < N ; ++i){
            LL H = hash(words[i]);
            M[H].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        list<int> L1 = M[hash(word1)];
        list<int> L2 = M[hash(word2)];
        list<int>::iterator p1 = L1.begin(), p2 = L2.begin();
        int MinDis = N;
        while(p1 != L1.end() && p2 != L2.end()){
            int Dis = *p1 > *p2 ? *p1 - *p2++ : *p2 - *p1++;
            MinDis = min(MinDis, Dis);
        }
        return MinDis;
    }
    LL hash(string &str){
        LL H = 0;
        for(auto ch : str){
            H = H * 137 + ch;
        }
        return H;
    }
    void Test(){
        
    }
};


int main(){
    WordDistance S({});
    S.Test();
	return 0;
}
