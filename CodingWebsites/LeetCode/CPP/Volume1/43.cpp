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
public:
    string multiply(string num1, string num2) {
        int N1 = num1.size(), N2 = num2.size();
        reverse(num1);
        reverse(num2);
        for(int i = 0 ; i < N1 ; ++i) num1[i] -= '0';
        for(int i = 0 ; i < N2 ; ++i) num2[i] -= '0';
        string A(N1+N2,0);
        for(int i = 0 ; i < N1 ; ++i){
            for(int j = 0 ; j < N2 ; ++j){
                int Cnt = num1[i] * num2[j];
                A[i + j] += Cnt;
                Cnt = i + j;
                while(A[Cnt] > 9){
                    A[Cnt+1] += A[Cnt]/10;
                    A[Cnt] %= 10;
                    ++Cnt;
                }
            }
        }
        for(int i = 0 ; i < N1 + N2 ; ++i){
            A[i] += '0';
        }
        while(A.size() > 1 && A[A.size() - 1] == '0'){
            A.resize(A.size() - 1);
        }
        reverse(A);
        
        return A;
    }
    void reverse(string &str){
        int N = str.size();
        for(int i = 0 ; i < N / 2 ; ++i){
            swap(str[i],str[N - i - 1]);
        }
    }
    void Test(){
        string num1 = "15";
        string num2 = "15";
        string A = multiply(num1,num2);
        cout<<A<<endl;
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
