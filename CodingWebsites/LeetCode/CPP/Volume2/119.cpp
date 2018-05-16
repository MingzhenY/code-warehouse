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
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1,1);
        row[0] = 1;
        for(int j = 0 ; j < rowIndex ; ++j){
            for(int k = j ; k >= 1 ; --k){
                row[k] += row[k - 1];
            }
        }
        return row;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
