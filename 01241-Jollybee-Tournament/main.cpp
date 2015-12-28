#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

int main()
{
  int nbCase;
  int N, M;
  vector<bool> players;
  int idxAbsent;
  assert(scanf("%d", &nbCase) == 1);
  while (nbCase--)
    {
      assert(scanf("%d", &N) == 1);
      assert(scanf("%d", &M) == 1);
      int length = 1 << N; 
      players.assign(length, true); //true is for present, false if absent
      for (int i = 0 ; i < M; ++i)
	{
	  assert(scanf("%d", &idxAbsent) == 1);
	  idxAbsent--; //to get index 
	  players[idxAbsent] = false;
	}
      int cntWO = 0; //count walk over: exactly one of the 2 players is absent (XOR)
      while (length > 1)
	{
	  for (int i = 0; i < length; i += 2)
	    {
	      if (!players[i] != !players[i + 1])//XOR
		{
		  cntWO++;
		  players[i / 2] = true;
		}
	      else if (!players[i] && !players[i + 1]) //2 absents
		{
		  players[i / 2] = false;
		}
	      else 
		{
		  players[i / 2] = true;
		}
	    }
	  length /= 2;
	}
      printf("%d\n", cntWO);
    }
  return 0;
}
