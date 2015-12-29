#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

int n, maxNbEggs, maxWeight;
vector<vector<int> > memo;
vector<int> eggsW;
int maxEggs(int id, int remWeight)
{
  if (id == n) return 0;
  if (remWeight <= 0) return 0;
  int &ans = memo[id][remWeight];
  if (ans != -1) return ans;
  if (remWeight < eggsW[id]) ans = maxEggs(id + 1, remWeight);
  else
    ans = max(1 + maxEggs(id + 1, remWeight - eggsW[id]), maxEggs(id + 1, remWeight));
  return ans;
}

int main()
{
  int nbCase;
  assert(scanf("%d", &nbCase) == 1);
  int caseNb = 1;
  while (nbCase--)
    {
     
      assert(scanf("%d", &n) == 1);
      assert(scanf("%d", &maxNbEggs) == 1);
      assert(scanf("%d", &maxWeight) == 1);
      eggsW.assign(n, 0);
      for (int i = 0; i < n; ++i)
	{
	  assert(scanf("%d", &eggsW[i]) == 1);
	}
      memo.assign(n, vector<int>(maxWeight + 1, -1));
      printf("Case %d: %d\n", caseNb++, min(maxEggs(0, maxWeight), maxNbEggs));
    }
  return 0;
}
