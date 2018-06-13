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
#include <unordered_set>
#include <stack>
using namespace std;

class Solution {
    #define LL long long
    void getXY(LL g,int &x,int &y){
        x = g >> 32;
        y = g - ((LL)x << 32);
    }
    LL getG(int x,int y){
        return ((LL)x << 32) | (LL) y;
    }
    struct A{
        LL xy;
        int v;
        A(LL xy, int v):xy(xy),v(v){}
        bool operator <(const A &B)const{
            return v > B.v;
        }
    };
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int N = matrix.size();
        priority_queue<A> Q;
        unordered_set<LL> S;
        S.insert(getG(0,0));
        Q.push(A(getG(0,0),matrix[0][0]));
        while(~Q.empty()){
            A t = Q.top(); Q.pop();
            if(!--k){
                //return value
                return t.v;
            }
            int x,y;
            getXY(t.xy,x,y);
            vector<pair<int,int>> Next = {{x+1,y},{x,y+1}};
            for(auto p : Next){
                int X = p.first, Y = p.second;
                LL G = getG(X,Y);
                if(X < N && Y < N && !S.count(G)){
                    S.insert(G);
                    Q.push(A(G,matrix[X][Y]));
                }
            }
        }
        return -1;
    }
    void Test(){
        vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
        printf("%d\n",kthSmallest(matrix,8));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
