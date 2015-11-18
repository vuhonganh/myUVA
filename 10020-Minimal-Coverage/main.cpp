//UVA problem 10020: Minimal coverage
//detail is in note.txt in this same folder

#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>


using namespace std; 

struct Interval
{
  int L;
  int R;
  bool operator< (const Interval & a) const
  {
    return L < a.L;
  }
};

int main()
{
  int nbCase;
  assert(scanf("%d", &nbCase) == 1);
  while (nbCase--)
    {
      vector<Interval> interVs;
      int M;
      assert(scanf("%d", &M) == 1);
      int Li, Ri;
      while (scanf("%d %d", &Li, &Ri) == 2)
	{
	  if (Li == 0 && Ri == 0) break;
	  Interval cur {Li, Ri};
	  interVs.push_back(cur);
	}
      //sort the array of intervals
      if (!interVs.empty())
	{
	  sort(interVs.begin(), interVs.end());
	}
      int curCovered = 0;
      int maxRight = 0;
      size_t maxId = 0;
      vector<size_t> res;
      for (size_t i = 0; i < interVs.size(); ++i)
	{
	  if (maxRight >= M) //covering done  
	    break;
	  
	  if (interVs[i].L > curCovered) //there is a gap i.e. : a range that can not be covered
	    break;
	  
	  while (interVs[i].L <= curCovered)
	    {
	      if (maxRight < interVs[i].R)
		{
		  maxId = i;
		  maxRight = interVs[i].R;
		}
	      i++;
	    }
	  //go out of while i.e. reach the first interval uncovered 
	  //-> need to update the current covered point (curCovered) 
	  //and decrement i to take care of this interval
	  curCovered = maxRight;
	  res.push_back(maxId);
	  i--;
	} //end for
      if (maxRight >= M)
	{
	  printf("%zu\n", res.size());
	  for (size_t i = 0; i < res.size(); ++i)
	    {
	      size_t id = res[i];
	      printf("%d %d\n", interVs[id].L, interVs[id].R);
	    }
	}
      else printf("%d\n", 0);
      if (nbCase) printf("\n");
    }
  
  return 0;
}
