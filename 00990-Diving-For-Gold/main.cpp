//UVA 990 Diving for Gold
//Type: Dynamic Programming, must to print solution
//There are several methods (bottom up, top down, etc.) and here I use Top-Down, printing solution is not trivial: need keep track of feasible sol then a for loop
#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

bool debug = false;

int gold(int i, int remainTime, vector<vector<int> > &memo, vector<int> &values, vector<int> &depths, int w, vector<vector<bool> > &takenTreasures) //max gold can make while considering treasure i and having remainTime left
{
  if (i == (int) values.size()) return 0; //cover all treasures
  if (remainTime <= 0) return 0; //run out of time
  int &ans = memo[i][remainTime];
  if (ans != -1) return ans;
  if (debug) printf("at beginning of function gold, i = %d, remainTime = %d\n", i, remainTime);
  int choice1 = gold(i + 1, remainTime, memo, values, depths, w, takenTreasures); //can't go for this one
  int choice2 = values[i] + gold(i + 1, remainTime - 3 * w * depths[i], memo, values, depths, w, takenTreasures); //go for this one
  if (3 * w * depths[i] > remainTime) //can't go for this one
    {
      ans = choice1;
    }
  else
    {
      if (choice1 < choice2)
	{
	  takenTreasures[i][remainTime] = true;
	  ans = choice2;
	  if (debug) printf("adding this i = %d\n", i);
	}
      else
	{
	  takenTreasures[i][remainTime] = false; //this line is important, in "recursive style", we can not be sure about unexpected behavior, so need to make things clear and explicit as most as possible
	  ans = choice1;
	}
    }
  if (debug) printf("i = %d, remainTime = %d\n", i, remainTime);
  if (debug) printf("choice1 = %d, choice2 = %d\n", choice1, choice2);
  if (debug) printf("ans = %d\n", ans);
  return ans;
}

int main()
{
  int t, w;
  int caseNb = 1;
  while (scanf("%d %d", &t, &w) == 2)
    {
      if (caseNb++ != 1)
	{
	  printf("\n");
	}
      int n;
      assert(scanf("%d", &n) == 1);
      vector<int> depths(n, 0);
      vector<int> values(n, 0);
      for (int i = 0; i < n; ++i)
	{
	  assert(scanf("%d %d", &depths[i], &values[i]) == 2);
	}
      vector<vector<int> > memo(n, vector<int>(t + 1, -1));
      vector<vector<bool> > takenTreasures(n, vector<bool>(t + 1, false));

      int maxGold = gold(0, t, memo, values, depths, w, takenTreasures);
      printf("%d\n", maxGold);
      
      int time = t;
      vector<bool> obj(n, false);
      int cnt = 0;
      for (int i = 0; i < n; ++i)
	{
	  if (takenTreasures[i][time])
	    {
	      obj[i] = true;
	      cnt++;
	      time -= 3 * w * depths[i];
	    }
	}
      printf("%d\n", cnt);
      for (int i = 0; i < n; ++i)
	{
	  if (obj[i]) printf("%d %d\n", depths[i], values[i]);
	}
    }
  return 0;
}
