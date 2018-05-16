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

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        vector<int> S(n,0);
        //0 for not visited, 1 for visited, 2 for not celebrity
        int A = 0 , B = 1;
        S[0] = S[1] = 1;
        while(1){
            int AB = knows(A,B), BA = knows(B,A);
            if(AB == BA){
                //skip A and B
                while(A < n && S[A] != 0) ++A;
                if(A == n) return -1;
                S[A] = 1;
                while(B < n && S[B] != 0) ++B;
                if(B == n) break;
                S[B] = 1;
            }
            else{
                if(AB){
                    while(A < n && S[A] != 0) ++A;
                    if(A == n) break;
                    S[A] = 1;
                }
                else{
                    while(B < n && S[B] != 0) ++B;
                    if(B == n) break;
                    S[B] = 1;
                }
            }
        }
        if(A == n) A = B;
        for(int i = 0 ; i < n ; ++i){
            if(i == A) continue;
            if(!knows(i,A)) return -1;
            if(knows(A,i)) return -1;
        }
        return A;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
