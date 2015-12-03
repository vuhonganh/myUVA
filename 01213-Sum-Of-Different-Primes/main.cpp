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

bool debug = false;

long nbSumOfDifPrimes(int idx, int remainN, int remainK, vector<int> &primes, vector< vector< vector<long> > > &memo)
{
  if (debug) printf("idx = %d, remainN = %d, remainK = %d\n", idx, remainN, remainK);
  if (remainN == 0 && remainK == 0) return 1; //a possible sum
  if (remainK == 0 && remainN > 0) return 0;
  if (idx == (int) primes.size()) //reach the end of the list of primes
    {
      return 0; //we still have remainN or remainK while already run out of primes  
    }
  long &ans = memo[idx][remainN][remainK];
  if (ans != -1) return ans;
  ans = 0;
  //at each possible-sum-up prime, we can choose either count or don't count it 
  if (primes[idx] <= remainN)
    {
      if (debug) printf("idx = %d, remainN = %d, remainK = %d\n", idx, remainN, remainK);
      ans = nbSumOfDifPrimes(idx + 1, remainN - primes[idx], remainK - 1, primes, memo); //take it
      if (debug) printf("take this idx = %d, nbSum = %ld\n", idx, ans);
      ans += nbSumOfDifPrimes(idx + 1, remainN, remainK, primes, memo); //don't take it
      if (debug) printf("plus case dont take this idx = %d, nbSum = %ld\n", idx, ans);
    }
  return ans;
}

void bottomUp(int n, int k, vector<int> &primes, vector<vector<long> > &memoBottomUp)
{
  //if (n == 0 && k == 0) return 1;
  long &ans = memoBottomUp[n][k];
  if (ans != 0) return;
  for (size_t i = 0; i < primes.size(); ++i)
    {
      for (int cur = n; cur >= primes[i]; --cur)
	{
	  for (int j = 1; j <= k; j++)
	    {
	      memoBottomUp[cur][j] += memoBottomUp[cur - primes[i]][j - 1];
	    }
	}
    }
}

int main()
{
  int n, k;
  vector<int> primes = sieve(1120); //according to the statement of problem, n <= 1120
  int nbPrimes = (int) primes.size();
  while (scanf("%d %d", &n, &k) == 2)
    {
      if (n == 0 && k == 0) break;
      //vector< vector< vector<long> > > memo(nbPrimes, vector< vector<long> >(n + 1, vector<long>(k + 1, -1)));
      //printf("%ld\n", nbSumOfDifPrimes(0, n, k, primes, memo));
      vector<vector<long> > memoBottomUp(1121, vector<long>(k + 1, 0));
      memoBottomUp[0][0] = 1;
      bottomUp(n, k, primes, memoBottomUp);
      printf("%ld\n", memoBottomUp[n][k]); 
    }
  
  return 0;
}
