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
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(),ransomNote.end());
        sort(magazine.begin(),magazine.end());
        string &s1 = ransomNote;
        string &s2 = magazine;
        int n1 = s1.length(), n2 = s2.length();
        int i1 = 0, i2 = 0;
        for(i1 = 0 ; i1 < n1 ; ++i1, ++i2){
            while(i2 < n2 && s2[i2] != s1[i1])
                ++i2;
            if(i2 == n2)
                return false;
        }
        return true;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
