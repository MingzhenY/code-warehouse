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

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<pair<int,int>> wordsets = getWordSets(words);
        int ANS = 0, N = words.size();
        for(int i = 0 ; i < N ; ++i){
            for(int j = i + 1 ; j < N ; ++j){
                if(wordsets[i].first & wordsets[j].first) ;
                else{
                    int D = wordsets[i].second * wordsets[j].second;
                    if(D > ANS) ANS = D;
                }
            }
        }
        return ANS;
    }
    vector<pair<int,int>> getWordSets(vector<string>& words){
        int N = words.size();
        vector<pair<int,int>> ret(N);
        for(int i = 0 ; i < N ; ++i){
            int s = 0, l = 0;
            for(auto ch : words[i]){
                s = s | (1 << ((ch - 'a')));
                ++l;
            }
            ret[i] = make_pair(s,l);
        }
        return ret;
    }
    void Test(){
        vector<string> words = {"abc","ac","bc","a"};
        printf("%d\n",maxProduct(words));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
