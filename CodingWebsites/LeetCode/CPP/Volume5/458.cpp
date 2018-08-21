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
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets == 1) return 0;
        int NumberOfRounds = minutesToTest / minutesToDie;
        //B : Bucket number
        //R : Number of Rounds
        //Each pig can test R rounds, it can figure out
        //one digit in a (R+1)-base number
        //So the question becomes
        //how many digits are there if we
        //turn (B-1) into a (R+1)-base number.
        
        return floor(log(buckets - 1) / log(NumberOfRounds + 1)) + 1;
    }
    void Test(){
        cout<<poorPigs(1000,15,60)<<endl;//5 pigs
        cout<<poorPigs(5,15,60)<<endl;//1 pig
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
