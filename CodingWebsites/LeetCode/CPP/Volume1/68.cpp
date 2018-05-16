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
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int L = 0, R, N = words.size();
        vector<string> ANS;
        while(1){
            //printf("L=%d,R=%d\n",L,R);
            R = L;
            int WordCount = words[L].length();
            while(R + 1 < N && WordCount + 1 + words[R + 1].length() <= maxWidth){
                WordCount += 1 + words[++R].length();
            }
            if(R + 1 == N){
                //Record Answer(left justified)
                int Count = 0;
                string line = words[L];
                for(int i = L + 1 ; i <= R ; ++i){
                    line += " ";
                    line += words[i];
                    Count += words[i].size() + 1;
                }/*
                for(int i = Count ; i < maxWidth ; ++i){
                    line += " ";
                }*/
                L = R + 1;
                while(line.size() < maxWidth) line.push_back(' ');
                ANS.push_back(line);
                //break
                break;
            }
            else{
                //Record Answer
                if(L == R){
                    int Spaces = maxWidth - words[L].length();
                    string line;
                    
                    line += words[L];
                    for(int i = 0 ; i < Spaces ; ++i){
                        line +=' ';
                    }
                    ANS.push_back(line);
                    L = R + 1;
                }
                else{
                    string line = words[L];
                    int Spaces = maxWidth;
                    for(int i = L ; i <= R ; ++i) Spaces -= words[i].length();
                    int Gaps = R - L;
                    for(int i = 0 ; i < Gaps ; ++i){
                        int nSpace = (Spaces + Gaps - 1 - i)/Gaps;
                        //printf("nSpace=%d\n",nSpace);
                        for(int j = 0 ; j < nSpace ; ++j) line+=" ";
                        line += words[L + i + 1];
                    }
                    ANS.push_back(line);
                    L = R + 1;
                }
            }
        }
        return ANS;
    }
    void Test(){
        vector<string> str;
        //str.push_back("");
        /*
        str.push_back("This");
        str.push_back("is");
        str.push_back("an");
        str.push_back("example");
        str.push_back("of");
        str.push_back("text");
        str.push_back("justification.");*/
        /*
        str.push_back("Listen");
        str.push_back("to");
        str.push_back("many,");
        str.push_back("speak");
        str.push_back("to");
        str.push_back("a");
        str.push_back("few.");//6  */
        str.push_back("What");
        str.push_back("must");
        str.push_back("be");
        str.push_back("shall");
        str.push_back("be.");
        
        vector<string> ANS = fullJustify(str,12);
        for(auto line : ANS){
            cout<<line<<"|"<<endl;
        }
        cout<<endl;
        
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
