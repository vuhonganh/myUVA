//UVA 10382: watering grass
//main idea: transfer the problem into a interval covering problem
//sort these interval (left increasing, break ties with right decreasing 
//then, process on this array of intervals 
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>

#define eps 0.000001
using namespace std;

struct interval
{
  double left;
  double right;
  int id;
  bool operator<(const interval & a) const
  {
    return ((left < a.left) || ( abs(left - a.left) < eps && right > a.right));
  }
};

int main()
{
  int n; //number of sprinkler
  int l; //length of the strip of grass
  int w; //width of the strip of grass
  
  int x; //position 
  int r; //radius
  double dx = 0.0; 
  vector<interval> arrIntv;
  
  bool debug = false;
  // bool debug = true;
  bool feasible;
  vector<int> res; //number of minimum sprinklers need to be turned on
  double rightMost;
  double lastRightMost;
  int curId; //keep track of the rightMost interval
  while (scanf("%d %d %d", &n, &l, &w) == 3)
    {
      if (!arrIntv.empty()) arrIntv.clear();
      for (int i = 0; i < n; ++i)
	{
	  assert(scanf("%d %d", &x, &r) == 2);
	  dx = sqrt(r * r - w * w * 0.25);
	  interval cur {x - dx, x + dx, i};
	  arrIntv.push_back(cur);
	}
      
      sort(arrIntv.begin(), arrIntv.end());
      rightMost = 0.0;
      lastRightMost = 0.0;
      curId = 0;
      feasible = true;
      if (!res.empty()) res.clear();
      for (int i = 0; i < n; ++i)
	{
	  if (debug) cout << arrIntv[i].left <<  ", " << arrIntv[i].right << endl;
	  if (i == 0)
	    {
	      if (arrIntv[i].left > eps) //no sol
		{
		  feasible = false;
		  break;
		}
	      else
		{
		  rightMost = arrIntv[i].right;
		  lastRightMost = arrIntv[i].right;
		  res.push_back(i);
		  curId = i;
		  if (debug) cout << "add this circle id:" << curId << endl;
		  continue;
		}
	    }
	  
	  //cases (note to take care of extreme case first
	  if (lastRightMost > l) //already cover -> found minimum sol 
	    break;
	  else if (rightMost + eps < arrIntv[i].left) //there is a gap -> no sol
	    {
	      feasible = false;
	      break;
	    }
	  else if (lastRightMost + eps < arrIntv[i].left) //there is no gap but this is a change point that we need to update the lastRightMost
	    {
	      lastRightMost = rightMost;
	      res.push_back(curId);
	      if (debug) cout << "add the circle id : " << curId << endl;
	    }
	  
	  if (rightMost < arrIntv[i].right - eps) //if this is not a change point thant this could be a candidate
	    {
	      rightMost = arrIntv[i].right;
	      curId = i;
	    }
	  
	  if (i == n-1)
	    {
	      if (rightMost < l - eps)
		feasible = false;
	      else if (rightMost > lastRightMost + eps)
		{
		  lastRightMost = rightMost;
		  res.push_back(curId);
		  if (debug) cout << "add the circle id : " << curId << endl;
		}
	    }
	}
      if (feasible) printf("%zu\n", res.size());
      else printf("%d\n", -1);
      if (debug) cout << "Done one case\n\n"; 
    }
  
  return 0;
}
