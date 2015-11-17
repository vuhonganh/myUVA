//UVA 01193: Radar Installation
//see note in the note.txt at the same folder for more details of algorithm and implementation

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define eps 0.000000001

struct Interval
{
  double l; //left end
  double r; //right end
  bool operator<( const Interval & a) const
  {
    return (r < a.r);
  }
};

int main()
{
  int nbIslands;
  int d; //distance that the radar can cover
  int caseNb = 1;
  while (scanf("%d %d", &nbIslands, &d) == 2)
    {
      if (nbIslands == 0 && d == 0) break;
      int x; int y;
      bool noSol = false;
      vector<Interval> interVs;
      for (int i = 0; i < nbIslands; ++i)
	{
	  assert(scanf("%d %d", &x, &y) == 2);
	  if (y > d) noSol = true;
	  else
	    {
	      double dx = (double) (d*d - y*y);
	      dx = sqrt(dx);
	      Interval cur {(double) (x) - dx, (double) (x) + dx};
	      interVs.push_back(cur);
	    }
	}
      if (noSol || interVs.empty()) printf("Case %d: %d\n", caseNb++, -1);
      else
	{
	  sort(interVs.begin(), interVs.end());
	  double curRada = interVs[0].r;
	  int res = 1;
	  for (size_t i = 1; i < interVs.size(); ++i)
	    {
	      if (interVs[i].l > curRada + eps) //a new interval that does not overlap
		{
		  curRada = interVs[i].r;
		  res++;
		}
	      else
		{
		  continue;
		}
	    }
	  printf("Case %d: %d\n", caseNb++, res);
	}
    }
  return 0;
}
