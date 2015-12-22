//uva 11496 Musical Loop
//Need always 3 consecutive numbers to detect if it's a peak (local min or local max)
//pay attention because this is a loop, so need to count the last number with the 2 first numbers as a case also

#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

int main()
{
	int N;
	int x1, x2, x3;
	int firstE, secondE;
	int cnt;
	while (scanf("%d", &N) == 1 && N != 0)
	{
		cnt = 0;
		for (int i = 0; i < N + 2; ++i)
		{
			if (i == 0) 
			{
				assert(scanf("%d", &x1) == 1);
				firstE = x1;				
			}
			else if (i == 1)
			{
				assert(scanf("%d", &x2) == 1);
				secondE = x2;				
			}
			else if (i < N) //can start counting peak
			{
				assert(scanf("%d", &x3) == 1);
				if ((x2 - x3) * (x2 - x1) > 0) cnt++;	
				x1 = x2;
				x2 = x3;
			}
			else if (i == N)//i == N start count the last two cases
			{
				x3 = firstE;
				if ((x2 - x3) * (x2 - x1) > 0) cnt++;
				x1 = x2;
				x2 = x3;				
			}
			else
			{
				x3 = secondE;
				if ((x2 - x3) * (x2 - x1) > 0) cnt++;
			}			
		}
		printf("%d\n", cnt);
	}	
  	return 0;
}
