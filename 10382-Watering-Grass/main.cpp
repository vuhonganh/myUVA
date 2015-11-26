//UVA 10382: watering grass
//main idea: transfer the problem into a interval covering problem
//sort these interval (left increasing, break ties with right decreasing 
//then, process on this array of intervals 
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>

#define eps 0.000000001
using namespace std;

struct interval
{
  double left;
  double right;
  int id;
  bool operator<(const interval & a) const
  {
    //return ((left < a.left) || ( abs(left - a.left) < eps && right > a.right));
    return left < a.left;
  }
};


int main()
{
  int n; //number of sprinkler
  int l; //length of the strip of grass
  int w; //width of the strip of grass
  
  int x; //position 
  int r; //radius
 
  vector<interval> arrIntv;
  
  bool debug = false;
  //bool debug = true;


  while (scanf("%d %d %d", &n, &l, &w) == 3)
    {
      if (!arrIntv.empty()) arrIntv.clear();
      for (int i = 0; i < n; ++i)
	{
	  assert(scanf("%d %d", &x, &r) == 2);
	  double dx = (double)(r) * r - w * w * 0.25;
	  if (dx <= 0) continue;
	  else dx = sqrt(dx);
	  interval cur {x - dx, x + dx, i};
	  arrIntv.push_back(cur);
	}
      if (debug) for (int i = 0; i < (int) arrIntv.size(); ++i)
		   printf("%f, %f\n", arrIntv[i].left, arrIntv[i].right);
      if (debug) cout << endl << "sorting....\n";
      //sort the interval: left most first
      sort(arrIntv.begin(), arrIntv.end());
      if (debug) for (int i = 0; i < (int) arrIntv.size(); ++i)
		   printf("%f, %f\n", arrIntv[i].left, arrIntv[i].right);
      if (debug) cout << endl << "DONE sorting....\n\n";
      
      vector<int> res; //number of minimum sprinklers need to be turned on
      //compute here:
      double left = 0.0;
      double right = 0.0;
      res.push_back(0);
      int i;
      int cnt = 1;
      if (debug) printf("l = %d, n = %d, w = %d\n", l, n, w); 
      for (i = 0; i < (int) arrIntv.size(); ++i)
	{
	  if (debug) cout << "i = " << i << ", " << arrIntv[i].left << ", " << arrIntv[i].right << endl;
	  if(right >= l) break;
	  if (arrIntv[i].left <= left) 
	    {
	      right = max(right, arrIntv[i].right);
	    }
	  else
	    {
	      if (right < arrIntv[i].left) //gap
		    break;
	      //else update left and right
	      left = right;
	      res.push_back(i);
	      if (debug) cout << "add this i = " << i;
	      cnt++;
	      i--;
	    }
	}
      
      if (right < l) printf("%d\n", -1);
      //      else printf("%zu\n", res.size());
      else printf("%d\n", cnt);
      if (debug) cout << "Done one case\n\n"; 
    }
  
  return 0;
}
