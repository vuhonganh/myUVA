//UVA 562 Dividing Coins
//Type: dynamic programming

#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

int val(int i, int remainCapa, vector<vector<int> > &memo, vector<int> &coinVals)
{
  if (remainCapa == 0) return 0; //coin division is equal now
  if (i == (int) coinVals.size()) return 0; //we have no coin left
  int &ans = memo[i][remainCapa];
  if (ans != -1) return ans;
  if (coinVals[i] > remainCapa) //can not take this coin
    {
      ans = val(i + 1, remainCapa, memo, coinVals);
    }
  else
    {
      ans = max(val(i + 1, remainCapa, memo, coinVals), val(i + 1, remainCapa - coinVals[i], memo, coinVals) + coinVals[i]);
    }
  return ans;
}

int main()
{
  int nbCase;
  assert(scanf("%d", &nbCase) == 1);
  while (nbCase--)
    {
      int n;
      assert(scanf("%d", &n) == 1);
      vector<int> coinVals(n, 0);
      int sum = 0;
      for (int i = 0; i < n; ++i)
	{
	  assert(scanf("%d", &coinVals[i]) == 1);
	  sum += coinVals[i];
	}
      int capa = sum / 2;
      vector<vector<int> > memo(n, vector<int>(capa + 1, -1));
      int theMaxSmaller = val(0, capa, memo, coinVals);
      int minDiff = sum - (theMaxSmaller * 2); 
      printf("%d\n", minDiff);
    }
  return 0;
}
