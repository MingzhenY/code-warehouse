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

class Solution {
    bool A[26][26];
    bool Vis[26],Has[26];
    int In[26];
public:
    string alienOrder(vector<string>& words) {
        //Step One: Find order
        memset(A,0,sizeof(A));
        int n = words.size();
        for(int i = 1 ; i < n ; ++i)
            F(words[i-1],words[i]);
        //Show();
        //Step Two: Topological sort
        queue<int> Q;
        memset(Has,0,sizeof(Has));
        memset(In,0,sizeof(In));
        for(auto x:words){
            for(auto ch:x){
                Has[ch-'a'] = true;
            }
        }
        for(int i = 0 ; i < 26 ; ++i){
            for(int j = 0 ; j < 26 ; ++j){
                if(A[i][j]){
                    ++In[j];
                }
            }
        }
        for(int i = 0 ; i < 26 ; ++i){
            if(Has[i] && !In[i]){
                Q.push(i);
                //printf("Added %d in Init()\n",i);
            }
        }
        string ret;
        memset(Vis,0,sizeof(Vis));
        while(!Q.empty()){
            int id = Q.front();Q.pop();
            Vis[id] = true;
            //printf("id=%d\n",id);
            ret += char(id + 'a');
            for(int j = 0 ; j < 26 ; ++j)
                if(A[id][j] && --In[j] == 0){
                    Q.push(j);
                    //printf("Added %d in Q\n",j);
                }
        }
        //Step Three: Succeed or not
        int HasCount = 0;
        for(int i = 0 ; i < 26 ; ++i) {
            HasCount += Has[i];
        }
        if(HasCount == ret.length())
            return ret;
        else return "";
    }
    void F(string &str1, string &str2){
        int L1 = str1.length();
        int L2 = str2.length();
        int i1,i2;
        i1 = i2 = 0;
        while(i1 < L1 && i2 < L2){
            if(str1[i1] != str2[i2]){
                A[str1[i1] - 'a'][str2[i2] - 'a'] = true;
                return;
            }
            ++i1;
            ++i2;
        }
    }
    void Show(){
        for(int i = 0 ; i < 26 ; ++i){
            for(int j = 0 ; j < 26 ; ++j){
                if(A[i][j]){
                    printf("%c->%c\n",i+'a',j+'a');
                }
            }
        }
    }
    void Test(){
        vector<string> words = {"wrt","wrf","er","ett","rftt"};
        words = {"a","a"};
        cout<<alienOrder(words)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
