//UVA 111 History Grading
//Type: dynamic programming
//In the competitive programming book, this is Longest Increasing Subsequence (LIS)
//But I do not know how to turn this problem into LIS
//Instead, Longest Common Subsequence (LCS) is more intuitive
//Take care about the statement of this problem (i.e. understand if read carefully the statement)
//Need to understand how to turn it to a LCS problem
/*
Given the correct order of events below
3 1 2 4 9 5 10 6 8 7
| | | | | | |  | | |
1 2 3 4 5 6 7  8 9 10
means (the event 1 happened 3rd, the event 2 happened 1st, event 3 happened 2nd ....)
remap follow the chronological order of events: (first event happened, second event happened etc.)

-> 2 3 1 4 6 8 10 9 5 7 : means: event 2 happened 1st, after event 2 is event 3, after event 3 is event 1, after event 1 is event 4 etc.

Now consider an order of events that a student wrote like below:
2 10 1 3 8 4 9 5 7 6
| |  | | | | | | | |
1 2  3 4 5 6 7 8 9 10
remap follow the chronological order of events that student wrote: 
-> 3 1 4 6 8 10 9 5 7 2 : means: event 3 happened 1st, after event 3 is event 1, after event 1 is event 4 etc.

Now, we can see, the problem turns to a 'finding the LCS' problem
*/

/*
  LCS: ar1[idx_0, ..., idx_i, ...], ar2[idx_0, ..., idx_j, ...] 
  memo[i][j] = (ar1[i] == ar2[j]) ? (memo[i-1][j-1] + 1) : max(memo[i-1][j], memo[i][j-1])
  
*/


#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

int LCS(const vector<int> &ar1, const vector<int> &ar2, vector<vector<int> > &memo, int idx_1, int idx_2)
{
  //memo.assign(ar1.size(), vector<int>(ar2.size(), 0));
  if (idx_1 < 1 || idx_2 < 1) return 0;
  int &ans = memo[idx_1][idx_2];
  if (ans != -1) return ans;
  if (ar1[idx_1] == ar2[idx_2]) ans = LCS(ar1, ar2, memo, idx_1 - 1, idx_2 - 1) + 1;
  else ans = max(LCS(ar1, ar2, memo, idx_1 - 1, idx_2), LCS(ar1, ar2, memo, idx_1, idx_2 - 1));
  return ans;
}

int main()
{
  int N;
  assert(scanf("%d", &N) == 1);
  vector<int> correctOrder(N + 1, 0);
  int eventOrder;
  for (int eventNb = 1; eventNb < N + 1; ++eventNb)
    {
      assert(scanf("%d", &eventOrder) == 1);
      correctOrder[eventOrder] = eventNb;
    }
  vector<int> studentAns(N + 1, 0);
  int count = 0; //count is eventNb
  while (scanf("%d", &eventOrder) != EOF)
    {
      count++;
      if (count > N)
	{
	  studentAns.assign(N + 1, 0);
	  count = 1;
	}
      studentAns[eventOrder] = count;
      if (count == N)
	{
	  vector<vector<int> >memo(N + 1, vector<int>(N + 1, -1)); 
	  printf("%d\n", LCS(correctOrder, studentAns, memo, N, N));
	}
    }
  return 0;
}
