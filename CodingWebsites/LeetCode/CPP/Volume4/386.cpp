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

class Solution1 {
    /*
    TLE
    */
    #define K 7
    vector<int> Ten;
    int getDigit(int v, int n){
        //get the n-th digit of v, -1 if doesn't exists
        for(int i = K - 1 ; i >= 0 ; --i){
            if(v >= Ten[i]){
                //v has i + 1 digits
                if(n <= i + 1){
                    int k = i + 1 - n;
                    //if(k < 9) 
                    v = v % Ten[k + 1];
                    v = v / Ten[k];
                    return v;
                }
                else
                    return -1;
            }
        }
        return n == 1 ? 0 : -1;
    }
    void SortByDigit(list<int> &ret,int digit){
        list<int> List[11];//[-1,9] -> [0,10]
        for(auto x:ret){
            List[getDigit(x,digit) + 1].push_back(x);
        }
        ret = list<int>();
        for(int i = 0 ; i <= 10 ; ++i){
            ret.insert(ret.end(),List[i].begin(),List[i].end());
        }
    }
public:
    Solution1(){
        Ten.resize(K + 1);
        Ten[0] = 1;
        for(int i = 1 ; i <= K ; ++i)
            Ten[i] = Ten[i - 1] * 10;
    }
    vector<int> lexicalOrder(int n) {
        if(n >= 100000000)
            return {};
        list<int> ret;
        for(int i = 1 ; i <= n ; ++i) 
            ret.push_back(i);
        for(int digit = K ; digit >= 1 ; --digit){
            if(n < Ten[digit]) continue;
            SortByDigit(ret,digit);
        }
        return vector<int>(ret.begin(),ret.end());
    }
    void Test(){
        vector<int> V = lexicalOrder(23);
        for(auto x:V){
            printf("%d ",x);
        }
        printf("\n");
    }
};

class Solution {// AC
    void F(vector<int> &ret, int v, int n){
        if(v <= n)
            ret.push_back(v);
        else
            return;
        for(int i = 0 ; i <= 9 ; ++i){
            int nv = v * 10 + i;
            F(ret,nv,n);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        for(int i = 1 ; i <= 9 ; ++i){
            F(ret,i,n);
        }
        return ret;
    }
    void Test(){
        vector<int> V = lexicalOrder(23);
        for(auto x:V){
            printf("%d ",x);
        }
        printf("\n");
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
