//uva 10050 Hartals
#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

int main()
{
  int nbCase;
  assert(scanf("%d", &nbCase) == 1);
  int N;
  int nbParties;
  vector<bool> checkH;
  while (nbCase--)
    {
      assert(scanf("%d", &N) == 1);
      checkH.assign(N + 1, false);
      assert(scanf("%d", &nbParties) == 1);
      int cur_h;
      for (int i = 0; i < nbParties; ++i)
	{
	  assert(scanf("%d", &cur_h) == 1);
	  for (int j = cur_h; j <= N; j += cur_h)
	    {
	      checkH[j] = true;
	    }
	}
      int cnt = 0;
      for (int i = 1; i <= N; ++i)
	{
	  int checkHoliday = i % 7;
	  if (checkHoliday == 6 || checkHoliday == 0) continue;
	  if (checkH[i]) cnt++;
	}
      printf("%d\n", cnt);
    }
  
  return 0;
}

