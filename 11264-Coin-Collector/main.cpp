//uva 11264 Coin Collector
//Details see in note.txt in the same folder

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

int main()
{
  int nbCase;
  assert(scanf("%d", &nbCase) == 1);
  while (nbCase--)
    {
      int nbCoin;
      assert(scanf("%d", &nbCoin) == 1);
      vector<int> coins(nbCoin); 
      for (int i = 0; i < nbCoin; ++i)
	{
	  assert(scanf("%d", &coins[i]) == 1);
	}
      long S = 0;
      int res = 0;
      for (int i = 0; i < nbCoin - 1; ++i)
	{
	  if (S + coins[i] < coins[i+1]) 
	    {
	      res++;
	      S += coins[i];
	    }
	}
      printf("%d\n", res + 1); //the last one is missed count in the for loop above
    }
}
