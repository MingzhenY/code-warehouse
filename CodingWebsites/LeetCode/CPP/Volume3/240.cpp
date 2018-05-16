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
#include <set>
using namespace std;

class Solution1 {
    /*
     split the are into 4 areas, seach each
     */
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M = matrix.size();
        if(!M) return false;
        int N = matrix[0].size();
        if(!N) return false;
        return search(matrix,target,0,M - 1,0,N - 1);
    }
    bool search(vector<vector<int>>& matrix, int target,int U,int D,int L,int R){
        //printf("Matrix[%d..%d][%d..%d]\n",U,D,L,R);
        if(U == D && L == R) return matrix[U][R] == target;
        //search target in matrix[U..D][L..R]
        int MUD = (U + D) >> 1;
        int MLR = (L + R) >> 1;
        //(U,L)           (U,R)
        //      (MUD,MLR) (MUD,R)
        //(D,L) (D,MLR)   (D,R)
        bool T1,T2,T3,T4;
        //T1 T3
        //T2 T4
        T1 = target >= matrix[U][L] && target <= matrix[MUD][MLR] ? search(matrix,target,U,MUD,L,MLR) : false;
        if(T1) return true;
        T2 = target <= matrix[D][MLR] && MUD < D && target >= matrix[MUD+1][L]? search(matrix,target,MUD+1,D,L,MLR) : false;
        if(T2) return true;
        T3 = target <= matrix[MUD][R] && MLR < R && target >= matrix[U][MLR+1]? search(matrix,target,U,MUD,MLR+1,R) : false;
        if(T3) return true;
        T4 = target > matrix[MUD][MLR] && target <= matrix[D][R] && MUD < D && MLR < R ? search(matrix,target,MUD+1,D,MLR+1,R) : false;
        return T4;
    }
    void Test(){
        vector<vector<int>> matrix = {
            {1,   4,  7, 11, 15},
            {2,   5,  8, 12, 19},
            {3,   6,  9, 16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
        };
        vector<vector<int>> matrix2 = {
            {1,  2,  3,  4,  5},
            {6,  7,  8,  9, 10},
            {11, 12, 13, 14,15},
            {16, 17, 18, 19, 20},
            {21, 22, 23, 24, 25}
        };
        cout<<searchMatrix(matrix2,5)<<endl;
    }
};
class Solution2 {
    /*
     split the are into 4 areas, and discard two,
     search the other two
     */
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M = matrix.size();
        if(!M) return false;
        int N = matrix[0].size();
        if(!N) return false;
        return search(matrix,target,0,M - 1,0,N - 1);
    }
    bool search(vector<vector<int>>& matrix, int target,int U,int D,int L,int R){
        //printf("Matrix[%d..%d][%d..%d]\n",U,D,L,R);
        if(U == D && L == R) return matrix[U][R] == target;
        if(target < matrix[U][L] || target > matrix[D][R]) return false;
        //search target in matrix[U..D][L..R]
        int MUD = (U + D) >> 1;
        int MLR = (L + R) >> 1;
        //(U,L)           (U,R)
        //      (MUD,MLR) (MUD,R)
        //(D,L) (D,MLR)   (D,R)
        
        //Move MUD
        //while(MUD < D && matrix[MUD][MLR] < target) ++MUD;
        //while(MUD > U && matrix[MUD][MLR] > target) --MUD;
        int _L = U,_R = D + 1, _M;//[_L,_R) find last <= target or first element if otherwise
        while(_L + 1 < _R){
            _M = (_L + _R) >> 1;
            if(matrix[_M][MLR] <= target) _L = _M;
            else _R = _M;
        }
        MUD = _L;
        
        if(matrix[MUD][MLR] == target) return true;
        if(matrix[MUD][MLR] < target){
            bool T1 = MLR + 1 <= R ? search(matrix,target,U,MUD,MLR + 1,R): false;
            if(T1) return true;
            bool T2 = MUD + 1 <= D && L <= MLR - 1 ? search(matrix,target,MUD + 1,D,L,MLR - 1) : false;
            return T2;
        }
        else{
            bool T1 = MLR + 1 <= R && MUD - 1 >= U ? search(matrix,target,U,MUD - 1,MLR + 1,R) : false;
            if(T1) return true;
            bool T2 = L <= MLR - 1 ? search(matrix,target,MUD,D,L,MLR - 1) : false;
            return T2;
        }
        return false;
    }
    void Test(){
        vector<vector<int>> matrix = {
            {1,   4,  7, 11, 15},
            {2,   5,  8, 12, 19},
            {3,   6,  9, 16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
        };
        vector<vector<int>> matrix2 = {
            {1,  2,  3,  4,  5},
            {6,  7,  8,  9, 10},
            {11, 12, 13, 14,15},
            {16, 17, 18, 19, 20},
            {21, 22, 23, 24, 25}
        };
        cout<<searchMatrix(matrix,5)<<endl;
    }
};
class Solution {
    // O(M+N)
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M = matrix.size();
        if(!M) return false;
        int N = matrix[0].size();
        if(!N) return false;
        
        int X = M - 1, Y = 0;
        while(X >= 0 && Y < N){
            if(target == matrix[X][Y]) return true;
            if(target < matrix[X][Y]){
                //discard numbers to the right of (X,Y)
                //because they are all larger than matrix[X][Y]
                --X;
            }
            else{
                //discard numbers above (X,Y)
                //because they are all smaller than matrix[X][Y]
                ++Y;
            }
        }
        return false;
    }
    void Test(){
        vector<vector<int>> matrix = {
            {1,   4,  7, 11, 15},
            {2,   5,  8, 12, 19},
            {3,   6,  9, 16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
        };
        vector<vector<int>> matrix2 = {
            {1,  2,  3,  4,  5},
            {6,  7,  8,  9, 10},
            {11, 12, 13, 14,15},
            {16, 17, 18, 19, 20},
            {21, 22, 23, 24, 25}
        };
        cout<<searchMatrix(matrix,5)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
