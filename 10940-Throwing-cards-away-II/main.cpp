//uva 10940 Throwing cards away II
//deque simulation

#include <cstdio>
#include <deque>

using namespace std;

int main()
{
  deque<int> dq;
  int n;
  while (scanf("%d", &n) == 1 && n != 0)
    {
      dq.clear();
      for (int i = n; i > 0; --i)
	{
	  dq.push_back(i);
	}
      while (dq.size() > 1)
	{
	  dq.pop_back();
	  int addToBottom = dq.back();
	  dq.pop_back();
	  dq.push_front(addToBottom);
	}
      printf("%d\n", dq.back());
    }
  return 0;
}
