/*
 * Author:  Eyelids
 * Created Time:  2013/12/19 10:27:43
 * File Name: D.cpp
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
using namespace std;
const double eps(1e-8);
typedef long long lint;
#define clr(x) memset( x , 0 , sizeof(x) )
#define sz(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define clrs( x , y ) memset( x , y , sizeof(x) )
#define inf 1000000007
int n, m;
int isBad[1000010], step[1000010], event[1000010], cntBad[1000010];
int cntHit[1000010];

int main() {
    scanf( "%d%d", &n, &m );

    for ( int i = 1; i <= n; i ++ ) step[i] = inf;
    int t;
    while ( m -- ) {// isBad:纪录i是否在被移除的列表中。 
        scanf( "%d", &t );
        step[t] = isBad[t] = 1;
    }
    for ( int i = 1; i <= n; i ++ ) {//cntBad:记录i之前 有多少个被移除。 
        cntBad[i] = cntBad[i - 1] + isBad[i];
        if ( !isBad[i] ) step[i] = step[i - cntBad[i]] + 1;
    }
 //   printf("\nstep[1]=%d\n",step[1]);
    for ( int i = 1; i <= n; i ++ ) {
        scanf( "%d", &event[i] );
        if ( event[i] == -1 ) cntHit[i] = 1;
    }
    for ( int i = n; i > 0; i -- ) 
        cntHit[i] += cntHit[i + 1];
   
    int len = 0; 
    for ( int i = 1; i <= n; i ++ )
        if ( event[i] == -1 ) 
            len -= cntBad[len];
        else if ( cntHit[i] < step[++len] ) 
            printf( "%d", event[i] );
   
    if ( !len ) printf( "Poor stack!" );
    printf( "\n" );
                
    
    return 0;
}








