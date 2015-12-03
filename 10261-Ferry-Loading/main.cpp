//UVA 10261 Ferry Loading 
//Type: Dynamic programming, knapsack 

#include <cstdio>
#include <cassert>
#include <vector>
using namespace std;
bool debug = true;

int nbCar(int i, int remL, int remR, vector<int> &lenCars, vector<vector<vector<int> > > &memo, vector<bool> &atLeft)
{
  if (i == (int) lenCars.size()) return 0;
  if (lenCars[i] > remL && lenCars[i] > remR) return 0;
  if (remL < 0 || remR < 0) return 0;
  int &ans = memo[i][remL][remR];
  if (ans != -1) return ans;
  int nbCarIfPutToLeft = 1 + nbCar(i + 1, remL - lenCars[i], remR, lenCars, memo, atLeft);
  int nbCarIfPutToRight = 1 + nbCar(i + 1, remL, remR - lenCars[i], lenCars, memo, atLeft);
  if (nbCarIfPutToLeft > nbCarIfPutToRight)
    {
      ans = nbCarIfPutToLeft;
      atLeft[i] = true;
    }
  else
    {
      ans = nbCarIfPutToRight;
      atLeft[i] = false;
    }
  return ans;
}

int main()
{
  int nbCase;
  assert(scanf("%d", &nbCase) == 1);

  while (nbCase--)
    {
      int LenFerry;
      assert(scanf("%d", &LenFerry) == 1);
      LenFerry *= 100; //turn meter to centimeter
      vector<int> lenCars;
      int l;
      assert(scanf("%d", &l) == 1);
      do
	{
	  lenCars.push_back(l);
	  assert(scanf("%d", &l) == 1);
	}
      while (l != 0);
      if (debug) printf("read Input OK\n");
      vector<vector<vector<int> > >memo(lenCars.size(), vector<vector<int> >(LenFerry + 1, vector<int>(LenFerry + 1, -1)));
      //int memo[7][2500][2500];
      vector<bool> atLeft(lenCars.size(), false);
      if (debug) printf("before compute OK\n");
      int nbCarCanPut = nbCar(0, LenFerry, LenFerry, lenCars, memo, atLeft);
      printf("%d\n", nbCarCanPut);
      for (int i = 0; i < nbCarCanPut; ++i)
	{
	  if (atLeft[i]) printf("port\n");
	  else printf("starboard\n");
	}
      if (nbCase) printf("\n");
    }
  return 0;
}
