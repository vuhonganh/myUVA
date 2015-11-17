#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;

int main()
{
  int dragons[20000];
  int knights[20000];
  
  int nbDragons;
  int nbKnights;

  while (scanf("%d %d", &nbDragons, &nbKnights) == 2)
    {
      if (nbDragons == 0 && nbKnights == 0) break;
      for (int i = 0; i < nbDragons; ++i)
	{
	  assert(scanf("%d", &dragons[i]) == 1);
	}
      for (int i = 0; i < nbKnights; ++i)
	{
	  assert(scanf("%d", &knights[i]) == 1);
	}
      sort(dragons, dragons + nbDragons);
      sort(knights, knights + nbKnights);
      int d = 0;
      int k = 0;
      int gold = 0;
      
      while (k < nbKnights && d < nbDragons)
	{
	  while (knights[k] < dragons[d] && k < nbKnights) 
	    {
	      ++k;
	    }
	  if (k == nbKnights) break; //already out of knights
	  gold += knights[k];
	  ++d; ++k;
	}
      if (d == nbDragons) printf("%d\n", gold);
      else printf("Loowater is doomed!\n");
    }
  
  return 0;
}
