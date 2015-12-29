//uva 12024 Hats 
//mathematical type
//given one configuration from 1 to n (like 1 2 3 ... n), how many permutation that satisfy the fact that all pairs with corresponding position is different numbers, for example:
//1 2 3 4
//3 1 4 2 is the permutation that satisfy because (1, 3), (2, 1), (3, 4), (4, 2) are paris of different numbers
//Solution: we have (n - 1) choice for the first position. Now, the problem returns to a small problem: given 2 sets of n - 1 numbers each, they have n - 2 common numbers. There are how many ways to present the second set given a specific configuration of the first set subject to each pair with corresponding position is of different numbers.
//we see the recursive property here: first, if we know the answer for set of n - 1 (denote ANS(n-1)), this will be ANS(n - 1) + ANS(n - 2) because: they have n - 1 numbers each, 
//but only n - 2 common numbers, so we must add ANS(n - 2) in the answer because the set of configuration constructed by these n - 2 numbers is not related/intersected with 
//the set of configuration constructed by n - 1 numbers. Because, if they intersect, then the configuration of intersection contains the (n-1)th element is at the same position 
//with itself in the original configuration -> contradiction
  
//IN SHORT: ANS(n) = (n - 1) * [ANS(n - 1) + ANS(n - 2)]

#include <cstdio>
#include <cassert>
#include <cstring>

#define SZ 16
int factos[SZ];
int ANS[SZ];

int getFactos(int i)
{
  if (i < 0) return -1;
  if (i == 0 || i == 1) return 1;
  int &ans = factos[i];
  if (ans != -1) return ans;
  else ans = i * getFactos(i - 1);
  return ans;
}

int getAns(int n)
{
  if (n == 0 || n == 1) return 0;
  if (n == 2) return 1;
  int &ans = ANS[n];
  if (ans != -1) return ans;
  ans = (n - 1) * (getAns(n - 1) + getAns(n - 2));
  return ans;
}


int main()
{
  int nbCase;
  memset(factos, -1, sizeof(factos));
  memset(ANS, -1, sizeof(ANS));
  assert(scanf("%d", &nbCase) == 1);
  while (nbCase--)
    {
      int N;
      assert(scanf("%d", &N) == 1);
      printf("%d/%d\n", getAns(N), getFactos(N));
    }
  return 0;
}
