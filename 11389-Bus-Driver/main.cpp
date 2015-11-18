//greedy type
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

int main()
{
  
  int n, d, r;
  while (scanf("%d %d %d", &n, &d, &r) == 3)
    {
      if (n == 0 && d == 0 && r == 0) break;
      vector<int> ms(n); //morning route length
      vector<int> es(n); //evening route length
      for (int i = 0; i < n; ++i)
	{
	  assert(scanf("%d", &ms[i]) == 1);
	}
      for (int i = 0; i < n; ++i)
	{
	  assert(scanf("%d", &es[i]) == 1);
	}
      sort(ms.begin(), ms.end());
      sort(es.begin(), es.end());
      int S = 0; //supplementary amount
      for (int i = 0; i < n; ++i)
	{
	  if (ms[i] + es[n - 1 - i] > d)
	    S += (ms[i] + es[n - 1 - i] - d) * r;
	}
      printf("%d\n", S);
    }
}
