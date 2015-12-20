//uva 10858 Unique Factorization
//Type: array manipulation, stack use, tricky to implement, need recursive technique

#include <cstdio>
#include <cassert>
#include <stack>
#include <vector>
#include <deque>
using namespace std;

vector<deque<int> > result;

void addFactor(int remainN, int div, deque<int> &factor)
{
  for (int i = div; i * i <= remainN; ++i)
    {
      if (remainN % i == 0)
	{
	  factor.push_back(i);
	  addFactor(remainN / i, i, factor);
	  factor.pop_back(); //need to pop out after having all factors for one factorization
	}
    }
      factor.push_back(remainN); //the remain factor after the for loop
      result.push_back(factor);
      factor.pop_back(); //need to pop out after having all factors for one factorization (to make an empty stack)
}

int main()
{
  int N;
  deque<int> factor;
  while (scanf("%d", &N) == 1 && N != 0)
    {
      result.clear();

      addFactor(N, 2, factor);
      printf("%lu\n", result.size() - 1);
      for (size_t i = 0; i < result.size() - 1; ++i)
	{
	  for (size_t j = 0; j < result[i].size(); ++j)
	    {
	      if (j == result[i].size() - 1) printf("%d\n", result[i][j]);
	      else printf("%d ", result[i][j]);
	    }
	}
    }
  
  return 0;
}
