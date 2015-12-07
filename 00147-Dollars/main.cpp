//UVA 147: Dollars
//DP type: Coin change type
//Call ways(i, amount) = number of ways to use a0...ai value_of_moneys to present amount 
//ways(i, amount) = ways(i - 1, amount) + ways(i, amount - moneys[i])
//ways(i < 0, amount) = 0;
//ways(i, amount = 0) = 1;
//Ex: ways(0, 1) = ways(-1, 1) + ways(0, 0) = 0 + 1 = 1

#include <cstdio>
#include <cassert>
#include <vector>
#include <cstring>
using namespace std;
#define sizeAr 11
#define maxSz 6004
int moneys[sizeAr] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
long long int memo[sizeAr][maxSz]; //because according to the statement, max amount is 300, 300/0.05 = 6000

long long int ways(int i, int amount)
{
  if (i < 0) return 0;
  if (amount == 0) return 1;
  long long int &ans = memo[i][amount];
  if (ans != -1) return ans;
  ans = 0;
  if (amount < moneys[i]) return ans = ways(i - 1, amount);
  else return ans = ways(i - 1, amount) + ways(i, amount - moneys[i]);
}

int main()
{
  double amountInDouble;
  int amount; 

  memset(memo, -1, sizeof(memo));
  bool debug = false;
  while (scanf("%lf", &amountInDouble) == 1)
    {
      if (debug)
	{
	  printf("amountInDouble = %f\n", amountInDouble);
	  double inCents = amountInDouble * 100 + 0.5;
	  printf("amountInCents = %f\n", inCents);
	  int turnToInt = (int) inCents;
	  printf("wtf is that: %d\n", turnToInt);
	  //amount = (int) (amountInDouble * 100.0); //NOT ADDING 0.5 will lead to some errors eventually because the compiler will truncate while convert from double to int for example 28565.000 can be converted to 28564
	}
      amount = (int) (amountInDouble * 100.0 + 0.5);
      if (amount == 0) break;
      if (amount % 5 != 0)
	{
	  printf("%*.2f%*d\n", 6, amountInDouble, 17, 0);
	  continue;
	}
      amount /= 5;
      printf("%*.2f%*lld\n", 6, amountInDouble, 17, ways(sizeAr - 1, amount));
      //printf("%*f%*ll\n", 6, amountInDouble, 17, ways(sizeAr - 1, amount));
    }
  return 0;
}
