//UVA 10003 Cutting Stick
//type: Dynamic programming
//idea: add 0 and l (length of the original stick) in the set of cutting point
//consider a intermediate stick to be cut comprise of 2 positions in that set above
//cost_cut_of_stick_from_left_to_right(left, right = left + 1) = 0 because there is no medium point to cut (and of course this intermediate stick does not need to be cut)
// cost_cut_of_stick_from_left_to_right(left, right) = min (cost_cut_of_stick_from_left_to_right(left, i) + cost_cut_of_stick_from_left_to_right(i, right) + length(right - left))
//because the cost we consider here, is the cost after cutting all the position in the range [left, right] that we have to cut, at each cut, it takes the cost length(right-left), and the cost of cuts between left and right

//the answer is cost_cut_of_stick_from_left_to_right(0, n + 1) because n + 1 is the index of length l

#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

vector<vector<int> > cost; //cost cut of stick from left to right
vector<int> pos; //position to cut, added 0 and length

int cut(int left, int right)
{
  if (left + 1 == right) return 0;
  if (left < 0 || right <= left) return 0;
  int &ans = cost[left][right];
  if (ans != -1) return ans;
  ans = 1000000000; //assign a max value for ans to take in into the min operator
  for (int i = left + 1; i < right; ++i)
    {
      ans = min(ans, cut(left, i) + cut(i, right) + pos[right] - pos[left]);
    }
  return ans;
}

int main()
{
  int length;
  int n;
  while (scanf("%d", &length) == 1)
    {
      if (length == 0) break;
      assert(scanf("%d", &n) == 1);
      cost.assign(n + 2, vector<int>(n + 2, -1));
      pos.assign(n + 2, 0);
      pos[n + 1] = length;
      for (int i = 1; i < n + 1; ++i)
	{
	  assert(scanf("%d", &pos[i]) == 1);
	}
      printf("The minimum cutting is %d.\n", cut(0, n + 1));
    }
  return 0;
} 
