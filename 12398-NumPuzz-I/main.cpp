#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

//size of the square here is 3

#define SIZE 3

int dx[5] = {1, -1, 0, 0, 0};
int dy[5] = {0, 0, 1, -1, 0};

int square[SIZE][SIZE];

inline bool inBound(int x, int y)
{
  return (x > -1 && x < SIZE && y > -1 && y < SIZE);
}

void process(char c)
{
  //find the coordinate of this character c in the square
  int x = (int(c) - int ('a')) / SIZE;
  int y = (int(c) - int ('a')) % SIZE;
  for (int i = 0; i < 5; ++i)
    {
      int curX = x + dx[i];
      int curY = y + dy[i];
      if (inBound(curX, curY))
	{
	  square[curX][curY]++;
	  square[curX][curY] %= 10;
	}
    }
}

int main()
{
  int nbCase = 1;
  string line;
  while (getline(cin, line))
    {
      memset(square, 0, sizeof(square));
      for (int i = (int) line.length() - 1; i > -1; --i)
	{
	  char c = line[i];
	  process(c);
	}
      printf("Case #%d:\n",  nbCase++);
      for (int i = 0; i < SIZE; ++i)
	{
	  for (int j = 0; j < SIZE; ++j)
	    {
	      printf(j == SIZE - 1 ? "%d\n" : "%d ", square[i][j]);
	    }
	}
    }
  
  return 0;
}
