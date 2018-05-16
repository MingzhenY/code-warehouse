#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <list>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;


class Solution {
private:
    struct Line{
        int x;
        int L, R;
        bool in;
        Line(int x,int L,int R,bool in):x(x),L(L),R(R),in(in){}
        bool operator < (const Line &B)const{
            return x < B.x;
        }
    };
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        vector<Line> V;
        V.push_back(Line(A,B,D,true));
        V.push_back(Line(C,B,D,false));
        V.push_back(Line(E,F,H,true));
        V.push_back(Line(G,F,H,false));
        sort(V.begin(),V.end());
        int Area = 0;
        int L1,R1,L0,R0,X = 0, PrevX = V[0].x, PrevL = 0;
        for(int i = 0 ; i < V.size() ; ++i){
            Area += (V[i].x - PrevX) * PrevL;
            if(V[i].in){
                //Add line
                if(X & 1){
                    L1 = V[i].L;
                    R1 = V[i].R;
                    X |= 2;
                }
                else{
                    L0 = V[i].L;
                    R0 = V[i].R;
                    X |= 1;
                }
            }
            else{
                //Remove line
                if((X & 1) && L0 == V[i].L && R0 == V[i].R){
                    X ^= 1;
                }
                else if((X & 2) && L1 == V[i].L && R1 == V[i].R){
                    X ^= 2;
                }
            }
            PrevX = V[i].x;
            if(X){
                if(X == 1) PrevL = R0 - L0;
                else if(X == 2) PrevL = R1 - L1;
                else{
                    if(R0 < L1 || R1 < L0){
                        PrevL = R0 - L0 + R1 - L1;
                    }
                    else{
                        if(L0 > L1){
                            swap(L0,L1);
                            swap(R0,R1);
                        }
                        PrevL = max(R0,R1) - L0;
                    }
                }
            }
            else{
                PrevL = 0;
            }
        }
        return Area;
    }
    void Test(){
        cout<<computeArea(-3,0,3,4,0,-1,9,2)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
