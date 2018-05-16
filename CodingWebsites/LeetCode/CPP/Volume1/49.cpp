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
#define u64 unsigned long long
    struct A{
        string str;
        u64 mask;
        A(){}
        A(string str,u64 mask):str(str),mask(mask){}
        bool operator <(const A &B)const{
            return mask < B.mask;
        }
    };
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //Step One: Hash
        vector<A> Hash = StepOne_Hash(strs);
        //Step Two: Sort
        sort(Hash.begin(),Hash.end());
        //Step Three: Group
        return StepThree_Group(Hash);
    }
    vector<A> StepOne_Hash(vector<string>& strs){
        int N = strs.size();
        vector<A> Hash(N);
        for(int i = 0 ; i < N ; ++i) Hash[i] = A(strs[i],getMask(strs[i]));
        return Hash;
    }
    vector<vector<string>> StepThree_Group(vector<A> &Hash){
        int L = 0, N = Hash.size();
        vector<vector<string>> ANS;
        for(int i = 0 ; i < N ; ++i){
            if(i + 1 == N || Hash[i].mask != Hash[i + 1].mask){
                //Record [L,i]
                vector<string> temp;
                for(int j = L ; j <= i ; ++j) temp.push_back(Hash[j].str);
                ANS.push_back(temp);
                L = i + 1;
            }
        }
        return ANS;
    }
    
    u64 getMask(string str){
        int N = str.length();
        sort(str.begin(),str.end());
        u64 A = 0;
        for(int i = 0 ; i < N ; ++i){
            A = A * 137 + str[i];
        }
        return A;
    }
    void Test(){
        char p[5][25]={"abc","bac","abcd","dcba","adbc"};
        vector<string> V;
        for(int i = 0 ; i < 5 ; ++i) V.push_back(p[i]);
        vector<vector<string>> ANS = groupAnagrams(V);
        for(auto line: ANS){
            cout<<"---------------"<<endl;
            for(auto x:line){
                cout<<x<<endl;
            }
            cout<<endl;
        }
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
