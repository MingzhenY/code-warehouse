#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(1 == numRows) return s;
        string t(s);
        int tI = 1;
        int N = s.length();
        for(int Row = 0 ; Row < numRows ; ++Row){
            int Base = 0;
            for(int A = 0 ; Base < N ; ++A, Base += numRows - 1){
                if(A & 1){// '/'
                    if(Row < numRows - 1 && Base + numRows - 1 - Row < N){
                        t[tI++] = s[Base + numRows - 1 - Row];
                    }
                }
                else{//  '|'
                    if(Row > 0 && Base + Row < N){
                        t[tI++] = s[Base+Row];
                    }
                }
            }
        }
        return t;
    }
    void Test(){
        cout<<convert("PAYPALISHIRING",3)<<endl;
        cout<<convert("PAYPALISHIRING",4)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
