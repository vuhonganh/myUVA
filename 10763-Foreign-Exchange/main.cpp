//UVA 10763 Foreign Exchange
//use map from a pair to an integer
//each time found a reverse pair -> decrease integer value
//or found a same pair -> increase integer value

#include <cstdio>
#include <map>
#include <cassert>

using namespace std;

struct pairAB
{
  int A;
  int B;
  bool operator< (const pairAB &o) const
  {
    if (A != o.A) return (A < o.A);
    else
      {
   	if (B != o.B) return (B < o.B);
   	return false; //here A equals o.A and B equals o.B
   	//so this must return false in order for find to work
	//because in STL, a == b iff (!(a < b) && !(b < a))
      }
  }
};


int main()
{
  int n; //number candidate
  map<pairAB, int> maps;
  map<pairAB, int>::iterator it;
  int a, b;
  while (scanf("%d", &n) == 1 && n != 0)
    {
      if (!maps.empty()) maps.clear();
      for (int i = 0; i < n; ++i)
	{
	  assert(scanf("%d %d", &a, &b) == 2);
	  if (a < b)
	    {
	      pairAB cur{a, b};
	      it = maps.find(cur);
	      if (it != maps.end())
		{
		  (it->second)++;
		}
	      else
		{
		  maps.insert(make_pair(cur, 1));
		}
	    }
	  else //a > b -> swap and find
	    {
	      pairAB cur{b, a};
	      it = maps.find(cur);
	      if (it != maps.end())
		{
		  (it->second)--;
		}
	      else
		{
		  maps.insert(make_pair(cur, -1));
		}
	    
	    }
	}
      bool possible = true;
      for (it = maps.begin(); it != maps.end(); ++it)
	{
	  if (it->second != 0)
	    {
	      possible = false;
	      break;
	    }
	}
      if (possible) printf("YES\n");
      else printf("NO\n");
    }
  
  return 0;
}
