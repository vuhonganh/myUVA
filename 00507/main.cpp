//UVA 00507: Jill Rides Again
//Type: Dynamic Programming

#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
  int nbRoutes = 0;
  int nbStops;
  int readOneInt;
  vector<int> niceness;

  readOneInt = scanf("%d", &nbRoutes); assert(readOneInt == 1);
  //for each road:
  for(int h = 0; h < nbRoutes; ++h)
    {
      //read nb of stops and init niceness
      readOneInt = scanf("%d", &nbStops); assert(readOneInt == 1);
      niceness.assign(nbStops-1, 0);

      //read input niceness of this route
      for(size_t j = 0; j < niceness.size(); ++j)
	{
	  readOneInt = scanf("%d", &niceness[j]); assert(readOneInt == 1);
	}
      int maxVal = 0;
      int sum = 0;
      int cur_start = 1;
      int cur_end = 1;
      int res_start = 1;
      int res_end = 1;
      bool debug = false;
      //ready to compute:
      for(size_t i = 0; i < niceness.size(); ++i)
	{
	  sum += niceness[i];
	  if(debug) cout << "i = " << i << endl;
	  if(debug) cout << "sum = " << sum << endl;
	  if(sum < 0)
	    {
	      sum = 0;
	      cur_start = i + 2;
	      cur_end = cur_start;
	      if(debug) cout << "this time sum < 0, ";
	    }
	  if(sum > maxVal)//update every thing
	    {
	      maxVal = sum;
	      cur_end = i + 2;
	      res_end = cur_end;
	      res_start = cur_start;
	    }
	  if(sum == maxVal)//update current end point
	    {
	      cur_end = i + 2;
	      if(cur_end - cur_start > res_end - res_start)
		{
		  res_end = cur_end;
		  res_start = cur_start;
		}
	    }
	 
	  if(debug) cout << "cur_start = " << cur_start << endl;	 
	  if(debug) cout << "cur_end = " << cur_end << endl;
	  if(debug) cout << "res_start = " << res_start << endl;
	  if(debug) cout << "res_end = " << res_end << endl;
	}
      
      if(maxVal == 0) cout << "Route " << h + 1 << " has no nice parts" << endl;
      else cout << "The nicest part of route " << h + 1 << " is between stops " << res_start << " and " << res_end << endl;
    }
  return 0;
}
