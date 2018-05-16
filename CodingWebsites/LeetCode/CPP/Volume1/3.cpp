#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
class Solution {
private:
    //Data for current interval
    int Count[256];
    int SumCount;
    int SumNonZero;
public:
    //Operation for current interval
    void Clear(){
        memset(Count,0,sizeof(Count));
        SumCount = SumNonZero = 0;
    }
    void Remove(int a){
        SumCount--;
        SumNonZero -= !--Count[a];
    }
    void Add(int a){
        SumCount++;
        SumNonZero += !Count[a]++;
    }
    //Main Function
    int lengthOfLongestSubstring(string s) {
        //two pointers
        int Len = s.length();
        int MaxLen = 0;
        Clear();
        int L = 0 , R = 0;//[L,R)
        while(L < Len){
            if(SumCount == SumNonZero){
                //Valid Record and move Right
                MaxLen = R - L > MaxLen ? R - L : MaxLen;
                if(R < Len) Add(s[R++]);
                else break;
            }
            else{
                //Invalid move Left
                Remove(s[L++]);
            }
        }
        return MaxLen;
    }
};

int main(){
    string str;
    Solution S;
    while(cin>>str){
        if(!strcmp(str.c_str(),"exit")){
            break;
        }
        cout<<S.lengthOfLongestSubstring(str)<<endl;
    }
	return 0;
}
