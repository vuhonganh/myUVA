//uva 10038 Jolly Jumpers

#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  vector<bool> check;
  int cur;
  int next;
  while (scanf("%d", &n) == 1 && n != 0)
    {
      check.assign(n - 1, false);
      assert(scanf("%d", &cur) == 1);
      for (int i = 0; i < n - 1; ++i)
	{
	  assert(scanf("%d", &next) == 1);
	  int idx = abs(next - cur) - 1;
	  if (-1 < idx && idx < n - 1) check[idx] = true;
	  cur = next;
	}
      bool isJolly = true;
      for (int i = 0; i < n - 1; ++i)
	{
	  if (check[i] == false)
	    {
	      isJolly = false;
	      break;
	    }
	}
      if (isJolly) printf("Jolly\n");
      else printf("Not jolly\n");
    }
  return 0;
}
