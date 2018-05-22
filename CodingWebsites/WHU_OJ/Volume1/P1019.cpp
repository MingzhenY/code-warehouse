#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;
// 68 per line
char classtable[1430]="\
+-----+-----------+-----------+-----------+-----------+-----------+\n\
|     |    MON    |    TUE    |    WED    |    THU    |    FRI    |\n\
+-----+-----------+-----------+-----------+-----------+-----------+\n\
|                          Morning                                |\n\
+-----+-----------+-----------+-----------+-----------+-----------+\n\
|  1  |           |           |           |           |           |\n\
+-----+-----------+-----------+-----------+-----------+-----------+\n\
|  2  |           |           |           |           |           |\n\
+-----+-----------+-----------+-----------+-----------+-----------+\n\
|  3  |           |           |           |           |           |\n\
+-----+-----------+-----------+-----------+-----------+-----------+\n\
|  4  |           |           |           |           |           |\n\
+-----+-----------+-----------+-----------+-----------+-----------+\n\
|                         Afternoon                               |\n\
+-----+-----------+-----------+-----------+-----------+-----------+\n\
|  1  |           |           |           |           |           |\n\
+-----+-----------+-----------+-----------+-----------+-----------+\n\
|  2  |           |           |           |           |           |\n\
+-----+-----------+-----------+-----------+-----------+-----------+\n\
|  3  |           |           |           |           |           |\n\
+-----+-----------+-----------+-----------+-----------+-----------+\n";

char table[1430];
map<string,int> M;
void MakeMap(){
    M[string("Morning")]=5*68;
    M[string("Afternoon")]=15*68;
    
    M[string("1")]=7;
    M[string("2")]=7+68*2;
    M[string("3")]=7+68*4;
    M[string("4")]=7+68*6;
    
    M[string("MON")]=0;
    M[string("TUE")]=12*1;
    M[string("WED")]=12*2;
    M[string("THU")]=12*3;
    M[string("FRI")]=12*4;
}
char line[256];
int main(){
    MakeMap();
    freopen("P1019.txt","r",stdin);
    string COURSE,DAY,TIME,NUMBER,Line;
    int n;
    while(cin>>n){
        strcpy(table,classtable);
        fgets(line,256,stdin);
        for(int i=0;i<n;++i){
            fgets(line,256,stdin);
            Line = line;
            int len = strlen(line), Mark = 0 , State = 0;
            for(int i = 0 ; i < len ; ++i){
                if(State == 2 && line[i]==' '){
                    TIME = Line.substr(Mark+1,i - Mark - 1);
                    Mark = i;
                    State = 3;
                }
                if(State == 1 && line[i]==' '){
                    DAY = Line.substr(Mark+1,3);
                    Mark = i;
                    State = 2;
                }
                if(line[i]==':'){
                    COURSE = Line.substr(0,i);
                    Mark = ++i;
                    State = 1;
                }
            }
            NUMBER = Line.substr(Mark+1,1);
            //printf("%s:-%s-%s-%s\n",COURSE.c_str(),DAY.c_str(),TIME.c_str(),NUMBER.c_str());
            int Offset = M[DAY]+M[TIME]+M[NUMBER]+ 5 - (COURSE.length()>>1);
            for(int i=0;i<COURSE.length();++i){
                if(table[Offset+i]==' ')
                    table[Offset+i] = COURSE[i];
            }
        }
        cout<<table<<endl;
    }
    return 0;
}


