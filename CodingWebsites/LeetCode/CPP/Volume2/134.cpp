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
/*
 Another solution would be using two pointers.
 Two pointers is a smart way of considering all pairs of (start,end).
 Where it avoids unnecessary calculations and uses O(n) time instead of O(n^2).
 */
class Solution {
    /*
     Status: AC
     See if a gas station i can reach i + 1, i + 2, i + 4, i + 8, ...
     Which can be computed quickly.
     The tricky part is to define a struct that can tell if
     a given segment is reachable. More importantly, the struct should support
     interval addition(which is defined inside struct 'Info').
     The struct 'Info' is used to serve the purpose.
     */
    struct Info {
        int GasSum;//Sum of gas - cost
        int GasNeeded;//Gas Needed to reach
        Info operator+(const Info &R){
            Info A, &L = *this;
            A.GasSum = L.GasSum + R.GasSum;
            //See if the car can reach the end of this segment
            if(L.GasNeeded == 0 && L.GasSum >= R.GasNeeded){
                A.GasNeeded = 0;
            }else{
                if(L.GasNeeded){
                    //Can not reach mid point
                    if(R.GasNeeded){
                        if(L.GasNeeded + L.GasSum >= R.GasNeeded)
                            A.GasNeeded = L.GasNeeded;
                        else
                            A.GasNeeded = max(L.GasNeeded, R.GasNeeded - L.GasNeeded - L.GasSum);
                    }else{
                        A.GasNeeded = L.GasNeeded;
                    }
                }else{
                    //Can reach mid point
                    if(L.GasSum >= R.GasNeeded)
                        A.GasNeeded = 0;
                    else
                        A.GasNeeded = R.GasNeeded - L.GasSum;
                }
            }
            return A;
        }
        void Show(int i,int j){
            printf("D[%d][%d]=(%d,%d)\n",i,j,GasSum,GasNeeded);
        }
    };
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if(!n) return -1;
        {
            int Sum_gas = 0;
            int Sum_cost = 0;
            for(auto x : gas) Sum_gas += x;
            for(auto x : cost) Sum_cost += x;
            if(Sum_gas < Sum_cost) return -1;
        }
        int V = 1, N = 0;
        while(2 * V <= n) V <<= 1, N++; // n/2 < V <= n
        
        //Keep N+1 values for each gas station
        //Showing if gas station i can reach i + 1, i + 2, i + 4, i + 8, ..., i + V
        vector<vector<Info> > D = vector<vector<Info> >(n,vector<Info>(N+1));
        
        for(int i = 0 ; i < n ; ++i){
            D[i][0].GasSum = gas[i] - cost[i];
            D[i][0].GasNeeded = cost[i] > gas[i] ? cost[i] - gas[i] : 0;
            //D[i][0].Show(i,0);
        }
        
        for(int Step = 1, StepI = 1 ; StepI <= N ; Step <<= 1, StepI++){
            for(int i = 0 ; i < n ; i++){
                int j = (i + Step) % n;
                D[i][StepI] = D[i][StepI - 1] + D[j][StepI - 1];
                //D[i][StepI].Show(i,StepI);
            }
        }
        
        for(int i = 0 ; i < n ; ++i){
            //Test if i is the answer
            //The Interval calculated here might be more than a full circle
            //But that is the same thing as a full circle in regard to reachableness.
            //Calculate a full circle here is possible but unnecessary.
            Info A = D[i][N] + D[(i + V) % n][N];
            if(A.GasNeeded == 0) return i;
        }
        return -1;
    }
    void Test(){
        int Gas[] = {1,2,3,3};
        int Cost[] = {2,1,5,1};
        vector<int> gas(Gas,Gas+sizeof(Gas)/sizeof(Gas[0]));
        vector<int> cost(Cost,Cost+sizeof(Cost)/sizeof(Cost[0]));
        cout<<canCompleteCircuit(gas,cost)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
class Solution1 {
    /*
     Brute Force: TLE
     */
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if(!n) return -1;
        {
            int Sum_gas = 0;
            int Sum_cost = 0;
            for(auto x : gas) Sum_gas += x;
            for(auto x : cost) Sum_cost += x;
            if(Sum_gas < Sum_cost) return -1;
        }
        
        for(int start = 0 ; start < n ; start++){
            int Gas = 0, Cnt = start, Run = 0;
            for(int i = 0; i < n ; i++){
                Gas += gas[Cnt];
                if(cost[Cnt] <= Gas){
                    Gas -= cost[Cnt];
                    Run++;
                    Cnt = (Cnt + 1) % n;
                }
                else break;
            }
            if(Run == n) return start;
        }
        return -1;
    }
    void Test(){
        
    }
};

