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
    int compress(vector<char>& chars) {
        int N = chars.size();
        int I = 0;
        
        int Count = 0;
        char ch = 0;
        
        for(int i = 0 ; i <= N ; ++i){
            if(i == N || ch != chars[i]){
                //Compress 
                if(Count > 0){
                    if(Count == 1)
                        chars[I++] = ch;
                    else{
                        string str = to_string(Count);
                        chars[I++] = ch;
                        for(auto t : str){
                            chars[I++] = t;
                        }
                    }
                }
                //break if this is the last one
                if(i == N)
                    break;
                //start new count
                ch = chars[i];
                Count = 1;
            }
            else{
                Count++;
            }
        }
        return I;
    }
    void Test(){}
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
