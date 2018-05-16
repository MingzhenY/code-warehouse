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
#include <map>
using namespace std;

class Solution {
#define LL long long
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator == 0) return "";
        LL A=numerator,B=denominator;
        string PartOne = StepOne(A,B);
        string PartTwo = StepTwo(A,B);
        return PartOne + PartTwo;
    }
    string StepOne(LL &numerator, LL &denominator){
        //Sign and interger part
        int sign = 1;
        if(numerator < 0) {
            numerator = -numerator;
            sign = -sign;
        }
        if(denominator < 0){
            denominator = -denominator;
            sign = -sign;
        }
        // no sign when numerator is 0
        if(numerator == 0){
            sign = 1;
        }
        
        char line[32];
        if(sign == 1)
            sprintf(line,"%lld",numerator/denominator);
        else
            sprintf(line,"-%lld",numerator/denominator);
        numerator %= denominator;
        
        if(numerator){
            for(int i = 0 ; i < 31 ; i++){
                if(!line[i]){
                    line[i] = '.';
                    line[i+1] = '\0';
                    break;
                }
            }
        }
        return line;
    }
    string StepTwo(LL &numerator, LL &denominator){
        //The rest
        //1. devide by gcd
        LL D = gcd(numerator,denominator);
        numerator /= D;
        denominator /= D;
        //2. Start calculating
        string ANS;
        map<LL,int> P;
        LL R = numerator;
        int X = -1;
        while(R != 0){
            if(P.count(R)){
                X = P[R];
                break;
            }
            else{
                P[R] = int(ANS.length());
                R *= 10;
                int N = R / denominator;
                R = R % denominator;
                char line[32];
                sprintf(line,"%d",N);
                ANS += string(line);
            }
        }
        if(X == -1)
            return ANS;
        else
            return ANS.substr(0,X) + "(" + ANS.substr(X,ANS.length()-X) + ")";
    }
    int gcd(LL x,LL y){while(y) {int t=x%y;x=y;y=t;}return x;}
    void Test(){
        cout<<fractionToDecimal(-1,-2147483648)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
