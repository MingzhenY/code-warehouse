/*
 * Author:  Eyelids
 * Created Time:  2013/12/18 23:55:40
 * File Name: C.cpp
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
char w[3010][3010];//字符 
bool v[3010][3010];//判断走过 
int f[3010][3010];//记录步数 
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int ans;

int Dfs( int x, int y ) {
    if ( f[x][y] ) return f[x][y];
    
    int nx, ny;
    int &ret = f[x][y]; 
    if ( w[x][y] == 'A' ) f[x][y] = 1;
  
    v[x][y] = true;
    for ( int i = 0; i < 4; i ++ ) {
        nx = x + dx[i];
        ny = y + dy[i];
  
        if ( ans == inf ) return 0;
        if ( w[x][y] == 'D' && w[nx][ny] == 'I' ||
             w[x][y] == 'I' && w[nx][ny] == 'M' ||
             w[x][y] == 'M' && w[nx][ny] == 'A' ||
             w[x][y] == 'A' && w[nx][ny] == 'D' ) {
           
            if ( v[nx][ny] ) {
                ans = inf;
                return 0; 
            }
            ret = max( ret, Dfs( nx, ny ) + ( w[x][y] == 'A' ) );
            if ( ans == inf ) return 0;
        }
    }
    v[x][y] = false;
       
    return ret; 
}

int main(){
    scanf( "%d%d", &n, &m );
    for ( int i = 0; i < n; i ++ ) {
        scanf( "%c", &w[3001][3001] );
        for ( int j = 0; j < m; j ++ )
            scanf( "%c", &w[i][j] );
    }
   
    ans = 0; 
    for ( int i = 0; i < n; i ++ )
        for ( int j = 0; j < m; j ++ )
            if ( w[i][j] == 'D' )
                ans = max( ans, Dfs( i, j ) );
  
    if ( ans == inf ) 
        cout <<"Poor Inna!"<<endl;
    else if ( ans == 0 )
        cout <<"Poor Dima!"<<endl;
    else
        cout <<ans<<endl; 
     
    return 0;
}






