//UVA 10249 - The Grand Dinner
//Greedy type, seem not so difficult after sorting

#include <cstdio>
#include <algorithm>  //sort
#include <vector>
#include <cassert>
#include <set>        //multiset
#include <functional> //greater
using namespace std;

struct table
{
  int cap; //capacity of the table
  int id;  //id of the table: to keep track after sorting
  bool operator< (const table &a) const
  {
    return cap > a.cap;
  }
};

struct team 
{
  int id;
  int nbMem;
};

bool sortNbMem(const team &lhs, const team &rhs)
{
  return lhs.nbMem > rhs.nbMem;
}

bool sortId(const team &lhs, const team &rhs)
{
  return lhs.id < rhs.id;
}

int main()
{
  
  int nbTeam;  //number of team
  int nbTable; //number of table
  multiset<table> tables;
  vector<team> teams;   //store the number of people in each team
  while (scanf("%d %d", &nbTeam, &nbTable) == 2)
    {
      //INIT
      if (nbTeam == 0 && nbTable == 0) break;
      if (!teams.empty()) teams.clear();
      if (!tables.empty()) tables.clear();

      //READ INPUT
      int numberMem;
      int capacity;
      for (int i = 0; i < nbTeam; ++i)
	{
	  assert(scanf("%d", &numberMem) == 1);
	  team curTeam {i, numberMem};
	  teams.push_back(curTeam);
	}
      for (int i = 0; i < nbTable; ++i)
	{
	  assert(scanf("%d", &capacity) == 1);
	  table cur {capacity, i + 1};
	  tables.insert(cur);
	} 

      //SORT (note: tables is a multiset object with operator < implemented 
      //so it's already sorted while inserting)
      sort(teams.begin(), teams.end(), sortNbMem);
      
      //COMPUTE
      if (teams[0].nbMem > nbTable) //base case
	{ 
	  printf("%d\n", 0);
	  continue;
	}
      int ar2D[nbTeam][teams[0].nbMem];
      //for each team, (start with the biggest team to the smallest team)
      //assign for each member in this team one table, start from the
      //most available table (one has biggest available places)
      //after assigning (done for one team), update the capacity available of 
      //these used tables this time
      bool possible = true;
      vector<table> storage;
      for (int idTeam = 0; idTeam < nbTeam && possible; ++idTeam)
	{
	  multiset<table>::iterator it = tables.begin();
	  if (!storage.empty()) storage.clear();
	  for (int idMember = 0; idMember < teams[idTeam].nbMem && possible; ++idMember)
	    {
	      if (it == tables.end())
		{
		  possible = false;
		  break;
		}
	      else 
		{
		  ar2D[teams[idTeam].id][idMember] = (*it).id;
		  storage.push_back(*it);		  
		  ++it;
		}
	    }
	  if (possible) //update
	    {
	      tables.erase(tables.begin(), it);
	      for (int i = 0; i < teams[idTeam].nbMem; ++i)
		{
		  table cur = storage[i];
		  if (cur.cap > 1)
		    {
		      cur.cap -= 1;
		      tables.insert(cur);
		    }
		}
	    }
	}
      if (!possible) printf("%d\n", 0);
      else
	{
	  printf("%d\n", 1);
	  sort(teams.begin(), teams.end(), sortId);
	  for (int i = 0; i < nbTeam; ++i)
	    {
	      for (int j = 0; j < teams[i].nbMem; ++j)
		{
		  if (j != teams[i].nbMem - 1) printf("%d ", ar2D[i][j]);
		  else printf("%d\n", ar2D[i][j]);
		}
	    }
	}
    }
  return 0;
}

