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
    map<string,pair<string,double>> M;
    pair<string,double> Find(string var){
        if(!M.count(var))
            M[var] = make_pair(var,1.0);
        
        pair<string, double> p = M[var];
        double K = p.second;
        while(M[p.first].first != p.first){
            p = M[p.first];
            K *= p.second;
        }
        return M[var] = make_pair(p.first,K);
    }
    void Union(string var1, string var2, double k){
        //var1 / var2 = k
        //(var1/r1) / (var2/r2) = k * r2 / r1
        pair<string,double> r1 = Find(var1);
        pair<string,double> r2 = Find(var2);
        M[r1.first] = make_pair(r2.first,k * r2.second / r1.second);
    }
    double Get(string var1, string var2){
        pair<string,double> r1 = Find(var1);
        pair<string,double> r2 = Find(var2);
        if(r1.first == r2.first){
            return r1.second / r2.second;
        }
        else return -1.0;
    }
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int N = equations.size();
        for(int i = 0 ; i < N ; ++i){
            Union(equations[i].first,equations[i].second, values[i]);
        }
        vector<double> ret;
        for(auto p : queries){
            if(M.count(p.first) && M.count(p.second))
                ret.push_back(Get(p.first,p.second));
            else
                ret.push_back(-1.0);
        }
        return ret;
    }
    void Test(){
        vector<pair<string,string>> equations = {{"a","b"},{"b","c"}};
        vector<pair<string,string>> queries = {{"a","c"},{"a","b"},{"b","c"}};
        vector<double> values = {2.0,3.0};
        vector<double> ans = calcEquation(equations,values,queries);
        for(auto x : ans){
            printf("%.2f\n",x);
        }
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
