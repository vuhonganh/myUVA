//UVA 231 Testing the Catcher: Longest Decreasing Sequence (straight forward)
//LIS[i] = size of the longest decreasing sequence from beginning to index i
//I was deconcentrated so I wrote LIS instead of LDS

/* The algorithm of LIS
for j = 0->(i-1), if (a[i] > a[j]) LIS[i] = max(LIS[j]) + 1;
*/

#include <vector>
#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

bool debug = false;
int computeLIS(int idx_i, vector<int> &ar, vector<int> &LIS)
{
  if (idx_i == 0) return 1;
  //if (ar[idx_i] > ar[0]) return 0;
  int &ans = LIS[idx_i];
  if (ans != -1) return ans;
  ans = 1;
  for (int j = 0; j < idx_i; ++j)
    {
      if (ar[j] >= ar[idx_i]) 
	{
	  ans = max(ans, computeLIS(j, ar, LIS) + 1);
	  if (debug) printf("idx_i = %d, ar[idx_i] = %d\n", idx_i, ar[idx_i]);
	  if (debug) printf("j = %d, ar[j] = %d\n", j, ar[j]);
	}
    }
  return ans;
}

int main()
{
  int nb;
  vector<int> ar;
  int testNb = 1;
  while (scanf("%d", &nb) == 1)
    {
      if (nb == -1) break;
      if (testNb != 1) printf("\n");
      if (!ar.empty()) ar.clear();
      ar.push_back(nb);
      while (scanf("%d", &nb) == 1)
	{
	  if (nb == -1) break;
	  ar.push_back(nb);
	}
      //done reading input
      vector<int> LIS(ar.size(), -1);
      int res = 0;
      for (size_t i = 0; i < ar.size(); ++i)
	{
	  res = max(computeLIS(i, ar, LIS), res);
	  if (debug) printf("current index i = %zd, res = %d, computeLIS(i,ar,LIS) = %d\n", i, res, computeLIS(i, ar, LIS));
	}
      printf("Test #%d:\n  maximum possible interceptions: %d\n", testNb++, res);
    }
  return 0;
}
