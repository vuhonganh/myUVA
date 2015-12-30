#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int target;
int N;
vector<double> memo;
vector<vector<double> > dist;
vector< int > xs;
vector< int > ys;
const double INF = 1000000000; //one billion

void calculDist()
{
  //there are 2N students
  for (int i = 0; i < 2 * N; ++i)
    {
      for (int j = i + 1; j < 2 * N; ++j)
	{
	  dist[i][j] = dist[j][i] = sqrt((xs[i] - xs[j]) * (xs[i] - xs[j]) + (ys[i] - ys[j]) * (ys[i] - ys[j]));
	}
    }
}

double costToTarget(int bitmaskState)
{
  if (bitmaskState == target) return 0;
  if (memo[bitmaskState] > -0.5) return memo[bitmaskState];
  double &ans = memo[bitmaskState];
  ans = INF;
  int i, j;
  for (i = 0; i < 2 * N; ++i)
    {
      for (j = i + 1; j < 2 * N; ++j)
	{
	  if ( (((1 << i) & bitmaskState) == 0) && (((1 << j) & bitmaskState) == 0))
	    {
	      ans = min(ans, dist[i][j] + costToTarget(bitmaskState | (1 << i) | ( 1 << j))); 
	    }
	}
      
    }
  return ans;
}

int main()
{
  string name;
  int caseNb = 1;
  while(cin >> N && N != 0)
    {
      xs.assign(2 * N, 0);
      ys.assign(2 * N, 0);
      dist.assign(2 * N, vector<double>(2 * N, 0.0));
      memo.assign( 1 << (2 * N), -1.0);
      for (int i = 0; i < 2 * N; ++i)
	{
	  cin >> name;
	  cin >> xs[i] >> ys[i];
	}
      target = (1 << (2 * N)) - 1;
      calculDist();
      printf("Case %d: %.2f\n", caseNb++, costToTarget(0));
    }
  return 0;
}
