//uva 11034 Ferry Loading IV
//queues problems

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  int nbCase;
  int ferryL, nbCar, carL;
  string side;
  cin >> nbCase;
  int LEFT = 0;
  int RIGHT = 1;
  int ferrySide;
  vector<queue<int> >qs;
  while (nbCase--)
    {
      ferrySide = LEFT;
      qs.assign(2, queue<int>());
      cin >> ferryL >> nbCar;
      ferryL *= 100;
      for (int i = 0; i < nbCar; ++i)
	{
	  cin >> carL >> side;
	  if (side == "left") qs[LEFT].push(carL);
	  else qs[RIGHT].push(carL);
	}
      int cntCross = 0;
      while (!qs[LEFT].empty() || !qs[RIGHT].empty())
	{
	  int curL = 0;
	  while (!qs[ferrySide].empty() && (curL + qs[ferrySide].front() <= ferryL))
	    {
	      curL += qs[ferrySide].front();
	      qs[ferrySide].pop();
	    }
	  cntCross++;
	  ferrySide = (ferrySide + 1) % 2;
	}
      printf("%d\n", cntCross);
    }
  return 0;
}
