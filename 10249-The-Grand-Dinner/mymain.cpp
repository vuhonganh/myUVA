//UVA 10249 - The Grand Dinner
//Greedy type, seem not so difficult after sorting

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

int main()
{
  
  int nbTeam;  //number of team
  int nbTable; //number of table
  while (scanf("%d %d", &nbTeam, &nbTable) == 2)
    {
      if (nbTeam == 0 && nbTable == 0) break;

      vector<int> teams(nbTeam);   //store the number of people in each team
      vector<int> tables(nbTable); //store the number of places in each table
      for (int i = 0; i < nbTeam; ++i)
	{
	  assert(scanf("%d", &teams[i]) == 1);
	}
      for (int i = 0; i < nbTable; ++i)
	{
	  assert(scanf("%d", &tables[i]) == 1);
	} 
    }
  return 0;
}

