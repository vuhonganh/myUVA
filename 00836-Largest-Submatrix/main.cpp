//UVA 836 Largest Submatrix
//Type: Dynamic programing with: max 2D range sum
//Key point: convert 0 to -inf or a negative amount large enough
//so the sub matrix with largest sum will be matrix of only ones

#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

int minusVal = -10000;

vector< vector<int> >mat; //matrix 2D

void printMat2D(const vector<vector<int> > &ar)
{
  for (size_t i = 0; i < ar.size(); ++i)
    {
      for (size_t j = 0; j < ar[i].size(); ++j)
	{
	  printf("%d", ar[i][j]);
	}
      printf("\n");
    }
  printf("\n");
}


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

int main()
{

  int nbCase;
  assert(scanf("%d", &nbCase) == 1);
  char c;
  while (nbCase--)
    {
      while (scanf("%c", &c) != EOF)
	{
	  if (c == '1' || c == '0') break;
	}
      //find first element of matrix
      if (!mat.empty()) mat.clear();
      vector<int> oneLine;
      size_t N = 0;
     
      while (true)
	{
	  if (!oneLine.empty()) oneLine.clear();
	  do
	    {
	      if (c == '1') oneLine.push_back(1);
	      else oneLine.push_back(minusVal);
	      ++N;
	      if(scanf("%c", &c) == EOF) break;
	    }
	  while (c == '0' || c == '1');

	  mat.push_back(oneLine);
	  if (mat.size() == N) break;
	  N = 0;
	  while (c != '0' && c != '1') assert(scanf("%c", &c) == 1);
	}
      //DONE READING INPUT
      
      //printMat2D(mat);
      makeCumRowMat(mat);
      int maxVal = 0;
      for (size_t left = 0; left < N; ++left)
	{
	  for (size_t right = left; right < N; ++right)
	    {
	      int sum = 0;
	      for (size_t row = 0; row < N; ++row)
		{
		  if (left > 0) sum += mat[row][right] - mat[row][left - 1];
		  else sum += mat[row][right];
		  maxVal = max(sum, maxVal);
		  if (sum < 0) sum = 0;
		}
	    }
	}
      printf("%d\n", maxVal);
      if (nbCase) printf("\n");
    }
  
  
  
  return 0;
}
