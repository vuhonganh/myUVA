//uva 591 box of bricks
//simple 1D array manipulation

#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  vector<int> heights;
  int setNb = 1;
  while (scanf("%d", &n) == 1 && n != 0)
    {
      heights.assign(n, 0);
      int sum = 0;
      for (int i = 0; i < n; ++i)
	{
	  assert(scanf("%d", &heights[i]) == 1);
	  sum += heights[i];
	}
      int average = sum / n;
      int nbMove = 0;
      for (int i = 0; i < n; ++i)
	{
	  nbMove += abs(average - heights[i]);
	}
      nbMove /= 2; //the real work is only this value
      printf("Set #%d\nThe minimum number of moves is %d.\n\n", setNb++, nbMove);
    }
  
  return 0;
}
