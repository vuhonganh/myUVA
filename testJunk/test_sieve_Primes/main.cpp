#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

vector<int> sieve(int n) //return a vector<int> of prime number from 2 to n
{
  vector<int> primes;
  vector<bool> isPrimes(n + 1, true);
  for (int i = 2; i < n; ++i)
    {
      if (isPrimes[i]) 
	{
	  primes.push_back(i);
	  for (int j = 2 * i; j < n; j+=i)
	    {
	      isPrimes[j] = false;
	    }
	}
    }
  return primes;
}

int main()
{
  int n;
  while (true)
    {
      printf("enter the number n (0 to break): ");
      assert(scanf("%d", &n) == 1);
      if (n == 0) break;
      vector<int> primes = sieve(n);
      for (size_t i = 0; i < primes.size(); ++i)
	{
	  printf("%d\n", primes[i]);
	}      
    }
	return 0;
}
