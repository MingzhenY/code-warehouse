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
    int N;
    vector<vector<int>> ST;
    void Build(string &num, int n){
        N = 1;
        while(N < n + 2) N <<= 1;
        ST.resize(2 * N);
        for(int i = 0, j = N ; i < N ; ++i, ++j){
            ST[j] = vector<int>(10,-1);
            if(i >= 1 && i <= n){
                int digit = num[i - 1] - '0';
                if(digit >= 0 && digit <= 9)
                    ST[j][digit] = i;
                else{
                    printf("ERROR!");
                    return;
                }
            }
        }
        for(int i = N - 1 ; i >= 1 ; --i){
            ST[i].resize(10);
            int LS = i << 1;
            int RS = LS | 1;
            for(int digit = 0 ; digit < 10 ; ++digit){
                if(-1 == ST[LS][digit])
                    ST[i][digit] = ST[RS][digit];
                else 
                    ST[i][digit] = ST[LS][digit];
            }
        }
    }
    int Find(int L,int R,int digit){
        ++L, ++R;
        //Find the leftmost digit in [L,R]
        int LeftMost = -1;
        for(int s = N + L - 1, t = N + R + 1 ; s ^ t ^ 1 ; s >>= 1, t >>= 1){
            if(~s & 1){
                int V = ST[s ^ 1][digit];
                if( (V != -1) &&
                    (LeftMost == -1 || V < LeftMost) )
                    LeftMost = V;
            }
            if(t & 1){
                int V = ST[t ^ 1][digit];
                if( (V != -1) &&
                    (LeftMost == -1 || V < LeftMost) )
                    LeftMost = V;
            }
        }
        return LeftMost - 1;
    }
    string FindString(string &num, int start, int n, int d){
        if(d <= 0) return "";
        //Find the smallest d-digit number in num[start,n)
        //for t = 0 ~ 9, find the leftmost t in num[start..n-d]
        for(int t = 0 ; t < 10 ; ++t){
            int pos = Find(start , n - d , t);
            if(pos >= 0){
                //printf("digit = %d, next search range = [%d,%d) d=%d\n",t,pos+1,n,d - 1);
                return to_string(t) + FindString(num,pos + 1, n , d - 1);
            }
        }
        return "0";
    }
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if(k == n) return "0";
        Build(num,n);
        string ret = FindString(num,0,n,n-k);
        while(ret.length() > 1 && ret[0] == '0')
            ret = ret.substr(1);
        return ret;
    }
    void Test(){
        cout<<removeKdigits("1432219",3)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
