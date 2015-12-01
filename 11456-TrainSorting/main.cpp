//UVA 11456 TrainSorting
//Below code is not correct because it does not cover all the ties
//it takes only the configuration of the first tie, hence leads to wrong solutions in complicated test case

#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

vector<int> memo;
vector<int> arrW;
vector<int> minW;
vector<int> maxW;
bool debug = true;
int maxLenAt(int i)
{
  //if (i < 0) return 0;
  if (debug) printf(" i = %d, memo[i] = %d\n", i, memo[i]);
  int &ans = memo[i];
  if (ans != -1) return ans;
  
  int idxMax = 0;
  int lenMax = 0;
  for (int j = 0; j < i; ++j)
    {
      if (arrW[i] > maxW[j] || arrW[i] < minW[j])
	{
	  if (lenMax < (maxLenAt(j) + 1))
	    {
	      idxMax = j;
	      lenMax = memo[j] + 1;
	    }
	}
    }
  if (debug) printf(" lenMax = %d, idxMax = %d\n", lenMax, idxMax);
  if (debug) printf(" maxW[idxMaw] = %d, minW[idxMax] = %d\n",maxW[idxMax], minW[idxMax]);
  if (debug) printf("i = %d, arrW[i] = %d\n", i, arrW[i]);
  ans = lenMax;
  if (arrW[i] > maxW[idxMax]) 
    {
      maxW[i] = arrW[i];
      minW[i] = minW[idxMax];
    }
  else if (arrW[i] < minW[idxMax])
    {
      maxW[i] = maxW[idxMax];
      minW[i] = arrW[i];
    }
  else
    {
      printf("something is fucking wrong here, because it always exist idxMax = 0 to satisfy if and else if above\n");
    }
  if (debug) printf("DONE ONE CALCUL\n\n");
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
      memo.assign(n, -1);
      arrW.assign(n, 0);
      minW.assign(n, 0);
      maxW.assign(n, 0);
      for (int i = 0; i < n; ++i)
	{
	  assert(scanf("%d", &arrW[i]) == 1);
	}
      minW[0] = maxW[0] = arrW[0];
      if (debug) printf("minW[0] = %d, maxW[0] = %d, arr[0] = %d\n", minW[0], maxW[0], arrW[0]);
      memo[0] = 1;
      int result = 0;
      for (int i = 1; i < n; ++i)
	{
	  result = max(result, maxLenAt(i));
	}
      printf("%d\n", result);
    }
  return 0;
}
