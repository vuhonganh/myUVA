//UVA 00108 another way to solve this problem
//idea is quite the same: cummulative, but the different is cummulative for each row: for every row r: mat[r][col] = cell[r][0] + cell[r][col] 
//then, use Kadane algorithm

#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

vector<vector<int> > mat;

int main()
{
  int N;
  while (scanf("%d", &N) == 1)
    {
      mat.assign(N, vector<int>(N, 0));
      //reading input and calculating cummulative sum at same time
      for (int i = 0; i < N; ++i)
	{
	  for (int j = 0; j < N; ++j)
	    {
	      assert(scanf("%d", &mat[i][j]) == 1);
	      //if possible (not in edge) calculate the cummulative sum 
	      if (j > 0) mat[i][j] += mat[i][j-1]; //cummulative in the same row
	    }
	}
      int maxSum = -1000000000; //init maxSum to minus billion
      
      for (int left = 0; left < N; ++left)
	{
	  for (int right = left; right < N; ++right)
	    {
	      int sum = 0;
	      for (int row = 0; row < N; ++row)
		{
		  if (left > 0) sum -= mat[row][left - 1];
		  sum += mat[row][right];
		  //done summing one part of the row (from idx left to idx right only)
		  maxSum = max(maxSum, sum);
		  if (sum < 0) sum = 0;
		}
	    }
	}
      printf("%d\n", maxSum);
    }
  return 0;
}









