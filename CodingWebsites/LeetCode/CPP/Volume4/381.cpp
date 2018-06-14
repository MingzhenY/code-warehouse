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

struct TNode{
    int Count;
    TNode *L,*R;
    TNode():Count(0),L(NULL),R(NULL){}
};

class RandomizedCollection {
    vector<int> Mask;
    TNode *root;
    bool Insert(TNode *&root,int v,int k){
        if(!root)
            root = new TNode();
        
        //return if reached leaf
        if(k == 32){
            bool ret = root->Count == 0;
            root->Count++;
            return ret;
        }
        
        //Left 0, Right 1
        bool ret;
        if(v & Mask[k])
            ret = Insert(root->R,v,k+1);
        else
            ret = Insert(root->L,v,k+1);
        root->Count ++;
        return ret;
    }
    int Count(TNode *root,int v,int k){
        if(!root)
            return 0;
        if(k == 32){
            return root->Count;
        }
        if(v & Mask[k])
            return Count(root->R,v,k+1);
        else
            return Count(root->L,v,k+1);
    }
    bool Remove(TNode *&root,int v,int k){
        if(!root)
            return false;
        if(k == 32){
            bool ret = root->Count > 0;
            root->Count--;
            return ret;
        }
        bool ret;
        if(v & Mask[k])
            ret = Remove(root->R,v,k+1);
        else
            ret = Remove(root->L,v,k+1);
        root->Count--;
        return ret;
    }
    int GetRandom(TNode *root,int v,int k){
        if(k == 32){
            return v;
        }
        int LC = root->L ? root->L->Count : 0;
        int RC = root->R ? root->R->Count : 0;
        int RandInt = rand() % (LC + RC);
        if(RandInt < LC)
            return GetRandom(root->L,v,k+1);
        else
            return GetRandom(root->R,v | Mask[k],k+1);
    }
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        Mask.resize(32);
        Mask[0] = 1;
        for(int i = 1 ; i < 32 ; ++i)
            Mask[i] = Mask[i - 1] << 1;
        root = NULL;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        return Insert(root,val,0);
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(Count(root,val,0) > 0)
            return Remove(root,val,0);
        else
            return 0;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        //printf("Starting to Get Random\n");
        return GetRandom(root,0,0);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main(){
    srand(time(NULL));
    RandomizedCollection S;
    printf("%d\n",S.insert(3));
    printf("%d\n",S.insert(3));
    printf("%d\n",S.getRandom());
    printf("%d\n",S.getRandom());
    printf("%d\n",S.insert(1));
    printf("%d\n",S.remove(3));
    printf("%d\n",S.getRandom());
    printf("%d\n",S.getRandom());
    printf("%d\n",S.insert(0));
    printf("%d\n",S.remove(0));
    
	return 0;
}
