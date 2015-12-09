//uva 357 Let me count the ways
//DP: Coin Change type: given an amount, how many ways can represents this amount?
//ways(i, amount) = ways(i - 1, amount) + ways(i, amount - val[i])
//where ways(i, amount) is the number of ways using (vals[0],... vals[i]) to represent the amount

#include <cstdio>
#include <cassert>
#include <algorithm>
#include <cstring>
using namespace std;

#define sizeAr 5
#define maxSZ 30004
int vals[sizeAr] = {1, 5, 10, 25, 50};
long long int memo[sizeAr][maxSZ];

long long int ways(int i, int amount)
{
  if (i < 0) return 0;
  if (amount == 0) return 1;
  long long int &ans = memo[i][amount];
  if (ans != -1) return ans;
  if (amount < vals[i]) return ans = ways(i - 1, amount);
  return ans = ways(i - 1, amount) + ways(i, amount - vals[i]);
}

int main()
{
  int amount;
  memset(memo, -1, sizeof(memo));
  while (scanf("%d", &amount) == 1)
    {
      long long int res = ways(sizeAr - 1, amount);
      if (res == 1) printf("There is only %lld way to produce %d cents change.\n", res, amount);
      else printf("There are %lld ways to produce %d cents change.\n", res, amount);
    }
  return 0;
}
