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
    bool getChar(vector<int>&data, int &L){
        int D = 1 << 7, N = 0;
        while(D & data[L]){
            ++N;
            D >>= 1;
        }
        if(1 == N || N > 4)
            return false;
        N += !N;
        //printf("%d char\n",N);
        //[L,L+N)
        if(L + N > data.size())
            return false;
        else{
            for(int i = L + 1 ; i < L + N ; ++i)
                if(((data[i] >> 6) & 255) != 2)
                    return false;
            L += N;
            return true;
        }
    }
public:
    bool validUtf8(vector<int>& data) {
        int L = 0, N = data.size();
        if(!N) return true;
        while(L < N){
            if(!getChar(data,L))
                return false;
        }
        return L == data.size();
    }
    void Test(){
        //145 = 10010001
        //250 = 11111010
        vector<int> data = {197,130,1},data2 = {250,145,145,145,145};
        printf("%d\n",validUtf8(data));
        printf("%d\n",validUtf8(data2));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
