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
private:
    // Vis.size() = 6 * n
    // Row   Column      /        \
    //  x       y       x+y      x-y
    //[0,n)  [n,2n)   [2n,4n)  [4n,6n)
    vector<bool> Vis;
public:
    vector<vector<string>> solveNQueens(int n) {
        Vis = vector<bool>(6 * n , false);
        vector<vector<string>> ANS;
        if(n <= 0) return ANS;
        vector<int> Stack(n,-1);
        int Top = 0;
        while(Top >= 0){
            if(Top == n){
                //Record Answer
                ANS.push_back(GenerateVString(Stack));
                //Move Down
                --Top;
                setValue(n,Top,Stack[Top],false);
            }
            else{
                if(++Stack[Top] >= n){
                    //Move down
                    Stack[Top] = -1;
                    if(--Top >= 0){
                        setValue(n,Top,Stack[Top],false);
                    }
                }
                else{
                    //if the number works
                    if(isValid(n,Top,Stack[Top])){
                        //Move Up
                        setValue(n,Top,Stack[Top],true);
                        ++Top;
                    }
                }
            }
        }
        return ANS;
    }
    bool isValid(int n,int x,int y){
        return !Vis[x] && !Vis[n + y] && !Vis[2 * n + x + y] && !Vis[5 * n + x - y];
    }
    void setValue(int n,int x,int y,bool b){
        Vis[x] = Vis[n + y] = Vis[2 * n + x + y] = Vis[5 * n + x - y] = b;
    }
    vector<string> GenerateVString(vector<int>&Stack){
        int n = Stack.size();
        vector<string> ANS(n,string(n,'.'));
        for(int i = 0 ; i < Stack.size() ; ++i){
            ANS[i][Stack[i]] = 'Q';
        }
        return ANS;
    }
    void Test(){
        vector<vector<string>>ANS = solveNQueens(4);
        for(auto game:ANS){
            for(auto line:game){
                cout<<line<<endl;
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
