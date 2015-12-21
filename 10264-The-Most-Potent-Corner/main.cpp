//uva 10264 The most potent corner
//Bit manipulation type
//one N-cube has 2^N corners, do not know why, but we can deduce from the construction : move the (n-1)-cube into a new direction to have the n-cube -> the number of corner is doubled after each move
//Observation 1 : the corner weight is given by increase order: 00...0 -> 00...1 --> 00...10 --> 00...11 --> 00..100 -> just like from 0 to 2^N - 1
//Observation 2 : two corners are connected if they differ exactly in 1 bit (i.e. their distance is 1, otherwise their distance is greater than 1 -> not connected because the cube is a unit cube)
//so for every corner (represented by N bits) the neighbor of it can be found by flipping exactly one bit at a time: for ex: 000 has neighbors: 001, 010, 100. To flip we use XOR
//in general: the result of flipping the k-th bit of a number n is: n^(1 << k) = n XOR 2^k because: the k-th bit is flipped (if it's 1: 1 XOR 1 = 0 -> flipped, if it's 0 then 0 XOR 1 = 1 -> flipped), others: if 0 remains 0 (0 XOR 0), if 1 remains 1 (1 XOR 0)

#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

int main()
{
  int N;
  vector<int> weights;
  vector<int> sumNeig;
  while (scanf("%d", &N) == 1)
    {
      int nbCorner = 1 << N;
      weights.assign(nbCorner, 0);
      sumNeig.assign(nbCorner, 0);
      for (int i = 0; i < nbCorner; ++i)
	{
	  assert(scanf("%d", &weights[i]) == 1);
	}
      //for each corner calculate its sumNeig
      for (int i = 0; i < nbCorner; ++i)
	{
	  for (int k = 0; k < N; ++k)
	    {
	      int idNeig = i ^ (1 << k);
	      sumNeig[i] += weights[idNeig];
	    }
	}
      int maxSum = 0;
       for (int i = 0; i < nbCorner; ++i)
	{
	  for (int k = 0; k < N; ++k)
	    {
	      int idNeig = i ^ (1 << k);
	      maxSum = max(maxSum, sumNeig[idNeig] + sumNeig[i]);
	    }
	}
       printf("%d\n", maxSum);
    }

}
  



