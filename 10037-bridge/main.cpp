//UVA 10037 - bridge
//greedy with sorting

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

int main()
{
  int nbCase;
  assert(scanf("%d", &nbCase) == 1);
  while (nbCase--)
    {
      int n; 
      assert(scanf("%d", &n) == 1);
      vector<int> times(n);
      for (int i = 0; i < n; ++i)
	{
	  assert(scanf("%d", &times[i]) == 1);
	}
      sort(times.begin(), times.end());

      //base case
      if (n == 0) 
	{
	  printf("%d\n", 0);
	  if (nbCase) printf("\n");
	  continue;
	}
      if (n == 1) 
	{
	  printf("%d\n", times[0]);
	  printf("%d\n", times[0]);
	  if (nbCase) printf("\n");
	  continue;
	}

      //normal case
      int remains = n;
      int last = (n % 2) + 2;//last case: if n is odd -> last case remains 2 people, if n is even, last case remains 3 people 
      int i = n - 1; //
      int  sum = 0;
      vector<bool> useLeftExpr(n, false);
      while (remains > last)
	{
	  if (2 * times[0] + times[i] + times[i - 1] < 2 * times[1] + times[0] + times[i])
	    {
	      sum += 2 * times[0] + times[i] + times[i - 1];
	      useLeftExpr[i] = useLeftExpr[i - 1] = true;
	    } 
	  else
	    {
	      sum += 2 * times[1] + times[0] + times[i];
	    }
	  remains -= 2;
	  i -= 2;
	}
      
      if (remains == 2)
	{
	  sum += times[1];
	  printf("%d\n", sum);
	  for (int j = n - 1; j > i; j -= 2)
	    {
	      if (useLeftExpr[j])
		{
		  printf("%d %d\n%d\n%d %d\n%d\n", times[0], times[j], times[0], times[0], times[j - 1], times[0]);
		}
	      else
		{
		  printf("%d %d\n%d\n%d %d\n%d\n", times[0], times[1], times[0], times[j - 1], times[j], times[1]);
		}
	    }
	  printf("%d %d\n", times[0], times[1]);
	}
      else //remain == 3
	{
	  sum += (times[0] + times[1] + times[2]); 
	  printf("%d\n", sum);
	  for (int j = n - 1; j > i; j -= 2)
	    {
	      if (useLeftExpr[j])
		{
		  printf("%d %d\n%d\n%d %d\n%d\n", times[0], times[j], times[0], times[0], times[j - 1], times[0]);
		}
	      else
		{
		  printf("%d %d\n%d\n%d %d\n%d\n", times[0], times[1], times[0], times[j - 1], times[j], times[1]);
		}
	    }
	  printf("%d %d\n%d\n%d %d\n", times[0], times[2], times[0], times[0], times[1]);
	}
      if (nbCase) printf("\n");
    }
  return 0;
}
