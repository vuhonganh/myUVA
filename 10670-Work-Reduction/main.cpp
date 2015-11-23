//UVA 10670 Work Reduction
//type: greedy
#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

struct agence
{
  char name[20]; //name of agence
  int charLen;
  int priceUnit; //price to reduce one unit of work
  int priceHalf; //price to reduce half of work
  int cost; //cost to pay in order to achive the work reduction

  bool operator<(const agence &a) const
  {
    if (cost != a.cost) return cost < a.cost;
    else
      {
	for (int i = 0; i < min(charLen, a.charLen); ++i)
	  {
	    if ((int) name[i] != (int) a.name[i]) return ((int) name[i] < (int) a.name[i]);
	  }
	if (charLen < a.charLen) return true;
	else return false;
      }
  }
};

void printAgences(const vector<agence> &ar, const int &nbAgen)
{
  for (int i = 0; i < nbAgen; ++i)
    {
      for (int j = 0; j < ar[i].charLen; ++j)
	{
	  printf("%c", ar[i].name[j]);
	}
      printf(" %d\n", ar[i].cost);
    }
}

int main()
{
  int current; //current work load
  int target;  //target work load (that we need to exactly achive)
  int nbAgen;  //number of agencies
  int nbCase;
  int caseNb = 1;
  assert(scanf("%d", &nbCase) == 1);
  vector<agence> agences;
  while(nbCase--)
    {
      assert(scanf("%d %d %d\n", &current, &target, &nbAgen) == 3);
      if (!agences.empty()) agences.clear();
      for (int j = 0; j < nbAgen; ++j)
	{
	  agence cur;
	  int i = 0;
	  while(scanf("%c", &cur.name[i]) == 1 && cur.name[i] != ':') i++;
	  assert(scanf("%d,%d\n", &cur.priceUnit, &cur.priceHalf) == 2);
	  cur.charLen = i;
	  cur.cost = 0;
	  agences.push_back(cur);
	}
    
      for (int j = 0; j < nbAgen; ++j)
	{
	  int c = current;
	  while (c > target)
	    {
	      if (c/2 < target)//no need to half the workload
		{
		  agences[j].cost += (c - target) * agences[j].priceUnit;
		  c = target;
		}
	      else 
		{
		  int diff = c - c/2;
		  if (diff * agences[j].priceUnit > agences[j].priceHalf)
		    agences[j].cost += agences[j].priceHalf;
		  else
		    agences[j].cost += diff * agences[j].priceUnit;
		  c -= diff;
		}
	    }
	}
      sort(agences.begin(), agences.end());
      printf("Case %d\n", caseNb++);
      printAgences(agences, nbAgen);
    }
  
  return 0;
}
