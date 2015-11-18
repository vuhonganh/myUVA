//UVA 10026 Shoemaker 's problem
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

struct job
{
  int t; //time
  int f; //fine
  int i; //index in the input
  bool operator< (const job &a) const
  {
    long e  = (long) (f) * a.t;
    long ae = (long) (t) * a.f;
    if (e != ae) return (e > ae);
    else return (i < a.i);
  }
};

int main()
{
  int nbCase;
  assert(scanf("%d", &nbCase) == 1);
  while (nbCase--)
    {
      int N;
      assert(scanf("%d", &N) == 1);
      int ti, fi;
      vector<job> arrJobs(N);
      for (int i = 0; i < N; ++i)
	{
	  assert(scanf("%d", &ti) == 1);
	  assert(scanf("%d", &fi) == 1);
	  job cur {ti, fi, i + 1};
	  arrJobs[i] = cur;
	}
      sort(arrJobs.begin(), arrJobs.end());
      for (int i = 0; i < N - 1; ++i)
	{
	  printf("%d ", arrJobs[i].i);
	}
      printf("%d\n", arrJobs[N - 1].i);
      
      if (nbCase) printf("\n");
    }
  return 0;
}
