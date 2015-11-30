//uva 437 The tower of babylon
//type: dynamic programming (not really, but we have to remember the memo table)
//Key point: one block -> 3 objects, after that, use iteration with the contiguous-updating memo table

#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

struct Obj
{
  int x, y, z;
};


int buildFrom(size_t idx, vector<Obj> &objects, vector<int> &memo)
{
  if (idx < 0 || idx >= objects.size()) return 0;
  int &ans = memo[idx];
  if (ans != -1) return ans;
  int theRest = 0;
  for (size_t i = 0; i < objects.size(); ++i) //KEY POINT OF THE PROBLEM
    {
      if ( (objects[idx].x > objects[i].x && objects[idx].y > objects[i].y) ||
	   (objects[idx].x > objects[i].y && objects[idx].y > objects[i].x) )
	{
	  theRest = max(buildFrom(i, objects, memo), theRest); //if possible to build, calculate the max height that we can build from this one
	}
    }
  ans = objects[idx].z + theRest;
  return ans;
}

int main()
{
  int n;
  int caseNb = 1;
  while(scanf("%d", &n) == 1)
    {
      if (n == 0) break;
      vector<Obj> objects(3 * n);
      vector<int> memo(3 * n, -1);
      int xi, yi, zi;
      for (int i = 0; i < n; ++i)
	{
	  assert(scanf("%d %d %d", &xi, &yi, &zi) == 3);
	  Obj o1{xi, yi, zi};
	  Obj o2{zi, xi, yi};
	  Obj o3{zi, yi, xi};
	  objects[3 * i] = o1;
	  objects[3 * i + 1] = o2;
	  objects[3 * i + 2] = o3;
	}
      int maxH = 0;
      for (size_t i = 0; i < objects.size(); ++i)
	{
	  maxH = max(maxH, buildFrom(i, objects, memo));
	}
      printf("Case %d: maximum height = %d\n", caseNb++, maxH);
    }
  return 0;
}
