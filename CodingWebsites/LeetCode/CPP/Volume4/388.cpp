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
    pair<int,string> getLevel(string line){
        int D = 0, L = line.length();
        while(D < L && line[D] == '\t')
            ++D;
        return make_pair(D,line.substr(D));
    }
    vector<pair<int,string>> splitLines(string input){
        vector<pair<int,string>> ret;
        while(true){
            int pos = input.find("\n");
            if(pos != string::npos){
                string line = input.substr(0,pos);
                input = input.substr(pos + 1);
                ret.push_back(getLevel(line));
            }
            else{
                ret.push_back(getLevel(input));
                break;
            }
        }
        return ret;
    }
public:
    int lengthLongestPath(string input) {
        vector<pair<int,string>> lines = splitLines(input);
        stack<int> S;
        int CntPath = 0, MaxPath = 1;
        for(auto p : lines){
            //pop out deeper dirs
            while(S.size() > p.first){
                int t = S.top();
                CntPath -= t;
                S.pop();
            }
            //add current one
            int DL = p.second.length() + 1;
            S.push(DL);
            CntPath += DL;
            if(p.second.find('.') != string::npos && CntPath > MaxPath)
                MaxPath = CntPath;
        }
        return MaxPath - 1;
    }
    void Test(){
        string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
        printf("longest path = %d\n",lengthLongestPath(input));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
