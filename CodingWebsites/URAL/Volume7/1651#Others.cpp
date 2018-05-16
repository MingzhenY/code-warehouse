#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 100005;
const int inf = 0x7f7f7f7f;
 typedef pair<int, int> pii;
 typedef vector<pii> vpii;
int rec[maxn], dis[maxn], buf[maxn];
 bool inq[maxn];
 vpii rel[maxn], opRel[maxn];
  
  void input(int n) {
      for (int i = 0; i < maxn; i++) {
          rec[i] = -1;
          rel[i].clear();
          opRel[i].clear();
          dis[i] = inf;
          inq[i] = false;
      }
  
     int cur;
  
      scanf("%d", &cur);
      rec[cur] = 0;
      buf[0] = cur;
      for (int i = 1; i < n; i++) {
          scanf("%d", &cur);
          buf[i] = cur;
          rel[i - 1].push_back(make_pair(i, 1));
          opRel[i].push_back(make_pair(i - 1, 1));
          if (~rec[cur]) {
              rel[rec[cur]].push_back(make_pair(i, 0));
              opRel[i].push_back(make_pair(rec[cur], 0));
          }
          rec[cur] = i;
      }
  
  //    for (int i = 0; i < n; i++) {
  //        printf("%d :", i);
  //        for (int j = 0, size = rel[i].size(); j < size; j++) {
  //            printf(" %d-%d", rel[i][j].first, rel[i][j].second);
  //        }
  //        puts(" ~~");
  //    }
  }
  
  int q[maxn], qh, qt;
  
  void spfa(int s) {
      int cur = s;
  
      qh = qt = 0;
      q[qt++] = s;
      dis[s] = 0;
      inq[cur] = true;
      while (qh < qt) {
          cur = q[qh++];
          inq[cur] = false;
  
          for (vpii::iterator ii = rel[cur].begin(); ii != rel[cur].end(); ii++) {
             int next = (*ii).first, len = (*ii).second;
  
              if (dis[next] > dis[cur] + len) {
                  dis[next] = dis[cur] + len;
                  if (!inq[next]) {
                      q[qt++] = next;
                      inq[next] = true;
                  }
              }
          }
      }
  //    for (int i = 0; i < 10; i++) {
  //        printf("dis %d : %d\n", i, dis[i]);
  //    }
  }
  
  int Stack[maxn], top;
  
  void backTrack(int T) {
      top = -1;
  
      int cur = T;
  
      Stack[++top] = buf[cur];
      while (cur) {
          for (vpii::iterator ii = opRel[cur].begin(); ii != opRel[cur].end(); ii++) {
              if (dis[cur] == dis[(*ii).first] + (*ii).second) {
                  cur = (*ii).first;
                  if (Stack[top] != buf[cur]) Stack[++top] = buf[cur];
                  break;
              }
          }
      }
      while (~top) {
          printf("%d", Stack[top]);
         if (top) {
             putchar(' ');
         }
         top--;
     }
     puts("");
 }
 
 int main() {
     int n;
 freopen("1651.txt","r",stdin); 
 //    freopen("in", "r", stdin);
     while (~scanf("%d", &n)) {
         input(n);
         spfa(0);
         backTrack(n - 1);
     }
 
     return 0;
 }
