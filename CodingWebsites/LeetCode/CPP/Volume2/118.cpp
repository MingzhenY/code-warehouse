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
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ANS;
        if(!numRows) return ANS;
        vector<int> V(1,1);
        ANS.push_back(V);
        for(int i = 1 ; i < numRows ; ++i){
            V = getNextLine(V);
            ANS.push_back(V);
        }
        return ANS;
    }
    vector<int> getNextLine(vector<int> &Line){
        vector<int> nextLine(Line.size() + 1,1);
        for(int i = 1 ; i < Line.size() ; ++i){
            nextLine[i] = Line[i] + Line[i - 1];
        }
        return nextLine;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
