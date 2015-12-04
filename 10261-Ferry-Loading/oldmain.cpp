//UVA 10261 Ferry Loading 
//Type: Dynamic programming, knapsack 

#include <cstdio>
#include <cassert>
#include <vector>
using namespace std;
bool debug = true;

int nbCarOneSide(int i, int remainLen, int &idxOver, vector<int> &lenCars, vector<vector<int> > &memo, vector<bool> &atThisSide, bool firstTime, int &nbCars)
{
  if (firstTime || !atThisSide[i])
    {
      if (i >= idxOver || i == (int) lenCars.size()) return 0;
      if (remainLen < 0) return 0;
      int &ans = memo[i][remainLen];
      if (ans != -1) return ans;
      
      if (debug) printf("i = %d, remainLen = %d, firstTime = %d\n", i, remainLen, (int)firstTime);
      
      int nbCarPutThisCar_i = 0;
      if (remainLen >= lenCars[i]) nbCarPutThisCar_i = lenCars[i] + nbCarOneSide(i + 1, remainLen - lenCars[i], idxOver, lenCars, memo, atThisSide, firstTime, nbCars);
      int nbCarDontPutThisCar_i = nbCarOneSide(i + 1, remainLen, idxOver, lenCars, memo, atThisSide, firstTime, nbCars);
     
      if (nbCarPutThisCar_i > nbCarDontPutThisCar_i)
	{
	  if (firstTime) atThisSide[i] = true; //change it only the first time
	  ans = nbCarPutThisCar_i;
	  nbCars++;
	}
      else
	{
	  if (firstTime) atThisSide[i] = false; //change it only the first time
	  ans = nbCarDontPutThisCar_i;
	  nbCars--;
	}
      if (debug) printf("if put this car index i = %d, nbCar = %d, else nbCarDontPutThisCar = %d\n", i, nbCarPutThisCar_i, nbCarDontPutThisCar_i);
      if (debug) if (firstTime) printf("index i = %d, atThisSide[i] = %d\n", i, (int) atThisSide[i]);
      return ans;
    }
  else return nbCarOneSide(i + 1, remainLen, idxOver, lenCars, memo, atThisSide, firstTime, nbCars);
}

int nbCar(int i, int remL, int remR, vector<int> &lenCars, vector<vector<vector<int> > > &memo, vector<bool> &atLeft)
{
  if (i == (int) lenCars.size()) return 0;
  if (lenCars[i] > remL && lenCars[i] > remR) return 0;
  if (remL < 0 || remR < 0) return 0;
  int &ans = memo[i][remL][remR];
  if (ans != -1) return ans;
  int nbCarIfPutToLeft = 1 + nbCar(i + 1, remL - lenCars[i], remR, lenCars, memo, atLeft);
  int nbCarIfPutToRight = 1 + nbCar(i + 1, remL, remR - lenCars[i], lenCars, memo, atLeft);
  if (nbCarIfPutToLeft > nbCarIfPutToRight)
    {
      ans = nbCarIfPutToLeft;
      atLeft[i] = true;
    }
  else
    {
      ans = nbCarIfPutToRight;
      atLeft[i] = false;
    }
  return ans;
}

int main()
{
  int nbCase;
  assert(scanf("%d", &nbCase) == 1);

  while (nbCase--)
    {
      int LenFerry;
      assert(scanf("%d", &LenFerry) == 1);
      LenFerry *= 100; //turn meter to centimeter
      vector<int> lenCars;
      int l;
      int idxOver = 0;
      int sum = 0;
      assert(scanf("%d", &l) == 1);
      do
	{
	  lenCars.push_back(l);
	  sum += l;
	  if (sum <= 2 * LenFerry) idxOver++;
	  assert(scanf("%d", &l) == 1);
	}
      while (l != 0);
      if (debug) printf("idxOver = %d\n", idxOver);
      vector<bool> atThisSide(lenCars.size(), false);
      vector<vector<int> > memo(lenCars.size(), vector<int>(LenFerry + 1, -1));
      vector<vector<int> > memo2(lenCars.size(), vector<int>(LenFerry + 1, -1));
      int nbcar1 = 0;
      int nbcar2 = 0;
      int nbCarFirstTime = nbCarOneSide(0, LenFerry, idxOver, lenCars, memo, atThisSide, true, nbcar1);
      int nbCarSecondTime = nbCarOneSide(0, LenFerry, idxOver, lenCars, memo2, atThisSide, false, nbcar2);
      if (debug) printf("length 1 = %d\n", nbCarFirstTime);
      if (debug) printf("length 2 = %d\n", nbCarSecondTime);
      
      //int nbCarTotal = nbCarFirstTime + nbCarSecondTime;
      int nbCarTotal = nbcar1 + nbcar2;
      printf("%d\n", nbCarTotal);
      for (int i = 0; i < nbCarTotal; ++i)
	{
	  if (atThisSide[i]) printf("port\n");
	  else printf("starboard\n");
	}
      if (nbCase) printf("\n");
    }
  return 0;
}
