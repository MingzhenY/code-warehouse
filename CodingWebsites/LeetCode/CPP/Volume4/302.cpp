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
    /*
     (x,y) is black, black tiles are all connected.
     Binary search in four directions to find 4 boundries.
     */
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int M = image.size();
        if(!M) return 0;
        int N = image[0].size();
        if(!N) return 0;
        
        int xL,xR,yL,yR;
        {//Find xL
            int L = 0, R = x;//[L,R]
            while(L < R){//find first black count > 0
                int Mid = (L + R) >> 1;
                int C = 0;
                for(int j = 0 ; j < N ; ++j){
                    if(image[Mid][j] == '1'){
                        C = 1;
                        break;
                    }
                }
                if(C) R = Mid;
                else L = Mid + 1;
            }
            xL = L;
        }
        {//find xR
            int L = x, R = M;//[L,R)
            while(L + 1 < R){//find last black count > 0
                int Mid = (L + R) >> 1;
                int C = 0;
                for(int j = 0 ; j < N ; ++j){
                    if(image[Mid][j] == '1'){
                        C = 1;
                        break;
                    }
                }
                if(C) L = Mid;
                else R = Mid;
            }
            xR = L;
        }
        {//Find yL
            int L = 0, R = y;//[L,R]
            while(L < R){//find first black count > 0
                int Mid = (L + R) >> 1;
                int C = 0;
                for(int j = 0 ; j < M ; ++j){
                    if(image[j][Mid] == '1'){
                        C = 1;
                        break;
                    }
                }
                if(C) R = Mid;
                else L = Mid + 1;
            }
            yL = L;
        }
        {//find xR
            int L = y, R = N;//[L,R)
            while(L + 1 < R){//find last black count > 0
                int Mid = (L + R) >> 1;
                int C = 0;
                for(int j = 0 ; j < M ; ++j){
                    if(image[j][Mid] == '1'){
                        C = 1;
                        break;
                    }
                }
                if(C) L = Mid;
                else R = Mid;
            }
            yR = L;
        }
        return (yR - yL + 1) * (xR - xL + 1);
    }
    void Test(){
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
