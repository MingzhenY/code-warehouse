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
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int gN = g.size(), sN = s.size();
        int sp = 0, gp = 0, ANS = 0;
        while(sp < sN && gp < gN){
            //try giving out cookie s[sp]
            if(s[sp] >= g[gp]){
                //give out cookie
                sp++;
                gp++;
                ANS++;
            }
            else{
                //skip this cookie
                sp++;
            }
        }
        return ANS;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
