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
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        list<int> v1 = split(version1), v2 = split(version2);
        list<int>::iterator i1 = v1.begin(), i2 = v2.begin();
        while(i1 != v1.end() && i2 != v2.end()){
            if(*i1 > *i2) return 1;
            if(*i1 < *i2) return -1;
            i1++;
            i2++;
        }
        while(i1 != v1.end()){
            if(*i1 > 0) return 1;
            i1++;
        }while(i2 != v2.end()){
            if(*i2 > 0) return -1;
            i2++;
        }
        return 0;
    }
    list<int> split(string version){
        list<int> Ret;
        size_t L = 0;
        while(1){
            size_t pos = version.find('.',L);
            if(pos == string::npos){
                //reach the end
                try {
                    Ret.push_back(stoi(version.substr(L,version.length()-L)));
                }
                catch (const std::invalid_argument& ia) {
                    cout<<version.substr(L,version.length()-L)<<"is not a number"<<endl;
                }
                break;
            }
            else{
                try {
                    Ret.push_back(stoi(version.substr(L,pos-L)));
                }
                catch (const std::invalid_argument& ia) {
                    cout<<version.substr(L,pos-L)<<"is not a number"<<endl;
                }
            }
            L = pos + 1;
        }
        return Ret;
    }
    void Test(){
        cout<<compareVersion("1","1.0")<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
