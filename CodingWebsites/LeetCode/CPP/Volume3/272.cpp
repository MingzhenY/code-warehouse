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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
    struct A{
        int V;
        double dist;
        A(){}
        A(int V,double dist):V(V),dist(dist){}
        bool operator <(const A &B)const{
            return dist < B.dist;
        }
    };
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<A> VA = F(root,target,k);
        vector<int> ret;
        for(auto x:VA)
            ret.push_back(x.V);
        return ret;
    }
    vector<A> F(TreeNode* root, double target, int k) {
        if(!root) return {};
        vector<A> L,R;
        L = F(root->left,target,k);
        R = F(root->right,target,k);
        for(auto x:R) L.push_back(x);
        L.push_back(A(root->val,abs(root->val - target)));
        sort(L.begin(),L.end());
        if(L.size() > k)  L.resize(k);
        return L;
    }
    void Test(){
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
