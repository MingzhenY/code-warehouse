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
    vector<string> generateParenthesis(int n) {
        //Step One: crate mask
        int Mask[30];
        Mask[0] = 1;
        for(int i = 1 ; i < 30 ; ++i){
            Mask[i] = Mask[i - 1] << 1 | 1;
        }
        
        //Step Two: enumerate patterns
        if(n <= 15){
            int N = 1 << (n << 1);
            string Str(2 * n,'(');
            vector<string> ANS;
            for(int I = 0 ; I < N ; ++I){
                if(countBit(I) == n){
                    bool Valid = true;
                    //Check if I is valid
                    for(int i = 2 * n - 1 ; i >= 0 ; --i){
                        Valid = Valid && countBit(I & Mask[i]) <= (i + 1) / 2;
                    }
                    if(Valid){
                        //Generate Answer using I
                        int M = I;
                        for(int i = 0 ; i < 2 * n ; ++i){
                            Str[i] = M & 1 ? ')' : '(';
                            M >>= 1;
                        }
                        ANS.push_back(Str);
                    }
                }
            }
            return ANS;
        }
        else{
            return vector<string>();
        }
    }
    int countBit(unsigned int n){
        n = (n & 0x55555555) + ((n & 0xaaaaaaaa) >> 1);
        n = (n & 0x33333333) + ((n & 0xcccccccc) >> 2);
        n = (n & 0x0f0f0f0f) + ((n & 0xf0f0f0f0) >> 4);
        n = (n & 0x00ff00ff) + ((n & 0xff00ff00) >> 8);
        n = (n & 0x0000ffff) + ((n & 0xffff0000) >> 16);
        return n;
    }
    void Test(){
        vector<string> S = generateParenthesis(3);
        for(auto str:S){
            cout<<str<<endl;
        }
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
