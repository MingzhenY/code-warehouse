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

class Vector2D {
    vector<vector<int>> vec;
    bool valid;
    vector<vector<int>>::iterator i;
    vector<int>::iterator j;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        vec = vec2d;
        valid = false;
        i = vec.begin();
        while(i != vec.end()){
            j = i->begin();
            if(j == i->end()) ++i;
            else {
                valid = true;
                break;
            }
        }
    }
    int next() {
        int ret = *j++;
        //value = next value
        while(valid){
            if(j == i->end()){
                if(++i != vec.end()){
                    j = i->begin();
                }
                else valid = false;
            }
            else break;
        }
        return ret;
    }
    
    bool hasNext() {
        return valid;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

int main(){
   
	return 0;
}
