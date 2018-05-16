#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        //Step One: convert parentheses to codes
        //(:1 ,):6
        //[:2 ,]:5
        //{:3 ,}:4
        int N = s.size();
        vector<int> Code(N);
        for(int i = 0 ; i < N ; ++i){
            Code[i] =
              s[i] <= ')' ? s[i] == '(' ? 1 : 6
            : s[i] <= ']' ? s[i] == '[' ? 2 : 5
            : s[i] <= '}' ? s[i] == '{' ? 3 : 4
            : 0;
        }
        
        //Step Two: Use stack to match the parentheses
        int Top = -1;
        bool Error = false;
        vector<int> Stack(N);
        for(int i = 0 ; i < N ; ++i){
            if(Code[i] <= 3){
                //Left part: Advance
                Stack[++Top] = Code[i];
            }
            else{
                if(-1 == Top){
                    //Enconter ),],} when empty - report error
                    Error = true;
                    break;
                }
                //Right part: Reduce
                if(Code[i] + Stack[Top] == 7){
                    //Match - Reduce
                    --Top;
                }
                else{
                    //No Match - Report Error
                    Error = true;
                    break;
                }
            }
        }
        //If Top >= 0 there are still some (,[,{ not matched
        Error = Error || Top >= 0;
        return !Error;
    }
    void Test(){
        string str = "[(])";
        
        cout<<isValid(str)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
