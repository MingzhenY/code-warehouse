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
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        for(int i = 1 ; i <= n ; ++i){
            if(i % 3 == 0 || i % 5 == 0){
                string s3 = i % 3 == 0 ? "Fizz" : "";
                string s5 = i % 5 == 0 ? "Buzz" : "";
                ret.push_back(s3 + s5);
            }
            else ret.push_back(to_string(i));
        }
        return ret;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
