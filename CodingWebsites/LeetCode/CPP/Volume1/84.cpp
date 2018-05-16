#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <stack>
using namespace std;
class Solution_Sort_Set {
private:
    struct A{
        int height,position;
        A(){}
        A(int h,int p):height(h),position(p){}
        bool operator < (const A &B)const{
            return height < B.height;
        }
    };
public:
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size();
        if(!N) return 0;
        //Step One, sort by height
        vector<A> VA(N);
        for(int i = 0 ; i < N ; ++i){
            VA[i] = A(heights[i],i);
        }
        sort(VA.begin(),VA.end());
        //Step Two, starting from low to high
        //calculate the largest rectangle with that height using std::set
        set<int> S;
        S.insert(-1);
        S.insert(N);
        int Max = 0;
        for(int i = 0 ; i < N ; ++i){
            int Pos = VA[i].position;
            int Height = VA[i].height;
            S.insert(Pos);
            set<int>::iterator p = S.find(Pos);
            set<int>::iterator l = p, r = p;
            int C = Height * (*++r - *--l - 1);
            if(C > Max) Max = C;
        }
        return Max;
    }
    void Test(){
        int A[] = {2,1,5,6,2,3};
        vector<int> heights(A,A+sizeof(A)/sizeof(A[0]));
        cout<<largestRectangleArea(heights)<<endl;
    }
};

class Solution {//Stack
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int N = heights.size();
        stack<int> Stack;
        int MaxArea = 0;
        for(int i = 0 ; i < N ; ++i){
            while(!Stack.empty() && heights[i] < heights[Stack.top()]){
                int Cnt = Stack.top();
                Stack.pop();
                int L = Stack.empty()? -1 : Stack.top();
                //interval: (L,i)
                int C = heights[Cnt] * (i - L - 1);
                MaxArea = max(MaxArea,C);
            }
            
            if(Stack.empty() || heights[i] >= heights[Stack.top()]){
                Stack.push(i);
            }
            
        }
        return MaxArea;
    }
    void Test(){
        int A[] = {0,1,0,1};
        vector<int> heights(A,A+sizeof(A)/sizeof(A[0]));
        cout<<largestRectangleArea(heights)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
