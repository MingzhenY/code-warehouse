#include <cstdio>

int main()
{
  freopen("1651.txt","w",stdout);
  int n = 10000, sum = 0;

  printf("%d\n", 99951);
  for (int i = 6; i <= n; i++)
  {
    printf("1 %d 2 %d 3 %d 4 %d 5 %d ", i, i, i, i, i);
    sum += 10;
  }
  puts("1");
  sum++;
  
  return 0;
}








