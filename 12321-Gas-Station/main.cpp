//UVA 12321 Gas Station: greedy type: interval covering
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

struct Interval
{
  int L; //left end 
  int R; //right end 
  bool operator< (const Interval &a) const
  {
    return L < a.L;
  }
};

int main()
{
  int roadLen; //road length
  int nbStas; //number of stations
  while (scanf("%d %d", &roadLen, &nbStas) == 2)
    {
      bool debug = false;
      if (debug) printf("roadLen = %d\n", roadLen);
      if (debug) printf("nbStas = %d\n", nbStas);
      if (roadLen == 0 && nbStas == 0) break;
      vector<Interval> interVs(nbStas);
      int xi, ri;
      for (int i = 0; i < nbStas; ++i)
	{
	  assert(scanf("%d %d", &xi, &ri) == 2);
	  Interval cur {xi -ri, xi + ri};
	  interVs[i] = cur;
	}
      if (debug) printf("size of interval array is = %zu, nbStas = %d\n", interVs.size(), nbStas);
      if (!interVs.empty()) sort(interVs.begin(), interVs.end());
      int curCovered = 0;
      int maxRight = 0;
      int res = 0;
      for (int i = 0; i < nbStas; ++i)
	{
	  if (maxRight >= roadLen) break; //already done covering
	  if (interVs[i].L > curCovered) break; //there is a gap
	  
	  if (debug) printf("interVs[i].L = %d\n", interVs[i].L);
	  if (debug) printf("interVs[i].R = %d\n", interVs[i].R);
	  if (debug) printf("curCovered = %d\n", curCovered);
	  if (debug) printf("maxRight = %d\n", maxRight);
	  while (i <= nbStas && interVs[i].L <= curCovered) //when there is increment index, SHOULD ALWAYS check if index possible
	    {
	      maxRight = max(maxRight, interVs[i].R);
	      ++i; 
	      if (debug) printf("continue with i = %d...\n", i);

	    }
	  if (debug) printf("update curCovered, increment result\n");
	  curCovered = maxRight;
	  res++;
	  if (debug) printf("now res = %d\n", res);
	  --i;
	}
      if (maxRight < roadLen) printf("%d\n", -1);
      else printf("%d\n", nbStas - res);
      if (debug) printf("DONE ONE CASE\n\n");
    }
  
  return 0;
}
