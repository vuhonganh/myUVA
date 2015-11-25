//UVA 108 Maximum Sum (search for sub matrix having maximum sum)
//using cummulative sum: a[i][j] = sum of the submatrix from (0,0) to (i,j)

#include <cstdio>
#include <cassert>
#include <vector>

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
	      if (i > 0) mat[i][j] += mat[i-1][j];
	      if (j > 0) mat[i][j] += mat[i][j-1];
	      if (i > 0 && j > 0) mat[i][j] -= mat[i-1][j-1];
	    }
	}
      int maxSum = -1000000000; //init maxSum to minus billion
      for (int i = 0; i < N; ++i)
	{
	  for (int j = 0; j < N; ++j)
	    {
	      for (int k = i; k < N; ++k)
		{
		  for (int l = j; l < N; ++l)
		    {
		      int sum = mat[k][l];
		      if (i > 0) sum -= mat[i - 1][l];
		      if (j > 0) sum -= mat[k][j - 1];
		      if (i > 0 && j > 0) sum += mat[i - 1][j - 1];
		      maxSum = max(sum, maxSum);
		    }
		}
	    }
	}
      printf("%d\n", maxSum);
    }
  
  return 0;
}
