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
 Solution: Use Segment Tree to speed up the check of palindromes
 Result: TLE
 */
class Solution {
private:
    struct Node{
        unsigned int n,VL,VR;
        Node(int n = 0,int VL = 0, int VR = 0):n(n),VL(VL),VR(VR){}
    };
    int N;
    vector<Node> ST;
public:
    int minCut(string s) {
        int n = s.length();
        int ANS = n;//minCut for now
        if(!n) return ANS - 1;
        
        InitST(s);
        BuildST(s,1,N,1);
        Cut(s,0,0,n,ANS);
        return ANS - 1;
    }
    void Cut(string &s,int nCut,int L,int R,int &MinCut){
        if(L == R){
            if(nCut < MinCut){
                MinCut = nCut;
            }
            return;
        }
        if(nCut > MinCut) return;
        //[L,R) find first cut from right to left
        for(int i = R; i > L ; --i){
            Node X = CheckST(L+1,i,1,N,1);
            if(X.VL == X.VR){
                Cut(s,nCut + 1,i,R,MinCut);
            }
        }
    }
    //Segment Tree check
    void InitST(string &s){
        N = s.length();
        ST = vector<Node>(4 * N);
    }
    unsigned int qPow(unsigned int a,unsigned int k){
        unsigned int A = 1;
        while(k){
            if(k & 1) A *= a;
            a *= a;
            k >>= 1;
        }
        return A;
    }
    Node NodeAdd(Node L,Node R){
        Node A;
        A.VL = L.VL * qPow(137,R.n) + R.VL;
        A.VR = L.VR + R.VR * qPow(137,L.n);
        A.n = L.n + R.n;
        return A;
    }
    void PushUp(int rt,int ln,int rn){
        ST[rt] = NodeAdd(ST[rt<<1],ST[rt<<1|1]);
    }
    void BuildST(string &s,int l,int r,int rt){
        if(l == r){
            ST[rt].VL = s[l-1];
            ST[rt].VR = s[l-1];
            ST[rt].n = 1;
            return;
        }
        int m = (l + r) >> 1;
        BuildST(s,l,m,rt<<1);
        BuildST(s,m+1,r,rt<<1|1);
        PushUp(rt,m-l+1,r-m);
    }
    Node CheckST(int L,int R,int l,int r,int rt){
        if(L <= l && r <= R){
            //printf("Check(%d,%d) = (%u,%u)\n",l,r,ST[rt].VL,ST[rt].VR);
            return ST[rt];
        }
        int m = (l + r) >> 1;
        int X = 0;
        Node AL,AR;
        int nL = m - max(l,L) + 1,nR = min(r,R) - m;
        if(L <= m){
            AL = CheckST(L,R,l,m,rt<<1);
            nL =
            X += 1;
        }
        if(R > m){
            AR = CheckST(L,R,m+1,r,rt<<1|1);
            X += 2;
        }
        if(X == 1) return AL;
        if(X == 2) return AR;
        Node X3 = NodeAdd(AL,AR);
        return X3;
    }
    //naive check
    bool check(string &s,int L,int R){//[L,R)
        long long VL = 0 , VR = 0;
        for(int i = L, j = R - 1 ; i < R ; ++i, --j){
            VL = VL * 137 + s[i];
            VR = VR * 137 + s[j];
        }
        return VL == VR;
    }
    void Test(){
        string str = "aabaabcdcba";
        int ANS = minCut(str);
        cout<<ANS<<endl;
        
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
