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
    void reverseWords(vector<char>& str) {
        ReverseAll(str);
        ReverseEachWord(str);
    }
    void ReverseAll(vector<char>& str){
        int n = str.size();
        for(int i = 0 ; i < n/2 ; i++){
            swap(str[i],str[n - i - 1]);
        }
    }
    void ReverseEachWord(vector<char>& str){
        int n = str.size();
        int L = 0 , R = 0;
        while(R < n){
            while(R < n && str[R] != ' ') R++;
            //reverse [L,R)
            for(int i = L , j = R - 1 ; i < j ; i++, j--){
                swap(str[i],str[j]);
            }
        }
    }
    void Test(){
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
