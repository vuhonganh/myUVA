#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

int maxLenFirstSide(int i, int remainLen, vector<int> &carLens, vector<vector<bool> > &used, vector<vector<int> > &memo)
{
  if (i == (int) carLens.size()) return 0;
  if (remainLen == 0) return 0;
  int &ans = memo[i][remainLen];
  if (ans != -1) return ans;
  if (remainLen < carLens[i])
    {
      return ans = maxLenFirstSide(i + 1, remainLen, carLens, used, memo);
    }
  else
    {
      int useThisCar = carLens[i] + maxLenFirstSide(i + 1, remainLen - carLens[i], carLens, used, memo);
      int dontUseThis = maxLenFirstSide(i + 1, remainLen, carLens, used, memo);
      if (useThisCar > dontUseThis)
	{
	  ans = useThisCar;
	  used[i][remainLen] = true;
	}
      else
	{
	  ans = dontUseThis;
	  used[i][remainLen] = false;
	}
      return ans;
    }
}

int main()
{
  int sum;
  vector<int> carLens;
  vector<vector<int> > memo;
  vector<vector<bool> > used;
  vector<bool> firstUsed;
  
  int ferryLen;
  int nbCase;
  assert(scanf("%d", &nbCase) == 1);
  while (nbCase--)
    {
      sum = 0; //very important to reinit it here
      if (!carLens.empty()) carLens.clear();
      assert(scanf("%d", &ferryLen) == 1);
      ferryLen *= 100; //turn to cm
      int l;
      while (scanf("%d", &l) == 1 && l != 0)
	{
	  sum += l;
	  if (sum > 2 * ferryLen) continue;
	  carLens.push_back(l);
	}
      memo.assign(carLens.size(), vector<int>(ferryLen + 1, -1));
      used.assign(carLens.size(), vector<bool>(ferryLen + 1, false));
      firstUsed.assign(carLens.size(), false);

      int first = maxLenFirstSide(0, ferryLen, carLens, used, memo);
      (void) first;
      int len = ferryLen;
      int cnt = 0;
      for (size_t i = 0; i < carLens.size(); ++i)
	{
	  if (used[i][len]) 
	    {
	      firstUsed[i] = true;
	      len -= carLens[i];
	      ++cnt;
	    }
	}
      sum = 0;
      for (size_t i = 0; i < carLens.size(); ++i)
	{
	  if (!firstUsed[i])
	    {
	      sum += carLens[i];
	      if (sum > ferryLen) break;
	      cnt++;
	    }
	}
      printf("%d\n", cnt);
      for (int i = 0; i < cnt; ++i)
	{
	  if(firstUsed[i]) printf("port\n");
	  else printf("starboard\n");
	}
      if (nbCase) printf("\n");
    }
  return 0;
}
