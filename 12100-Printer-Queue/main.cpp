#include <cstdio>
#include <queue>
#include <cassert>
#include <utility>

using namespace std;

int main()
{
  int nbCase;
  int n, idx; //n = number of print jobs, idx = index of our job
  queue<pair<int, int> > q;
  vector<int> priorityExist;
  int pJob; //priority of our job

  assert(scanf("%d", &nbCase) == 1);
  while (nbCase--)
    {
      while (!q.empty()) 
	{
	  q.pop();
	}

      priorityExist.assign(10, 0);
      assert(scanf("%d", &n) == 1);
      assert(scanf("%d", &idx) == 1);
      int curP;
      for (int i = 0; i < n; ++i)
	{
	  assert(scanf("%d", &curP) == 1);
	  priorityExist[curP]++;
	  q.push(make_pair(i, curP));
	  if (i == idx) pJob = curP;
	}
      int time = 0;
      int curId;
      while (true)
	{
	  curId = q.front().first;
	  curP = q.front().second;
	  bool printThisOne = true;
	  for (int i = curP + 1; i < 10; ++i)
	    {
	      if (priorityExist[i] != 0)
		{
		  printThisOne = false;
		  break;
		}
	    }
	  q.pop();
	  if (printThisOne) 
	    {
	      priorityExist[curP]--;
	      time++;
	      if (curId == idx) break;
	    }
	  else
	    {
	      q.push(make_pair(curId, curP));
	    }
	}
      printf("%d\n", time);
    }
  return 0;
}
