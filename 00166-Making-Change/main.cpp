//UVA 166: Making change
//Dynamic programming, Coin change type
//two problems of coin change variants in this problem
//Problem 1: we need to calculate the minimum number of coins of the Shopkeeper for any given amount, the supply of coins is infinite
//Problem 2: for a given amount, calculate the minimum number of coins of the buyer to sum to that amount, the supply of each coin value is finite
//the Problem 1 is classical and wellknown, it is solved in nbCoinShop method below
//the Problem 2 is more difficult while we have to keep track of the current coin index and the number of remain coins -> a array 3D
//it seems that we have to reinitialize this 3D array at each new test case, because the values in this array is dependent (one is calculated depend on others)
//another attention to calculate the maxSZ of the array (it should not be over 100 because the max amount is $5.00)
/*
  algorithm:
  first calculate the number specific the buyer have to pay for the given amount (Problem 2)
  then, for any value from the given amount to min(maxPayable, 100) calculate the minimum nbCoin the buyer give + the minimum nbCoin the Shop payback
  compare and take the minimum value
*/
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

#define sizeAr 6
#define maxSZ 104

using namespace std;

const int INF = 1000000; //choose the infinity value is one million
int vals[sizeAr] = {1, 2, 4, 10, 20, 40}; //value of currency divided by 5
int capBuy[sizeAr + 1] = {0, 0, 0, 0, 0, 0, 0}; //capacity of corresponding coins of buyer
int changesShop[maxSZ]; //up to $5.00
int changesBuyer[sizeAr][maxSZ][maxSZ]; //up to 100 coins of 5 cents for the maximum transaction $5.00

bool debug = false;

int nbCoinShop(int amount) //return the minimum number of coin to represent amount 
{
  if (debug) printf("calculate nbCoinShop for amount = %d\n", amount);
  if (amount == 0) return 0;
  int &ans = changesShop[amount];
  if (ans != -1) return ans;
  ans = INF;
  for (int i = sizeAr - 1; i > -1; --i)
    {
      if (vals[i] > amount) continue;
      ans = min(ans, 1 + nbCoinShop(amount - vals[i]));
    }

  return ans;
}

int nbCoinBuy(int i, int amount, int remCoins_i)//from coin type at index i (to max-val of coins), with the number remaining of this type is remCoins_i, return the number of coin that buyer have to use to represent amount
{
  if (debug) printf("calculate nbCoinBuy for i = %d, amount = %d, remCoins_i = %d\n", i, amount, remCoins_i);
  if (amount == 0) return 0;
  if (i == sizeAr || i < 0) return INF;
  if (remCoins_i == 0)
    {
      if (i == sizeAr - 1) return INF;
      return nbCoinBuy(i + 1, amount, capBuy[i + 1]);
    }
  int &ans = changesBuyer[i][amount][remCoins_i];
  if (ans != -1) return ans;
  if (vals[i] > amount) return ans = INF;
  ans = min(1 + nbCoinBuy(i, amount - vals[i], remCoins_i - 1), nbCoinBuy(i + 1, amount, capBuy[i + 1]));
  return ans;
}

int main()
{
  double amountInDouble;
  int cntZero;
  int maxPayable;
  memset(changesShop, -1, sizeof(changesShop));
  
  while (scanf("%d", &capBuy[0]) == 1)
    {
      memset(changesBuyer, -1, sizeof(changesBuyer));
      if (capBuy[0] > 100) capBuy[0] = 100;
      maxPayable = vals[0] * capBuy[0];
      cntZero = (capBuy[0] == 0)? 1 : 0;
      
      for (int i = 1; i < sizeAr; ++i)
	{
	  assert(scanf("%d", &capBuy[i]) == 1);
	  if (capBuy[i] > 100) capBuy[i] = 100;
	  maxPayable += vals[i] * capBuy[i];
	  cntZero += (capBuy[i] == 0)? 1 : 0;
	}
      maxPayable = min(maxPayable, maxSZ - 1);
      if (cntZero == 6) break;
      scanf("%lf", &amountInDouble);
      amountInDouble *= 100;
      int amount = (int) (amountInDouble + 0.5);
      amount /= 5;
      
      if (debug) printf("read input ok, amount = %d\n", amount);
      int concreteCoinNb = nbCoinBuy(0, amount, capBuy[0]);
      int res = concreteCoinNb;
      if (debug) printf("concreteCoinNb computed ok, concreteCoinNb = %d\n", concreteCoinNb);

      for (int biggerAmount = amount + 1; biggerAmount <= maxPayable; ++biggerAmount)
	{
	  int nbCoin1 = nbCoinBuy(0, biggerAmount, capBuy[0]);
	  if (nbCoin1 >= INF) continue;
	  int nbCoin2 = nbCoinShop(biggerAmount - amount);
	  res = min(res, nbCoin1 + nbCoin2);
	}
      printf("%*d\n", 3, res);
    }
  return 0;
}
