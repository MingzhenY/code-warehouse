#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;


class Solution {
public:
    string getPermutation(int n, int k) {
        //C[i] = i!
        vector<int> C(n + 1,1);
        for(int i = 2 ; i <= n ; ++i) C[i] = i * C[i - 1];
        --k;
        vector<bool> visit(n + 1,false);
        string ans;
        for(int i = n - 1 ; i >= 0 ; --i){
            int Digit = getNext(visit,k / C[i]);
            ans.push_back(char(Digit+'0'));
            k %= C[i];
        }
        return ans;
    }
    int getNext(vector<bool> &visit,int k){
        int N = visit.size();
        for(int i = 1 ; i < N ; ++i){
            if(!visit[i] && k-- == 0){
                visit[i] = true;
                return i;
            }
        }
        return -1;
    }
    void Test(){
        for(int i = 1 ; i <= 24 ; ++i){
            cout<<getPermutation(4,i)<<endl;
        }
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
