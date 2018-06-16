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
    int fill(vector<int> &WL, int &Count, int n, int SL, int cnt){
        //next word is WL[cnt]
        //fill n positions(first pos must be space)
        //Add completed sentences to Count
        //return next word.
        Count += n / SL;
        n %= SL;
        while(n >= WL[cnt]){
            n -= WL[cnt];
            cnt = (cnt + 1) % WL.size();
            if(!cnt) Count++;
        }
        return cnt;
    }
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        vector<int> WL;
        int SL = 0;
        for(auto s : sentence){
            WL.push_back(s.length()+1);
            SL += s.length() + 1;
        }
        int Count = 0, startID = 0;
        for(int i = 0 ; i < rows ; ++i){
            startID = fill(WL,Count,cols+1,SL,startID);
        }
        return Count;
    }
    void Test(){
        vector<string> sentence = {"a","bcd","e"};
        int rows = 3, cols = 6;
        // Output:  2
        // Explanation:
        // a-bcd- 
        // e-a---
        // bcd-e-
        printf("%d\n",wordsTyping(sentence,rows,cols));
        
        sentence = {"hello","world"};
        rows = 2;
        cols = 8;
        printf("%d\n",wordsTyping(sentence,rows,cols));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
