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

// Forward declaration of isBadVersion API.
bool isBadVersion(int version){
    return version >= 1702766719;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int L = 1 , R = n;//[L,R) first bad
        while(L ^ R){
            int M = L + ((R - L) >> 1);
            if(isBadVersion(M)) R = M;
            else L = M + 1;
        }
        return L;
    }
    void Test(){
        cout<<firstBadVersion(2126753390)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
