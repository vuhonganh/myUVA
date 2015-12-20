//uva 10057 a mid-summer night's dream
//the value A is the median of the array
//if N is odd there is only one unique value for the median
//if N is even, there are 2 elements are medians -> a range from this lower up this upper is A
//The concept seems not so difficult using this approach, however, NEED TO BE CAREFULL TO SOLVE CORRECTLY, there are many cases to take care


#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

#define maxSz 65536
bool debug = false;
//bool debug = true;
int main()
{
  int num;
  vector<int> nbOfVal;
  int N;
  while (scanf("%d", &N) == 1)
    {
      nbOfVal.assign(maxSz, 0);
      for (int i = 0; i < N; ++i)
	{
	  assert(scanf("%d", &num) == 1);
	  nbOfVal[num]++;
	}
      //if N is odd -> there is only one value for the median
      //3/2 = 1, 4/2 = 2
      int iMed = 0;
      int cntNb = 0; //to count the number in our part from small to big
      int halfN = N / 2;
      while (cntNb < halfN)
	{
	  cntNb += nbOfVal[iMed++];
	}
      //now the number of value is equal or greater than N / 2
      if (debug) printf("done cntNb = %d, iMed = %d\n", cntNb, iMed);
      int iMedLow = iMed - 1; //need to reduce by one because of effect of iMed++ in the while loop above
      
      //rewrite to make it clear
      if (cntNb == halfN) //if at this iMedLow this is realy divide the set into 2 equal parts (or our part is less than the other part)
	{
	  while (nbOfVal[iMed] == 0) iMed++;    //find the real median value for both case
	  if (halfN * 2 != N)
	    printf("%d %d %d\n", iMed, nbOfVal[iMed], 1); //if odd there is only one value
	  else
	    printf("%d %d %d\n", iMedLow, nbOfVal[iMedLow] + nbOfVal[iMed], iMed - iMedLow + 1); 
	}
      else //if our part is bigger than the other, than there is only one unique value of median
	{
	  printf("%d %d %d\n", iMedLow, nbOfVal[iMedLow], 1);
	}
    }
  return 0;
}
