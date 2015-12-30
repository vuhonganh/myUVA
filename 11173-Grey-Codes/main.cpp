//uva 11173 grey codes
//type: mathematical, number theory type

#include <cstdio>
#include <cassert>

int getVal(int n, int k)
{
  if (k == 0 || k == 1) return k;
  
  if (k < (1 << (n - 1))) return getVal(n - 1, k);
  else
    {
      int k_reflect = (1 << n) - 1 - k;
      return ((1 << (n - 1)) + getVal(n - 1, k_reflect));
    }
}

int main()
{
  int nbCase, n, k;
  assert(scanf("%d", &nbCase) == 1);
  while (nbCase--)
    {
      assert(scanf("%d", &n) == 1);
      assert(scanf("%d", &k) == 1);
      printf("%d\n", getVal(n, k));
    }
  return 0;
}
