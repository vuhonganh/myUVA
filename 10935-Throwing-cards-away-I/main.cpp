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
      int discard;
      int addToBottom;
      printf("Discarded cards:");
      while (dq.size() > 1)
	{
	  discard = dq.back();
	  printf( (dq.size() == 2) ? " %d" : " %d,", discard); 
	  dq.pop_back();
      
	  addToBottom = dq.back();
	  dq.pop_back();
      
	  dq.push_front(addToBottom);
	}
      printf("\nRemaining card: %d\n", dq.back());
    }
  return 0;
}
