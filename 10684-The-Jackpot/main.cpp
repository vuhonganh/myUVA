#include <cstdio>
#include <cassert>

using namespace std;

int max(const int &a, const int &b)
{
  if (a < b) return b;
  else return a;
}

int main()
{
  int N;
  while (scanf("%d", &N) == 1)
    {
      if (N == 0) break;
      int sum = 0;
      int maxSeq = 0;
      int cur; //reading current bet
      for (int i = 0; i < N; ++i)
	{
	  assert(scanf("%d", &cur) == 1);
	  sum += cur;
	  if (sum < 0) sum = 0;
	  else maxSeq = max(maxSeq, sum);
	}
      if (maxSeq == 0) printf("Losing streak.\n");
      else printf("The maximum winning streak is %d.\n", maxSeq);
    }
  
  return 0;
}

