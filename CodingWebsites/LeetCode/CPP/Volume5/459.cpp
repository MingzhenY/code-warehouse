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
    vector<int> getFactors(int N){
        if(N == 1) return {};
        vector<int> factors = {1};
        for(int i = 2 ; i * i <= N ; i++){
            if(N % i == 0){
                factors.push_back(i);
                factors.push_back(N / i);
            }
        }
        return factors;
    }
public:
    bool repeatedSubstringPattern(string s) {
        int N = s.length(), K = 137, M = (1 << 22) + 1;
        vector<int> factors = getFactors(N);
        
        for(auto X : factors){
            //check if substring of length X works
            bool works = true;
            int V = -1;
            for(int i = 0 ; i < N ; i += X){
                int _V = 0;
                for(int j = 0 ; j < X ; ++j)
                    _V = (_V * K + s[i + j]) % M;
                if(V == -1)
                    V = _V;
                if(V != _V){
                    works = false;
                    break;
                }
            }
            if(works){
               return true; 
            }
        }
        return false;
    }
    void Test(){
        printf("True Tests:\n");
        vector<string> T = {"abcabc","aaaaaaa","acacacac","xxxaxxxxxxaxxx"};
        for(auto s : T){
            cout<<repeatedSubstringPattern(s)<<endl;
        }
        printf("False Tests:\n");
        vector<string> F = {"a","aba","aaaxaaa","axapaxa","abcdcba","aabbcc"};
        for(auto s : F){
            cout<<repeatedSubstringPattern(s)<<endl;
        }
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
