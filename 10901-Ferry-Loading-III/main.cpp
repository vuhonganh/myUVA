//uva 10901 Ferry Loading III
//type: queue: 2 queues for left and right side of the river

#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

int LEFT = 0;
int RIGHT = 1;

int main()
{
  //use queue to store the index of cars
  //and use vector to store arrivalTime of each car
  vector<queue<int> >qs;
  vector<int> arrivalTime;
  vector<int> unloadedTime;
  int nbCase;
  cin >> nbCase;
  while (nbCase--)
    {
      int n, t, m;
      cin >> n >> t >> m;
      qs.assign(2, queue<int>() );     
      arrivalTime.assign(m, 0);
      unloadedTime.assign(m, 0);
      int timeArrive;
      string side;
      for (int i = 0; i < m; ++i)
	{
	  cin >> timeArrive >> side;
	  arrivalTime[i] = timeArrive;
	  if (side == "left") qs[LEFT].push(i);
	  else qs[RIGHT].push(i);
	}
      int curTime = 0;
      int curSide = LEFT;
      while ( !qs[LEFT].empty() || !qs[RIGHT].empty() )
	{
	  int nextTime = 0;
	  if (qs[LEFT].empty())
	    {
	      nextTime = arrivalTime[qs[RIGHT].front()];
	    } 
	  else if (qs[RIGHT].empty())
	    {
	      nextTime = arrivalTime[qs[LEFT].front()];
	    } 
	  else
	    {
	      nextTime = min(arrivalTime[qs[RIGHT].front()], arrivalTime[qs[LEFT].front()]);
	    } 
	  curTime = max(curTime, nextTime);
	  int cnt = 0;
	  while (!qs[curSide].empty() && arrivalTime[qs[curSide].front()] <= curTime && cnt < n)
	    {
	      unloadedTime[qs[curSide].front()] = curTime + t;
	      qs[curSide].pop();
	      cnt++;
	    }
	  curTime += t;
	  curSide = (curSide + 1) % 2;
	}
      
      for (int i = 0; i < m; ++i)
	{
	  printf("%d\n", unloadedTime[i]);
	}
      if (nbCase) printf("\n");
    }
  return 0;
}
