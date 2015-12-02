//UVA 11456 TrainSorting
//another type of Longest Increasing/Decreasing Sequence
//Here the problem is a little bit different, is that, STARTING AT SOME INDEX i, find the LIS and LDS FROM THIS INDEX i
//Note that in this particular problem, a trick is that we can use a reverse FOR loop helps us to save some space

#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

vector<int> arrW;
vector<int> LIS_from_idx;
vector<int> LDS_from_idx;

int main()
{
  int nbCase;
  assert(scanf("%d", &nbCase) == 1);
  while (nbCase--)
    {
      int n;
      assert(scanf("%d", &n) == 1);
      if (n == 0 || n == 1 || n == 2)  //base case
	{
	  printf("%d\n", n);
	  int x;
	  for (int i = 0; i < n; ++i)
	    {
	      assert(scanf("%d", &x) == 1);
	    }
	  //done reading
	  continue;
	}

      arrW.assign(n, 0);
      LIS_from_idx.assign(n, 1);
      LDS_from_idx.assign(n, 1);
      for (int i = 0; i < n; ++i)
	{
	  assert(scanf("%d", &arrW[i]) == 1);
	}
      for (int i = n - 1; i > -1; --i)
	{
	  for (int j = i + 1; j < n; ++j)
	    {
	      if (arrW[j] > arrW[i]) LIS_from_idx[i] = max(LIS_from_idx[j] + 1, LIS_from_idx[i]);
	      else LDS_from_idx[i] = max(LDS_from_idx[j] + 1, LDS_from_idx[i]); 
	    }
	}
      int res = 0;
      for (int i = 0; i < n; ++i)
	{
	  res = max(res, LIS_from_idx[i] + LDS_from_idx[i] - 1);
	}
      printf("%d\n", res);
    }
  return 0;
}
