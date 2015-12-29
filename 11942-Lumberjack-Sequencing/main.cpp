#include <cstdio>
#include <cassert>

int main()
{
  int nbCase;
  assert(scanf("%d", &nbCase) == 1);
  printf("Lumberjacks:\n");
  while (nbCase--)
    {
      int first, second;
      assert(scanf("%d", &first) == 1);
      assert(scanf("%d", &second) == 1);
      bool ordered = true;
      int diff = second - first;
      for (int i = 0; i < 8; ++i) //there are only 10 integer each line
	{
	  first = second;
	  assert(scanf("%d", &second) == 1);
	  if ((second - first) * diff < 0) ordered = false;
	}
      if (ordered) printf("Ordered\n");
      else printf("Unordered\n");
    }
  return 0;
}
