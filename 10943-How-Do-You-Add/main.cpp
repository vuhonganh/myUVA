//UVA 10943 How Do You Add
//Type: Dynamic Programming
//key point(as normal dp problem: use an array memo to remember what computed before
//algo: ways(n, 1) = 1 because there is only one way
//ways(n, k) = sum (ways (n - x, k - 1)) for x from 0 to n, i.e.: extract n to 2 parts, than recursive compute the other part with decreased number k (number of element in the addition)
#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;
int N, K;
vector<vector<int> > memo;
int ways(int n, int k)
{
  if (k == 1) return 1;
  int &ans = memo[n][k];
  if (ans != -1) return ans;
  else ans = 0;
  for (int i = 0; i < n + 1; ++i)
    {
      ans += ways(n - i, k - 1);
      ans %= 1000000;
    }
  return ans;
}
int main()
{
  while(scanf("%d %d", &N, &K) == 2 && (N != 0 && K != 0))
    {
      memo.assign(N + 1, vector<int>(K + 1, -1));
      printf("%d\n", ways(N, K) % 1000000);
    }
  return 0;
}
