//UVA 10763 Foreign Exchange
//use map from a pair to an integer
//each time found a reverse pair -> decrease integer value
//or found a same pair -> increase integer value

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


int main
{
  
  return 0;
}
