//UVA 11450 Wedding Shopping
//Type: Dynamic Programming

//top-down dp observation: if in the optimal solution, we choose model i (price_i) for garment g=0, hence, this solution is also optimal for current_money - price_i for garment g=1 and above (g=2,3,...)

#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

int budget;
int nbGars;
vector< vector<int> > prices;
vector< vector<int> > memo; //memory table (which is the key idea of DP)

int shop(int money, int g)
{
  if (money < 0) return -100000;
  if (g == nbGars) return budget - money;
  int &ans = memo[money][g]; //refer the memory address of memo[money][g] to ans
  if (ans != -1) return ans; //ans already calculated before, no need to redo
  //for each model, if choose this one, then go for the next model to buy with reduced money
  for (size_t i = 0; i < prices[g].size(); ++i)
    {
      ans = max(ans, shop(money - prices[g][i], g + 1));
    }
  
  return ans;
}

void printVect2D(vector< vector<int> > &V2D)
{
  for (size_t i = 0; i < V2D.size(); ++i)
    {
      for (size_t j = 0; j < V2D[i].size(); ++j)
	{
	  printf("%d ", V2D[i][j]);
	}
      printf("\n");
    }
  printf("\n\n");
}

int main()
{
  int nbCase;
  bool debug = false;
  assert(scanf("%d", &nbCase) == 1);
  for (int i = 0; i < nbCase; ++i)
    {
      assert(scanf("%d %d", &budget, &nbGars) == 2);
      prices.assign(nbGars, vector<int>());
      memo.assign(budget + 1, vector<int>(nbGars, -1));
      for (int j = 0; j < nbGars; ++j)
	{
	  int len;
	  assert(scanf("%d", &len) == 1);
	  prices[j].assign(len, 0);
	  for (int k = 0; k < len; ++k)
	    {
	      assert(scanf("%d", &prices[j][k]) == 1);
	    }
	}
      if (debug) printVect2D(prices);
      if (debug) printVect2D(memo);
      int res = shop(budget, 0);
      if (res < 0) printf("no solution\n");
      else printf("%d\n", res);
    }
  
  return 0;
}
