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
Brute force TLE
*/
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        //maxChoosableInteger <= 20   => there are at most 2^20 states
        if(maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
            return false;
        else if(desiredTotal <= 0){
            return true;
        }
        else {
            int toChoose = 0;
            for(int i = 0 ; i < maxChoosableInteger ; ++i)
                toChoose |= 1 << i;
            return canWin(0,toChoose,desiredTotal,maxChoosableInteger);
        }
    }
    bool canWin(int Sum, int toChoose, int Target, int maxChoosableInteger){
        if(Sum >= Target){
            //if Sum already >= Target, you lose
            return false;
        }
        //returns if the current player can force a win
        int State = toChoose, k = 0, number = maxChoosableInteger, Count = 0, All = 0;
        while(State){
            if(State & 1){
                //try choosing k
                Count += canWin(Sum + number, toChoose & (~(1 << k)),Target,maxChoosableInteger);
                All ++;
                if(Count < All)
                    return true;
            }
            ++k;
            --number;
            State >>= 1;
        }
        return Count < All;
    }
    void Test(){
        //True set
        printf("true set\n");
        //1.Win by choosing one, then force (n+2) at each step
        cout<<canIWin(10,12)<<endl;
        cout<<canIWin(10,0)<<endl;
        
        printf("false set:\n");
        //False set
        cout<<canIWin(10,11)<<endl;
        cout<<canIWin(5,20)<<endl;
    }
};


class Solution {
    bool Win[1<<20];
    bool Vis[1<<20];
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        //maxChoosableInteger <= 20   => there are at most 2^20 states
        if(maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
            return false;
        else if(desiredTotal <= 0){
            return true;
        }
        else {
            int toChoose = 0;
            for(int i = 0 ; i < maxChoosableInteger ; ++i)
                toChoose |= 1 << i;
            memset(Vis,0,sizeof(Vis));
            return canWin(0,toChoose,desiredTotal,maxChoosableInteger);
        }
    }
    bool canWin(int Sum, int toChoose, int Target, int maxChoosableInteger){
        if(Vis[toChoose])
            return Win[toChoose];
        if(Sum >= Target){
            //if Sum already >= Target, you lose
            Vis[toChoose] = false;
            return Win[toChoose] = false;
        }
        //returns if the current player can force a win
        int State = toChoose, k = 0, number = maxChoosableInteger, Count = 0, All = 0;
        while(State){
            if(State & 1){
                //try choosing k
                Count += canWin(Sum + number, toChoose & (~(1 << k)),Target,maxChoosableInteger);
                All ++;
                if(Count < All){
                    Vis[toChoose] = true;
                    return Win[toChoose] = true;
                }
            }
            ++k;
            --number;
            State >>= 1;
        }
        Vis[toChoose] = true;
        return Win[toChoose] = false;
    }
    void Test(){
        //True set
        printf("true set\n");
        //1.Win by choosing one, then force (n+2) at each step
        cout<<canIWin(10,12)<<endl;
        cout<<canIWin(10,0)<<endl;
        
        printf("false set:\n");
        //False set
        cout<<canIWin(10,11)<<endl;
        cout<<canIWin(5,20)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
