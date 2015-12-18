#include <cstdio>
#include <cassert>
#include <set>

using namespace std;

int main()
{
  unsigned int nb;
  multiset<unsigned int> mSet;
  multiset<unsigned int>::iterator it;
  int count = 0;
  while (scanf("%u", &nb) == 1)
    {
      count++;
      mSet.insert(nb);
      if (count % 2 == 1)
	{
	  it = mSet.begin();
	  advance(it, count / 2);
	  unsigned int median = *it;
	  printf("%u\n", median);
	}
      else
	{
	  it = mSet.begin();
	  advance(it, (-1 + count / 2));
	  unsigned int leftElem = *it;
	  it++;
	  unsigned int rightElem = *it;
	  unsigned int median = (rightElem + leftElem) / 2;
	  printf("%u\n", median);
	}
    }
  return 0;
}
