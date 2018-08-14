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
    struct A{
        char ch;
        int count;
        A(){
            count = 0;
        }
        bool operator < (const A &B)const{
            return count > B.count;
        }
    };
public:
    string frequencySort(string s) {
        A Count[128];
        for(int i = 0 ; i < 128 ; ++i) 
            Count[i].ch = i;
        for(auto ch : s){
            Count[ch].count++;
        }
        sort(Count,Count+128);
        string ret;
        for(int i = 0 ; i < 128 ; ++i){
            while(Count[i].count-- > 0){
                ret += Count[i].ch;
            }
        }
        return ret;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
