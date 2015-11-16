//UVA 410: Station Balance
//greedy solution, pay attention on this condition 1 <= S <= 2C 
//this is because each chamber can contain 0,1 or 2 specimens, so take
//attention to add more 0-weighted specimens to form a pair for each chamber

#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;


int main()
{
  int nbChambers;
  int nbSpecs;
  
  vector<int> specsW; //specs weight
  int w;
  int sum;
  double averageW;
  double imbalance;
  int set = 1;
  while(scanf("%d", &nbChambers) == 1)
    {
      sum = 0;
      imbalance = 0.0;
      specsW.assign(nbChambers * 2, 0);
      assert(scanf("%d", &nbSpecs) == 1);

      for(int i = 0; i < nbSpecs; ++i)
	{
	  assert(scanf("%d", &w) == 1);
	  specsW[i] = w;
	  sum += w;
	}
      averageW = double(sum)/nbChambers;
      
      for(int i = 0; i < 2*nbChambers - nbSpecs; ++i)
	{
	  specsW[nbSpecs + i] = 0;
	}

      //READY TO COMPUTE
      //first sort the specs weight list:
      sort(specsW.begin(), specsW.end());
      printf("Set #%d\n", set++);
      for(int i = 0; i < nbChambers; ++i)
	{
	  if(specsW[i] != 0) printf(" %d: %d %d\n", i, specsW[i], specsW[2 * nbChambers - 1 - i]);
	  else if(specsW[2 * nbChambers - 1 - i] != 0) printf(" %d: %d\n", i, specsW[2 * nbChambers -i - 1]);
	  else printf(" %d:\n", i);
	  imbalance += abs(averageW - specsW[i] - specsW[2 * nbChambers - 1 - i]);
	}
      printf("IMBALANCE = %.5lf\n\n", imbalance);
    }
  
  return 0;
}
