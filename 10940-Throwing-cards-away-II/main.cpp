//uva 10940 Throwing cards away II
//deque simulation

#include <cstdio>
#include <deque>
#include <cstring>

using namespace std;

int memo[500004];

int getIdx(int n) //note that we return the index of remaining number, index starting from 0
{
  if (n == 1 || n == 2) return n - 1;
  int &ans = memo[n];
  if (ans != -1) return ans;
  int idx_n_minus_1 = getIdx(n - 1);
  ans = (idx_n_minus_1 == n - 2) ? 1 : idx_n_minus_1 + 2;
  return ans;
} 

int main()
{
  int n;
  memset(memo, -1, sizeof(memo));
  memo[1] = 0;
  memo[2] = 1;
  bool debug = false;
  if (debug) printf("start\n");
  int caseNb = 1;

  
  for (int i = 1; i < 500001; ++i)
    {
      getIdx(i);
    }
  
  while (scanf("%d", &n) == 1 && n != 0)
    {
      printf("%d\n", memo[n] + 1);
      //printf("%d\n", getIdx(n) + 1);
      if (debug) printf("done case %d\n\n", caseNb++);
    }
  return 0;
}
