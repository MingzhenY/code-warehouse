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
    int gcd(int x,int y){
        while(y){
            int t = x % y;
            x = y;
            y = t;
        }
        return x;
    }
    void Normalize(int &A, int &B){
        int gcdAB = gcd(A,B);
        A /= gcdAB;
        B /= gcdAB;
    }
    void Distinct(vector<pair<int, int>>& points){
        int N = points.size();
        int I = 1;
        sort(points.begin(),points.end());
        for(int i = 1 ; i < N ; ++i){
            if(points[i] != points[i - 1])
                points[I++] = points[i];
        }
        points.resize(I);
    }
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if(!points.size()) return true;
        Distinct(points);
        map<int,vector<int>> M;
        int A = 0,B = points.size();
        for(auto p:points){
            M[p.second].push_back(p.first);
            A += p.first;
        }
        Normalize(A,B);
        //printf("A,B = %d,%d\n",A,B);
        for(auto x:M){
            sort(x.second.begin(),x.second.end());
            int N = x.second.size();
            int Sum = x.second[0] + x.second[N-1];
            for(int i = 0, j = N - 1 ; i < j ; ++i, --j){
                if(x.second[i] + x.second[j] != Sum)
                    return false;
            }
            int HA = Sum, HB = 2;
            Normalize(HA,HB);
            //printf("HA,HB = %d,%d\n",HA,HB);
            if(HA != A || HB != B)
                return false;
            
        }
        return true;
    }
    void Test(){
        vector<pair<int, int>> points = {{0,0},{1,0},{3,0}};
        printf("%d\n",isReflected(points));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
