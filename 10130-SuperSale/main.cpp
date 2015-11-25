//UVA 10130 SuperSale
//Dynamic Programming: type knapsack

#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;
//global variable
int nbObj;
vector<int> prices;
vector<int> weights;
vector<int> capas;
int maxCapa;
vector< vector<int> > memos;
bool debug = false;


//THIS METHOD BELOW IS CORRECT
int valWithIdxObjConsidering(int id_obj, int remainCapa)
{
  if (remainCapa == 0) return 0;
  if (id_obj == nbObj) return 0; //considered all the objects already
  int &ans = memos[id_obj][remainCapa];
  if (ans != 0) return ans;
  if (weights[id_obj] > remainCapa)
    {
      ans = valWithIdxObjConsidering(id_obj + 1, remainCapa);
    }
  else
    {
      ans = max(valWithIdxObjConsidering(id_obj + 1, remainCapa), 
		prices[id_obj] + valWithIdxObjConsidering(id_obj + 1, remainCapa - weights[id_obj]));
    }
  return ans;
}

//THIS METHOD BELOW IS NOT CORRECT
int findMaxValWithState(int id_obj, int cur_capa) //find max value that reach with obj range from 0 to id_obj and current_capacity to carry 
{
  if (id_obj == nbObj || id_obj < 0) return 0;    //we reach the end
  if (cur_capa > maxCapa || cur_capa < 0) return 0; //dont need to go further
  if (debug) printf("id_obj and cur_capa in valid range: id_obj = %d, cur_capa = %d\n", id_obj, cur_capa);
  int &ans = memos[id_obj][cur_capa];
  if (debug) printf("current value of ans = memos[id_obj][cur_capa] = %d\n", ans);
  if (ans != 0) return ans; //if already calculate, no need to redo
  if (debug) printf("go search for ans..........\n");
  ans = max(findMaxValWithState(id_obj - 1, cur_capa), findMaxValWithState(id_obj - 1, cur_capa - weights[id_obj]) + prices[id_obj]);
  if (debug) printf("for id_obj = %d, cur_capa = %d, ans = %d\n", id_obj, cur_capa, ans);
  return ans;
}

int main()
{
  int nbCase;
  assert(scanf("%d", &nbCase) == 1);
  while (nbCase--)
    {
      assert(scanf("%d", &nbObj) == 1);
      prices.assign(nbObj, 0);
      weights.assign(nbObj, 0);
      for (int i = 0; i < nbObj; ++i)
	{
	  assert(scanf("%d %d", &prices[i], &weights[i]) == 2);
	}
      int nbPpl; //number of people buying
      assert(scanf("%d", &nbPpl) == 1);
      capas.assign(nbPpl, 0); //capacity to carry of each people
      for (int i = 0; i < nbPpl; ++i)
	{
	  assert(scanf("%d", &capas[i]) == 1);
	  maxCapa = max(maxCapa, capas[i]);
	}
      memos.assign(nbObj, vector<int>(maxCapa + 1, 0));
      int sum = 0;
      for (int i = 0; i < nbPpl; ++i)
	{
	  //int res = findMaxValWithState(0, capas[i]);
	  int res = valWithIdxObjConsidering(0, capas[i]);
	  sum += res;
	}
      printf("%d\n", sum);
    }
  return 0;
}
