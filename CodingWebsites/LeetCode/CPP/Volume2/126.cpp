#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <list>
#include <cmath>
#include <queue>
using namespace std;

class Solution {
private:
    struct ArcNode{
        int to;
        ArcNode *next;
        ArcNode(int to = 0, ArcNode *next = NULL):to(to),next(next){}
    };
    struct Node{
        string word;
        int Dist;
        int Prev;
        bool vis;
        ArcNode *L;
        Node(string word = "", int Dist = -1, ArcNode *L = NULL):word(word),Dist(Dist),L(L),vis(false){
            Prev = -1;
        }
    };
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        map<string,int> ID;
        vector<Node> node;
        int WID = 0;
        wordList.push_back(beginWord);
        for(auto x:wordList){
            if(!ID.count(x)){
                //Build graph nodes
                node.push_back(Node(x,x == beginWord?0:-1));
                //Assign id to words
                ID[x] = WID++;
            }
        }
        if(!ID.count(endWord)) return vector<vector<string>>();
        
        //Build edges
        int n = ID.size();
        for(int i = 0 ; i < n ; ++i){
            for(int j = i + 1 ; j < n ; ++j){
                if(StrNear(node[i].word,node[j].word)){
                    ArcNode *temp;
                    temp = new ArcNode(j);
                    temp->next = node[i].L;
                    node[i].L = temp;
                    temp = new ArcNode(i);
                    temp->next = node[j].L;
                    node[j].L = temp;
                }
            }
        }
        
        //Run BFS to fill Dis
        queue<int> Q;
        Q.push(ID[beginWord]);
        node[ID[beginWord]].Dist = 0;
        node[ID[beginWord]].vis = true;
        while(!Q.empty()){
            int cnt = Q.front(); Q.pop();
            ArcNode *temp = node[cnt].L;
            while(temp){
                if(!node[temp->to].vis){
                    node[temp->to].vis = true;
                    node[temp->to].Dist = node[cnt].Dist + 1;
                    Q.push(temp->to);
                }
                temp = temp->next;
            }
        }
        //Output results
        int S = ID[beginWord];
        int T = ID[endWord];
        vector<vector<string>> ANS;
        FindPath(node,ANS,S,T,S,0);
        //return ANS;
        return ANS;
    }
    void FindPath(vector<Node> &node,vector<vector<string>> &ANS,int S,int T,int v,int depth){
        if(v == T){
            //Find a path, add to Answer
            vector<string> V;
            int I = T;
            while(I != -1){
                V.push_back(node[I].word);
                I = node[I].Prev;
            }
            //reverse the vector
            int Vn = V.size();
            for(int i = Vn / 2 - 1; i >= 0 ; --i){
                swap(V[i],V[Vn - i - 1]);
            }
            ANS.push_back(V);
            return;
        }
        ArcNode *temp = node[v].L;
        while(temp){
            if(node[temp->to].Dist > node[v].Dist){
                node[temp->to].Prev = v;
                FindPath(node,ANS,S,T,temp->to,depth + 1);
            }
            temp = temp->next;
        }
    }
    bool StrNear(string &s1,string &s2){
        int Diff = 0;
        int L1 = s1.length();
        int L2 = s2.length();
        for(int i = 0 , j = 0 ; i < L1 && j < L2 ; ++i, ++j){
            Diff += s1[i] != s2[j];
            
        }
        return Diff == 1;
    }
    void Test(){
        string str[] = {"hot","dot","dog","lot","log","cog"};
        vector<string> D(str,str + sizeof(str)/sizeof(str[0]));
        vector<vector<string>> ANS;
        ANS = findLadders("hit","cog",D);
        for(auto S:ANS){
            for(auto x:S){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
};



int main(){
    Solution S;
    S.Test();
	return 0;
}
