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
    int Encode(string str){
        //8 char -> 16bit -> 65536 states
        //A 00 C 01 G 10 T 11
        int ret = 0;
        for(auto ch : str){
            switch(ch){
                case 'A':
                ret = (ret << 2) | 0;
                break;
                case 'C':
                ret = (ret << 2) | 1;
                break;
                case 'G':
                ret = (ret << 2) | 2;
                break;
                case 'T':
                ret = (ret << 2) | 3;
                break;
            }
        }
        return ret;
    }
    vector<int> Next(int state){
        vector<int> ret;
        for(int mask = 3, i = 0 ; i < 8 ; ++i, mask <<= 2){
            int A = ~mask & state;
            for(int k = 0 ; k < 4 ; ++k){
                int B = k << (2 * i);
                if((A|B) != state)
                    ret.push_back(A | B);
            }
        }
        return ret;
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        vector<int> Valid(65536,0);
        vector<int> Dist(65536,-1);
        Valid[Encode(start)] = 1;
        for(auto s : bank){
            Valid[Encode(s)] = 1;
        }
        queue<int> Q;
        Q.push(Encode(start));
        Dist[Encode(start)] = 0;
        while(!Q.empty()){
            int state = Q.front(); Q.pop();
            vector<int> nexts = Next(state);
            for(auto next : nexts){
                if(Valid[next] && -1 == Dist[next]){
                    Dist[next] = Dist[state] + 1;
                    Q.push(next);
                }
            }
        }
        return Dist[Encode(end)];
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
