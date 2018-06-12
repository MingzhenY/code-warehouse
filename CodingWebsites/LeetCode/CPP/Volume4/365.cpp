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
    /*
    use pair<int,int> TLE.
    use long long AC.
    */
    #define LL long long
public:
    bool canMeasureWater(int x, int y, int z) {
        //set<int> S;
        unordered_set<LL> state;
        map<LL,LL> Pre;
        queue<LL> Q;
        LL Start = ((LL)x << 32) | y;
        Q.push(Start);
        while(!Q.empty()){
            LL p = Q.front();
            Q.pop();
            int X = p >> 32, Y = p - ((LL)X << 32);
            int XtoY = X + Y <= y ? X : y - Y;
            int YtoX = X + Y <= x ? Y : x - X;
            vector<pair<int,int>> V = {{0,Y},{X,0},{x,Y},{X,y},{X-XtoY,Y+XtoY},{X+YtoX,Y-YtoX}};
            for(auto t : V){
                LL st = (((LL) t.first) << 32) | t.second;
                if(!state.count(st)){
                    Pre[st] = p;
                    if(t.first + t.second == z){
                        //printf("%d,%d\n",t.first,t.second);
                        LL temp = st;
                        while(temp != Start){
                            int tx = temp >> 32, ty = temp - ((LL)tx << 32);
                            printf("%d,%d\n",tx,ty);
                            temp = Pre[temp];
                        }
                        return true;
                    }
                    state.insert(st);
                    //S.insert(t.first+t.second);
                    Pre[st] = p;
                    Q.push(st);
                }
            }
        }
        return false;
    }
    void Test(){
        printf("%d\n",canMeasureWater(34,5,6));
        printf("%d\n",canMeasureWater(3,5,4));
        printf("%d\n",canMeasureWater(2,6,5));
        //printf("%d\n",canMeasureWater(104597,104623,123));
    }
};

class Solution2 {
    int gcd(int x,int y){
        while(y){
            int t = x % y;
            x = y;
            y = t;
        }
        return x;
    }
public:
    bool canMeasureWater(int x, int y, int z) {
        int GCD = gcd(x,y);
        return GCD  ? z <= x + y && (z % GCD == 0) : z == 0;
    }
    void Test(){
        printf("%d\n",canMeasureWater(34,5,6));
        printf("%d\n",canMeasureWater(3,5,4));
        printf("%d\n",canMeasureWater(2,6,5));
        //printf("%d\n",canMeasureWater(104597,104623,123));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
