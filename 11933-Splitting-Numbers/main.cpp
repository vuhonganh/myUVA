//uva 11933 Splitting Numbers
//type: Bit Manipulation

#include <cstdio>
#include <cassert>

int main()
{
  unsigned int N;
  while (scanf("%u", &N) == 1 && N != 0)
    {
      int k = 0;
      bool odd = true;
      unsigned int oddIdx = 0;
      unsigned int evenIdx = 0;
      unsigned int cur;
      while ( (cur = (1 << k)) <= N)
	{
	  if (cur & N)
	    {
	      if (odd) oddIdx += cur;
	      else evenIdx += cur;
	      odd = !odd;
	    }
	  k++;
	}
      printf("%u %u\n", oddIdx, evenIdx);
    }
  return 0;
}
