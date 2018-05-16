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
    int nthUglyNumber(int n) {
        priority_queue<int,vector<int>,greater<int>> Q;
        set<int> S;
        Q.push(1);
        while(1){
            long long V = Q.top();Q.pop();
            //printf("%d\n",V);
            if(--n){
                long long T;
                T = V * 2;
                if(T < INT_MAX && !S.count(T)){
                    S.insert(T);
                    Q.push(T);
                }
                T = V * 3;
                if(T < INT_MAX && !S.count(T)){
                    S.insert(T);
                    Q.push(T);
                }
                T = V * 5;
                if(T < INT_MAX && !S.count(T)){
                    S.insert(T);
                    Q.push(T);
                }
            }
            else return V;
        }
    }
    void Test(){
        cout<<nthUglyNumber(20)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
