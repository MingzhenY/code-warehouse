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
#include <queue>
using namespace std;



struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
 
class Solution {
#define ULL unsigned long long
public:
    int maxPoints(vector<Point>& points) {
        int MaxP = 0, n = points.size();
        for(int i = 0 ; i < n ; ++i){
            map<ULL,int> S;
            for(int j = i + 1 ; j < n ; ++j){
                Point slope = Slope(points[i],points[j]);
                ULL h = hash(slope);
                S[h] = S[h] + 1;
            }
            int MaxS = 0;
            for(auto x:S){
                if(x.first != 0){
                    if(x.second > MaxS) MaxS = x.second;
                }
            }
            int CurP = MaxS + 1 + S[0];
            if(CurP > MaxP) MaxP = CurP;
        }
        return MaxP;
    }
    unsigned long long hash(Point A){
        return A.x * 600000001ULL + A.y * 700000001ULL;
    }
    Point Slope(Point A, Point B){
        if(A.x == B.x && A.y == B.y) return Point(0,0);
        Point C(B.x - A.x,B.y - A.y);
        int D = gcd(C.x,C.y);
        C.x /= D;
        C.y /= D;
        if(C.y < 0){
            C.x = -C.x;
            C.y = -C.y;
            return Point(-C.x,-C.y);
        }else if(C.y == 0 && C.x < 0){
            C.x = -C.x;
        }
        return C;
        
    }
    int gcd(int x,int y){
        while(y){
            int t = x % y;
            x = y;
            y = t;
        }
        return x;
    }
    void Show(Point A){
        printf("(%d,%d)\n",A.x,A.y);
    }
    void Test(){
        
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
