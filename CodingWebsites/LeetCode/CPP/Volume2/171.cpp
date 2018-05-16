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
public:
    int titleToNumber(string s) {
        int A = 0, B = 0;
        long long p26 = 1;
        for(int i = s.length() ; i > 0 ; --i){
            A += p26;
            p26 *= 26;
        }
        for(auto x:s){
            B = B * 26 + (x - 'A');
        }
        return A + B;
    }
    void Test(){
        cout<<titleToNumber("A")<<endl;
        cout<<(titleToNumber("AA") - 26)<<endl;
        cout<<(titleToNumber("AAA") - 26 - 26 * 26)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
