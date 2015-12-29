//uva 11636 Hello World
//mathematical problems: reasoning based on that from a nearest power of 2 of N, we can also solve the equation x + y = nearestPow2 && 2*x + y = N
//it means that the minimum time to solve is to reach to the nearest power of 2 then plus 1 if N is greater than this power of 2
//this is the optimal solution because double each time is the fastest way we can do 

#include <cstdio>
#include <cmath>

int main()
{
  int N;
  int caseNb = 1;
  while (scanf("%d", &N) == 1 && N >= 0)
    {
      int res;
      if (N == 0) res = 0; 
      else
	{
	  int k = (int) log2(N);
	  int nearestPower2 = 1 << k;
	  if (nearestPower2 == N) res = k;
	  else res = k + 1;
	}
      printf("Case %d: %d\n", caseNb++, res);
    }
  return 0;
}
