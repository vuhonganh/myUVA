//uva 481 What Goes Up
//Longest Increasing Sequence (LIS) type, seem like dynamic programming approach got Time Limit Exceed
//So we use another method with time complexity O(nlogk) with k is the maximum size of LIS
//The key point of this method: store an array L with L[i] represents the smallest ending value of all length-i LISs found so far
//The number of the elements in LIS is equal the size of this array L
//Also, store an array of index L_id and an array of predecessor (Parrent) to print result, see code below for detail implementation
#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
  int nb;
  vector<int> Arr;//the array that contains all the number
  vector<int> L;  //L[i] represents the smallest ending value of all length-i LISs found so far
  vector<int> L_id;
  int i = 0;
  vector<int> Parrent; // store the predecessor (in order to print)
  while (scanf("%d", &nb) == 1)
    {
      Arr.push_back(nb);
      //given this number, need to find where it is in L
      size_t pos = lower_bound(L.begin(), L.end(), nb) - L.begin();
      if (pos == L.size()) //all value in L is smaller than this nb
	{
	  L.push_back(nb);
	  L_id.push_back(i);
	}
      else
	{
	  L[pos] = nb;
	  L_id[pos] = i;
	}
      //update predecessor, Parrent.push_back equivalent to Parrent[i] = 
      //because we dont know the size so we use puch_back
      if (pos > 0) Parrent.push_back(L_id[pos - 1]);
      else Parrent.push_back(-1); //if this value is smallest so far, it has no predecessor
      ++i;
    }
  printf("%zd\n", L.size());
  stack<int> sequence;
  int idLastElem = L_id[L.size() - 1];
  sequence.push(Arr[idLastElem]);
  int idxParrent = Parrent[idLastElem];
  while (idxParrent != -1)
    {
      sequence.push(Arr[idxParrent]);
      idxParrent = Parrent[idxParrent];
    }
  printf("-\n");
  while (!sequence.empty())
    {
      printf("%d\n", sequence.top());
      sequence.pop();
    }
  return 0;
}
