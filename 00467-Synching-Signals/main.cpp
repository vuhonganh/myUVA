//uva 467 Synching Signals

#include <cstdio>
#include <cassert>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
  int periode;
  string line;
  vector<int> periodes;
  vector<bool> green;
  int minP;
  int setNb = 1;
  bool debug = false;
  while (getline(cin, line))
    {
      if (!periodes.empty()) periodes.clear();
      minP = 90;
      //NEED TO USE STRINGSTREAM HERE
      stringstream ss(line);
      while (ss >> periode)
	{
	  periodes.push_back(periode);
	  minP = min(periode, minP);
	}
      green.assign(periodes.size(), false);
      if (debug) for (size_t i = 0; i < periodes.size(); ++i)
	{
	  printf((i == periodes.size() - 1)? "%d\n" : "%d ", periodes[i]);
	}
      int k = 2;
      int time = k * minP; //time for the fastest light turn green again
      while (true)
	{
	  if (debug) printf("time = %d\n", time);
	  if (time > 3600)
	    {
	      printf("Set %d is unable to synch after one hour.\n", setNb++);
	      break;
	    }
	  size_t cnt = 0;
	  for (size_t i = 0; i < periodes.size(); ++i)
	    {
	      int round = time/periodes[i];
	      if (debug) printf("periodes[%zd] = %d, round = %d\n", i, periodes[i], round);
	      if (round % 2 == 0) //if not red
		{
		  green[i] = ( time % periodes[i] < periodes[i] - 5) ? true : false; //green or yellow
		  cnt += (green[i]) ? 1 : 0;
		  if (debug) printf("green[%zd] = %d\n", i, (int) green[i]);
		}
	    }
	  if (cnt == periodes.size()) 
	    {
	      printf("Set %d synchs again at %d minute(s) and %d second(s) after all turning green.\n", setNb++, time / 60, time % 60);
	      break;
	    }
	  if (time < (k + 1) * minP - 5) time++;
	  else 
	    {
	      k += 2;
	      time = k * minP;
	    }
	}
    }
  return 0;
}
