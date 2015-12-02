//uva 11790 Murcia 's Skyline
//LIS (longest increasing sequence) and LDS (Longest decreasing sequence)

#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

vector<int> LIS;
vector<int> LDS;
vector<int> heights;
vector<int> widths;
int computeLIS(int i)//compute LIS at index i
{
  int &ans = LIS[i];
  if (ans != -1) return ans;
  ans = 0;
  for (int j = 0; j < i; ++j)
    {
      if (heights[i] > heights[j])
	{
	  ans = max(ans, computeLIS(j));
	}
    }
  ans += widths[i];
  return ans;
}

int computeLDS(int i)//compute LDS at index i
{
  int &ans = LDS[i];
  if (ans != -1) return ans;
  ans = 0;
  for (int j = 0; j < i; ++j)
    {
      if (heights[i] < heights[j])
	{
	  ans = max(ans, computeLDS(j));
	}
    }
  ans += widths[i];
  return ans;
}
int main()
{
  int nbCase;
  int caseNb = 1;
  assert(scanf("%d", &nbCase) == 1);
  while (nbCase--)
    {
      int n;
      assert(scanf("%d", &n) == 1);
      heights.assign(n, 0);
      widths.assign(n, 0);
      LIS.assign(n, -1);
      LDS.assign(n, -1);
      for (int i = 0; i < n; ++i)
	{
	  assert(scanf("%d", &heights[i]) == 1);
	}
      for (int i = 0; i < n; ++i)
	{
	  assert(scanf("%d", &widths[i]) == 1);
	}
      int maxIncr = 0;
      for (int i = 0; i < n; ++i)
	{
	  maxIncr = max(maxIncr, computeLIS(i));
	}
      int maxDecr = 0;
      for (int i = 0; i < n; ++i)
	{
	  maxDecr = max(maxDecr, computeLDS(i));
	} 
      if (maxDecr > maxIncr)
	{
	  printf("Case %d. Decreasing (%d). Increasing (%d).\n", caseNb++, maxDecr, maxIncr);
	}
      else
	{
	  printf("Case %d. Increasing (%d). Decreasing (%d).\n", caseNb++, maxIncr, maxDecr);
	}
    }
  return 0;
}
