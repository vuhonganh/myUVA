//uva 10496 Collecting Beepers
//type of travelling saleman problem
//use bitmask to represent the set

#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <cmath>
using namespace std;

//bool debug = true;
bool debug = false;
vector<vector<int> > dist;
int nbObj;
vector<vector<int> > memo;

int defVal = -1;
struct point2D
{
  int x;
  int y;
  int calculDist(const point2D &a) const
  {
    return abs(x - a.x) + abs(y - a.y);
  }
};

void calculDistAr(vector<point2D> &listPoints, vector< vector<int> > &dist)
{
  dist.assign(listPoints.size(), vector<int>(listPoints.size(), 0));
  for (size_t i = 0; i < listPoints.size(); ++i)
    {
      point2D p1 = listPoints[i];
      for (size_t j = i + 1; j < listPoints.size(); ++j) //right up triangle
	{
	  point2D p2 = listPoints[j];
	  dist[i][j] = p1.calculDist(p2);
	}
      for (size_t j = 0; j < i; ++j) //left bottom triangle
	{
	  dist[i][j] = dist[j][i];
	}
    }
  if (debug)
    {
      for (size_t i = 0; i < listPoints.size(); ++i)
	{
	  for (size_t j = 0; j < listPoints.size(); ++j)
	    printf("%d ", dist[i][j]);
	  printf("\n");
	}
    }
} 



int tsp(int cur_pos, int mask)
{
  if (mask == (1 << (nbObj + 1)) - 1) //nbObj does not count the start point yet
    {
      return dist[cur_pos][0];
    }
  if (debug) printf("go into tsp \n");
 
  //if (memo[cur_pos][mask] != defVal) printf("what the fuck is going on here\n");
  if (memo[cur_pos][mask] != defVal) return memo[cur_pos][mask];
  int ans = 2000000000; //2 billions
  for (int i = 0; i < nbObj + 1; ++i)
    {
      if (debug) printf("DOES IT GO HERE\n");
      if (((mask & (1 << i)) == 0) && (i != cur_pos)) 
	{
	  ans = min(ans, dist[cur_pos][i] + tsp(i, mask | (1 << i))); 
	  if (debug) printf("does we go here in if consition\n");
	}
    }
  if (debug) printf("after for loop, ans = %d\n", ans);
  if (debug) printf("%d\n", ans);
  return memo[cur_pos][mask] = ans;
}

int main()
{
  int nbCase;
  assert(scanf("%d", &nbCase) == 1);
  while(nbCase--)
    {
      int szX, szY;
      assert(scanf("%d %d", &szX, &szY) == 2);
      int startX, startY;
      assert(scanf("%d %d", &startX, &startY) == 2);
      
      assert(scanf("%d", &nbObj) == 1);
      vector<point2D> listPoints(nbObj + 1);
      point2D start {startX, startY};
      listPoints[0] = start;
      int x, y;
      for (int i = 0; i < nbObj; ++i)
	{
	  assert(scanf("%d %d", &x, &y) == 2);
	  point2D cur {x, y};
	  listPoints[i + 1] = cur;
	}
      calculDistAr(listPoints, dist);
      memo.assign(nbObj + 1, vector<int>(1 << (nbObj+1), defVal));

      
      printf("The shortest path has length %d\n", tsp(0, 1));

    }
  
  return 0;
}
