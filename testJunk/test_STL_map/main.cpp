#include <cstdio>
#include <map>

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
  map<pairAB, int> maps;
  map<pairAB, int>::iterator it;
  pairAB p1{1, 3};
  pairAB p2{3, 1};
  pairAB p3{1, 3};
  
  if (!maps.empty())
    {
      it = maps.find(p1);
      if (it != maps.end())
	(it->second)++;
      else
	maps.insert(make_pair(p1, 1));     	
    }
  else
    {
      maps.insert(make_pair(p1, 1));     
    }
 
 if (!maps.empty())
    {
      it = maps.find(p2);
      if (it != maps.end())
	(it->second)++;
      else
	maps.insert(make_pair(p2, 1));     	
    }
  else
    {
      maps.insert(make_pair(p2, 1));     
    }

 if (!maps.empty())
    {
      it = maps.find(p3);
      if (it != maps.end())
	(it->second)++;
      else
	maps.insert(make_pair(p3, 1));     	
    }
  else
    {
      maps.insert(make_pair(p3, 1));     
    }

  for (it = maps.begin(); it != maps.end(); ++it)
    {
      printf("%d, %d -> %d\n", (it->first).A, (it->first).B, it->second);
    }
  return 0;
}
