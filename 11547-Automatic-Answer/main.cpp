#include <cstdio>
#include <cassert>

int main()
{
  int nbCase;
  int n;
  assert(scanf("%d", &nbCase) == 1);
  while (nbCase--)
    {
      assert(scanf("%d", &n) == 1);
      n = n * 567 / 9 + 7492;
      n = n * 235 /47 - 498;
      if (n < 0) n *= -1;
      n /= 10;
      printf("%d\n", n % 10);
    }
  return 0;
}
