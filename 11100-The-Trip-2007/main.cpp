//UVA 11100 The Trip 2007
//Greedy type, key point: the minimum number of pieces = the nb of elements in the largest sequence containing the same number (i.e. bags having the same dimension)
//because number of pieces can not be smaller than this (if not, exist piece with bag having same dimension -> contradiction)
//after that, to minimize the bags in each pieces, the normal way is to distribute gradually for each piece the bag in the sorted list
#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;

int main()
{
  int n;
  int nbCase = 1;
  bool debug = false;
  while (scanf("%d", &n) == 1)
    {
      if (nbCase > 1 && n != 0) printf("\n");
      if (n == 0) break;

      vector<int> bags(n);
      for (int i = 0; i < n; ++i)
	{
	  assert(scanf("%d", &bags[i]) == 1);
	}
      sort(bags.begin(), bags.end());
      int nbPiece = 0;
      bool firstPrint = false;
      for (int i = 0; i < n; ++i)
	{
	  if (firstPrint) printf("to verify if i after break and here equals, i = %d\n", i);
	  for (int j = i + 1; j < n; ++j)
	    {
	      if (bags[j] != bags[i])
		{
		  nbPiece = max(nbPiece, j - i);
		  i = j - 1; //because it will be incremented by one right before enter next loop
		  if (debug) printf("i = %d\n", i);
		  if (debug) firstPrint = true;
		  break;
		}
	      else
		{
		  if (j == n - 1) nbPiece = max(nbPiece, j - i + 1); //count also this last element
		}
	    }
	  if (debug) printf("after break this goes here and i = %d\n", i);
	}
      vector<int> ans[nbPiece];
      for (int i = 0; i < n; ++i)
	{
	  ans[i % nbPiece].push_back(bags[i]);
	}
      printf("%d\n", nbPiece);
      for (int i = 0; i < nbPiece; ++i)
	{
	  for (size_t j = 0; j < ans[i].size(); ++j)
	    {
	      printf( (j < ans[i].size() - 1)? "%d " : "%d\n", ans[i][j]);
	    }
	}
      nbCase++;
    }
}
