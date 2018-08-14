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
public:
    string removeDuplicateLetters(string s) {
        //the problem is about choosing the letters in order.
        //in each step, one question should be answerd:
        //if I choose a letter ch next, is it possible to choose the rest.
        //This question can be answerd using a character mask by maping each letter to a bit
        
        
        map<char,int> Map;
        for(int i = 'a' ; i <= 'z' ; ++i){
            Map[i] = 1 << (i - 'a');
        }
        int Len = s.length();
        vector<int> Mask(Len + 1,0);
        //Mask[i] contains all the letters in s[i..]
        for(int i = Len - 1 ; i >= 0 ; --i){
            Mask[i] = Mask[i + 1] | Map[s[i]];
        }
        //store letter positions
        vector<int> V[26];
        for(int i = 0 ; i < s.length() ; ++i){
            V[s[i]-'a'].push_back(i);
        }
        
        int Chosen = 0, CntPos = -1;
        string ret;
        while(Chosen != Mask[0]){
            bool done = false;
            //Choose the next letter
            for(int i = 0, m = 1 ; i < 26 ; ++i, m <<= 1){
                if((Chosen & m) == 0){
                    //can choose i, check if possible
                    
                    //find the first letter starting from CntPos
                    for(int I = 0 ; I < V[i].size() ; ++I){
                        if(V[i][I] > CntPos){
                            //check if it is possible to choose the rest after
                            //choosing this letter
                            if((Chosen | Mask[V[i][I]]) == Mask[0]){
                                Chosen = Chosen | m;
                                ret += char(i + 'a');
                                CntPos = V[i][I];
                                done = true;
                            }
                            break;
                        }
                    }
                }
                if(done) break;
            }
        }
        return ret;
    }
    void Test(){
        string s = "cbacdcbc";
        cout<<removeDuplicateLetters(s)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
