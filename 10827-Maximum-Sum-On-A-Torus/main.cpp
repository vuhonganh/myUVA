//10827 Maximum sum on a Torus
//Type: dynamic programming 2D range max sum
//Key point: turn 2D array n * n => (2*n - 1) * (2*n - 1)
//than use adding according to possible range

#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

void makeCumRowMat(vector<vector<int> > &ar) //make cumulative mat according to row
{
  for (size_t i = 0; i < ar.size(); ++i)
    {
      for (size_t j = 1; j < ar[i].size(); ++j)
	{
	  ar[i][j] += ar[i][j - 1];
	}
    }
}

void printMat2D(const vector<vector<int> > &ar)
{
  for (size_t i = 0; i < ar.size(); ++i)
    {
      for (size_t j = 0; j < ar[i].size(); ++j)
	{
	  printf("%3d  ", ar[i][j]);
	}
      printf("\n");
    }
  printf("\n");
}


int main()
{
  int nbCase;
  vector<vector<int> > mat;
  assert(scanf("%d", &nbCase) == 1);
  while (nbCase--)
    {
      int n;
      assert(scanf("%d", &n) == 1);
      mat.assign(2 * n - 1, vector<int>(2 * n - 1, 0));
      for (int i = 0; i < n; ++i)
	{
	  for (int j = 0; j < n; ++j)
	    {
	      assert(scanf("%d", &mat[i][j]) == 1);
	      
	      
	     
	      if (i != n - 1 && j != n - 1) mat[i][j + n] = mat[i + n][j] = mat[i + n][j + n] = mat[i][j];
	      else 
		{
		  if (j == n - 1 && i != n - 1) mat[i + n][j] = mat[i][j];
		  if (i == n - 1 && j != n - 1) mat[i][j + n] = mat[i][j];
		}
	    }
	}
      //      printMat2D(mat);
      makeCumRowMat(mat);
      int maxVal = -1000000000; //minus one billion
      for (int left = 0; left < n; ++left)
	{
	  for (int right = left; right < left + n; ++right)
	    {
	      for (int rowUp = 0; rowUp < n; ++rowUp)
		{
		  int sum = 0;
		  for (int row = rowUp; row < rowUp + n; ++row)
		    {
		      if (left > 0) sum += mat[row][right] - mat[row][left - 1];
		      else sum += mat[row][right];
		      maxVal = max(sum, maxVal);
		      if (sum < 0) sum = 0;
		    }
		  
		}
	    } 
	}
      printf("%d\n", maxVal);
    }
  return 0;
}
