//UVA 11951 Area
//Type Dynamic Programming: type 2D range sum

#include <cstdio>
#include <cassert>
#include <vector>

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
  int caseNb = 1;
  assert(scanf("%d", &nbCase) == 1);
  while (nbCase--)
    {
      int N, M, K; // matrix N*M (N lines, M collumns), and K is the money Steve can pay
      assert(scanf("%d %d %d", &N, &M, &K) == 3);
      vector<vector<int> > mat(N, vector<int>(M, 0));
      for (int i = 0; i < N; ++i)
	{
	  for (int j = 0; j < M; ++j)
	    {
	      assert(scanf("%d", &mat[i][j]) == 1);  //read input
	      if (j > 0) mat[i][j] += mat[i][j - 1]; //make it an cumulative row matrix
	    }
	}
      int maxArea = 0;
      int minPay = 1000000000; //init to one billion
      for (int left = 0; left < M; ++left)
	{
	  for (int right = left; right < M; ++right)
	    {
	      int cost = 0;
	      int startedRow = 0;
	      for (int row = 0; row < N; ++row)
		{
		  cost += mat[row][right];
		  if (left > 0) cost -= mat[row][left - 1];
		  if (cost > K)
		    {
		      while (cost > K)
			{
			  int costStartedRow = mat[startedRow][right];
			  if (left > 0) costStartedRow -= mat[startedRow][left - 1];
			  cost -= costStartedRow;
			  startedRow++;
			}
		    }
		  //now cost is not greater than K
		  int curArea = (row - startedRow + 1) * (right - left + 1);
		  if (curArea == maxArea)
		    {
		      minPay = min(cost, minPay);
		    }
		  else if (curArea > maxArea)
		    {
		      maxArea = curArea;
		      minPay = cost;
		    }
		}
	    }
	}
      printf("Case #%d: %d %d\n", caseNb++, maxArea, minPay);
      
    }
  return 0;
}
