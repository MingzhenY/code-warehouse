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
    int countSegments(string s) {
        int Count = 0, State = 0;
        //State:
        //0 ready
        //1 receiving
        for(auto ch : s){
            if(ch == ' '){
                Count += State > 0;
                State = 0;
            }
            else{
                State = 1;
            }
        }
        Count += State > 0;
        return Count;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
