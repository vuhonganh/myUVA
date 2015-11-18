//UVA 12405 Scarecrow: greedy type

#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

int main()
{
  int nbCase;
  int caseNb = 1;
  assert(scanf("%d\n", &nbCase) == 1);
  while (nbCase--)
    {
      int N;
      bool debug = false;
      //assert(scanf("%d", &N) == 1);
      scanf("%d\n", &N);
      if (debug) printf("N = %d\n", N);
      vector<int> field(N);
      char c;
      for (int i = 0; i < N; ++i)
	{
	  assert(scanf("%c", &c) == 1);
	  if (c == '.') field[i] = 1;
	  else field[i] = 0;
	}
      if (debug) 
	{
	  for (int i = 0; i < N; ++i)
	    {
	      if (field[i] == 1) printf(".");
	      else printf("#");
	    }
	  printf("\n");
	}
      int i = 0;
      while (i < N)
	{
	  //search for the first useful cell (able to plant)
	  //if (debug) printf("i = %d\n", i);
	  while (i < N && (field[i] == 0 || field[i] == 2)) ++i;
	  //found the first field
	  if (i < N)
	    {
	      if (i + 1 < N)
		{
		  field[i + 1] = 2;
		  i += 3;
		}
	      else
		{
		  field[i] = 2;
		}
	    }
	}
      int res = 0;
      for (int i = 0; i < N; ++i)
	{
	  if (field[i] == 2) res++;
	}
      printf("Case %d: %d\n", caseNb++, res);
    }
  
  return 0;
}
