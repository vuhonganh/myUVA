//UVA 00674 Coin Change: dynamic programming

#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define maxNum 7492
#define nbCoin 5

vector<int> coins = {1, 5, 10, 25, 50};

int ways[nbCoin][maxNum];

int calcul(int id_coin, int value)
{
  if (value == 0) return 1;
  if (value < 0) return 0;
  if (id_coin == nbCoin) return 0;


  int &ans = ways[id_coin][value];
  if (ans != -1) return ans;
  ans = calcul(id_coin + 1, value) + calcul(id_coin, value - coins[id_coin]);
  return ans;
}

int main()
{
  int val;
  memset(ways, -1, sizeof ways);
  while (scanf("%d", &val) == 1)
    {
      int res = calcul(0, val);
      printf("%d\n", res);
    }
  
  return 0;
} 
